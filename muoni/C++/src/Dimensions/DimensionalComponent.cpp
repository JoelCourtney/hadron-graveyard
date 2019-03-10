//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/DimensionalComponent.h"
#include <cmath>
#include "Dimensions/BaseDimension.h"

DimensionalComponent::DimensionalComponent(const NamedDimension* b, double e) : base(b), exponent(e) {}

std::string DimensionalComponent::toString() const {
    if (fmod(exponent,1.) == 0) {
        if (exponent != 1) {
            return base->toString() + "^" + std::to_string((int)exponent);
        } else {
            return base->toString();
        }
    } else {
        return base->toString() + "^" + std::to_string(exponent);
    }
}

bool DimensionalComponent::isUnity() const {
    return exponent == 0.;
}

bool DimensionalComponent::areEquivalent(DimensionalComponent a, DimensionalComponent b) {
    return a.base == b.base && a.exponent == b.exponent;
}