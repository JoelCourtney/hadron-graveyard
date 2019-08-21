//
// Created by joel on 8/20/19.
//

#ifndef C_RANGE_H
#define C_RANGE_H

#include "List.h"

class Range : public Primitive {
public:
    bool left_inc;
    Data* first;
    Data* step = nullptr;
    Data* last;
    bool right_inc;

    explicit Range(bool,Data*,Data*,bool);
    explicit Range(bool,Data*,Data*,Data*,bool);
    ~Range() override;

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

    Data* negate() override;

    Data* add(Data*) override;
    Data* subtract(Data*) override;
    
    Data* iterate() const;
    std::vector<Data*> toList() const;
};

#endif //C_RANGE_H
