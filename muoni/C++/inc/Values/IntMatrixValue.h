//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_INTMATRIX_H
#define C_INTMATRIX_H

#include "MatrixValue.h"
#include <Eigen/Dense>

using namespace Eigen;

class IntMatrixValue : public MatrixValue {
    MatrixXi m;

public:
    IntMatrixValue(MatrixXi);
    ~IntMatrixValue() override = default;

    std::string toString() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* determinant() override;
    void invert() override;
};

#endif //C_INTMATRIX_H
