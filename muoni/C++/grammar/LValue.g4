grammar LValue;

import Base, RValue;

lvalue
    : NAME
    | matrixDecomposition
    | listDecomposition
    | subset
    | discard;

matrixDecomposition : OPAREN NEWLINE? (lvalue ((COMMA | NEWLINE | SEMICOLON) lvalue)* NEWLINE?)? CPAREN;

listDecomposition : OBRACKET NEWLINE? (lvalue (COMMA lvalue)*)? CBRACKET;

subset : NAME lArgList;

discard : UNDERSCORE;

lArgList : OPAREN (lvalue (COMMA lvalue)*)? CPAREN;