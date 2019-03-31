//
// Created by Joel Courtney on 2019-03-16.
//

#include "Environment/FileScope.h"

Scope* FileScope::defer() const {
    std::cout << "Cannot defer." << std::endl;
    exit(10);
}
