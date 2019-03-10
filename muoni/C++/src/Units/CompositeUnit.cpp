//
// Created by Joel Courtney on 2019-03-09.
//

#include "Units/CompositeUnit.h"
#include "Units/NamedUnit.h"
#include <iostream>

CompositeUnit::CompositeUnit(const Dimension* d, std::vector<UnitComponent> v, double m)
    : Unit(d), components(std::move(v)), multiplier(m) {
}

std::string CompositeUnit::toString() const {
    std::string result;
    for (UnitComponent component : components) {
        result += component.toString() + " ";
    }
    result.pop_back();
    return result;
}

std::vector<UnitComponent> CompositeUnit::toComponents() const {
    return components;
}

std::vector<UnitComponent> CompositeUnit::toBaseComponents() const {
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

double CompositeUnit::getMultiplier() const {
    return multiplier;
}

double CompositeUnit::getBaseMultiplier() const {
    double m = multiplier;
    std::cout << m << " zxvc " << std::endl;
    for (UnitComponent c : components) {
        m *= c.base->getBaseMultiplier();
    }
    return m;
}
