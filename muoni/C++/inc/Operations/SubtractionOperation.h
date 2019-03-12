//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_SUBTRACTIONOPERATION_H
#define C_SUBTRACTIONOPERATION_H

#include "BinaryOperation.h"

class SubtractionOperation : public BinaryOperation {
public:
    static Operation* getInstance();

    std::string toString() const override;
};

#endif //C_SUBTRACTIONOPERATION_H
