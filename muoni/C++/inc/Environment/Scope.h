//
// Created by Joel Courtney on 2019-03-12.
//

#ifndef C_SCOPE_H
#define C_SCOPE_H

#include <unordered_map>
#include "Data/Primitive.h"
#include "Dimensions/Dimension.h"
#include "Units/Unit.h"

class Scope {
public:
    Scope() = default;
    virtual ~Scope() = default;

    virtual Scope* defer() const = 0;

    virtual Data* getVarl(const std::string&) const = 0;
    virtual bool assignVarl(const std::string&, Data*) = 0;
    virtual bool containsVarl(const std::string&) const = 0;
    virtual bool declareVarl(const std::string&, bool) = 0;
    
    virtual bool pushAns(Data*) = 0;
    virtual Data* getTopAns() = 0;
};

#endif //C_SCOPE_H
