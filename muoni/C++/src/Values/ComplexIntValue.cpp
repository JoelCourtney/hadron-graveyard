//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/ComplexIntValue.h"
#include "Values/ValueFactory.h"
#include "Types/IntType.h"

ComplexIntValue::ComplexIntValue(std::complex<int> c) : c(std::move(c)) {}

std::string ComplexIntValue::toString() const {
    int r = c.real();
    int i = c.imag();
    if (i >= 0) {
        return std::to_string(r) + "+" + std::to_string(i) + "i";
    } else {
        return std::to_string(r) + "-" + std::to_string(i) + "i";
    }
}

Type* ComplexIntValue::getType() const {
    return IntType::getInstance();
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