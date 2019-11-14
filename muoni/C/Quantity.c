#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Quantity.h"




void createCompoundQuantity(char* name, Quantity* num, int numL, Quantity* den, int denL) {
	Quantity* q = malloc(sizeof(Quantity));
	q->name = name;
	unsigned long long int newNum = 1;
	unsigned long long int newDen = 1;
	for (int i = 0; i < numL; i++) {
		newNum *= num[i].num;
		newDen *= den[i].den;
	}
	for (int i = 0; i < denL; i++) {
		newNum *= num[i].den;
		newDen *= den[i].num;
	}
	ListNode* cursor = quantityListHead;
	unsigned long long int p;
	while (cursor != NULL) {
		p = ((Quantity*)(cursor->data))->num;
		if (newNum % p == 0 && newDen % p == 0) {
			newNum /= p;
			newDen /= p;
		} else {
			cursor = cursor->next;
		}
	}
	q->num = newNum;
	q->den = newDen;
	ListNode* newNode = malloc(sizeof(ListNode));
	newNode->data = q;
	if (compoundListHead == NULL) {
		compoundListHead = newNode;
	} else {
		compoundListTail->next = newNode;
	}
	compoundListTail = newNode;
}

Quantity* getQuantityByName(char* name) {
	ListNode* cursor = quantityListHead;
	while (cursor != NULL) {
		if (strcmp(name, ((Quantity*)(cursor->data))->name) == 0) {
			return ((Quantity*)(cursor->data));
		}
		cursor = cursor->next;
	}
	cursor = compoundListHead;
	while (cursor != NULL) {
		if (strcmp(name, ((Quantity*)(cursor->data))->name) == 0) {
			return ((Quantity*)(cursor->data));
		}
		cursor = cursor->next;
	}
	return NULL;
}

void printQuantityLists() {
	ListNode* cursor = quantityListHead;
	while (cursor != NULL) {
		char* n = ((Quantity*)(cursor->data))->name;
		printf("%s\n",n);
		cursor = cursor->next;
	}
	cursor = compoundListHead;
	while (cursor != NULL) {
		char* n = ((Quantity*)(cursor->data))->name;
		printf("%s\n",n);
		cursor = cursor->next;
	}
}

// MEMORY LEAKS FOR DAYS
void deleteQuantityLists() {
	deleteList(quantityListHead);
	deleteList(compoundListHead);
}
