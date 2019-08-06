//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_MATRIXVALUE_H
#define C_MATRIXVALUE_H

#include "Numeric.h"
#include "Scalar.h"

class Matrix : public Numeric {
public:
    explicit Matrix(Type);
    ~Matrix() override = default;
};

#endif //C_MATRIXVALUE_H
