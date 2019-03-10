//
// Created by Joel Courtney on 2019-03-06.
//

#include "Units/DerivedUnit.h"

DerivedUnit::DerivedUnit(const Dimension* d, std::string s, std::vector<UnitComponent> c, double m)
    : NamedUnit(d,std::move(s)), components(std::move(c)), multiplier(m) {
}

std::vector<UnitComponent> DerivedUnit::toBaseComponents() const {
    std::vector<UnitComponent> v;
    for (UnitComponent c : components) {
        const NamedUnit* d = c.base;
        std::vector<UnitComponent> subComponents = d->toBaseComponents();
        for (UnitComponent& c2 : subComponents) {
            c2.exponent *= c.exponent;
        }
        std::copy(subComponents.begin(), subComponents.end(), std::back_inserter(v));
    }
    reduce(v);
    return v;
}

double DerivedUnit::getMultiplier() const {
    return multiplier;
}

double DerivedUnit::getBaseMultiplier() const {
    double m = multiplier;
    for (UnitComponent c : components) {
        m *= c.base->getBaseMultiplier();
    }
    return m;
}
