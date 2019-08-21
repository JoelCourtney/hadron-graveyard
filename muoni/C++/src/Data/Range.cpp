//
// Created by joel on 8/20/19.
//

#include "Data/DataFactory.h"

Range::Range(bool li, Data* f, Data* l, bool ri) : Primitive(Type::RANGE), left_inc(li), first(f), last(l), right_inc(ri) {}
Range::Range(bool li, Data* f, Data* s, Data* l, bool ri) : Primitive(Type::RANGE), left_inc(li), first(f), step(s), last(l), right_inc(ri) {}

Range::~Range() {
    delete first;
    delete last;
    if (step)
        delete step;
}

std::string Range::toString() const {
    std::string res = ((left_inc)?"[":"(") + first->toString() + " : ";
    if (step)
        res += step->toString() + " : ";
    return res + last->toString() + ((right_inc)?"]":")");
}

bool Range::toBool() const {
    throw NotImplementedError();
}

int Range::toInt() const {
    throw InvalidConversionError();
}

double Range::toFloat() const {
    throw InvalidConversionError();
}

BigIntBackend Range::toBigInt() const {
    throw InvalidConversionError();
}

Eigen::MatrixXi Range::toIntMatrix() const {
    throw InvalidConversionError();
}

Eigen::MatrixXd Range::toFloatMatrix() const {
    throw InvalidConversionError();
}

std::complex<int> Range::toComplexInt() const {
    throw InvalidConversionError();
}

std::complex<double> Range::toComplexFloat() const {
    throw InvalidConversionError();
}

Data* Range::clone() const {
    if (step)
        return DataFactory::from(left_inc, first->clone(), last->clone(), right_inc);
    else
        return DataFactory::from(left_inc, first->clone(), step->clone(), last->clone(), right_inc);
}

Data* Range::negate() {
    first->negate();
    last->negate();
    if (step)
        step->negate();
}

Data* Range::add(Data* d2) {
    throw InvalidOperationError();
}

Data* Range::subtract(Data*) {
    throw InvalidOperationError();
}

Data* Range::iterate() const {
    static Data* cursor = first->clone();
    static Data* local_step = (step) ? step : DataFactory::from(1);
    Data *res;
    if (left_inc) {
        res = cursor->clone();
        cursor = cursor->add(local_step->clone());
    } else {
        cursor = cursor->add(local_step->clone());
        res = cursor->clone();
    }
    // Check upper bound
    throw NotImplementedError();
    return res;
}

std::vector<Data*> Range::toList() const {
    Data* cursor = first->clone();
    Data* local_step = (step) ? step : DataFactory::from(1);
    std::vector<Data*> res;
    if (left_inc) {
        while (true) {
            res.push_back(cursor->clone());
            cursor = cursor->add(local_step->clone());
            throw NotImplementedError();
        }
    } else {
        while (true) {
            cursor = cursor->add(local_step->clone());
            res.push_back(cursor->clone());
            throw NotImplementedError();
        }
    }
    return res;
}