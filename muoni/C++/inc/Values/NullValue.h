//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_NULLVALUE_H
#define C_NULLVALUE_H

#include "Value.h"

class NullValue : public Value {
public:
    NullValue();
    ~NullValue() override = default;

    std::string toString() const override;
    bool isNull() const override;

    Type* getType() const override;
};

#endif //C_NULLVALUE_H
