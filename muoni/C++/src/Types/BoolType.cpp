//
// Created by Joel Courtney on 2019-03-04.
//

#include "Types/BoolType.h"

std::string BoolType::toString() const {
    return "bool";
}

Value* BoolType::toThis(Value* v) const {
    return v->getType()->toBoolValue(v);
}

BoolValue* BoolType::toBoolValue(Value* v) const {
    return dynamic_cast<BoolValue*>(v);
}

void BoolType::toNull(Value* v) const {
    unwrap(dynamic_cast<BoolValue*>(v));
}

bool BoolType::toBool(Value* v) const {
    return unwrap(dynamic_cast<BoolValue*>(v));
}

int BoolType::toInt(Value* v) const {
    return (int) unwrap(dynamic_cast<BoolValue*>(v));
}

double BoolType::toFloat(Value* v) const {
    return (double) toInt(v);
}

BigInt BoolType::toBigInt(Value* v) const {
    return BigInt(toInt(v));
}

MatrixXi BoolType::toIntMatrix(Value* v) const {
    MatrixXi m(1,1);
    m << toInt(v);
    return m;
}

MatrixXd BoolType::toFloatMatrix(Value* v) const {
    MatrixXd m(1,1);
    m << toFloat(v);
    return m;
}

std::complex<int> BoolType::toComplexInt(Value* v) const {
    return std::complex<int>(toInt(v),0);
}

std::complex<double> BoolType::toComplexFloat(Value* v) const {
    return std::complex<double>(toFloat(v),0);
}
