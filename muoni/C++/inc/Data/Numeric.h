//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_NUMERICVALUE_H
#define C_NUMERICVALUE_H

#include "Data.h"

class Numeric : public Data {
public:
    explicit Numeric(Type);
    ~Numeric() override = default;
};

#endif //C_NUMERICVALUE_H
