//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/DerivedDimension.h"

DerivedDimension::DerivedDimension(std::string s, std::vector<DimensionalComponent> c)
    : name(std::move(s)), components(std::move(reduce(std::move(c)))) {
}

std::string DerivedDimension::toString() const {
    return name;
}

std::vector<DimensionalComponent> DerivedDimension::toComponents() const {
    std::vector<DimensionalComponent> v;
    v.emplace_back(this,1.);
    return v;
}

std::vector<DimensionalComponent> DerivedDimension::toBaseComponents() const {
    std::vector<DimensionalComponent> v;
    for (DimensionalComponent c : components) {
        const Dimension* d = c.base;
        std::vector<DimensionalComponent> subComponents = d->toComponents();
        for (DimensionalComponent& c2 : subComponents) {
            c2.multiplicity *= c.multiplicity;
        }
        std::copy (subComponents.begin(), subComponents.end(), std::back_inserter(v));
    }
    return reduce(v);
}

bool DerivedDimension::isBase() const {
    return false;
}

bool DerivedDimension::isNamed() const {
    return true;
}
