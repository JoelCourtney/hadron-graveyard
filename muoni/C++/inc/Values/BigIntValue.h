//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_BIGINTVALUE_H
#define C_BIGINTVALUE_H

#include "BigInt.h"
#include "ScalarValue.h"

class BigIntValue : public ScalarValue {
    BigInt b;

    friend class Type;

public:
    explicit BigIntValue(BigInt);
    ~BigIntValue() override = default;

    std::string toString() const override;

    Type* getType() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;


};

#endif //C_BIGINTVALUE_H
