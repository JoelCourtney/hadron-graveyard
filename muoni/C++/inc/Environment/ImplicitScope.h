//
// Created by Joel Courtney on 2019-03-14.
//

#ifndef C_IMPLICITSCOPE_H
#define C_IMPLICITSCOPE_H

#include "Scope.h"

class ImplicitScope : public Scope {
    std::unordered_map<std::string,Data*> vars;
    
    Scope* deferTo;
    
    bool locked = false;
    
public:
    explicit ImplicitScope(Scope*);
    ~ImplicitScope() override;

    Scope* defer() const override;

    Data* getVarl(const std::string&) const override;
    bool assignVarl(const std::string&, Data*) override;
    bool containsVarl(const std::string&) const override;
    bool declareVarl(const std::string&, bool) override;
    
    bool pushAns(Data*) override;
    Data* getTopAns() override;
    
    void lock();
    ImplicitScope* cloneSetup() const;
};

#endif //C_IMPLICITSCOPE_H
