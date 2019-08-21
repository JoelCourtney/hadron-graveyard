//
// Created by Joel Courtney on 2019-03-01.
//

#ifndef C_VALUEFACTORY_H
#define C_VALUEFACTORY_H

#include "Primitive.h"
#include "Null.h"
#include "Bool.h"
#include "Float.h"
#include "String.h"
#include "Int.h"
#include "ComplexInt.h"
#include "ComplexFloat.h"
#include "BigInt.h"
#include "IntMatrix.h"
#include "FloatMatrix.h"
#include "List.h"
#include "Range.h"

class DataFactory {
public:
    static Null* from();
    static Bool* from(bool);
    static String* from(std::string);
    static Int* from(int);
    static Float* from(double);
    static BigInt* from(BigIntBackend);
    static ComplexInt* from(std::complex<int>);
    static ComplexFloat* from(std::complex<double>);
    static IntMatrix* from(Eigen::MatrixXi);
    static FloatMatrix* from(Eigen::MatrixXd);
    static List* from(std::vector<Data*>);
    static Range* from(bool,Data*,Data*,bool);
    static Range* from(bool,Data*,Data*,Data*,bool);
};

#endif //C_VALUEFACTORY_H
