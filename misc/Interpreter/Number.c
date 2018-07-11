#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Environment.h"
#include "Number.h"
#include "List.h"

inline void printNumber(Number n) {
	printf("%f[%llu/%llu]\n",n.n,n.num,n.den);
}

inline void printNumberAs(Number n, char* u) {
	Number converter = getConverter(u);
	n = divideNumbers(n,converter);
	if (!unitsEmpty(n)) {
		printf("Cannot convert number to %s.\n",u);
	}
	printf("%f[%s]\n",n.n,u);
}

inline Number copyNumber(Number n) {
	return (Number){n.num, n.den, n.n};
}

inline bool unitsEqual(Number n1, Number n2) {
	return (n1.num == n2.num) && (n1.den == n2.den);
}

inline bool unitsEmpty(Number n) {
	return (n.num - n.den) == 0;
}

inline Number negateNumber(Number n) {
	return (Number){n.num, n.den, -n.n};
}

inline Number invertNumber(Number n) {
	return (Number){n.den, n.num, 1/n.n};
}

inline Number addNumbers(Number n1, Number n2) {
	return (Number){n1.num,n1.den,n1.n + n2.n};
}

inline Number subtractNumbers(Number n1, Number n2) {
	return (Number){n1.num,n1.den,n1.n - n2.n};
}

inline Number multiplyNumbers(Number n1, Number n2) {
	unsigned long long int num = n1.num * n2.num;
	unsigned long long int den = n1.den * n2.den;
	Scope* cursor = scopeStack;
	int p;
	while (cursor != NULL) {
		for (int i = 0; i < cursor->numBaseFamilies; i++) {
			p = (int)(cursor->baseFamilies[i].converter.num);
			if (num % p == 0 && den % p == 0) {
				num /= p;
				den /= p;
				i--;
			}
		}
		cursor = cursor->next;
	}
	return (Number){num,den,n1.n*n2.n};
}

inline Number divideNumbers(Number n1, Number n2) {
	return multiplyNumbers(n1, invertNumber(n2));
}
