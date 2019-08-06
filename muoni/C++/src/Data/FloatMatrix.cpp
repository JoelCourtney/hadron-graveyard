//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/FloatMatrix.h"
#include "Data/DataFactory.h"

FloatMatrix::FloatMatrix(Eigen::MatrixXd m) : Matrix(Type::FLOAT_MATRIX), m(std::move(m)) {}

std::string FloatMatrix::toString() const {
    std::stringstream ss;
    ss << m;
    return ss.str();
}

Type* FloatMatrix::getType() const {
    return IntType::getInstance();
}

void FloatMatrix::increment() {
    m = (m.array() + 1).matrix();
}

void FloatMatrix::decrement() {
    m = (m.array() - 1).matrix();
}

void FloatMatrix::negate() {
    m *= -1;
}

void FloatMatrix::conjugate() {}

Scalar* FloatMatrix::determinant() {
    return DataFactory::from(m.determinant());
}

void FloatMatrix::invert() {
    m = m.inverse();
}
