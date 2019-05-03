//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_ERROR_H
#define C_ERROR_H

#include <exception>
#include <vector>
#include <string>

class Error : public std::exception {
    std::string offendingLine;
    size_t offendingLineNumber;
    std::vector<size_t> offendingCharacters;

public:
    virtual void say() const;
};

#endif //C_ERROR_H
