//
// Created by Joel Courtney on 2019-03-12.
//

#include "Environment/Scope.h"

Scope::~Scope() {
    auto it1 = values.begin();
    while(it1 != values.end()) {
        delete it1->second;
        it1++;
    }
    auto it2 = variables.begin();
    while(it2 != variables.end()) {
        delete it2->second;
        it2++;
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
}
