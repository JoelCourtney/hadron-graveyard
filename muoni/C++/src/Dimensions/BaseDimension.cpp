//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/BaseDimension.h"

BaseDimension::BaseDimension(std::string s) : name(std::move(s)) {}

std::string BaseDimension::toString() const {
    return name;
}

std::vector<DimensionalComponent> BaseDimension::toComponents() const {
    std::vector<DimensionalComponent> v;
    v.emplace_back(this,1.);
    return v;
}

std::vector<DimensionalComponent> BaseDimension::toBaseComponents() const {
    return toComponents();
}

bool BaseDimension::isBase() const {
    return true;
}

bool BaseDimension::isNamed() const {
    return true;
}
