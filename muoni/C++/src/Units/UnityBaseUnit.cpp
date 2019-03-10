//
// Created by Joel Courtney on 2019-03-09.
//

#include "Units/UnityBaseUnit.h"

UnityBaseUnit::UnityBaseUnit(const UnityDimension* d, std::string s) : BaseUnit(d,std::move(s)) {}

std::vector<UnitComponent> UnityBaseUnit::toMultiplicationComponents() const {
    std::vector<UnitComponent> v;
    return v;
}
