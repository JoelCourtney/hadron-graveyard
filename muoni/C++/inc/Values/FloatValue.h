//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_FLOATVALUE_H
#define C_FLOATVALUE_H

#include "ScalarValue.h"

class FloatValue : public ScalarValue {
    double d;

public:
    FloatValue(double);
    ~FloatValue() override = default;

    std::string toString() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;
};

#endif //C_FLOATVALUE_H
