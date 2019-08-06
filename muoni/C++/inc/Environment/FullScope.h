//
// Created by Joel Courtney on 2019-03-16.
//

#ifndef C_FULLSCOPE_H
#define C_FULLSCOPE_H

#include "Scope.h"

class FullScope : public Scope {
    std::unordered_map<std::string,Data*> varls;
    std::unordered_map<std::string,bool> mutability;
    std::unordered_map<std::string,Dimension*> dimensions;
    std::unordered_map<std::string,Unit*> units;

public:
    FullScope() = default;
    ~FullScope() override;

    Data* getVarl(const std::string&) const override;
    bool containsVarl(const std::string&) const override;
    bool assignVarl(const std::string&,Data*) override;
    bool declareVarl(const std::string&,bool) override;

    Scope* defer() const override = 0;
};

#endif //C_FULLSCOPE_H
