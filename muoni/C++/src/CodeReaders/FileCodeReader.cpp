//
// Created by Joel Courtney on 2019-03-09.
//

#include "CodeReaders/FileCodeReader.h"
#include <iostream>

FileCodeReader::FileCodeReader(std::string s) : file(s) {
    if (!file.is_open()) {
        std::cout << "Filename " << s << " not found." << std::endl;
        throw -1;
    }
}

FileCodeReader::~FileCodeReader() {
    file.close();
}

bool FileCodeReader::readLine() {
    if (!file.eof()) {
        std::getline(file, line);
        return true;
    } else {
        return false;
    }
}
