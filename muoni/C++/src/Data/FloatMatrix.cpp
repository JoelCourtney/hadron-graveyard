//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/DataFactory.h"
#include "Errors/InvalidOperationError.h"

FloatMatrix::FloatMatrix(Eigen::MatrixXd m) : Matrix(Type::FLOAT_MATRIX), m(std::move(m)) {}

Data* FloatMatrix::clone() const {
    return DataFactory::from(m);
}

std::string FloatMatrix::toString() const {
    std::stringstream ss;
    ss << m;
    return formatMatrix(ss.str());
}

bool FloatMatrix::toBool() const {
    return m.isZero();
}

int FloatMatrix::toInt() const {
    return (int) (toFloat());
}

double FloatMatrix::toFloat() const {
    return (m.size() == 1) ? m(1) : throw InvalidConversionError();
}

BigIntBackend FloatMatrix::toBigInt() const {
    return toInt();
}

Eigen::MatrixXi FloatMatrix::toIntMatrix() const {
    return m.cast<int>();
}

Eigen::MatrixXd FloatMatrix::toFloatMatrix() const {
    return m;
}

std::complex<int> FloatMatrix::toComplexInt() const {
    return std::complex<int>(toInt(),0);
}

std::complex<double> FloatMatrix::toComplexFloat() const {
    return std::complex<double>(toFloat(),0);
}

Data* FloatMatrix::negate() {
    m = -m;
    return this;
}

Data* FloatMatrix::add(Data* d2) {
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
        case Type::FLOAT:
            return DataFactory::from((Eigen::MatrixXd) (m.array() + p2->toFloat()).matrix());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (m + p2->toFloatMatrix()));
        case Type::COMPLEX_INT:
        case Type::COMPLEX_FLOAT:
            throw NotImplementedError();
        case Type::LIST: {
            auto l2 = dynamic_cast<List *>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
        } break;
        default:
            throw NotImplementedError();
    }
}

Data* FloatMatrix::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from((Eigen::MatrixXd) (m - p2->toFloatMatrix()));
        case Type::BOOL:
        case Type::INT:
        case Type::BIG_INT:
        case Type::FLOAT:
            return DataFactory::from((Eigen::MatrixXd) (m.array() - p2->toFloat()).matrix());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            return DataFactory::from((Eigen::MatrixXd) (m - p2->toFloatMatrix()));
        case Type::COMPLEX_INT:
        case Type::COMPLEX_FLOAT:
            throw NotImplementedError();
        case Type::LIST:
            throw InvalidOperationError();
        default:
            throw NotImplementedError();
    }
}

int FloatMatrix::getRows() const {
    return m.rows();
}

int FloatMatrix::getCols() const {
    return m.cols();
}
