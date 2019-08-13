//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/Int.h"
#include "Data/DataFactory.h"
#include "Errors/InvalidOperationError.h"

Int::Int(int i) : Scalar(Type::INT), i(i) {}

Data* Int::clone() const {
    return DataFactory::from(i);
}

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

Data* Int::negate() {
    i = -i;
    return this;
}

Data* Int::add(Data* d2) {
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
            return DataFactory::from(i + p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() + p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(i + p2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (p2->toIntMatrix().array() + i).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (p2->toFloatMatrix().array() + i).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(i + p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from((double) i + p2->toComplexFloat());
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}

Data* Int::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
        case Type::BOOL:
        case Type::INT:
            return DataFactory::from(i - p2->toInt());
        case Type::BIG_INT:
            return DataFactory::from(toBigInt() - p2->toBigInt());
        case Type::FLOAT:
            return DataFactory::from(i - p2->toFloat());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (i - p2->toIntMatrix().array()).matrix());
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (i - p2->toFloatMatrix().array()).matrix());
        case Type::COMPLEX_INT:
            return DataFactory::from(i - p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from((double) i - p2->toComplexFloat());
        case Type::LIST:
            throw InvalidOperationError();
    }
}
