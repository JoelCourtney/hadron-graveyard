//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Scalar.h"

Scalar::Scalar(Type t) : Numeric(t) {}

int Scalar::getRows() const {
    return 1;
}

int Scalar::getCols() const {
    return 1;
}
