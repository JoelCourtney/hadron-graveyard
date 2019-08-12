//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_INTMATRIX_H
#define C_INTMATRIX_H

#include "Matrix.h"

class IntMatrix : public Matrix {
    Eigen::MatrixXi m;

public:
    explicit IntMatrix(Eigen::MatrixXi);
    ~IntMatrix() override = default;

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
    
    int getRows() const override;
    int getCols() const override;
};

#endif //C_INTMATRIX_H
