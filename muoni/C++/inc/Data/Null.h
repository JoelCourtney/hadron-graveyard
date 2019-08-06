//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_NULLVALUE_H
#define C_NULLVALUE_H

#include "Data.h"

class Null : public Data {
public:
    Null();
    ~Null() override = default;

    std::string toString() const override;
    bool toBool() const override;
    int toInt() const override;
    BigIntBackend toBigInt() const override;
    double toFloat() const override;
    Eigen::MatrixXi toIntMatrix() const override;
    Eigen::MatrixXd toFloatMatrix() const override;
    std::complex<int> toComplexInt() const override;
    std::complex<double> toComplexFloat() const override;
    
    Data* add(Data*) const override;
};

#endif //C_NULLVALUE_H
