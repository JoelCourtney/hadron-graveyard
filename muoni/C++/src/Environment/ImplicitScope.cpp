//
// Created by Joel Courtney on 2019-08-12.
//

#include "Environment/ImplicitScope.h"

//
// Created by Joel Courtney on 2019-03-16.
//

#include "Errors/CannotAssignError.h"
#include "Environment/ImplicitScope.h"
#include "Data/DataFactory.h"

ImplicitScope::ImplicitScope(Scope* s) : deferTo(s) {}

ImplicitScope::~ImplicitScope() {
    auto it1 = vars.begin();
    while(it1 != vars.end()) {
        delete it1->second;
        it1++;
    }
}

Scope* ImplicitScope::defer() const {
    return deferTo;
}

Data* ImplicitScope::getVarl(const std::string& s) const {
    if (vars.count(s)) {
        return vars.at(s)->clone();
    }
    return nullptr;
}

bool ImplicitScope::containsVarl(const std::string& s) const {
    return vars.count(s);
}

bool ImplicitScope::assignVarl(const std::string& s, Data* v) {
    if (vars.count(s)) {
        delete vars.at(s);
        vars.at(s) = v;
        return true;
    } else {
        return false;
    }
}

bool ImplicitScope::declareVarl(const std::string& s, bool) {
    if (!locked) {
        vars[s] = nullptr;
        return true;
    } else {
        return false;
    }
}

bool ImplicitScope::pushAns(Data*) {
    return false;
}

Data* ImplicitScope::getTopAns() {
    return nullptr;
}

void ImplicitScope::lock() {
    locked = true;
}

ImplicitScope* ImplicitScope::cloneSetup() const {
    return nullptr;
}