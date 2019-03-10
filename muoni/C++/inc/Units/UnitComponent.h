//
// Created by Joel Courtney on 2019-03-05.
//

#ifndef C_UNITCOMPONENT_H
#define C_UNITCOMPONENT_H

#include <string>

class NamedUnit;

struct UnitComponent {
    const NamedUnit* base;
    double exponent;

    explicit UnitComponent(const NamedUnit*,double);

    std::string toString() const;
    bool isUnity() const;

    static UnitComponent multiply(UnitComponent,UnitComponent);
    static bool areEquivalent(UnitComponent,UnitComponent);
};

#endif //C_UNITCOMPONENT_H
