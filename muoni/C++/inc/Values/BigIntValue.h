//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_BIGINTVALUE_H
#define C_BIGINTVALUE_H

#include "bigint.h"
#include "ScalarValue.h"

class BigIntValue : public ScalarValue {
    bigint b;

public:
    BigIntValue(bigint);
    ~BigIntValue() override = default;

    std::string toString() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;
};

#endif //C_BIGINTVALUE_H
