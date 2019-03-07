//
// Created by Joel Courtney on 2019-03-05.
//

#ifndef C_COMPOSITEDIMENSION_H
#define C_COMPOSITEDIMENSION_H

#include "BaseDimension.h"

class CompositeDimension : public Dimension {
    std::vector<DimensionalComponent> components;

public:
    explicit CompositeDimension(std::vector<DimensionalComponent>);
    ~CompositeDimension() override = default;

    std::string toString() const override;
    std::vector<DimensionalComponent> toComponents() const override;
    std::vector<DimensionalComponent> toBaseComponents() const override;

    bool isBase() const override;
    bool isNamed() const override;
};

#endif //C_COMPOSITEDIMENSION_H
