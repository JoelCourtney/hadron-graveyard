//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_COMPLEXINTVALUE_H
#define C_COMPLEXINTVALUE_H

#include "ScalarValue.h"
#include <complex>

class ComplexIntValue : public ScalarValue {
    std::complex<int> c;

public:
    ComplexIntValue(int,int);
    ~ComplexIntValue() override = default;

    std::string toString() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;
};

#endif //C_COMPLEXINTVALUE_H
