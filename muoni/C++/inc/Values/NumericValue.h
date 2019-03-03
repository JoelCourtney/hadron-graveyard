//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_NUMERICVALUE_H
#define C_NUMERICVALUE_H

#include "Value.h"

class NumericValue : public Value {
public:
    virtual ~NumericValue() = default;

    virtual void increment() = 0;
    virtual void decrement() = 0;
    virtual void negate() = 0;
    virtual void conjugate() = 0;
};

#endif //C_NUMERICVALUE_H
