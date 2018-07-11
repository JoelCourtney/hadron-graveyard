#ifndef PARSER_H
#define PARSER_H

typedef enum {
	Seq,
	ClassDecl,
	FunctionDecl,
	QuantityDecl,
	UnitDecl,
	For,
	While,
	DoWhile,
	Switch,
	If,
	Assignment,
	Equation,
	UnaryOp,
	BinaryOp,
	TernayOp,
	VarDecl
} ExprType;

typedef enum {
	Add,
	Sub,
	Mult,
	ElMult,
	Div,
	Exp,
	ElExp,
	And,
	Or,
	Xor,
	BAnd,
	BOr,
	BXor,
	Eq,
	Gt,
	Lt,
	Geq,
	Leq,
	Neq
} BinaryOps;

typedef enum {
	Neg,
	Not,
	Norm,
} UnaryOps;

typedef enum {
	ChainIneq,
} TernaryOps;

typedef enum {
	int numExprs;
	void** exprs;
	ExprType* exprTypes;
} Seq;

typedef struct {
	BinaryOps op;
	void* e1;
	ExprType e1Type;
	void* e2;
	ExprType e2Type;
} Binary;

typedef struct {
	UnaryOps op;
	void* e1;
	ExprType e1Type;
} Unary;

typedef struct {
	TernaryOps op;
	void* e1;
	ExprType e1Type;
	void* e2;
	ExprType e2Type;
	void* e3;
	ExprType e3Type;
} Ternary;

int parseLine(char*);


#endif
