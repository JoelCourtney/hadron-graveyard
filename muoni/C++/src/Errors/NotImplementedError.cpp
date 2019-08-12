//
// Created by joel on 8/5/19.
//

#include "Errors/NotImplementedError.h"

const char* NotImplementedError::what() const noexcept {
    return "Not implemented";
}
