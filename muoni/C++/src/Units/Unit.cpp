//
// Created by Joel Courtney on 2019-03-04.
//

#include "Units/CompositeUnit.h"
#include "Dimensions/Dimension.h"
#include <iostream>

Unit::Unit(const Dimension* d) : dimension(d) {}

std::vector<UnitComponent> Unit::toMultiplicationComponents() const {
    return toComponents();
}

const Dimension* Unit::getDimension() const {
    return dimension;
}

bool Unit::areEquivalent(const Unit* u1, const Unit* u2) {
    return Dimension::areEquivalent(u1->getDimension(), u2->getDimension());
}

void Unit::reduce(std::vector<UnitComponent>& v) {
    for (unsigned long i = 0; i < v.size(); i++) {
        UnitComponent& c1 = v.at(i);
        for (unsigned long j = i+1; j < v.size(); j++) {
            UnitComponent& c2 = v.at(j);
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

Unit* Unit::multiply(const Unit* u1, const Unit* u2) {
    auto v1 = u1->toMultiplicationComponents();
    auto v2 = u2->toMultiplicationComponents();

    auto d1 = u1->getDimension();
    auto d2 = u2->getDimension();
    const Dimension* d = Dimension::multiply(d1,d2);

    std::copy(v2.begin(), v2.end(), std::back_inserter(v1));
    reduce(v1);
    return new CompositeUnit(d,v1,1);
}

Unit* Unit::divide(const Unit* u1, const Unit* u2) {
    auto v1 = u1->toMultiplicationComponents();
    auto v2 = u2->toMultiplicationComponents();

    for (UnitComponent &comp : v2) {
        comp.exponent *= -1;
    }

    auto d1 = u1->getDimension();
    auto d2 = u2->getDimension();
    const Dimension *d = Dimension::divide(d1, d2);

    std::copy(v2.begin(), v2.end(), std::back_inserter(v1));
    reduce(v1);
    return new CompositeUnit(d, v1, 1);
}

double Unit::convert(const Unit* from, const Unit* to) {
    if (areEquivalent(from,to)) {
        double m1 = from->getBaseMultiplier();
        double m2 = to->getBaseMultiplier();
        std::cout << m1 << " " << m2 << std::endl;
        return m1 / m2;
    } else {
        std::cout << "Units of different dimensionality cannot be converted." << std::endl;
        exit(-1);
    }
}
