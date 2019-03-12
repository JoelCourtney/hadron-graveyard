//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_KEYWORDS_H
#define C_KEYWORDS_H

#include <unordered_map>

static const std::unordered_map<std::string,Symbol> keywords = {
        {"val",       Symbol::Val},
        {"var",       Symbol::Var},
        {"drop",      Symbol::Drop},
        {"fn",        Symbol::Fn},
        {"if",        Symbol::If},
        {"elseif",    Symbol::ElseIf},
        {"else",      Symbol::Else},
        {"while",     Symbol::While},
        {"for",       Symbol::For},
        {"loop",      Symbol::Loop},
        {"as",        Symbol::As},
        {"at",        Symbol::At},
        {"dimension", Symbol::Dimension},
        {"unity",     Symbol::Unity},
        {"print",     Symbol::Print},
        {"struct",    Symbol::Struct},
        {"class",     Symbol::Class},
        {"enum",      Symbol::Enum}
};

#endif //C_KEYWORDS_H
