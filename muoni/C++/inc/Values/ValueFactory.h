//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_VALUEFACTORY_H
#define C_VALUEFACTORY_H

#include "Value.h"
#include "NullValue.h"
#include "BoolValue.h"
#include "FloatValue.h"
#include "StringValue.h"
#include "IntValue.h"
#include "ComplexIntValue.h"
#include "ComplexFloatValue.h"
#include "BigIntValue.h"
#include "IntMatrixValue.h"
#include "FloatMatrixValue.h"

class ValueFactory {
public:
    static NullValue* from();
    static BoolValue* from(bool);
    static StringValue* from(std::string);
    static IntValue* from(int);
    static FloatValue* from(double);
    static BigIntValue* from(bigint);
    static ComplexIntValue* from(int,int);
    static ComplexFloatValue* from(double,double);
    static IntMatrixValue* from(MatrixXi);
    static FloatMatrixValue* from(MatrixXd);
};

#endif //C_VALUEFACTORY_H
