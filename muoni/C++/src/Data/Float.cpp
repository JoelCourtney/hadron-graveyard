//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/Float.h"
#include "Data/DataFactory.h"

Float::Float(double d) : Scalar(Type::FLOAT), d(d) {}

Data* Float::clone() const {
    return DataFactory::from(d);
}

std::string Float::toString() const {
    return std::to_string(d);
}

bool Float::toBool() const {
    return d;
}

int Float::toInt() const {
    return d;
}

double Float::toFloat() const {
    return d;
}

BigIntBackend Float::toBigInt() const {
    return BigIntBackend(toString());
}

Eigen::MatrixXi Float::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << (int) d;
    return m;
}

Eigen::MatrixXd Float::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << d;
    return m;
}

std::complex<int> Float::toComplexInt() const {
    return std::complex<int>(d,0);
}

std::complex<double> Float::toComplexFloat() const {
    return std::complex<double>(d,0);
}

Data* Float::negate() {
    d = -d;
    return this;
}

Data* Float::add(Data* d2) {
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
            return DataFactory::from(d + p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() + p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(d + p2->toFloat());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (p2->toFloatMatrix().array() + d).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from((int) d + p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(d + p2->toComplexFloat());
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}

Data* Float::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(d - p2->toFloat());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(d - p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() - p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(d - p2->toFloat());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (d - p2->toFloatMatrix().array()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from((int) d - p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(d - p2->toComplexFloat());
        case Type::LIST:
            throw InvalidOperationError();
    }
}