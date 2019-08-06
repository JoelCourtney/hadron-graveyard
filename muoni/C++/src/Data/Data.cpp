//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Data.h"

Data::Data(Type t) : type(t) {}

Type Data::getType() const {
    return type;
}

std::ostream& operator<<(std::ostream& o, const Data* v) {
    o << v->toString();
    return o;
}

std::ostream& operator<<(std::ostream& o, const Data& v) {
    o << v.toString();
    return o;
}

Data* Data::add(Data*) const {
    return nullptr;
}
