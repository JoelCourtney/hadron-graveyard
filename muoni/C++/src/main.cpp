#include <iostream>
#include "Values/Value.h"
#include "Values/NumericValue.h"
#include "Values/ValueFactory.h"
#include "Values/bigint.h"
#include <complex>
#include <Eigen/Dense>

int main() {
    bigint b; b.read("1234");
    std::cout << ValueFactory::from(b) << std::endl;

    return 0;
}