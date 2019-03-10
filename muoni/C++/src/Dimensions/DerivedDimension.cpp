//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/DerivedDimension.h"

DerivedDimension::DerivedDimension(std::string s, std::vector<DimensionalComponent> c)
    : NamedDimension(std::move(s)), components(std::move(c)) {
    reduce(components);
}

std::vector<DimensionalComponent> DerivedDimension::toBaseComponents() const {
    std::vector<DimensionalComponent> v;
    for (DimensionalComponent c : components) {
        const Dimension* d = c.base;
        std::vector<DimensionalComponent> subComponents = d->toBaseComponents();
        for (DimensionalComponent& c2 : subComponents) {
            c2.exponent *= c.exponent;
        }
        std::copy (subComponents.begin(), subComponents.end(), std::back_inserter(v));
    }
    reduce(v);
    return v;
}

bool DerivedDimension::isBase() const {
    return false;
}

bool DerivedDimension::isNamed() const {
    return true;
}
