//
// Created by Joel Courtney on 2019-03-09.
//

#ifndef C_COMMANDLINECODEREADER_H
#define C_COMMANDLINECODEREADER_H

#include "CodeReader.h"

class CommandLineCodeReader : public CodeReader {
public:
    explicit CommandLineCodeReader(std::string);
    ~CommandLineCodeReader() override = default;

    bool readLine() override;
};

#endif //C_COMMANDLINECODEREADER_H
