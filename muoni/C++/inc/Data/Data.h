//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_VALUE_H
#define C_VALUE_H

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
    
    virtual std::string toString() const = 0;
    virtual bool toBool() const = 0;
    virtual int toInt() const = 0;
    virtual BigIntBackend toBigInt() const = 0;
    virtual double toFloat() const = 0;
    virtual Eigen::MatrixXi toIntMatrix() const = 0;
    virtual Eigen::MatrixXd toFloatMatrix() const = 0;
    virtual std::complex<int> toComplexInt() const = 0;
    virtual std::complex<double> toComplexFloat() const = 0;
    
    Type getType() const;

    friend std::ostream& operator<<(std::ostream& o, const Data* v);
    friend std::ostream& operator<<(std::ostream& o, const Data& v);
    
    virtual Data* add(Data*) const;
};

#endif //C_VALUE_H
