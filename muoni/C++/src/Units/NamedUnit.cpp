//
// Created by Joel Courtney on 2019-03-06.
//

#include "Units/NamedUnit.h"

NamedUnit::NamedUnit(const Dimension* d, std::string s) : Unit(d), name(std::move(s)) {}

std::vector<UnitComponent> NamedUnit::toComponents() const {
    std::vector<UnitComponent> v;
    v.emplace_back(this,1);
    return v;
}

std::string NamedUnit::toString() const {
    return name;
}
