//
// Created by Joel Courtney on 2019-03-06.
//

#include "Dimensions/NamedDimension.h"

NamedDimension::NamedDimension(std::string s) : name(std::move(s)) {}

std::vector<DimensionalComponent> NamedDimension::toComponents() const {
    std::vector<DimensionalComponent> v;
    v.emplace_back(this,1.);
    return v;
}

std::string NamedDimension::toString() const {
    return name;
}
