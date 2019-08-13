grammar RValue;

import Base, Type;

rvalue
    : uop=PLUS r=rvalue # NoOperation
    | uop=DASH r=rvalue # NegateOperation
    | uop=DOLLAR r=rvalue # ShapeOperation
    | uop=HASH r=rvalue # SizeOperation
    | uop=NOT r=rvalue # NotOperation
    | r=rvalue bop=(AT_SYMBOL | AMPERSAND | TO) t=type # ConvertOperation
    | r1=rvalue bop=(CARROT | MATCARROT) r2=rvalue # ExpOperation
    | r1=rvalue bop=(STAR | SLASH | MATSTAR | MATSLASH) r2=rvalue # MultDivOperation
    | r1=rvalue bop=(PLUS | DASH) r2=rvalue # AddSubOperation
    | r1=rvalue bop=(OHAIRPIN | OHAIRPINEQUAL | CHAIRPIN | CHAIRPINEQUAL) r2=rvalue # CompOperation
    | r1=rvalue bop=(IS | ISNT) r2=rvalue # IsOperation
    | r1=rvalue bop=(AND | NAND) r2=rvalue # AndOperation
    | r1=rvalue bop=XOR r2=rvalue # XOrOperation
    | r1=rvalue bop=(OR | NOR) r2=rvalue # OrOperation
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

matrix : OPAREN (matrixRow ((NEWLINE | SEMICOLON) matrixRow)*)? CPAREN;
matrixRow : rvalue (COMMA rvalue)*;

list : OBRACKET (rvalue (COMMA rvalue)*)? CBRACKET;

scope : OBRACE (NEWLINE | SEMICOLON)? (control ((NEWLINE | SEMICOLON) control)*)? (NEWLINE | SEMICOLON)? CBRACE;

rArgList : OPAREN (rvalue (COMMA rvalue)*)? CPAREN;