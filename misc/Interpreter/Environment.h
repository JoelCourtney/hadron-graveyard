#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "List.h"
#include "Number.h"
#include "Quantity.h"

typedef enum {
	N = sizeof(Number),
	S = sizeof(char),
	B = sizeof(bool),
} DataType;

typedef struct {
	char* name;
	void* data;
	DataType type;
} Variable;

typedef struct {
	unsigned long long int num;
	unsigned long long int den;
	bool dimensionless;
	
	char* name;
} Quantity;

typedef struct {
	int numUnits;

	char** units;
	double* converters;

	Number converter;

	char* surname;
	Quantity* quantity;
} UnitFamily;

typedef struct scope Scope;

struct scope {
	Variable* variables;
	UnitFamily* baseFamilies;
	UnitFamily* derivedFamilies;
	Quantity* baseQuantities;
	Quantity* derivedQuantities;
	int numVariables;
	int numBaseFamilies;
	int numDerivedFamilies;
	int numBaseQuantities;
	int numDerivedQuantities;
	bool blocker;
	Scope* deferTo;
	Scope* next;
};

Scope* scopeStack;
Scope* scopeStackBase;

int compare(const void*,const void*);
Variable* getVariable(char*);
void createVariable(char*,void*,DataType);
bool setVariable(char*,void*,DataType);

void createBaseQuantity(char*, bool);
void createCompoundQuantity(char*, Number);
Quantity* getQuantityByName(char*);

void createUnitFamily(int,char**,double*,Number,char*,Quantity*);
Number getConverter(char*);

void pushNewScope(bool);
void popScope();

#endif
