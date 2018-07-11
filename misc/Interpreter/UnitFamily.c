#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Number.h"

void createUnitFamily(int numUnits,char**units,double*converters,Number converter,char*surname,Quantity*quantity) {
	UnitFamily* fam = malloc(sizeof(UnitFamily));
	fam->numUnits = numUnits;
	fam->units = units;
	fam->converters = converters;
	fam->surname = surname;
	fam->quantity = quantity;
	ListNode* node = malloc(sizeof(ListNode));
	node->next = NULL;
	node->data = fam;
	if (unitsEmpty(converter)) {
		if (familyListHead != NULL) {
			int n = (int)(((UnitFamily*)(familyListTail->data))->converter.num);
			int p;
			ListNode* cursor;
			while (true) {
				n++;
				cursor = familyListHead;
				p = (int)(((UnitFamily*)(cursor->data))->converter.num);
				while (p < n/2) {
					if (n % p == 0) {
						break;
					} else {
						cursor = cursor->next;
					}
					p = (int)(((UnitFamily*)(cursor->data))->converter.num);
				}
				if (n % p != 0) {
					converter.num = n;
					converter.den = 1;
					break;
				}
			}
			fam->converter = converter;
			familyListTail->next = node;
		} else {
			fam->converter = (Number){2,1,1};
			familyListHead = node;
			familyListTail = node;
		}
	} else {
		fam->converter = converter;
		node->next = derivedListHead;
		derivedListHead = node;
	}
}

Number getConverter(char* name) {
	ListNode* cursor = familyListHead;
	UnitFamily* fam;
	while (cursor != NULL) {
		fam = (UnitFamily*)(cursor->data);
		for (int i = 0; i < fam->numUnits; i++) {
			if (strcmp(fam->units[i],name) == 0) {
				Number n = copyNumber(fam->converter);
				n.n *= fam->converters[i];
				return n;
			}
		}
		cursor = cursor->next;
	}
	cursor = derivedListHead;
	while (cursor != NULL) {
		fam = (UnitFamily*)(cursor->data);
		for (int i = 0; i < fam->numUnits; i++) {
			if (strcmp(fam->units[i],name) == 0) {
				Number n = copyNumber(fam->converter);
				n.n *= fam->converters[i];
				return n;
			}
		}
		cursor = cursor->next;
	}
	return (Number){0,0,0};
}
