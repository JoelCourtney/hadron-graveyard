//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_LEXER_H
#define C_LEXER_H

#include "Syntax/Lexeme.h"
#include <string>

class Lexer {
    bool complete;
    Lexeme previous;

    Lexeme nextLexeme(std::string&);
    std::string extractWord(std::string&);

    bool isWordChar(char);
    bool isNumber(char);

public:
    std::vector<Lexeme> lex(std::string);
};

#endif //C_LEXER_H
