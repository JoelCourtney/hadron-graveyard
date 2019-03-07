//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_BASEDIMENSION_H
#define C_BASEDIMENSION_H

#include "Dimension.h"

class BaseDimension : public Dimension {
    std::string name;

public:
    explicit BaseDimension(std::string);
    ~BaseDimension() override = default;

    std::string toString() const override;
    std::vector<DimensionalComponent> toComponents() const override;
    std::vector<DimensionalComponent> toBaseComponents() const override;

    bool isBase() const override;
    bool isNamed() const override;
};

#endif //C_BASEDIMENSION_H
