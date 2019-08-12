//
// Created by Joel Courtney on 2019-08-11.
//

#ifndef C___DATA_H
#define C___DATA_H

#include <string>
#include <iostream>
#include "Type.h"
#include <Eigen/Dense>
#include <complex>
#include "BigIntBackend.h"
#include "Errors/InvalidOperationError.h"
#include "Errors/InvalidConversionError.h"
#include "Errors/NotImplementedError.h"

class Data {
protected:
    Type type;

public:
    explicit Data(Type);
    virtual ~Data() = default;

    virtual Data* clone() const = 0;
    
    Type getType() const;
    
    virtual std::string toString() const = 0;
    friend std::ostream& operator<<(std::ostream& o, const Data* v);
    friend std::ostream& operator<<(std::ostream& o, const Data& v);

    virtual Data* add(Data*) = 0;

    virtual bool isPrimitive() const;
    virtual bool isNumeric() const;
};

#endif //C___DATA_H
