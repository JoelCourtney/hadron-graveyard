//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_NUMERICVALUE_H
#define C_NUMERICVALUE_H

#include "Primitive.h"

class Numeric : public Primitive {
public:
    explicit Numeric(Type);
    ~Numeric() override = default;
    
    bool isNumeric() const override;
    
    virtual int getRows() const = 0;
    virtual int getCols() const = 0;
};

#endif //C_NUMERICVALUE_H
