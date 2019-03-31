//
// Created by Joel Courtney on 2019-03-14.
//

#ifndef C_EXPLICITSCOPE_H
#define C_EXPLICITSCOPE_H

#include "FullScope.h"

class ExplicitScope : public FullScope {
    Scope* deferTo;

public:
    explicit ExplicitScope(Scope*);
    ~ExplicitScope() override = default;

    Scope* defer() const override;
};

#endif //C_EXPLICITSCOPE_H
