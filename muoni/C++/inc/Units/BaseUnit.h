//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_BASEUNIT_H
#define C_BASEUNIT_H

#include "NamedUnit.h"

class BaseUnit : public NamedUnit {
public:
    explicit BaseUnit(const Dimension*, std::string);
    ~BaseUnit() override = default;

    double getMultiplier() const override;
    double getBaseMultiplier() const override;

    std::vector<UnitComponent> toBaseComponents() const override;
};

#endif //C_BASEUNIT_H
