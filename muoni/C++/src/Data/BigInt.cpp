//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/DataFactory.h"
#include "Data/BigInt.h"

BigInt::BigInt(const BigIntBackend& b) : Scalar(Type::BIG_INT), b(b) {}

std::string BigInt::toString() const {
    return b.toString();
}

bool BigInt::toBool() const {
    return !b.isZero();
}

int BigInt::toInt() const {
    return b.longValue();
}

double BigInt::toFloat() const {
    return std::stod(b.toString());
}

BigIntBackend BigInt::toBigInt() const {
    return b;
}

Eigen::MatrixXi BigInt::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << toInt();
    return m;
}

Eigen::MatrixXd BigInt::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << toFloat();
    return m;
}

std::complex<int> BigInt::toComplexInt() const {
    return std::complex<int>(toInt(),0);
}

std::complex<double> BigInt::toComplexFloat() const {
    return std::complex<double>(toFloat(),0);
}

Data* BigInt::add(Data* d2) const {
    Type t2 = d2->getType();
    switch(t2) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(toString() + d2->toString());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(b + d2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(b + d2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(b + d2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (d2->toIntMatrix().array() + toInt()).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (d2->toFloatMatrix().array() + toFloat()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(toInt() + d2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toFloat() + d2->toComplexFloat());
    }
}