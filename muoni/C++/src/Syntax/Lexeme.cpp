//
// Created by Joel Courtney on 2019-03-10.
//

#include <Syntax/Lexeme.h>

#include "Syntax/Lexeme.h"

Lexeme::Lexeme() : symbol(Symbol::NullLiteral), integerLiteral(0) {}

Lexeme::Lexeme(const Lexeme& l) {
    symbol = l.symbol;
    switch (symbol) {
        case Symbol::BreakSeries:
            breakSnake = l.breakSnake;
            break;
        case Symbol::UnaryOperation:
        case Symbol::BinaryOperation:
            operation = l.operation;
            break;
        case Symbol::IntegerLiteral:
        case Symbol::ImaginaryIntegerLiteral:
            integerLiteral = l.integerLiteral;
            break;
        case Symbol::FloatLiteral:
        case Symbol::ImaginaryFloatLiteral:
            floatLiteral = l.floatLiteral;
            break;
        case Symbol::BoolLiteral:
            boolLiteral = l.boolLiteral;
            break;
        case Symbol::StringLiteral:
        case Symbol::Name:
            stringLiteral = std::string(l.stringLiteral);
            break;
        default:
            integerLiteral = 0;
    }
}

Lexeme::~Lexeme() {
    switch (symbol) {
        case Symbol::BreakSeries:
            breakSnake.~BreakSnake();
            break;
        case Symbol::StringLiteral:
        case Symbol::Name:
            stringLiteral.~basic_string<char>();
            break;
        default:
            break;
    }
}

Lexeme& Lexeme::operator=(const Lexeme& l) {
    symbol = l.symbol;
    switch (symbol) {
        case Symbol::BreakSeries:
            breakSnake = l.breakSnake;
            break;
        case Symbol::UnaryOperation:
        case Symbol::BinaryOperation:
            operation = l.operation;
            break;
        case Symbol::IntegerLiteral:
        case Symbol::ImaginaryIntegerLiteral:
            integerLiteral = l.integerLiteral;
            break;
        case Symbol::FloatLiteral:
        case Symbol::ImaginaryFloatLiteral:
            floatLiteral = l.floatLiteral;
            break;
        case Symbol::BoolLiteral:
            boolLiteral = l.boolLiteral;
            break;
        case Symbol::StringLiteral:
        case Symbol::Name:
            stringLiteral = std::string(l.stringLiteral);
            break;
        default:
            integerLiteral = 0;
    }
    return *this;
}

Symbol Lexeme::getSymbol() const {
    return symbol;
}

void Lexeme::setSymbol(Symbol s) {
    symbol = s;
}

BreakSnake Lexeme::getBreakSnake() const {
    return breakSnake;
}

void Lexeme::setBreakSnake(BreakSnake s) {
    breakSnake = s;
}

Operation* Lexeme::getOperation() const {
    return operation;
}

void Lexeme::setOperation(Operation* o) {
    operation = o;
}

int Lexeme::getIntegerLiteral() const {
    return integerLiteral;
}

void Lexeme::setIntegerLiteral(int i) {
    integerLiteral = i;
}

double Lexeme::getFloatLiteral() const {
    return floatLiteral;
}

void Lexeme::setFloatLiteral(double f) {
    floatLiteral = f;
}

bool Lexeme::getBoolLiteral() const {
    return boolLiteral;
}

void Lexeme::setBoolLiteral(bool b) {
    boolLiteral = b;
}

std::string Lexeme::getStringLiteral() const {
    return stringLiteral;
}

void Lexeme::setStringLiteral(std::string s) {
    stringLiteral = std::move(s);
}

std::string Lexeme::toString() const {
    std::string result = SymbolHelper::toString(symbol);
    switch (symbol) {
        case Symbol::BreakSeries:
            result += ":" + breakSnake.toString();
            break;
        case Symbol::UnaryOperation:
        case Symbol::BinaryOperation:
            result += ":" + operation->toString();
            break;
        case Symbol::IntegerLiteral:
            result += ":" + std::to_string(integerLiteral);
            break;
        case Symbol::ImaginaryIntegerLiteral:
            result += ":" + std::to_string(integerLiteral) + "i";
            break;
        case Symbol::FloatLiteral:
            result += ":" + std::to_string(floatLiteral);
            break;
        case Symbol::ImaginaryFloatLiteral:
            result += ":" + std::to_string(floatLiteral) + "i";
            break;
        case Symbol::BoolLiteral:
            result += ":" + std::to_string(boolLiteral);
            break;
        case Symbol::StringLiteral:
        case Symbol::Name:
            result += ":" + stringLiteral;
            break;
        default:
            break;
    }
    return result;
}
