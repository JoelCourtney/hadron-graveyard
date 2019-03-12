//
// Created by Joel Courtney on 2019-03-03.
//

#ifndef C_OPERATION_H
#define C_OPERATION_H

#include "Values/IntValue.h"

class Operation {
public:
    virtual std::string toString() const = 0;
};

#endif //C_OPERATION_H
