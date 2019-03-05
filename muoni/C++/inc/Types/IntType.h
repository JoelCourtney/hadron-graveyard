//
// Created by Joel Courtney on 2019-03-03.
//

#ifndef C_INTTYPE_H
#define C_INTTYPE_H

#include "Type.h"

class IntType : public Type {
public:
    static IntType* getInstance()
    {
        static IntType instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return &instance;
    }

private:
    IntType() = default;

public:
    IntType(IntType const&) = delete;
    void operator=(IntType const&) = delete;

    std::string toString() const override;

    Value* toThis(Value*) const override;

    IntValue* toIntValue(Value*) const override;

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

#endif //C_INTTYPE_H
