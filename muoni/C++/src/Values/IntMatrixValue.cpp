//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/IntMatrixValue.h"
#include "Values/ValueFactory.h"

IntMatrixValue::IntMatrixValue(MatrixXi m) : m(m) {}

std::string IntMatrixValue::toString() const {
    std::stringstream ss;
    ss << m;
    return ss.str();
}

void IntMatrixValue::increment() {
    m = (m.array() + 1).matrix();
}

void IntMatrixValue::decrement() {
    m = (m.array() - 1).matrix();
}

void IntMatrixValue::negate() {
    m *= -1;
}

void IntMatrixValue::conjugate() {}

ScalarValue* IntMatrixValue::determinant() {
    return ValueFactory::from((int) m.cast<double>().determinant());
}

void IntMatrixValue::invert() {
    m = m.cast<double>().inverse().cast<int>();
}