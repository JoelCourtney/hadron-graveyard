//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/ComplexFloat.h"
#include "Data/DataFactory.h"

ComplexFloat::ComplexFloat(std::complex<double> c) : Scalar(Type::COMPLEX_FLOAT), c(std::move(c)) {}

std::string ComplexFloat::toString() const {
    double r = c.real();
    double i = c.imag();
    if (i >= 0) {
        return std::to_string(r) + "+" + std::to_string(i) + "i";
    } else {
        return std::to_string(r) + "-" + std::to_string(i) + "i";
    }
}
