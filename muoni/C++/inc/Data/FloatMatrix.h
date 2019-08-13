//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_FLOATMATRIXVALUE_H
#define C_FLOATMATRIXVALUE_H

#include "Matrix.h"

class FloatMatrix : public Matrix {
    Eigen::MatrixXd m;

public:
    explicit FloatMatrix(Eigen::MatrixXd);
    ~FloatMatrix() override = default;

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
    
    int getRows() const override;
    int getCols() const override;
};

#endif //C_FLOATMATRIXVALUE_H
