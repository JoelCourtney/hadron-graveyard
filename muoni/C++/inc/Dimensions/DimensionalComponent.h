//
// Created by Joel Courtney on 2019-03-05.
//

#ifndef C_DIMENSIONALCOMPONENT_H
#define C_DIMENSIONALCOMPONENT_H

#include <string>

class Dimension;

struct DimensionalComponent {
    const Dimension* base;
    double multiplicity;

    DimensionalComponent(const Dimension*,double);

    std::string toString() const;
    bool isOne() const;

    static DimensionalComponent multiply(DimensionalComponent,DimensionalComponent);
    static bool areEquivalent(DimensionalComponent,DimensionalComponent);
};

#endif //C_DIMENSIONALCOMPONENT_H
