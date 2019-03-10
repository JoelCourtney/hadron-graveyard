//
// Created by Joel Courtney on 2019-03-04.
//

#ifndef C_BOOLTYPE_H
#define C_BOOLTYPE_H

#include "Type.h"

class BoolType : public Type {
public:
    static BoolType* getInstance()
    {
        static BoolType instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return &instance;
    }

private:
    BoolType() = default;

public:
    BoolType(BoolType const&) = delete;
    void operator=(BoolType const&) = delete;

    std::string toString() const override;

    Value* toThis(Value*) const override;

    BoolValue* toBoolValue(Value*) const override;

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

#endif //C_BOOLTYPE_H
