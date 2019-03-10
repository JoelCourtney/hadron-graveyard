//
// Created by Joel Courtney on 2019-03-05.
//

#ifndef C_DERIVEDDIMENSION_H
#define C_DERIVEDDIMENSION_H

#include "NamedDimension.h"

class DerivedDimension : public NamedDimension {
    std::vector<DimensionalComponent> components;

public:
    explicit DerivedDimension(std::string,std::vector<DimensionalComponent>);
    ~DerivedDimension() override = default;

    std::vector<DimensionalComponent> toBaseComponents() const override;

    bool isBase() const override;
    bool isNamed() const override;
};

#endif //C_DERIVEDDIMENSION_H
