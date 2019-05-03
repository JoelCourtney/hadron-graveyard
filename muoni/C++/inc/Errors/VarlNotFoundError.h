//
// Created by Joel Courtney on 2019-03-31.
//

#ifndef C___VARLNOTFOUNDERROR_H
#define C___VARLNOTFOUNDERROR_H

#include "RuntimeError.h"
#include <string>

class VarlNotFoundError : public RuntimeError {
    std::string name;

public:
    explicit VarlNotFoundError(std::string);
};

#endif //C___VARLNOTFOUNDERROR_H
