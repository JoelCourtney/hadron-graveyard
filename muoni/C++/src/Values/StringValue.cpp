//
// Created by Joel Courtney on 2019-03-02.
//

#include "Values/StringValue.h"

StringValue::StringValue(std::string s) : s(s) {}

std::string StringValue::toString() const {
    return s;
}
