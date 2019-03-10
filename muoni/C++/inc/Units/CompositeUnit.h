//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_COMPOSITEUNIT_H
#define C_COMPOSITEUNIT_H

#include "Unit.h"
#include "UnitComponent.h"
#include <vector>

class CompositeUnit : public Unit {
    std::vector<UnitComponent> components;
    double multiplier;

public:
    explicit CompositeUnit(const Dimension*,std::vector<UnitComponent>,double);
    ~CompositeUnit() override = default;

    std::string toString() const override;

    std::vector<UnitComponent> toComponents() const override;
    std::vector<UnitComponent> toBaseComponents() const override;

    double getMultiplier() const override;
    double getBaseMultiplier() const override;
};

#endif //C_COMPOSITEUNIT_H
