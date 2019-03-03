//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/ComplexIntValue.h"
#include "Values/ValueFactory.h"

ComplexIntValue::ComplexIntValue(int r, int i) : c(r,i) {}

std::string ComplexIntValue::toString() const {
    int r = c.real();
    int i = c.imag();
    if (i >= 0) {
        return std::to_string(r) + "+" + std::to_string(i) + "i";
    } else {
        return std::to_string(r) + "-" + std::to_string(i) + "i";
    }
}

void ComplexIntValue::increment() {
    c += 1;
}

void ComplexIntValue::decrement() {
    c -= 1;
}

void ComplexIntValue::negate() {
    c = -c;
}

void ComplexIntValue::conjugate() {
    c = std::conj(c);
}

ScalarValue* ComplexIntValue::magnitude() {
    return ValueFactory::from(std::abs(c));
}