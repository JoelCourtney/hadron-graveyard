//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_INTVALUE_H
#define C_INTVALUE_H

#include "Scalar.h"

class Int : public Scalar {
    int i;

public:
    explicit Int(int);
    ~Int() override = default;

    Data* clone() const override;

    std::string toString() const override;
    bool toBool() const override;
    int toInt() const override;
    BigIntBackend toBigInt() const override;
    double toFloat() const override;
    Eigen::MatrixXi toIntMatrix() const override;
    Eigen::MatrixXd toFloatMatrix() const override;
    std::complex<int> toComplexInt() const override;
    std::complex<double> toComplexFloat() const override;

    Data* negate() override;

    Data* add(Data*) override;
    Data* subtract(Data*) override;
};

#endif //C_INTVALUE_H
