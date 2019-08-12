//
// Created by Joel Courtney on 2019-03-14.
//

#ifndef C_IMPLICITSCOPE_H
#define C_IMPLICITSCOPE_H

#include "Scope.h"

class ImplicitScope : public Scope {
    std::unordered_map<std::string,Data*> vars;

public:
    explicit ImplicitScope();
    ~ImplicitScope() override;
    
    
};

#endif //C_IMPLICITSCOPE_H
