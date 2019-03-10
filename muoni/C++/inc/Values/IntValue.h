//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_INTVALUE_H
#define C_INTVALUE_H

#include "ScalarValue.h"

class IntValue : public ScalarValue {
    int i;

    friend class Type;

public:
    explicit IntValue(int);
    ~IntValue() override = default;

    std::string toString() const override;

    Type* getType() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;
};

#endif //C_INTVALUE_H
