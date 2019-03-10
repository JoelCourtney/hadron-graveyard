//
// Created by Joel Courtney on 2019-03-07.
//

#ifndef C_UNITYDIMENSION_H
#define C_UNITYDIMENSION_H

#include "BaseDimension.h"

class UnityDimension : public BaseDimension {
public:
    explicit UnityDimension(std::string);
    ~UnityDimension() override = default;

    std::vector<DimensionalComponent> toMultiplicationComponents() const override;

    bool isUnity() const override;
};

#endif //C_UNITYDIMENSION_H
