//
// Created by Joel Courtney on 2019-03-06.
//

#ifndef C_NAMEDUNIT_H
#define C_NAMEDUNIT_H

#include "Unit.h"

class NamedUnit : public Unit {
protected:
    std::string name;

public:
    explicit NamedUnit(const Dimension*,std::string);
    virtual ~NamedUnit() = default;

    std::vector<UnitComponent> toComponents() const override;

    std::string toString() const override;
};

#endif //C_NAMEDUNIT_H
