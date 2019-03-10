//
// Created by Joel Courtney on 2019-03-09.
//

#ifndef C_UNITYBASEUNIT_H
#define C_UNITYBASEUNIT_H

#include "BaseUnit.h"
#include "Dimensions/UnityDimension.h"

class UnityBaseUnit : public BaseUnit {
public:
    explicit UnityBaseUnit(const UnityDimension*, std::string);
    ~UnityBaseUnit() override = default;

    std::vector<UnitComponent> toMultiplicationComponents() const override;
};

#endif //C_UNITYBASEUNIT_H
