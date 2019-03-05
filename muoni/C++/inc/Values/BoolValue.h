//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_BOOLVALUE_H
#define C_BOOLVALUE_H

#include "Value.h"

class BoolValue : public Value {
    bool b;

    friend class Type;

public:
    explicit BoolValue(bool);
    ~BoolValue() override = default;

    std::string toString() const override;

    Type* getType() const override;
};

#endif //C_BOOLVALUE_H
