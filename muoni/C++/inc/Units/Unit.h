//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_UNIT_H
#define C_UNIT_H

#include <string>

class Dimension;

class Unit {
    Dimension* dimension;

public:
    explicit Unit(Dimension*);
    virtual ~Unit() = default;

    virtual std::string toString() const = 0;

    virtual Dimension* getDimension() const;
};

#endif //C_UNIT_H
