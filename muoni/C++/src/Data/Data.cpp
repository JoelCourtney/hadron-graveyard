//
// Created by Joel Courtney on 2019-08-11.
//

#include "Data/Data.h"

Data::Data(Type t) : type(t) {}

std::ostream& operator<<(std::ostream& o, const Data* v) {
    o << v->toString();
    return o;
}

std::ostream& operator<<(std::ostream& o, const Data& v) {
    o << v.toString();
    return o;
}

bool Data::isPrimitive() const {
    return false;
}

bool Data::isNumeric() const {
    return false;
}
