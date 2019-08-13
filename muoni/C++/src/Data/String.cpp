//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/DataFactory.h"
#include "Data/String.h"

String::String(std::string& s) : Primitive(Type::STRING), s(std::move(s)) {}

Data* String::clone() const {
    return DataFactory::from(s);
}

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

Data* String::negate() {
    throw InvalidOperationError();
}

Data* String::add(Data* d2) {
    switch(d2->type) {
        case Type::NULL_TYPE:
            throw InvalidOperationError();
        case Type::LIST: {
            auto l2 = dynamic_cast<List *>(d2);
            l2->l.insert(l2->l.begin(), this);
            return l2;
        }
        default:
            return DataFactory::from(s + d2->toString());
    }
}

Data* String::subtract(Data* d2) {
    if (!d2->isPrimitive()) {
        throw InvalidOperationError();
    }
    auto p2 = reinterpret_cast<Primitive*>(d2);
    switch (p2->type) {
        case Type::NULL_TYPE:
        case Type::LIST:
            throw InvalidOperationError();
        case Type::STRING:
            return toNumeric()->subtract(reinterpret_cast<String*>(p2)->toNumeric());
        default:
            return toNumeric()->subtract(p2);
    }
}

Data* String::toNumeric() const {
    // will call eval
    return nullptr;
}