//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_COMPLEXFLOATVALUE_H
#define C_COMPLEXFLOATVALUE_H

#include "Scalar.h"
#include <complex>

class ComplexFloat : public Scalar {
    std::complex<double> c;

public:
    explicit ComplexFloat(std::complex<double>);
    ~ComplexFloat() override = default;

    std::string toString() const override;
};

#endif //C_COMPLEXFLOATVALUE_H
