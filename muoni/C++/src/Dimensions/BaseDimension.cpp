//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/BaseDimension.h"

BaseDimension::BaseDimension(std::string s) : NamedDimension(std::move(s)) {}

std::vector<DimensionalComponent> BaseDimension::toBaseComponents() const {
    return toComponents();
}

bool BaseDimension::isBase() const {
    return true;
}

bool BaseDimension::isNamed() const {
    return true;
}
