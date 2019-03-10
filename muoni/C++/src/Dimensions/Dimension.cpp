//
// Created by Joel Courtney on 2019-03-04.
//

#include "Dimensions/Dimension.h"
#include "Dimensions/NamedDimension.h"
#include <iostream>
#include "Dimensions/CompositeDimension.h"

std::vector<DimensionalComponent> Dimension::toMultiplicationComponents() const {
    return toComponents();
}

bool Dimension::areEquivalent(const Dimension* d1, const Dimension* d2) {
    auto v1 = d1->toBaseComponents();
    auto v2 = d2->toBaseComponents();

    for (DimensionalComponent c1 : v1) {
        bool found = false;
        for (DimensionalComponent c2 : v2) {
            if (DimensionalComponent::areEquivalent(c1,c2)) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

void Dimension::reduce(std::vector<DimensionalComponent>& v) {
    for (unsigned long i = 0; i < v.size(); i++) {
        DimensionalComponent& c1 = v.at(i);
        for (unsigned long j = i+1; j < v.size(); j++) {
            DimensionalComponent& c2 = v.at(j);
            if (c1.base == c2.base) {
                c1.exponent += c2.exponent;
                v.erase(v.begin() + j--);
            }
        }
        if (c1.isUnity()) {
            v.erase(v.begin() + i--);
        }
    }
}

bool Dimension::isUnity() const {
    return false;
}

Dimension* Dimension::multiply(const Dimension* d1, const Dimension* d2) {
    auto v1 = d1->toMultiplicationComponents();
    auto v2 = d2->toMultiplicationComponents();
    std::copy(v2.begin(), v2.end(), std::back_inserter(v1));
    reduce(v1);
    return new CompositeDimension(v1);
}

Dimension* Dimension::divide(const Dimension* d1, const Dimension* d2) {
    auto v1 = d1->toMultiplicationComponents();
    auto v2 = d2->toMultiplicationComponents();
    for (DimensionalComponent& comp : v2) {
        comp.exponent *= -1;
    }
    std::copy(v2.begin(), v2.end(), std::back_inserter(v1));
    reduce(v1);
    return new CompositeDimension(v1);
}
