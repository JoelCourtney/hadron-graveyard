//
// Created by Joel Courtney on 2019-03-10.
//

#include "CodeReaders/CommandLineCodeReader.h"
#include <iostream>

CommandLineCodeReader::CommandLineCodeReader(std::string message) {
    std::cout << message << std::endl;
}

bool CommandLineCodeReader::readLine() {
    std::cout << ">> ";
    line.clear();
    if (!std::cin.eof()) {
        std::getline(std::cin,line);
        return true;
    } else {
        return false;
    }
}
