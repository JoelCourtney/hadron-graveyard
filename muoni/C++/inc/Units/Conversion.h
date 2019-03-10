//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_CONVERSION_H
#define C_CONVERSION_H

class BaseUnit;

struct Conversion {
    double factor;
    BaseUnit* base;
};

#endif //C_CONVERSION_H
