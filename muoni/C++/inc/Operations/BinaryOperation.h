//
// Created by Joel Courtney on 2019-03-03.
//

#ifndef C_BINARYOPERATION_H
#define C_BINARYOPERATION_H

#include "Operation.h"
#include "Values/Value.h"

class BinaryOperation : Operation {
public:
    virtual Value* operate(Value*,Value*) const = 0;
};

#endif //C_BINARYOPERATION_H
