//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/ComplexFloat.h"
#include "Data/DataFactory.h"

ComplexFloat::ComplexFloat(std::complex<double> c) : Scalar(Type::COMPLEX_FLOAT), c(c) {}

Data* ComplexFloat::clone() const {
    return DataFactory::from(c);
}

std::string ComplexFloat::toString() const {
    double r = c.real();
    double i = c.imag();
    if (r != 0 && i != 0)
        return std::to_string(r) + ((i > 0)?"+":"") + std::to_string(i) + "i";
    else if (r != 0)
        return std::to_string(r);
    else if (i != 0)
        return std::to_string(i) + "i";
    else
        return "0";
}

bool ComplexFloat::toBool() const {
    return c.real() != 0 || c.imag() != 0;
}

int ComplexFloat::toInt() const {
    if (c.imag() == 0)
        return c.real();
    else
        throw InvalidConversionError();
}

double ComplexFloat::toFloat() const {
    if (c.imag() == 0)
        return c.real();
    else
        throw InvalidConversionError();
}

BigIntBackend ComplexFloat::toBigInt() const {
    if (c.imag() == 0)
        return BigIntBackend(std::to_string(c.real()));
    else
        throw InvalidConversionError();
}

Eigen::MatrixXi ComplexFloat::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << toInt();
    return m;
}

Eigen::MatrixXd ComplexFloat::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << toFloat();
    return m;
}

std::complex<int> ComplexFloat::toComplexInt() const {
    return c;
}

std::complex<double> ComplexFloat::toComplexFloat() const {
    return c;
}

Data* ComplexFloat::negate() {
    c = -c;
    return this;
}

Data* ComplexFloat::add(Data* d2) {
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
            return DataFactory::from(c + p2->toFloat());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            throw NotImplementedError();
        case Type::COMPLEX_INT:
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(c + p2->toComplexFloat());
        case Type::LIST:
            auto l2 = dynamic_cast<List*>(p2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
    }
}

Data* ComplexFloat::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidConversionError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch(p2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::STRING:
            return DataFactory::from(c - p2->toComplexFloat());
        case Type::BOOL:
        case Type::INT:
        case Type::BIG_INT:
        case Type::FLOAT:
            return DataFactory::from(c - p2->toFloat());
        case Type::INT_MATRIX:
        case Type::FLOAT_MATRIX:
            throw NotImplementedError();
        case Type::COMPLEX_INT:
        case Type::COMPLEX_FLOAT:
            return DataFactory::from(c - p2->toComplexFloat());
        case Type::LIST:
            throw InvalidOperationError();
    }
}
