//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_VALUE_H
#define C_VALUE_H

#include <string>

class Value {
public:
    virtual ~Value() = default;
    virtual std::string toString() const = 0;

    friend std::ostream& operator<<(std::ostream& o, Value const* v) {
        o << v->toString();
        return o;
    }
    friend std::ostream& operator<<(std::ostream& o, Value const& v) {
        o << v.toString();
        return o;
    }

};

#endif //C_VALUE_H
