//
// Created by Joel Courtney on 2019-03-01.
//

#include "Values/FloatValue.h"
#include "Values/ValueFactory.h"
#include "Types/IntType.h"

FloatValue::FloatValue(double d) : d(d) {}

std::string FloatValue::toString() const {
    return std::to_string(d);
}

Type* FloatValue::getType() const {
    return IntType::getInstance();
}

void FloatValue::increment() {
    d++;
}

void FloatValue::decrement() {
    d--;
}

void FloatValue::negate() {
    d = -d;
}

void FloatValue::conjugate() {}

ScalarValue* FloatValue::magnitude() {
    if (d >= 0) {
        return ValueFactory::from(d);
    } else {
        return ValueFactory::from(-d);
    }
}