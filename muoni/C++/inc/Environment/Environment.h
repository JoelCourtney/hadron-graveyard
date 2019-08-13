//
// Created by Joel Courtney on 2019-03-13.
//

#ifndef C_ENVIRONMENT_H
#define C_ENVIRONMENT_H

#include "Data/Primitive.h"
#include <stack>

class Scope;
class ExplicitScope;
class ImplicitScope;

class Environment {
    std::stack<Scope*> stack;

public:
    Environment() = default;
    ~Environment();

    void pushAns(Data*);

    Data* getVarl(const std::string&) const;
    void assignVarl(const std::string&, Data*);
    void declareVarl(const std::string&, bool);

    void push(Scope*);
    ExplicitScope* pushDefaultExplicitScope();
    ImplicitScope* pushDefaultImplicitScope();
    Data* pop();
    
    Scope* topScope();
};

#endif //C_ENVIRONMENT_H
