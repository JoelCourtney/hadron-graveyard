//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_LEXEME_H
#define C_LEXEME_H

#include "Symbol.h"
#include "BreakSnake.h"
#include "Operations/Operation.h"

class Lexeme {
    Symbol symbol;

    union {
        BreakSnake breakSnake;
        Operation* operation;
        int integerLiteral;
        double floatLiteral;
        bool boolLiteral;
        std::string stringLiteral;
    };

public:
    Lexeme();
    Lexeme(const Lexeme&);
    ~Lexeme();

    Lexeme& operator=(const Lexeme&);

    Symbol getSymbol() const;
    void setSymbol(Symbol);

    BreakSnake getBreakSnake() const;
    void setBreakSnake(BreakSnake);

    Operation* getOperation() const;
    void setOperation(Operation*);

    int getIntegerLiteral() const;
    void setIntegerLiteral(int);

    double getFloatLiteral() const;
    void setFloatLiteral(double);

    bool getBoolLiteral() const;
    void setBoolLiteral(bool);

    std::string getStringLiteral() const;
    void setStringLiteral(std::string);

    std::string toString() const;
};

#endif //C_LEXEME_H
