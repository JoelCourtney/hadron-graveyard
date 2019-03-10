//
// Created by Joel Courtney on 2019-03-09.
//

#include "Units/UnityDerivedUnit.h"

UnityDerivedUnit::UnityDerivedUnit(const UnityDimension* d, std::string s, std::vector<UnitComponent> c, double m)
    : DerivedUnit(d,std::move(s),std::move(c),m) {
}

std::vector<UnitComponent> UnityDerivedUnit::toMultiplicationComponents() const {
    std::vector<UnitComponent> v;
    return v;
}
