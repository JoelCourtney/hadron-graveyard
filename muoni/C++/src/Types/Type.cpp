//
// Created by Joel Courtney on 2019-03-03.
//

#include "Types/Type.h"

std::string Type::toString(Value* v) const {
    std::string s = v->toString();
    delete v;
    return s;
}

NullValue* Type::toNullValue(Value* v) const {
    return ValueFactory::from();
}

StringValue* Type::toStringValue(Value* v) const {
    return ValueFactory::from(toString(v));
}

BoolValue* Type::toBoolValue(Value* v) const {
    return ValueFactory::from(toBool(v));
}

IntValue* Type::toIntValue(Value* v) const {
    return ValueFactory::from(toInt(v));
}

FloatValue* Type::toFloatValue(Value* v) const {
    return ValueFactory::from(toFloat(v));
}

BigIntValue* Type::toBigIntValue(Value* v) const {
    return ValueFactory::from(toBigInt(v));
}

IntMatrixValue* Type::toIntMatrixValue(Value* v) const {
    return ValueFactory::from(toIntMatrix(v));
}

FloatMatrixValue* Type::toFloatMatrixValue(Value* v) const {
    return ValueFactory::from(toFloatMatrix(v));
}

ComplexIntValue* Type::toComplexIntValue(Value* v) const {
    return ValueFactory::from(toComplexInt(v));
}

ComplexFloatValue* Type::toComplexFloatValue(Value* v) const {
    return ValueFactory::from(toComplexFloat(v));
}

void Type::unwrap(NullValue* v) const {
    delete v;
}

std::string Type::unwrap(StringValue* v) const {
    std::string s = v->s;
    delete v;
    return s;
}

bool Type::unwrap(BoolValue* v) const {
    bool b = v->b;
    delete v;
    return b;
}

int Type::unwrap(IntValue* v) const {
    int i = v->i;
    delete v;
    return i;
}

double Type::unwrap(FloatValue* v) const {
    double d = v->d;
    delete v;
    return d;
}

BigInt Type::unwrap(BigIntValue* v) const {
    BigInt b = v->b;
    delete v;
    return b;
}

MatrixXi Type::unwrap(IntMatrixValue* v) const {
    MatrixXi m = v->m;
    delete v;
    return m;
}

MatrixXd Type::unwrap(FloatMatrixValue* v) const {
    MatrixXd m = v->m;
    delete v;
    return m;
}

std::complex<int> Type::unwrap(ComplexIntValue* v) const {
    std::complex<int> c = v->c;
    delete v;
    return c;
}

std::complex<double> Type::unwrap(ComplexFloatValue* v) const {
    std::complex<double> c = v->c;
    delete v;
    return c;
}