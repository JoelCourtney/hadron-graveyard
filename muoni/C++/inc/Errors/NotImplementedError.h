//
// Created by joel on 8/5/19.
//

#ifndef C___NOTIMPLEMENTEDERROR_H
#define C___NOTIMPLEMENTEDERROR_H

#include "Error.h"

class NotImplementedError : public Error {
public:
    const char* what() const noexcept override;
};

#endif //C___NOTIMPLEMENTEDERROR_H
