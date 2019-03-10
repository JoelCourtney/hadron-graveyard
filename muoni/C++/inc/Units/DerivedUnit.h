//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_DERIVEDUNIT_H
#define C_DERIVEDUNIT_H

#include "NamedUnit.h"
#include "UnitComponent.h"
#include <vector>

class DerivedUnit : public NamedUnit {
    std::vector<UnitComponent> components;
    double multiplier;

public:
    explicit DerivedUnit(const Dimension*,std::string,std::vector<UnitComponent>,double);
    ~DerivedUnit() override = default;

    std::vector<UnitComponent> toBaseComponents() const override;

    double getMultiplier() const override;
    double getBaseMultiplier() const override;
};

#endif //C_DERIVEDUNIT_H
