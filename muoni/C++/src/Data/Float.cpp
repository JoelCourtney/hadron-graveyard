//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/Float.h"
#include "Data/DataFactory.h"

Float::Float(double d) : Scalar(Type::FLOAT), d(d) {}

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
    return d;
}

Eigen::MatrixXi Float::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << d;
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

Data* Float::add(Data* d2) const {
    Type t2 = d2->getType();
    switch(t2) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(toString() + d2->toString());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(d + d2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() + d2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(d + d2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (d2->toFloatMatrix().array() + d).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (d2->toFloatMatrix().array() + d).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from((int) d + d2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(d + d2->toComplexFloat());
    }
}