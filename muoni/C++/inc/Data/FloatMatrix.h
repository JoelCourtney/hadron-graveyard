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

    std::string toString() const override;
};

#endif //C_FLOATMATRIXVALUE_H
