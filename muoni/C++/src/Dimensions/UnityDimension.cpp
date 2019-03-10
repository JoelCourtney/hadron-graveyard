//
// Created by Joel Courtney on 2019-03-09.
//

#include "Dimensions/UnityDimension.h"

UnityDimension::UnityDimension(std::string s) : BaseDimension(s) {}

std::vector<DimensionalComponent> UnityDimension::toMultiplicationComponents() const {
    std::vector<DimensionalComponent> v;
    return v;
}

bool UnityDimension::isUnity() const {
    return true;
}
