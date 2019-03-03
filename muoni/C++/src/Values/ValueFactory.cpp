//
// Created by Joel Courtney on 2019-03-01.
//

#include "Values/ValueFactory.h"

NullValue* ValueFactory::from() {
    return new NullValue();
}

BoolValue* ValueFactory::from(bool b) {
    return new BoolValue(b);
}

StringValue* ValueFactory::from(std::string s) {
    return new StringValue(s);
}

IntValue* ValueFactory::from(int i) {
    return new IntValue(i);
}

FloatValue* ValueFactory::from(double d) {
    return new FloatValue(d);
}

BigIntValue* ValueFactory::from(bigint b) {
    return new BigIntValue(b);
}

ComplexIntValue* ValueFactory::from(int r, int i) {
    return new ComplexIntValue(r,i);
}

ComplexFloatValue* ValueFactory::from(double r, double i) {
    return new ComplexFloatValue(r,i);
}

IntMatrixValue* ValueFactory::from(MatrixXi m) {
    return new IntMatrixValue(m);
}

FloatMatrixValue* ValueFactory::from(MatrixXd m) {
    return new FloatMatrixValue(m);
}