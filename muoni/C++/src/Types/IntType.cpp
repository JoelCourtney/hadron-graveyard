//
// Created by Joel Courtney on 2019-03-04.
//

#include "Types/IntType.h"

std::string IntType::toString() const {
    return "int";
}

Value* IntType::toThis(Value* v) const {
    return v->getType()->toIntValue(v);
}

IntValue* IntType::toIntValue(Value* v) const {
    return dynamic_cast<IntValue*>(v);
}

void IntType::toNull(Value* v) const {
    unwrap(dynamic_cast<IntValue*>(v));
}

bool IntType::toBool(Value* v) const {
    int i = unwrap(dynamic_cast<IntValue*>(v));
    return i != 0;
}

int IntType::toInt(Value* v) const {
    return unwrap(dynamic_cast<IntValue*>(v));
}

double IntType::toFloat(Value* v) const {
    return (double) toInt(v);
}

BigInt IntType::toBigInt(Value* v) const {
    return BigInt(toInt(v));
}

MatrixXi IntType::toIntMatrix(Value* v) const {
    MatrixXi m(1,1);
    m << toInt(v);
    return m;
}

MatrixXd IntType::toFloatMatrix(Value* v) const {
    MatrixXd m(1,1);
    m << toFloat(v);
    return m;
}

std::complex<int> IntType::toComplexInt(Value* v) const {
    return std::complex<int>(toInt(v),0);
}

std::complex<double> IntType::toComplexFloat(Value* v) const {
    return std::complex<double>(toFloat(v),0);
}