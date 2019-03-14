grammar Structure;

import Base, RValue, LValue;

control
    : statement # StatementControl
    | IF rvalue (NEWLINE | SEMICOLON) statement ((NEWLINE | SEMICOLON) ELSEIF rvalue (NEWLINE | SEMICOLON) statement)* ((NEWLINE | SEMICOLON) ELSE statement)? # IfSeries
    | LOOP (NEWLINE | SEMICOLON) statement # Loop
    | WHILE rvalue (NEWLINE | SEMICOLON) statement # WhileLoop
    | FOR rvalue (NEWLINE | SEMICOLON) statement # ForLoop
    | FOR rvalue AS lvalue (NEWLINE | SEMICOLON) statement # ForAsLoop
    | FOR rvalue AT lvalue (NEWLINE | SEMICOLON) statement # ForAtLoop
    | FOR rvalue AS as=lvalue AT at=lvalue (NEWLINE | SEMICOLON) statement # ForAsAtLoop
    | FOR rvalue AT at=lvalue AS as=lvalue (NEWLINE | SEMICOLON) statement # ForAsAtLoop;

statement
    : rvalue # RValueStatement
    | lvalue EQUAL rvalue # Assign
    | (VAL | VAR) lvalue # Declare
    | (VAL | VAR) lvalue EQUAL rvalue # DeclareAssign
    | DROP lvalue # DropName
    | FN NAME lArgList EQUAL CHAIRPIN rvalue # FunctionDeclare
    | PRINT rvalue # Print
    | OHAIRPIN (DASH | TILDE | EQUAL)+ (rvalue | VOID_LITERAL)? # BreakSnake
    | UNITY? DIMENSION NAME? OBRACKET (NEWLINE | SEMICOLON)? unitDeclaration ((NEWLINE | SEMICOLON) unitDeclaration)* (NEWLINE | SEMICOLON)? CBRACKET # DeclareDimension;

unitDeclaration
    : NAME
    | NAME EQUAL rvalue;
