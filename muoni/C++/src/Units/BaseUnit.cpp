//
// Created by Joel Courtney on 2019-03-06.
//

#include "Units/BaseUnit.h"

BaseUnit::BaseUnit(const Dimension* d, std::string s) : NamedUnit(d,std::move(s)) {}

std::vector<UnitComponent> BaseUnit::toBaseComponents() const {
    return toComponents();
}

double BaseUnit::getMultiplier() const {
    return 1;
}

double BaseUnit::getBaseMultiplier() const {
    return 1;
}
