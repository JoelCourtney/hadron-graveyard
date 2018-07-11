#ifndef NUMBER_H
#define NUMBER_H

#include <stdbool.h>
#include "List.h"

typedef struct {
	unsigned long long int num;
	unsigned long long int den;
	double n;
} Number;

void printNumber(Number);
void printNumberAs(Number,char*);

Number createNumber(double,ListNode*,ListNode*);
void deleteNumber(Number);
Number copyNumber(Number);

bool unitsEqual(Number,Number);
bool unitsEmpty(Number);

Number negateNumber(Number);
Number invertNumber(Number);

Number addNumbers(Number,Number);
Number subtractNumbers(Number,Number);

Number multiplyNumbers(Number,Number);
Number divideNumbers(Number,Number);

#endif
