grammar RValue;

import Base, Type;

rvalue
    : uop=PLUS r=rvalue # UnaryOperation
    | uop=DASH r=rvalue # UnaryOperation
    | uop=DOLLAR r=rvalue # UnaryOperation
    | uop=HASH r=rvalue # UnaryOperation
    | uop=NOT r=rvalue # UnaryOperation
    | r=rvalue bop=(AT_SYMBOL | AMPERSAND | TO) t=type # ConvertOperation
    | r1=rvalue bop=(CARROT | DOTCARROT) r2=rvalue # BinaryOperation
    | r1=rvalue bop=(STAR | SLASH | DOTSTAR | DOTSLASH) r2=rvalue # BinaryOperation
    | r1=rvalue bop=(PLUS | DASH) r2=rvalue # BinaryOperation
    | r1=rvalue bop=(OHAIRPIN | OHAIRPINEQUAL | CHAIRPIN | CHAIRPINEQUAL) r2=rvalue # BinaryOperation
    | r1=rvalue bop=(IS | ISNT) r2=rvalue # BinaryOperation
    | r1=rvalue bop=(AND | NAND) r2=rvalue # BinaryOperation
    | r1=rvalue bop=XOR r2=rvalue # BinaryOperation
    | r1=rvalue bop=(OR | NOR) r2=rvalue # BinaryOperation
    | a=atom # AtomRValue;

atom
    : literal # LiteralAtom
    | NAME # NameAtom
    | invoke # InvokeAtom
    | matrix # MatrixAtom
    | list # ListAtom
    | scope # ScopeAtom;

literal
    : SCIENTIFIC_FLOAT_LITERAL # FloatLiteral
    | IMAGINARY_SCIENTIFIC_FLOAT_LITERAL # ImaginaryFloatLiteral
    | FLOAT_LITERAL # FloatLiteral
    | IMAGINARY_FLOAT_LITERAL # ImaginaryFloatLiteral
    | INT_LITERAL # IntLiteral
    | IMAGINARY_INT_LITERAL # ImaginaryIntLiteral
    | STRING_LITERAL # StringLiteral
    | BOOL_LITERAL # BoolLiteral
    | NULL_LITERAL # NullLiteral;

invoke
    : NAME (list | matrix)
    | invoke (list | matrix)
    | list list
    | matrix (list | matrix);

matrix : OPAREN (rvalue ((COMMA | NEWLINE | SEMICOLON) rvalue)*)? CPAREN;

list : OBRACKET (rvalue (COMMA rvalue)*)? CBRACKET;

scope : OBRACE (NEWLINE | SEMICOLON)? (control ((NEWLINE | SEMICOLON) control)*)? (NEWLINE | SEMICOLON)? CBRACE;

rArgList : OPAREN (rvalue (COMMA rvalue)*)? CPAREN;