grammar Type;

import Base;

type
    : unit
    | dimension;

unit : OBRACKET typeRValue CBRACKET;

dimension : OBRACKET OBRACKET typeRValue CBRACKET CBRACKET;

typeRValue : typeMultiplyOperation;

typeMultiplyOperation
    : typePowerOperation
    | typePowerOperation (STAR | SLASH) typeMultiplyOperation;

typePowerOperation
    : typeAtom
    | typeAtom CARROT typePowerOperation;

typeAtom
    : typeLiteral
    | NAME
    | OPAREN typeRValue CPAREN;

typeLiteral
    : SCIENTIFIC_FLOAT_LITERAL
    | FLOAT_LITERAL
    | INT_LITERAL;