//
// Created by Joel Courtney on 2019-03-01.
//

#include "Values/IntValue.h"
#include "Values/ValueFactory.h"

IntValue::IntValue(int i) : i(i) {}

std::string IntValue::toString() const {
    return std::to_string(i);
}

void IntValue::increment() {
    i++;
}

void IntValue::decrement() {
    i--;
}

void IntValue::negate() {
    i = -i;
}

void IntValue::conjugate() {}

ScalarValue* IntValue::magnitude() {
    if (i >= 0) {
        return ValueFactory::from(i);
    } else {
        return ValueFactory::from(-i);
    }
}