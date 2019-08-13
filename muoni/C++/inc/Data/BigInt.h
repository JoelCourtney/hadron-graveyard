//
// Created by joel on 8/5/19.
//

#ifndef C___BIGINT_H
#define C___BIGINT_H

#include "Scalar.h"

class BigInt : public Scalar {
    BigIntBackend b;

public:
    explicit BigInt(const BigIntBackend&);
    ~BigInt() override = default;
    
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

#endif //C___BIGINT_H
