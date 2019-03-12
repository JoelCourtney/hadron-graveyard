//
// Created by Joel Courtney on 2019-03-09.
//

#ifndef C_FILECODEREADER_H
#define C_FILECODEREADER_H

#include "CodeReader.h"
#include <fstream>

class FileCodeReader : public CodeReader {
    std::ifstream file;

public:
    explicit FileCodeReader(std::string);
    ~FileCodeReader() override;

    bool readLine() override;
};

#endif //C_FILECODEREADER_H
