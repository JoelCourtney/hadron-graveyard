//
// Created by Joel Courtney on 2019-03-04.
//

#include "Dimensions/Dimension.h"
#include <iostream>

bool Dimension::areEquivalent(Dimension* a, Dimension* b) {
    auto v1 = a->toBaseComponents();
    auto v2 = b->toBaseComponents();

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

std::vector<DimensionalComponent> Dimension::reduce(std::vector<DimensionalComponent> v) {
    for (unsigned long i = 0; i < v.size(); i++) {
        DimensionalComponent& c1 = v.at(i);
        unsigned long s = v.size();
        for (unsigned long j = i+1; j < s; j++) {
            DimensionalComponent& c2 = v.at(j);
            if (c1.base == c2.base) {
                c1.multiplicity += c2.multiplicity;
                v.erase(v.begin() + j--);
            }
        }
        if (c1.multiplicity == 0.) {
            v.erase(v.begin() + i--);
        }
    }
    return v;
}
