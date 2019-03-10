//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_FLOATMATRIXVALUE_H
#define C_FLOATMATRIXVALUE_H

#include "MatrixValue.h"
#include <Eigen/Dense>

using namespace Eigen;

class FloatMatrixValue : public MatrixValue {
    MatrixXd m;

    friend class Type;

public:
    explicit FloatMatrixValue(MatrixXd);
    ~FloatMatrixValue() override = default;

    std::string toString() const override;

    Type* getType() const override;

    void increment() override;
    void decrement() override;
    void negate() override;
    void conjugate() override;

    ScalarValue* determinant() override;
    void invert() override;
};

#endif //C_FLOATMATRIXVALUE_H
