//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/ValueFactory.h"
#include "Values/BigIntValue.h"
#include "Types/IntType.h"

BigIntValue::BigIntValue(BigInt b) : b(b) {}

std::string BigIntValue::toString() const {
    return b.toString();
}

Type* BigIntValue::getType() const {
    return IntType::getInstance();
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
