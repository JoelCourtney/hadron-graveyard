//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_BOOLVALUE_H
#define C_BOOLVALUE_H

#include "Scalar.h"

class Bool : public Scalar {
    bool b;

public:
    explicit Bool(bool);
    ~Bool() override = default;

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
    
    Data* add(Data*) override;
};

#endif //C_BOOLVALUE_H
