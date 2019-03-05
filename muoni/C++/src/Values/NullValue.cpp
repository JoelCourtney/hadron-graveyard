//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/NullValue.h"
#include "Types/NullType.h"

NullValue::NullValue() {}

std::string NullValue::toString() const {
    return "null";
}

Type* NullValue::getType() const {
    return NullType::getInstance();
}
