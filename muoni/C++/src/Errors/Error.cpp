//
// Created by joel on 8/4/19.
//

#include "Errors/Error.h"
#include <iostream>

const char* Error::what() const noexcept {
    return "I am a big fancy error";
}
