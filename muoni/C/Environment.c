#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "Environment.h"

inline int compare(const void* s1, const void* s2) {
	return strcmp(((Variable*)(s1))->name, ((Variable*)(s2))->name);
}

Variable* getVariable(char* name) {
	Scope* s = scopeStack;
	int l, r, m, diff;
	while (s != NULL) {
		r = s->numVariables - 1;
		l = 0;
		while (l <= r) {
			m = (l + r) / 2;
			diff = strcmp(name, s->variables[m].name);
			if (diff == 0) {
				return &(s->variables[m]);
			} else if (diff < 0) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		if (s->blocker) {
			break;
		}
		s = s->next;
	}
	return NULL;
}

void createVariable(char* name, void* data, DataType type) {
	Scope* s = scopeStack;
	s->numVariables++;
	s->variables = realloc(s->variables, s->numVariables);
	s->variables[s->numVariables-1] = (Variable){name, data, type};
	qsort(s->variables,s->numVariables,sizeof(char),compare);
}

bool setVariable(char* name, void* data, DataType type) {
	Variable* v = getVariable(name);
	if (v == NULL || v->type != type) {
		return false;
	}
	if (type == N) {
		Number* n = (Number*)(v->data);
		if (!unitsEqual(*((Number*)(v->data)),*((Number*)(data)))) {
			return false;
		}
	}
	memcpy(v->data, data, type);
	return true;
}

void createBaseQuantity(char* name, bool dimensionless) {
	Scope* s = scopeStack;
	s->numBaseQuantities++;
	s->baseQuantities = realloc(s->baseQuantities, sizeof(Quantity)*s->numBaseQuantities);
	Quantity* q = &(s->baseQuantities[s->numBaseQuantities-1]);
	q->den = 1;
	q->dimensionless = dimensionless;
	q->name = name;
	int p = 0;
	while (s != NULL) {
		if (s->numBaseQuantities > 0) {
			p = (int)(s->baseQuantities[s->numBaseQuantities-1].num);
			break;
		}
		s = s->next;
	}
	if (p == 0) {
		q->num = 2;
	} else {
		int n = p;
		int i;
		bool notPrime = true;
		while (notPrime) {
			n++;
			s = scopeStack;
			while (s != NULL) {
				for (int i = 0; i < s->numBaseQuantities; i++) {
					p = s->baseQuantities[i].num;
					if (n % p == 0) {
						break;
					}
				}
				notPrime = n % p == 0;
			}
		}
		q->num = n;
	}
}

void createUnitFamily(int numUnits,char**units,double*converters,Number converter,char*surname,Quantity*quantity) {
	UnitFamily fam = (UnitFamily){numUnits,units,converters,converter,surname,quantity};
	if (unitsEmpty(converter)) {
		int p = 0;
		Number c = (Number){0,1,1};
		Scope* cursor = scopeStack;
		while (cursor != NULL) {
			if (cursor->numBaseFamilies != 0) {
				p = cursor->baseFamilies[cursor->numBaseFamilies-1].converter.num;
				break;
			}
			cursor = cursor->next;
		}
		if (p == 0) {
			c.num = 2;
		} else {
			int n = p;
			int i;
			bool notPrime = true;
			while (notPrime) {
				n++;
				cursor = scopeStack;
				while (cursor != NULL) {
					for (int i = 0; i < cursor->numBaseFamilies; i++) {
						p = cursor->baseFamilies[i].converter.num;
						if (n % p == 0) {
							break;
						}
					}
					notPrime = n % p == 0;
				}
			}
			c.num = n;
		}
		fam.converter = c;
		scopeStack->numBaseFamilies++;
		scopeStack->baseFamilies = realloc(scopeStack->baseFamilies,sizeof(UnitFamily)*scopeStack->numBaseFamilies);
		scopeStack->baseFamilies[scopeStack->numBaseFamilies-1] = fam;
	} else {
		scopeStack->numDerivedFamilies++;
		scopeStack->derivedFamilies = realloc(scopeStack->derivedFamilies,sizeof(UnitFamily)*scopeStack->numDerivedFamilies);
		scopeStack->derivedFamilies[scopeStack->numDerivedFamilies-1] = fam;
	}
}

Number getConverter(char* unit) {
	Scope* cursor = scopeStack;
	UnitFamily fam;
	while (cursor != NULL) {
		for (int i = 0; i < cursor->numBaseFamilies; i++) {
			fam = cursor->baseFamilies[i];
			for (int j = 0; j < fam.numUnits; j++) {
				if (strcmp(fam.units[i],unit) == 0) {
					Number n = copyNumber(fam.converter);
					n.n *= fam.converters[i];
					return n;
				}
			}
		}
		for (int i = 0; i < cursor->numDerivedFamilies; i++) {
			fam = cursor->derivedFamilies[i];
			for (int j = 0; j < fam.numUnits; j++) {
				if (strcmp(fam.units[i],unit) == 0) {
					Number n = copyNumber(fam.converter);
					n.n *= fam.converters[i];
					return n;
				}
			}
		}
	}
	return (Number){0,0,0};
}

void pushNewScope(bool blocker) {
	Scope* s = calloc(1,sizeof(Scope));
	s->variables = malloc(0);
	s->baseFamilies = malloc(0);
	s->derivedFamilies = malloc(0);
	s->blocker = blocker;
	s->next = scopeStack;
	scopeStack = s;
}

void popScope() {
	Scope* s = scopeStack;
	scopeStack = scopeStack->next;
	free(s->variables);
	free(s->baseFamilies);
	free(s->derivedFamilies);
	free(s->baseQuantities);
	free(s->derivedQuantities);
	free(s);
}
