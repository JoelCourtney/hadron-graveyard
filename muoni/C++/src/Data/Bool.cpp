//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Bool.h"
#include "Data/DataFactory.h"

Bool::Bool(bool b) : Data(Type::BOOL), b(b) {}

std::string Bool::toString() const {
    if (b)
        return "true";
    else
        return "false";
}

bool Bool::toBool() const {
    return b;
}

int Bool::toInt() const {
    return (int) b;
}

double Bool::toFloat() const {
    return (double) b;
}

BigIntBackend Bool::toBigInt() const {
    return BigIntBackend(b);
}

Eigen::MatrixXi Bool::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << b;
    return m;
}

Eigen::MatrixXd Bool::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << b;
    return m;
}

std::complex<int> Bool::toComplexInt() const {
    return std::complex<int>(b,0);
}

std::complex<double> Bool::toComplexFloat() const {
    return std::complex<double>(b,0);
}

Data* Bool::add(Data* d2) const {
    Type t2 = d2->getType();
    switch(t2) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(toString() + d2->toString());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(toInt() + d2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() + d2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(toFloat() + d2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (d2->toIntMatrix().array() + toInt()).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (d2->toFloatMatrix().array() + toFloat()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(toComplexInt() + d2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toComplexFloat() + d2->toComplexFloat());
    }
}
