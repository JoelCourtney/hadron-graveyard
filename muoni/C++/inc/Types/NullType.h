//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_NULLTYPE_H
#define C_NULLTYPE_H

#include "Type.h"

class NullType : public Type {
public:
    static NullType* getInstance()
    {
        static NullType instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return &instance;
    }

private:
    NullType() = default;

public:
    NullType(NullType const&) = delete;
    void operator=(NullType const&) = delete;

    std::string toString() const override;

    Value* toThis(Value*) const override;

    NullValue* toNullValue(Value*) const override;

    void toNull(Value*) const override;
    bool toBool(Value*) const override;
    int toInt(Value*) const override;
    double toFloat(Value*) const override;
    BigInt toBigInt(Value*) const override;
    MatrixXi toIntMatrix(Value*) const override;
    MatrixXd toFloatMatrix(Value*) const override;
    std::complex<int> toComplexInt(Value*) const override;
    std::complex<double> toComplexFloat(Value*) const override;
};

#endif //C_NULLTYPE_H
