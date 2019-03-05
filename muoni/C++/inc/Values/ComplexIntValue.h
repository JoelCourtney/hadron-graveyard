//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_COMPLEXINTVALUE_H
#define C_COMPLEXINTVALUE_H

#include "ScalarValue.h"
#include <complex>

class ComplexIntValue : public ScalarValue {
    std::complex<int> c;

    friend class Type;

public:
    ComplexIntValue(std::complex<int>);
    ~ComplexIntValue() override = default;

    std::string toString() const override;

    Type* getType() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;
};

#endif //C_COMPLEXINTVALUE_H
