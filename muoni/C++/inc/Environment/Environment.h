//
// Created by Joel Courtney on 2019-03-13.
//

#ifndef C_ENVIRONMENT_H
#define C_ENVIRONMENT_H

#include "Values/Value.h"
#include <stack>

class Scope;

class Environment {
    std::stack<Scope*> stack;

public:
    Environment() = default;
    ~Environment();

    void pushAns(const Value*);

    Value* getVarl(const std::string&) const;
    void assignVarl(const std::string&, Value*);
    void declareVarl(const std::string&, bool);

    void push(Scope*);
    void pop();
};

#endif //C_ENVIRONMENT_H
