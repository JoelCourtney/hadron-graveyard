//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/DataFactory.h"
#include "Data/BigInt.h"

BigInt::BigInt(const BigIntBackend& b) : Scalar(Type::BIG_INT), b(b) {}

Data* BigInt::clone() const {
    return DataFactory::from(b);
}

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

Data* BigInt::negate() {
    b.sign = -b.sign;
    return this;
}

Data* BigInt::add(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(toString() + p2->toString());
        case Type::BOOL:
        case Type::INT:
            (b + p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(b + p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(b + p2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (p2->toIntMatrix().array() + toInt()).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (p2->toFloatMatrix().array() + toFloat()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(toInt() + p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toFloat() + p2->toComplexFloat());
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}

Data* BigInt::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(b - toBigInt());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(b - p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(b - p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(b - p2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (toInt() - p2->toIntMatrix().array()).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (toFloat() - p2->toFloatMatrix().array()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(toInt() - p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toFloat() - p2->toComplexFloat());
        case Type::LIST:
            throw InvalidOperationError();
    }
}