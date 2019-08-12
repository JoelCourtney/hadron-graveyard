//
// Created by Joel Courtney on 2019-03-16.
//

#include "Errors/CannotAssignError.h"
#include "Environment/FullScope.h"
#include "Data/DataFactory.h"

FullScope::~FullScope() {
    auto it1 = varls.begin();
    while(it1 != varls.end()) {
        delete it1->second;
        it1++;
    }
    auto it3 = dimensions.begin();
    while(it3 != dimensions.end()) {
        delete it3->second;
        it3++;
    }
    auto it4 = units.begin();
    while(it4 != units.end()) {
        delete it4->second;
        it4++;
    }
    for (int i = 1; i < ans.size(); i++) {
        delete ans.at(i-1);
    }
}

Data* FullScope::getVarl(const std::string& s) const {
    if (varls.count(s)) {
        return varls.at(s)->clone();
    }
    return nullptr;
}

bool FullScope::containsVarl(const std::string& s) const {
    return varls.count(s);
}

bool FullScope::assignVarl(const std::string& s, Data* v) {
    if (mutability.count(s)) {
        if (mutability.at(s) || varls.at(s) == nullptr) {
            delete varls.at(s);
            varls.at(s) = v;
            return true;
        } else {
            throw CannotAssignError();
        }
    } else {
        return false;
    }
}

bool FullScope::declareVarl(const std::string& s, bool m) {
    if (mutability.count(s)) {
        mutability.at(s) = m;
        delete varls.at(s);
        varls[s] = nullptr;
    } else {
        varls[s] = nullptr;
        mutability[s] = m;
    }
    return true;
}

void FullScope::pushAns(Data* d) {
    ans.push_back(d);
}

Data* FullScope::getTopAns() {
    if (ans.size())
        return ans.back();
    else
        return nullptr;
}
