//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/StringValue.h"
#include "Types/IntType.h"

StringValue::StringValue(std::string& s) : s(std::move(s)) {}

std::string StringValue::toString() const {
    return s;
}

Type* StringValue::getType() const {
    return IntType::getInstance();
}