//
// Created by Joel Courtney on 2019-03-13.
//

#include <Environment/ImplicitScope.h>
#include "Environment/Environment.h"

#include "Data/DataFactory.h"
#include "Environment/ExplicitScope.h"
#include "Errors/CannotDeferError.h"
#include "Errors/VarlNotFoundError.h"

Environment::~Environment() {
    while(!stack.empty()) {
        delete stack.top();
        stack.pop();
    }
}

void Environment::pushAns(Data* v) {
    Scope* s = stack.top();
    while (!s->pushAns(v)) {
        s = s->defer();
    }
}

Data* Environment::getVarl(const std::string& name) const {
    Scope* s = stack.top();
    Data* v = s->getVarl(name);
    while (!v) {
        try {
            s = s->defer();
        } catch (const CannotDeferError& e) {
            throw VarlNotFoundError(name);
        }
        v = s->getVarl(name);
    }
    return v;
}

void Environment::assignVarl(const std::string& name, Data* v) {
    Scope* s = stack.top();
    while(!s->assignVarl(name, v)) {
        s = s->defer();
    }
}

void Environment::declareVarl(const std::string& name, bool mut) {
    Scope* s = stack.top();
    while(!s->declareVarl(name, mut)) {
        s = s->defer();
    }
}

void Environment::push(Scope* s) {
    stack.push(s);
}

ExplicitScope* Environment::pushDefaultExplicitScope() {
    auto res = new ExplicitScope(stack.top());
    stack.push(res);
    return res;
}

ImplicitScope* Environment::pushDefaultImplicitScope() {
    auto res = new ImplicitScope(stack.top());
    stack.push(res);
    return res;
}

Data* Environment::pop() {
    auto top = stack.top();
    auto fullTop = dynamic_cast<FullScope*>(top);
    if (fullTop != nullptr) {
        Data* res = fullTop->getTopAns();
        delete fullTop;
        stack.pop();
        return res;
    } else {
        delete top;
        stack.pop();
        return nullptr;
    }
}

Scope* Environment::topScope() {
    return stack.top();
}