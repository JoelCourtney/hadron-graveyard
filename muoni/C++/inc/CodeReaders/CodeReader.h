//
// Created by Joel Courtney on 2019-03-09.
//

#ifndef C_LOADER_H
#define C_LOADER_H

#include <string>

class CodeReader {
protected:
    std::string line;

public:
    virtual ~CodeReader() = default;

    virtual bool readLine() = 0;
    virtual std::string getLine() const;
};

#endif //C_LOADER_H
