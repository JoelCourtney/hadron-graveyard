//
// Created by Joel Courtney on 2019-03-14.
//

#ifndef C_BASESCOPE_H
#define C_BASESCOPE_H

#include "FullScope.h"

class FileScope : public FullScope {
public:
    explicit FileScope() = default;
    ~FileScope() override = default;

    Scope* defer() const override;
};

#endif //C_BASESCOPE_H
