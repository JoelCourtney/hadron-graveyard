//
// Created by Joel Courtney on 2019-03-10.
//

#include "Lexing/Lexer.h"
#include "Syntax/Keywords.h"
#include "Operations/SubtractionOperation.h"

Lexeme Lexer::nextLexeme(std::string& s) {
    char first = s.front();
    Lexeme lexeme;
    if (isWordChar(first)) {
        std::string word = extractWord(s);
        if (keywords.count(word)) {
            lexeme.setSymbol(keywords.at(word));
        } else {
            lexeme.setSymbol(Symbol::Name);
            lexeme.setStringLiteral(word);
        }
    } else if (first == '-') {
        if (SymbolHelper::isEndOfValue(previous.getSymbol())) {
            lexeme.setSymbol(Symbol::BinaryOperation);
            lexeme.setOperation(SubtractionOperation::getInstance());
        } else {
            if (s.size() > 1) {
                char next = s.at(10);
                if (isNumber(next) || next == '.') {

                }
            } else {
                lexeme.setSymbol(Symbol::BinaryOperation);
                lexeme.setOperation(SubtractionOperation::getInstance());
            }
        }
    } else {
        std::cout << "Lexeme not found or not implemented: " << s << std::endl;
        exit(1);
    }
    previous = lexeme;
    return lexeme;
}

std::string Lexer::extractWord(std::string& s) {
    size_t i = 1;
    while (i < s.size() && isWordChar(s.at(i))) {
        i++;
    }
    std::string word = s.substr(0,i);
    s.erase(0,i);
    return word;
}

bool Lexer::isWordChar(char c) {
    return isalpha(c) || c == '_' || c == '`';
}

std::vector<Lexeme> Lexer::lex(std::string s) {
    std::vector<Lexeme> vec;
    while (!s.empty()) {
        while (s.front() == ' ') {
            s.erase(0,1);
        }
        vec.push_back(nextLexeme(s));
    }
    return vec;
}

bool Lexer::isNumber(char c) {
    return true;
}
