lexer grammar Base;

VAL : 'val';

VAR : 'var';

DROP : 'drop';

FN : 'fn';

IF : 'if';

ELSEIF : 'elseif';

ELSE : 'else';

FOR : 'for';

AS : 'as';

AT : 'at';

WHILE : 'while';

LOOP : 'loop';

DIMENSION : 'dimension';

UNITY : 'unity';

STRUCT : 'struct';

CLASS : 'class';

ENUM : 'enum';

PRINT : 'print';

OR : 'or';
NOR : 'nor';
XOR : 'xor';

AND : 'and';
NAND : 'nand';

IS
    : 'is'
    | '==';
ISNT
    : 'isnt'
    | '!=';

MOD : 'mod';

TO : 'to';

NOT : 'not';

SCIENTIFIC_FLOAT_LITERAL
    : FLOAT_LITERAL E SIGN? INT_LITERAL
    | INT_LITERAL E SIGN? INT_LITERAL;

IMAGINARY_SCIENTIFIC_FLOAT_LITERAL
    : FLOAT_LITERAL I E SIGN? INT_LITERAL
    | INT_LITERAL I E SIGN? INT_LITERAL;

fragment SIGN : ('+' | '-');
fragment E : ('E' | 'e');
fragment I : ('I' | 'i');

FLOAT_LITERAL
    : [0-9]+ '.' [0-9]*
    | [0-9]* '.' [0-9]+;

IMAGINARY_FLOAT_LITERAL : FLOAT_LITERAL I;

INT_LITERAL : [0-9]+;

IMAGINARY_INT_LITERAL : INT_LITERAL I;

STRING_LITERAL
    : '"' .*? '"'
    | '\'' .*? '\'';

BOOL_LITERAL
    : 'true'
    | 'false';

NULL_LITERAL : 'null';

VOID_LITERAL : 'void';

NAME : [_a-zA-Z][_a-zA-Z0-9]*;

EQUAL : '=';

NEWLINE : (INLINE_COMMENT? '\r'? '\n' | INLINE_COMMENT? '\r')+;
SEMICOLON : ';'+;

COLON : ':';

COMMA : ',';

OPAREN : '(';
CPAREN : ')';

OBRACKET : '[';
CBRACKET : ']';

OBRACE : '{';
CBRACE : '}';

UNDERSCORE : '_';

DASH : '-';
TILDE : '~';

PLUS : '+';

OHAIRPIN : '<';
CHAIRPIN : '>';
OHAIRPINEQUAL : '<=';
CHAIRPINEQUAL : '>=';

BANG : '!';

BACKTICK : '`'; // escape greek

AT_SYMBOL : '@'; // Strip units

HASH : '#'; // size operator

DOLLAR : '$'; // shape operator

PERCENT : '%';

AMPERSAND : '&';

DOT : '.';

STAR : '*';
MATSTAR : '(*)';

SLASH : '/';
MATSLASH : '(/)';

CARROT : '^';
MATCARROT : '(^)';

fragment INLINE_COMMENT : '//' ~[\n\r]*;
BLOCK_COMMENT : '/*' .*? '*/' -> skip;

WHITESPACE : ' ' -> skip;