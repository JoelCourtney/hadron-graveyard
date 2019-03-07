//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_DIMENSION_H
#define C_DIMENSION_H

#include <string>
#include <vector>
#include "DimensionalComponent.h"

class BaseDimension;

class Dimension {
public:
    explicit Dimension() = default;
    virtual ~Dimension() = default;

    virtual std::string toString() const = 0;
    virtual std::vector<DimensionalComponent> toComponents() const = 0;
    virtual std::vector<DimensionalComponent> toBaseComponents() const = 0;

    virtual bool isBase() const = 0;
    virtual bool isNamed() const = 0;

    static bool areEquivalent(Dimension*,Dimension*);
    static std::vector<DimensionalComponent> reduce(std::vector<DimensionalComponent>);
};

#endif //C_DIMENSION_H
