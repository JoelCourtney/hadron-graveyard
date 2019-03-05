#include <iostream>
#include "Values/Value.h"
#include "Values/NumericValue.h"
#include "Values/ValueFactory.h"
#include "Values/BigInt.h"
#include <complex>
#include <Eigen/Dense>
#include "Operations/BinaryOperation.h"
#include "Types/Type.h"
#include <cstdio>
#include <ctime>

void doStuffs() {
    NullValue* v = ValueFactory::from();
    Type* t = v->getType();
    for (int i = 0; i < 10000000; i++) {
        v = v->getType()->toNullValue(v);
    }
    delete v;
}

int main() {
    std::cout << std::boolalpha;

    std::clock_t start = std::clock();

    doStuffs();

    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Time: "<< duration << std::endl;
    return 0;
}