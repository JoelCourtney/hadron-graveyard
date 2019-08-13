//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/ComplexInt.h"
#include "Data/DataFactory.h"

ComplexInt::ComplexInt(std::complex<int> c) : Scalar(Type::COMPLEX_INT), c(c) {}

Data* ComplexInt::clone() const {
    return DataFactory::from(c);
}

std::string ComplexInt::toString() const {
    int r = c.real();
    int i = c.imag();
    if (r != 0 && i != 0)
        return std::to_string(r) + ((i > 0)?"+":"") + std::to_string(i) + "i";
    else if (r != 0)
        return std::to_string(r);
    else if (i != 0)
        return std::to_string(i) + "i";
    else
        return "0";
}

bool ComplexInt::toBool() const {
    return c.real() != 0 || c.imag() != 0;
}

int ComplexInt::toInt() const {
    if (c.imag() == 0)
        return c.real();
    else
        throw InvalidConversionError();
}

double ComplexInt::toFloat() const {
    if (c.imag() == 0)
        return c.real();
    else
        throw InvalidConversionError();
}

BigIntBackend ComplexInt::toBigInt() const {
    return toInt();
}

Eigen::MatrixXi ComplexInt::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << toInt();
    return m;
}

Eigen::MatrixXd ComplexInt::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << toFloat();
    return m;
}

std::complex<int> ComplexInt::toComplexInt() const {
    return c;
}

std::complex<double> ComplexInt::toComplexFloat() const {
    return std::complex<double>(c.real(),c.imag());
}

Data* ComplexInt::negate() {
    c = -c;
    return this;
}

Data* ComplexInt::add(Data* d2) {
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
            return DataFactory::from(c + p2->toInt());
        case Type::FLOAT:
            return DataFactory::from(toComplexFloat() + p2->toFloat());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            throw NotImplementedError();
        case Type::COMPLEX_INT:
            return DataFactory::from(c + p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toComplexFloat() + p2->toComplexFloat());
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}

Data* ComplexInt::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(c - p2->toComplexInt());
        case Type::BOOL:
        case Type::INT:
        case Type::BIG_INT:
            return DataFactory::from(c - p2->toInt());
        case Type::FLOAT:
            return DataFactory::from(toComplexFloat() - p2->toFloat());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            throw NotImplementedError();
        case Type::COMPLEX_INT:
            return DataFactory::from(c - p2->toComplexInt());
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(toComplexFloat() - p2->toComplexFloat());
        case Type::LIST:
            throw InvalidOperationError();
    }
}