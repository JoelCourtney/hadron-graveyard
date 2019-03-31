grammar LValue;

import Base, RValue;

lvalue
    : NAME # NameLValue
    | OPAREN NEWLINE? (lvalue ((COMMA | NEWLINE | SEMICOLON) lvalue)* NEWLINE?)? CPAREN # MatrixDecompositionLValue
    | OBRACKET NEWLINE? (lvalue (COMMA lvalue)*)? CBRACKET # ListDecompositionLValue
    | NAME lArgList # SubsetLValue
    | UNDERSCORE # DiscardLValue;

lArgList : OPAREN (lvalue (COMMA lvalue)*)? CPAREN;