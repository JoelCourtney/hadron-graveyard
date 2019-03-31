//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_VALUE_H
#define C_VALUE_H

#include <string>
#include <iostream>

class Type;

class Value {
public:
    virtual ~Value() = default;
    virtual std::string toString() const = 0;

    virtual Type* getType() const = 0;

    virtual bool isNull() const;

    friend std::ostream& operator<<(std::ostream& o, const Value* v);
    friend std::ostream& operator<<(std::ostream& o, const Value& v);
};

#endif //C_VALUE_H
