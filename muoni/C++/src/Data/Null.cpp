//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Null.h"

Null::Null() : Data(Type::NULL_TYPE) {}

std::string Null::toString() const {
    return "null";
}

bool Null::toBool() const {
    throw InvalidConversionError();
}

int Null::toInt() const {
    throw InvalidConversionError();
}

double Null::toFloat() const {
    throw InvalidConversionError();
}

BigIntBackend Null::toBigInt() const {
    throw InvalidConversionError();
}

Eigen::MatrixXi Null::toIntMatrix() const {
    throw InvalidConversionError();
}

Eigen::MatrixXd Null::toFloatMatrix() const {
    throw InvalidConversionError();
}

std::complex<int> Null::toComplexInt() const {
    throw InvalidConversionError();
}

std::complex<double> Null::toComplexFloat() const {
    throw InvalidConversionError();
}

Data* Null::add(Data* d2) const {
    throw InvalidOperationError();
}