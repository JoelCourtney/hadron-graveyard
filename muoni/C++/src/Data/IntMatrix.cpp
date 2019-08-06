//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/IntMatrix.h"
#include "Data/DataFactory.h"

IntMatrix::IntMatrix(Eigen::MatrixXi m) : Matrix(Type::INT_MATRIX), m(std::move(m)) {}

std::string IntMatrix::toString() const {
    std::stringstream ss;
    ss << m;
    return ss.str();
}
