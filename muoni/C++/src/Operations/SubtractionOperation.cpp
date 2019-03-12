//
// Created by Joel Courtney on 2019-03-10.
//

#include "Operations/SubtractionOperation.h"

Operation* SubtractionOperation::getInstance() {
    static SubtractionOperation instance;
    return &instance;
}

std::string SubtractionOperation::toString() const {
    return "-";
}
