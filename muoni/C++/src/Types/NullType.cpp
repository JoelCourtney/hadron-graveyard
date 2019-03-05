//
// Created by Joel Courtney on 2019-03-04.
//

#include "Types/NullType.h"

std::string NullType::toString() const {
    return "null";
}

Value* NullType::toThis(Value* v) const {
    return v->getType()->toNullValue(v);
}

NullValue* NullType::toNullValue(Value* v) const {
    return dynamic_cast<NullValue*>(v);
}

void NullType::toNull(Value* v) const {
    unwrap(dynamic_cast<NullValue*>(v));
}

bool NullType::toBool(Value* v) const {
    toNull(v);
    return false;
}

int NullType::toInt(Value* v) const {
    toNull(v);
    return 0;
}

double NullType::toFloat(Value* v) const {
    toNull(v);
    return 0;
}

BigInt NullType::toBigInt(Value* v) const {
    toNull(v);
    return BigInt(0);
}

MatrixXi NullType::toIntMatrix(Value* v) const {
    toNull(v);
    MatrixXi m(0,0);
    return m;
}

MatrixXd NullType::toFloatMatrix(Value* v) const {
    toNull(v);
    MatrixXd m(0,0);
    return m;
}

std::complex<int> NullType::toComplexInt(Value* v) const {
    toNull(v);
    return std::complex<int>(0,0);
}

std::complex<double> NullType::toComplexFloat(Value* v) const {
    toNull(v);
    return std::complex<double>(0,0);
}
