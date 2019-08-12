//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Bool.h"
#include "Data/DataFactory.h"

Bool::Bool(bool b) : Scalar(Type::BOOL), b(b) {}

Data* Bool::clone() const {
    return DataFactory::from(b);
}

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

Data* Bool::add(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = dynamic_cast<Primitive*>(d2);
    Type t2 = p2->getType();
    switch(t2) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(toString() + p2->toString());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(toInt() + p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() + p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(toFloat() + p2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (p2->toIntMatrix().array() + toInt()).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (p2->toFloatMatrix().array() + toFloat()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(toComplexInt() + p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toComplexFloat() + p2->toComplexFloat());
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}
