//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_SCALARVALUE_H
#define C_SCALARVALUE_H

#include "NumericValue.h"
#include <string>

class ScalarValue : public NumericValue {
public:
    virtual ~ScalarValue() = default;

    virtual ScalarValue* magnitude() = 0;
};

#endif //C_SCALARVALUE_H
