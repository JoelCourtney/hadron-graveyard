//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/ComplexFloatValue.h"
#include "Values/ValueFactory.h"

ComplexFloatValue::ComplexFloatValue(double r, double i) : c(r,i) {}

std::string ComplexFloatValue::toString() const {
    double r = c.real();
    double i = c.imag();
    if (i >= 0) {
        return std::to_string(r) + "+" + std::to_string(i) + "i";
    } else {
        return std::to_string(r) + "-" + std::to_string(i) + "i";
    }
}

void ComplexFloatValue::increment() {
    c += 1;
}

void ComplexFloatValue::decrement() {
    c -= 1;
}

void ComplexFloatValue::negate() {
    c = -c;
}

void ComplexFloatValue::conjugate() {
    c = std::conj(c);
}

ScalarValue* ComplexFloatValue::magnitude() {
    return ValueFactory::from(std::abs(c));
}
