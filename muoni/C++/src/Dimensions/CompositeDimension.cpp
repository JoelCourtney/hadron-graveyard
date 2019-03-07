//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/CompositeDimension.h"
#include <math.h>

CompositeDimension::CompositeDimension(std::vector<DimensionalComponent> c)
    : components(std::move(reduce(std::move(c)))) {}

std::string CompositeDimension::toString() const {
    std::string result = "";
    for (DimensionalComponent component : components) {
        result += component.toString() + " ";
    }
    result.pop_back();
    return result;
}

std::vector<DimensionalComponent> CompositeDimension::toComponents() const {
    return components;
}

std::vector<DimensionalComponent> CompositeDimension::toBaseComponents() const {
    std::vector<DimensionalComponent> v;
    for (DimensionalComponent c : components) {
        const Dimension* d = c.base;
        std::vector<DimensionalComponent> subComponents = d->toBaseComponents();
        for (DimensionalComponent& c2 : subComponents) {
            c2.multiplicity *= c.multiplicity;
        }
        std::copy (subComponents.begin(), subComponents.end(), std::back_inserter(v));
    }
    return reduce(v);
}

bool CompositeDimension::isBase() const {
    return false;
}

bool CompositeDimension::isNamed() const {
    return false;
}
