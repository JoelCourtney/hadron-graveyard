//
// Created by Joel Courtney on 2019-08-08.
//

#include "Data/DataFactory.h"

List::List(std::vector<Data*> l) : Primitive(Type::LIST), l(std::move(l)) {}

List::~List() {
    for (Data* d : l)
        delete d;
}

std::string List::toString() const {
    int size = l.size();
    switch (size) {
        case 0:
            return "[]";
        case 1:
            return "[" + l[0]->toString() + "]";
        default:
            std::string res = "[";
            res += l[0]->toString();
            for (int i = 1; i < size; i++) {
                res += ", " + l[i]->toString();
            }
            return res + "]";
    }
}

bool List::toBool() const {
    return !l.empty();
}

int List::toInt() const {
    throw InvalidConversionError();
}

double List::toFloat() const {
    throw InvalidConversionError();
}

BigIntBackend List::toBigInt() const {
    throw InvalidConversionError();
}

Eigen::MatrixXi List::toIntMatrix() const {
    throw InvalidConversionError();
}

Eigen::MatrixXd List::toFloatMatrix() const {
    throw InvalidConversionError();
}

std::complex<int> List::toComplexInt() const {
    throw InvalidConversionError();
}

std::complex<double> List::toComplexFloat() const {
    throw InvalidConversionError();
}

Data* List::clone() const {
    std::vector<Data*> res(l.size());
    for (unsigned long i = 0; i < l.size(); i++) {
        res[i] = l[i]->clone();
    }
    return DataFactory::from(res);
}

Data* List::negate() {
    throw InvalidOperationError();
}

Data* List::add(Data* d2) {
    if (d2->type == Type::LIST) {
        auto c2 = reinterpret_cast<List*>(d2);
        l.insert( l.end(), c2->l.begin(), c2->l.end() );
    } else {
        l.push_back(d2);
    }
    return this;
}

Data* List::subtract(Data*) {
    throw InvalidOperationError();
}