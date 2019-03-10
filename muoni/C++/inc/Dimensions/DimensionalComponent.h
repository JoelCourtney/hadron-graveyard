//
// Created by Joel Courtney on 2019-03-05.
//

#ifndef C_DIMENSIONALCOMPONENT_H
#define C_DIMENSIONALCOMPONENT_H

#include <string>

class NamedDimension;

struct DimensionalComponent {
    const NamedDimension* base;
    double exponent;

    DimensionalComponent(const NamedDimension*,double);

    std::string toString() const;
    bool isUnity() const;

    static bool areEquivalent(DimensionalComponent,DimensionalComponent);
};

#endif //C_DIMENSIONALCOMPONENT_H
