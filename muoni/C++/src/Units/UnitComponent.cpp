//
// Created by Joel Courtney on 2019-03-06.
//

#include "Units/UnitComponent.h"
#include <math.h>
#include "Units/NamedUnit.h"

UnitComponent::UnitComponent(const NamedUnit* b, double e) : base(b), exponent(e) {}

std::string UnitComponent::toString() const {
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

bool UnitComponent::isUnity() const {
    return exponent == 0.;
}

UnitComponent UnitComponent::multiply(UnitComponent c1, UnitComponent c2) {
    if (c1.base == c2.base) {
        return UnitComponent(c1.base, c1.exponent+c2.exponent);
    } else {
        throw -1;
    }
}

bool UnitComponent::areEquivalent(UnitComponent a, UnitComponent b) {
    return a.base == b.base && a.exponent == b.exponent;
}
