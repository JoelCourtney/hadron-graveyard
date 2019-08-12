//
// Created by Joel Courtney on 2019-08-08.
//

#ifndef C_LIST_H
#define C_LIST_H

#include "Primitive.h"

class List : public Primitive {
public:
    std::vector<Data*> l;

    explicit List(std::vector<Data*>);
    ~List() override;

    Data* clone() const override;
    
    std::string toString() const override;
    bool toBool() const override;
    int toInt() const override;
    BigIntBackend toBigInt() const override;
    double toFloat() const override;
    Eigen::MatrixXi toIntMatrix() const override;
    Eigen::MatrixXd toFloatMatrix() const override;
    std::complex<int> toComplexInt() const override;
    std::complex<double> toComplexFloat() const override;

    Data* add(Data*) override;
};

#endif //C_LIST_H
