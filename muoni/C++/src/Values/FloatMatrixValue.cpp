//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/FloatMatrixValue.h"
#include "Values/ValueFactory.h"

FloatMatrixValue::FloatMatrixValue(MatrixXd m) : m(m) {}

std::string FloatMatrixValue::toString() const {
    std::stringstream ss;
    ss << m;
    return ss.str();
}

void FloatMatrixValue::increment() {
    m = (m.array() + 1).matrix();
}

void FloatMatrixValue::decrement() {
    m = (m.array() - 1).matrix();
}

void FloatMatrixValue::negate() {
    m *= -1;
}

void FloatMatrixValue::conjugate() {}

ScalarValue* FloatMatrixValue::determinant() {
    return ValueFactory::from(m.determinant());
}

void FloatMatrixValue::invert() {
    m = m.inverse();
}
