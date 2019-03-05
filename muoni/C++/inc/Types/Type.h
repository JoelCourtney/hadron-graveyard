//
// Created by Joel Courtney on 2019-03-03.
//

#ifndef C_TYPE_H
#define C_TYPE_H

#include <Eigen/Dense>
#include <complex>
#include "Values/ValueFactory.h"

using namespace Eigen;

class Type {
public:
    virtual std::string toString() const = 0;

    virtual Value* toThis(Value*) const = 0;

    virtual void toNull(Value*) const = 0;
    virtual std::string toString(Value*) const;
    virtual bool toBool(Value*) const = 0;
    virtual int toInt(Value*) const = 0;
    virtual double toFloat(Value*) const = 0;
    virtual BigInt toBigInt(Value*) const = 0;
    virtual MatrixXi toIntMatrix(Value*) const = 0;
    virtual MatrixXd toFloatMatrix(Value*) const = 0;
    virtual std::complex<int> toComplexInt(Value*) const = 0;
    virtual std::complex<double> toComplexFloat(Value*) const = 0;

    virtual NullValue* toNullValue(Value*) const;
    virtual StringValue* toStringValue(Value*) const;
    virtual BoolValue* toBoolValue(Value*) const;
    virtual IntValue* toIntValue(Value*) const;
    virtual FloatValue* toFloatValue(Value*) const;
    virtual BigIntValue* toBigIntValue(Value*) const;
    virtual IntMatrixValue* toIntMatrixValue(Value*) const;
    virtual FloatMatrixValue* toFloatMatrixValue(Value*) const;
    virtual ComplexIntValue* toComplexIntValue(Value*) const;
    virtual ComplexFloatValue* toComplexFloatValue(Value*) const;

protected:
    void unwrap(NullValue*) const;
    std::string unwrap(StringValue*) const;
    bool unwrap(BoolValue*) const;
    int unwrap(IntValue*) const;
    double unwrap(FloatValue*) const;
    BigInt unwrap(BigIntValue*) const;
    MatrixXi unwrap(IntMatrixValue*) const;
    MatrixXd unwrap(FloatMatrixValue*) const;
    std::complex<int> unwrap(ComplexIntValue*) const;
    std::complex<double> unwrap(ComplexFloatValue*) const;
};

#endif //C_TYPE_H
