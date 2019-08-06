//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/DataFactory.h"
#include "Data/String.h"

String::String(std::string& s) : Data(Type::STRING), s(std::move(s)) {}

std::string String::toString() const {
    return s;
}

bool String::toBool() const {
    return s.length() > 0 && s != "false";
}

int String::toInt() const {
    return std::stoi(s);
}

double String::toFloat() const {
    return std::stod(s);
}

BigIntBackend String::toBigInt() const {
    return BigIntBackend(std::stoi(s));
}

Eigen::MatrixXi String::toIntMatrix() const {
    Eigen::MatrixXi m(1,1);
    m << std::stoi(s);
    return m;
}

Eigen::MatrixXd String::toFloatMatrix() const {
    Eigen::MatrixXd m(1,1);
    m << std::stod(s);
    return m;
}

std::complex<int> String::toComplexInt() const {
    return std::complex<int>(std::stoi(s),0);
}

std::complex<double> String::toComplexFloat() const {
    throw NotImplementedError();
//    return std::complex<double>(b,0);
}

Data* String::add(Data* d2) const {
    Type t2 = d2->getType();
    switch(t2) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        default:
            return DataFactory::from(s + d2->toString());
    }
}