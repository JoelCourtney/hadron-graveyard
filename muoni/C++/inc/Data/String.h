//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_STRINGVALUE_H
#define C_STRINGVALUE_H

#include "Primitive.h"

class String : public Primitive {
    std::string s;

public:
    explicit String(std::string&);
    ~String() override = default;

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

#endif //C_STRINGVALUE_H
