//
// Created by Joel Courtney on 2019-03-12.
//

#ifndef C_SCOPE_H
#define C_SCOPE_H

#include <unordered_map>
#include "Values/Value.h"
#include "Dimensions/Dimension.h"
#include "Units/Unit.h"

class Scope {
    std::unordered_map<std::string,Value*> values;
    std::unordered_map<std::string,Value*> variables;
    std::unordered_map<std::string,Dimension*> dimensions;
    std::unordered_map<std::string,Unit*> units;

public:
    Scope() = default;
    virtual ~Scope();
};

#endif //C_SCOPE_H
