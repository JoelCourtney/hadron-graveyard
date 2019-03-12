//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_SYMBOL_H
#define C_SYMBOL_H

#include <string>

enum class Symbol {
    Val, Var, Drop,
    Fn,
    If, ElseIf, Else,
    For, While, Loop,
    As, At,
    Dimension, Unity,
    Print,
    BreakSeries,
    UnaryOperation, BinaryOperation,
    IntegerLiteral, FloatLiteral, ImaginaryIntegerLiteral, ImaginaryFloatLiteral,
    BoolLiteral, StringLiteral, NullLiteral,
    Assign, AssignOperator,
    Struct, Class, Enum,
    OpenParen, CloseParen,
    OpenBracket, CloseBracket,
    OpenBrace, CloseBrace,
    Pipe,
    Semicolon,
    Comma,
    Newline,
    Name
};

namespace SymbolHelper {
    std::string toString(Symbol);
    bool isEndOfValue(Symbol);
}

#endif //C_SYMBOL_H
