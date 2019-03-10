//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_MATRIXVALUE_H
#define C_MATRIXVALUE_H

#include "NumericValue.h"
#include "ScalarValue.h"

class MatrixValue : public NumericValue {
public:
    ~MatrixValue() override = default;
    virtual ScalarValue* determinant() = 0;
    virtual void invert() = 0;
};

#endif //C_MATRIXVALUE_H
