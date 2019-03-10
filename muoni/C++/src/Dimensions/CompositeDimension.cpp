//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/CompositeDimension.h"
#include <iostream>
#include <cmath>

CompositeDimension::CompositeDimension(std::vector<DimensionalComponent> c) : components(std::move(c)) {
    reduce(components);
}

std::string CompositeDimension::toString() const {
    std::string result;
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
            c2.exponent *= c.exponent;
        }
        std::copy(subComponents.begin(), subComponents.end(), std::back_inserter(v));
    }
    reduce(v);
    return v;
}

bool CompositeDimension::isBase() const {
    return false;
}

bool CompositeDimension::isNamed() const {
    return false;
}
