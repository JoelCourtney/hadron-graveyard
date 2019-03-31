//
// Created by Joel Courtney on 2019-03-14.
//

#include "Environment/ExplicitScope.h"

ExplicitScope::ExplicitScope(Scope* s) : deferTo(s) {}

Scope* ExplicitScope::defer() const {
    return deferTo;
}
