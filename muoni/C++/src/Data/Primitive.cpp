//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Primitive.h"

Primitive::Primitive(Type t) : Data(t) {}

bool Primitive::isPrimitive() const {
    return true;
}
