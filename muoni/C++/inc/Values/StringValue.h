//
// Created by Joel Courtney on 2019-03-02.
//

#ifndef C_STRINGVALUE_H
#define C_STRINGVALUE_H

#include "Value.h"

class StringValue : public Value {
    std::string s;

    friend class Type;

public:
    explicit StringValue(std::string);
    ~StringValue() override = default;

    std::string toString() const override;

    Type* getType() const override;
};

#endif //C_STRINGVALUE_H
