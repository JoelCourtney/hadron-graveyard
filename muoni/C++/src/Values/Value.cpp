//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/Value.h"

std::ostream& operator<<(std::ostream& o, const Value* v) {
    o << v->toString();
    return o;
}

std::ostream& operator<<(std::ostream& o, const Value& v) {
    o << v.toString();
    return o;
}