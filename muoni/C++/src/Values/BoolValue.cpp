//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/BoolValue.h"
#include "Types/BoolType.h"

BoolValue::BoolValue(bool b) : b(b) {}

std::string BoolValue::toString() const {
    if (b)
        return "true";
    else
        return "false";
}

Type* BoolValue::getType() const {
    return BoolType::getInstance();
}