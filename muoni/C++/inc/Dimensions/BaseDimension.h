//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_BASEDIMENSION_H
#define C_BASEDIMENSION_H

#include "NamedDimension.h"

class BaseDimension : public NamedDimension {
public:
    explicit BaseDimension(std::string);
    virtual ~BaseDimension() override = default;

    std::vector<DimensionalComponent> toBaseComponents() const override;

    bool isBase() const override;
    bool isNamed() const override;
};

#endif //C_BASEDIMENSION_H
