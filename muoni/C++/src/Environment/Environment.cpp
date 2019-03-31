//
// Created by Joel Courtney on 2019-03-13.
//

#include "Environment/Environment.h"

#include "Values/ValueFactory.h"
#include "Environment/ExplicitScope.h"

Environment::~Environment() {
    while(!stack.empty()) {
        delete stack.top();
        stack.pop();
    }
}

void Environment::pushAns(const Value* v) {
}

Value* Environment::getVarl(const std::string& name) const {
    Scope* s = stack.top();
    Value* v = s->getVarl(name);
    while (!v) {
        s = s->defer();
        v = s->getVarl(name);
    }
    return v;
}

void Environment::assignVarl(const std::string& name, Value* v) {
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

void Environment::pop() {
    delete stack.top();
    stack.pop();
}
