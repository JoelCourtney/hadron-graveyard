//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_UNIT_H
#define C_UNIT_H

#include <string>
#include <vector>
#include "UnitComponent.h"

class Dimension;

class Unit {
    const Dimension* dimension;

public:
    explicit Unit(const Dimension*);
    virtual ~Unit() = default;

    virtual std::string toString() const = 0;
    virtual const Dimension* getDimension() const;
    virtual double getMultiplier() const = 0;
    virtual double getBaseMultiplier() const = 0;

    virtual std::vector<UnitComponent> toComponents() const = 0;
    virtual std::vector<UnitComponent> toBaseComponents() const = 0;
    virtual std::vector<UnitComponent> toMultiplicationComponents() const;

    static bool areEquivalent(const Unit*, const Unit*);
    static void reduce(std::vector<UnitComponent>&);
    static Unit* multiply(const Unit*, const Unit*);
    static Unit* divide(const Unit*, const Unit*);
    static double convert(const Unit* from, const Unit* to);
};

#endif //C_UNIT_H
