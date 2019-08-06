//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_SCALARVALUE_H
#define C_SCALARVALUE_H

#include "Numeric.h"
#include <string>

class Scalar : public Numeric {
public:
    explicit Scalar(Type);
    ~Scalar() override = default;
};

#endif //C_SCALARVALUE_H
