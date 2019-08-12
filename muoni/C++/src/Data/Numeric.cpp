//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Numeric.h"

Numeric::Numeric(Type t) : Primitive(t) {}

bool Numeric::isNumeric() const {
    return true;
}
