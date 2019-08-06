//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/Int.h"
#include "Data/DataFactory.h"
#include "Errors/InvalidOperationError.h"

Int::Int(int i) : Scalar(Type::INT), i(i) {}

std::string Int::toString() const {
    return std::to_string(i);
}

bool Int::toBool() const {
    return i;
}

int Int::toInt() const {
    return i;
}

double Int::toFloat() const {
    return i;
}

BigIntBackend Int::toBigInt() const {
    return i;
}

Eigen::MatrixXi Int::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << i;
    return m;
}

Eigen::MatrixXd Int::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << i;
    return m;
}

std::complex<int> Int::toComplexInt() const {
    return std::complex<int>(i,0);
}

std::complex<double> Int::toComplexFloat() const {
    return std::complex<double>(i,0);
}

Data* Int::add(Data* d2) const {
    Type t2 = d2->getType();
    switch(t2) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(toString() + d2->toString());
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(i + d2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() + d2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(i + d2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (d2->toIntMatrix().array() + i).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (d2->toFloatMatrix().array() + i).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(i + d2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from((double) i + d2->toComplexFloat());
    }
}