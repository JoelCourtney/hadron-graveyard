//
// Created by Joel Courtney on 2019-03-05.
//

#include "Dimensions/DimensionalComponent.h"
#include <math.h>
#include "Dimensions/BaseDimension.h"

DimensionalComponent::DimensionalComponent(const Dimension* b, double d) : base(b), multiplicity(d) {}

std::string DimensionalComponent::toString() const {
    if (fmod(multiplicity,1.) == 0) {
        if (multiplicity != 1) {
            return base->toString() + "^" + std::to_string((int)multiplicity);
        } else {
            return base->toString();
        }
    } else {
        return base->toString() + "^" + std::to_string(multiplicity);
    }
}

bool DimensionalComponent::isOne() const {
    return multiplicity == 0.;
}

DimensionalComponent DimensionalComponent::multiply(DimensionalComponent c1, DimensionalComponent c2) {
    if (c1.base == c2.base) {
        return DimensionalComponent(c1.base, c1.multiplicity+c2.multiplicity);
    } else {
        throw -1;
    }
}

bool DimensionalComponent::areEquivalent(DimensionalComponent a, DimensionalComponent b) {
    return a.base == b.base && a.multiplicity == b.multiplicity;
}