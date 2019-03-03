//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/ValueFactory.h"
#include "Values/BigIntValue.h"

BigIntValue::BigIntValue(bigint b) : b(b) {}

std::string BigIntValue::toString() const {
    return b.toString();
}

void BigIntValue::increment() {
    b += 1;
}

void BigIntValue::decrement() {
    b -= 1;
}

void BigIntValue::negate() {
    b = -b;
}

void BigIntValue::conjugate() {}

ScalarValue* BigIntValue::magnitude() {
    if (b >= 0) {
        return ValueFactory::from(b);
    } else {
        return ValueFactory::from(-b);
    }
}
