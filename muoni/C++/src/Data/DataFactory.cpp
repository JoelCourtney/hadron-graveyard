//
// Created by Joel Courtney on 2019-03-01.
//

#include "Data/DataFactory.h"

Null* DataFactory::from() {
    return new Null();
}

Bool* DataFactory::from(bool b) {
    return new Bool(b);
}

String* DataFactory::from(std::string s) {
    return new String(s);
}

Int* DataFactory::from(int i) {
    return new Int(i);
}

Float* DataFactory::from(double d) {
    return new Float(d);
}

BigInt* DataFactory::from(BigIntBackend b) {
    return new BigInt(b);
}

ComplexInt* DataFactory::from(std::complex<int> c) {
    return new ComplexInt(c);
}

ComplexFloat* DataFactory::from(std::complex<double> c) {
    return new ComplexFloat(c);
}

IntMatrix* DataFactory::from(Eigen::MatrixXi m) {
    return new IntMatrix(std::move(m));
}

FloatMatrix* DataFactory::from(Eigen::MatrixXd m) {
    return new FloatMatrix(std::move(m));
}

List* DataFactory::from(std::vector<Data*> l) {
    return new List(l);
}