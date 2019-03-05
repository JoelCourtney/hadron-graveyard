//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_COMPLEXFLOATVALUE_H
#define C_COMPLEXFLOATVALUE_H

#include "ScalarValue.h"
#include <complex>

class ComplexFloatValue : public ScalarValue {
    std::complex<double> c;

    friend class Type;

public:
    ComplexFloatValue(std::complex<double>);
    ~ComplexFloatValue() override = default;

    std::string toString() const override;

    Type* getType() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* magnitude() override;
};

#endif //C_COMPLEXFLOATVALUE_H
