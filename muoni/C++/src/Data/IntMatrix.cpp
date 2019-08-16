//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/Int.h"
#include "Data/DataFactory.h"
#include "Errors/InvalidOperationError.h"

IntMatrix::IntMatrix(Eigen::MatrixXi m) : Matrix(Type::INT_MATRIX), m(std::move(m)) {}

Data* IntMatrix::clone() const {
    return DataFactory::from(m);
}

std::string IntMatrix::toString() const {
    std::stringstream ss;
    ss << m;
    return formatMatrix(ss.str());
}

bool IntMatrix::toBool() const {
    return !m.isZero();
}

int IntMatrix::toInt() const {
    return (m.size() == 1) ? m(1) : throw InvalidConversionError();
}

double IntMatrix::toFloat() const {
    return (double) toInt();
}

BigIntBackend IntMatrix::toBigInt() const {
    return toInt();
}

Eigen::MatrixXi IntMatrix::toIntMatrix() const {
    return m;
}

Eigen::MatrixXd IntMatrix::toFloatMatrix() const {
    return m.cast<double>();
}

std::complex<int> IntMatrix::toComplexInt() const {
    return std::complex<int>(toInt(),0);
}

std::complex<double> IntMatrix::toComplexFloat() const {
    return std::complex<double>(toFloat(),0);
}

Data* IntMatrix::negate() {
    m = -m;
    return this;
}

Data* IntMatrix::add(Data* d2) {
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
        case Type::BIG_INT:
            return DataFactory::from((Eigen::MatrixXi) (m.array() + p2->toInt()).matrix());
        case Type::FLOAT:
            return DataFactory::from((Eigen::MatrixXd) (toFloatMatrix().array() + p2->toFloat()).matrix());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (m + p2->toIntMatrix()));
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (toFloatMatrix() + p2->toFloatMatrix()));
        case Type::COMPLEX_INT:
        case Type::COMPLEX_FLOAT:
            throw NotImplementedError();
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}

Data* IntMatrix::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from((Eigen::MatrixXi) (m - p2->toIntMatrix()));
        case Type::BOOL:
        case Type::INT:
        case Type::BIG_INT:
            return DataFactory::from((Eigen::MatrixXi) (m.array() - p2->toInt()).matrix());
        case Type::FLOAT:
            return DataFactory::from((Eigen::MatrixXd) (toFloatMatrix().array() - p2->toFloat()).matrix());
        case Type::INT_MATRIX:
            return DataFactory::from((Eigen::MatrixXi) (m - p2->toIntMatrix()));
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (toFloatMatrix() - p2->toFloatMatrix()));
        case Type::COMPLEX_INT:
        case Type::COMPLEX_FLOAT:
            throw NotImplementedError();
        case Type::LIST:
            throw InvalidOperationError();
    }
}

int IntMatrix::getRows() const {
    return m.rows();
}

int IntMatrix::getCols() const {
    return m.cols();
}
