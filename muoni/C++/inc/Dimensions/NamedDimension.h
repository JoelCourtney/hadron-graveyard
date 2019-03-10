//
// Created by Joel Courtney on 2019-03-06.
//

#ifndef C_NAMEDDIMENSION_H
#define C_NAMEDDIMENSION_H

#include "Dimension.h"

class NamedDimension : public Dimension {
protected:
    std::string name;

public:
    explicit NamedDimension(std::string);
    ~NamedDimension() override = default;

    std::vector<DimensionalComponent> toComponents() const override;

    std::string toString() const override;
};

#endif //C_NAMEDDIMENSION_H
