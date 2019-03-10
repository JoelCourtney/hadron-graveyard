//
// Created by Joel Courtney on 2019-03-09.
//

#ifndef C_UNITYUNIT_H
#define C_UNITYUNIT_H

// The most unitish of all units

#include "DerivedUnit.h"
#include "Dimensions/UnityDimension.h"

class UnityDerivedUnit : public DerivedUnit {
public:
    explicit UnityDerivedUnit(const UnityDimension*,std::string,std::vector<UnitComponent>,double);
    ~UnityDerivedUnit() override = default;

    std::vector<UnitComponent> toMultiplicationComponents() const override;
};

#endif //C_UNITYUNIT_H
