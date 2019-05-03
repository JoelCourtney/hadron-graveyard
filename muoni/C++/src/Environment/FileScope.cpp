//
// Created by Joel Courtney on 2019-03-16.
//

#include "Environment/FileScope.h"
#include "Errors/CannotDeferError.h"

Scope* FileScope::defer() const {
    throw CannotDeferError();
}
