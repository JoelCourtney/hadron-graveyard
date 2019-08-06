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

    std::string toString() const override;
};

#endif //C_INTMATRIX_H
