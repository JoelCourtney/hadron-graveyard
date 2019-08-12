//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_VALUE_H
#define C_VALUE_H

#include "Data.h"

class Primitive : public Data {
public:
    explicit Primitive(Type);
    ~Primitive() override = default;
    
    virtual bool toBool() const = 0;
    virtual int toInt() const = 0;
    virtual BigIntBackend toBigInt() const = 0;
    virtual double toFloat() const = 0;
    virtual Eigen::MatrixXi toIntMatrix() const = 0;
    virtual Eigen::MatrixXd toFloatMatrix() const = 0;
    virtual std::complex<int> toComplexInt() const = 0;
    virtual std::complex<double> toComplexFloat() const = 0;
    
    bool isPrimitive() const override;
};

#endif //C_VALUE_H
