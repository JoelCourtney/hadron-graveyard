//
// Created by Joel Courtney on 2019-03-10.
//

#include <iostream>
#include "Syntax/Symbol.h"
#include <unordered_map>

std::string SymbolHelper::toString(Symbol s) {
    static std::unordered_map<Symbol, std::string> map = {
            {Symbol::Val,                     "Val"},
            {Symbol::Var,                     "Var"},
            {Symbol::Drop,                    "Drop"},
            {Symbol::Fn,                      "Fn"},
            {Symbol::Fn,                      "Fn"},
            {Symbol::If,                      "If"},
            {Symbol::ElseIf,                  "ElseIf"},
            {Symbol::Else,                    "Else"},
            {Symbol::For,                     "For"},
            {Symbol::While,                   "While"},
            {Symbol::Loop,                    "Loop"},
            {Symbol::As,                      "As"},
            {Symbol::At,                      "At"},
            {Symbol::Dimension,               "Dimension"},
            {Symbol::Unity,                   "Unity"},
            {Symbol::Print,                   "Print"},
            {Symbol::BreakSeries,             "BreakSeries"},
            {Symbol::UnaryOperation,          "UnaryOperation"},
            {Symbol::BinaryOperation,         "BinaryOperation"},
            {Symbol::IntegerLiteral,          "IntegerLiteral"},
            {Symbol::FloatLiteral,            "FloatLiteral"},
            {Symbol::ImaginaryIntegerLiteral, "ImaginaryIntegerLiteral"},
            {Symbol::ImaginaryFloatLiteral,   "ImaginaryFloatLiteral"},
            {Symbol::BoolLiteral,             "BoolLiteral"},
            {Symbol::StringLiteral,           "StringLiteral"},
            {Symbol::NullLiteral,             "NullLiteral"},
            {Symbol::Assign,                  "Assign"},
            {Symbol::AssignOperator,          "AssignOperator"},
            {Symbol::Struct,                  "Struct"},
            {Symbol::Class,                   "Class"},
            {Symbol::Enum,                    "Enum"},
            {Symbol::OpenParen,               "OpenParen"},
            {Symbol::CloseParen,              "CloseParen"},
            {Symbol::OpenBracket,             "OpenBracket"},
            {Symbol::CloseBracket,            "CloseBracket"},
            {Symbol::OpenBrace,               "OpenBrace"},
            {Symbol::CloseBrace,              "CloseBrace"},
            {Symbol::Pipe,                    "Pipe"},
            {Symbol::Semicolon,               "Semicolon"},
            {Symbol::Comma,                   "Comma"},
            {Symbol::Newline,                 "Newline"},
            {Symbol::Name,                    "Name"}
    };
    return map.at(s);
}

bool SymbolHelper::isEndOfValue(Symbol s) {
    switch (s) {
        case Symbol::NullLiteral:
        case Symbol::IntegerLiteral:
        case Symbol::FloatLiteral:
        case Symbol::ImaginaryIntegerLiteral:
        case Symbol::ImaginaryFloatLiteral:
        case Symbol::BoolLiteral:
        case Symbol::StringLiteral:
        case Symbol::Name:
        case Symbol::CloseParen:
        case Symbol::CloseBracket:
        case Symbol::CloseBrace:
            return true;
        default:
            return false;
    }
}
