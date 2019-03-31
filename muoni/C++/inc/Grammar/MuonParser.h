
// Generated from Muon.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  MuonParser : public antlr4::Parser {
public:
  enum {
    VAL = 1, VAR = 2, DROP = 3, FN = 4, IF = 5, ELSEIF = 6, ELSE = 7, FOR = 8, 
    AS = 9, AT = 10, WHILE = 11, LOOP = 12, DIMENSION = 13, UNITY = 14, 
    STRUCT = 15, CLASS = 16, ENUM = 17, PRINT = 18, OR = 19, NOR = 20, XOR = 21, 
    AND = 22, NAND = 23, IS = 24, ISNT = 25, MOD = 26, TO = 27, NOT = 28, 
    SCIENTIFIC_FLOAT_LITERAL = 29, IMAGINARY_SCIENTIFIC_FLOAT_LITERAL = 30, 
    FLOAT_LITERAL = 31, IMAGINARY_FLOAT_LITERAL = 32, INT_LITERAL = 33, 
    IMAGINARY_INT_LITERAL = 34, STRING_LITERAL = 35, BOOL_LITERAL = 36, 
    NULL_LITERAL = 37, VOID_LITERAL = 38, NAME = 39, EQUAL = 40, NEWLINE = 41, 
    SEMICOLON = 42, COLON = 43, COMMA = 44, OPAREN = 45, CPAREN = 46, OBRACKET = 47, 
    CBRACKET = 48, OBRACE = 49, CBRACE = 50, UNDERSCORE = 51, DASH = 52, 
    TILDE = 53, PLUS = 54, OHAIRPIN = 55, CHAIRPIN = 56, OHAIRPINEQUAL = 57, 
    CHAIRPINEQUAL = 58, BANG = 59, BACKTICK = 60, AT_SYMBOL = 61, HASH = 62, 
    DOLLAR = 63, PERCENT = 64, AMPERSAND = 65, DOT = 66, STAR = 67, DOTSTAR = 68, 
    SLASH = 69, DOTSLASH = 70, CARROT = 71, DOTCARROT = 72, BLOCK_COMMENT = 73, 
    WHITESPACE = 74
  };

  enum {
    RuleFile = 0, RuleControl = 1, RuleStatement = 2, RuleUnitDeclaration = 3, 
    RuleRvalue = 4, RuleAtom = 5, RuleLiteral = 6, RuleInvoke = 7, RuleMatrix = 8, 
    RuleList = 9, RuleScope = 10, RuleRArgList = 11, RuleType = 12, RuleUnit = 13, 
    RuleDimension = 14, RuleTypeRValue = 15, RuleTypeMultiplyOperation = 16, 
    RuleTypePowerOperation = 17, RuleTypeAtom = 18, RuleTypeLiteral = 19, 
    RuleLvalue = 20, RuleLArgList = 21
  };

  MuonParser(antlr4::TokenStream *input);
  ~MuonParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class ControlContext;
  class StatementContext;
  class UnitDeclarationContext;
  class RvalueContext;
  class AtomContext;
  class LiteralContext;
  class InvokeContext;
  class MatrixContext;
  class ListContext;
  class ScopeContext;
  class RArgListContext;
  class TypeContext;
  class UnitContext;
  class DimensionContext;
  class TypeRValueContext;
  class TypeMultiplyOperationContext;
  class TypePowerOperationContext;
  class TypeAtomContext;
  class TypeLiteralContext;
  class LvalueContext;
  class LArgListContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ControlContext *> control();
    ControlContext* control(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOF();
    antlr4::tree::TerminalNode* EOF(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  ControlContext : public antlr4::ParserRuleContext {
  public:
    ControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ControlContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ControlContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LoopContext : public ControlContext {
  public:
    LoopContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *LOOP();
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementControlContext : public ControlContext {
  public:
    StatementControlContext(ControlContext *ctx);

    StatementContext *statement();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForAtLoopContext : public ControlContext {
  public:
    ForAtLoopContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    RvalueContext *rvalue();
    antlr4::tree::TerminalNode *AT();
    LvalueContext *lvalue();
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForLoopContext : public ControlContext {
  public:
    ForLoopContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    RvalueContext *rvalue();
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForAsAtLoopContext : public ControlContext {
  public:
    ForAsAtLoopContext(ControlContext *ctx);

    MuonParser::LvalueContext *as = nullptr;
    MuonParser::LvalueContext *at = nullptr;
    antlr4::tree::TerminalNode *FOR();
    RvalueContext *rvalue();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *AT();
    StatementContext *statement();
    std::vector<LvalueContext *> lvalue();
    LvalueContext* lvalue(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfSeriesContext : public ControlContext {
  public:
    IfSeriesContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *IF();
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELSEIF();
    antlr4::tree::TerminalNode* ELSEIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileLoopContext : public ControlContext {
  public:
    WhileLoopContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    RvalueContext *rvalue();
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForAsLoopContext : public ControlContext {
  public:
    ForAsLoopContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    RvalueContext *rvalue();
    antlr4::tree::TerminalNode *AS();
    LvalueContext *lvalue();
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ControlContext* control();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrintContext : public StatementContext {
  public:
    PrintContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PRINT();
    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionDeclareContext : public StatementContext {
  public:
    FunctionDeclareContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *FN();
    antlr4::tree::TerminalNode *NAME();
    LArgListContext *lArgList();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *CHAIRPIN();
    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DropNameContext : public StatementContext {
  public:
    DropNameContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DROP();
    LvalueContext *lvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclareAssignContext : public StatementContext {
  public:
    DeclareAssignContext(StatementContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *EQUAL();
    RvalueContext *rvalue();
    antlr4::tree::TerminalNode *VAL();
    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakSnakeContext : public StatementContext {
  public:
    BreakSnakeContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *OHAIRPIN();
    RvalueContext *rvalue();
    antlr4::tree::TerminalNode *VOID_LITERAL();
    std::vector<antlr4::tree::TerminalNode *> DASH();
    antlr4::tree::TerminalNode* DASH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TILDE();
    antlr4::tree::TerminalNode* TILDE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclareDimensionContext : public StatementContext {
  public:
    DeclareDimensionContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DIMENSION();
    antlr4::tree::TerminalNode *OBRACKET();
    std::vector<UnitDeclarationContext *> unitDeclaration();
    UnitDeclarationContext* unitDeclaration(size_t i);
    antlr4::tree::TerminalNode *CBRACKET();
    antlr4::tree::TerminalNode *UNITY();
    antlr4::tree::TerminalNode *NAME();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RValueStatementContext : public StatementContext {
  public:
    RValueStatementContext(StatementContext *ctx);

    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignContext : public StatementContext {
  public:
    AssignContext(StatementContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *EQUAL();
    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclareContext : public StatementContext {
  public:
    DeclareContext(StatementContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *VAL();
    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  UnitDeclarationContext : public antlr4::ParserRuleContext {
  public:
    UnitDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *EQUAL();
    RvalueContext *rvalue();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnitDeclarationContext* unitDeclaration();

  class  RvalueContext : public antlr4::ParserRuleContext {
  public:
    RvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RvalueContext() : antlr4::ParserRuleContext() { }
    void copyFrom(RvalueContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryOperationContext : public RvalueContext {
  public:
    UnaryOperationContext(RvalueContext *ctx);

    antlr4::Token *uop = nullptr;
    MuonParser::RvalueContext *r = nullptr;
    antlr4::tree::TerminalNode *PLUS();
    RvalueContext *rvalue();
    antlr4::tree::TerminalNode *DASH();
    antlr4::tree::TerminalNode *DOLLAR();
    antlr4::tree::TerminalNode *HASH();
    antlr4::tree::TerminalNode *NOT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryOperationContext : public RvalueContext {
  public:
    BinaryOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *CARROT();
    antlr4::tree::TerminalNode *DOTCARROT();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *DOTSTAR();
    antlr4::tree::TerminalNode *DOTSLASH();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *DASH();
    antlr4::tree::TerminalNode *OHAIRPIN();
    antlr4::tree::TerminalNode *OHAIRPINEQUAL();
    antlr4::tree::TerminalNode *CHAIRPIN();
    antlr4::tree::TerminalNode *CHAIRPINEQUAL();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *ISNT();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *NAND();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *NOR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConvertOperationContext : public RvalueContext {
  public:
    ConvertOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::TypeContext *t = nullptr;
    RvalueContext *rvalue();
    TypeContext *type();
    antlr4::tree::TerminalNode *AT_SYMBOL();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *TO();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomRValueContext : public RvalueContext {
  public:
    AtomRValueContext(RvalueContext *ctx);

    MuonParser::AtomContext *a = nullptr;
    AtomContext *atom();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RvalueContext* rvalue();
  RvalueContext* rvalue(int precedence);
  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() : antlr4::ParserRuleContext() { }
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ScopeAtomContext : public AtomContext {
  public:
    ScopeAtomContext(AtomContext *ctx);

    ScopeContext *scope();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InvokeAtomContext : public AtomContext {
  public:
    InvokeAtomContext(AtomContext *ctx);

    InvokeContext *invoke();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatrixAtomContext : public AtomContext {
  public:
    MatrixAtomContext(AtomContext *ctx);

    MatrixContext *matrix();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListAtomContext : public AtomContext {
  public:
    ListAtomContext(AtomContext *ctx);

    ListContext *list();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NameAtomContext : public AtomContext {
  public:
    NameAtomContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralAtomContext : public AtomContext {
  public:
    LiteralAtomContext(AtomContext *ctx);

    LiteralContext *literal();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringLiteralContext : public LiteralContext {
  public:
    StringLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *STRING_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolLiteralContext : public LiteralContext {
  public:
    BoolLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *BOOL_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatLiteralContext : public LiteralContext {
  public:
    FloatLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *SCIENTIFIC_FLOAT_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImaginaryIntLiteralContext : public LiteralContext {
  public:
    ImaginaryIntLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *IMAGINARY_INT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImaginaryFloatLiteralContext : public LiteralContext {
  public:
    ImaginaryFloatLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *IMAGINARY_SCIENTIFIC_FLOAT_LITERAL();
    antlr4::tree::TerminalNode *IMAGINARY_FLOAT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntLiteralContext : public LiteralContext {
  public:
    IntLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *INT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullLiteralContext : public LiteralContext {
  public:
    NullLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *NULL_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext* literal();

  class  InvokeContext : public antlr4::ParserRuleContext {
  public:
    InvokeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    std::vector<ListContext *> list();
    ListContext* list(size_t i);
    std::vector<MatrixContext *> matrix();
    MatrixContext* matrix(size_t i);
    InvokeContext *invoke();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvokeContext* invoke();
  InvokeContext* invoke(int precedence);
  class  MatrixContext : public antlr4::ParserRuleContext {
  public:
    MatrixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatrixContext* matrix();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBRACKET();
    antlr4::tree::TerminalNode *CBRACKET();
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListContext* list();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    std::vector<ControlContext *> control();
    ControlContext* control(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeContext* scope();

  class  RArgListContext : public antlr4::ParserRuleContext {
  public:
    RArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RArgListContext* rArgList();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    DimensionContext *dimension();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBRACKET();
    TypeRValueContext *typeRValue();
    antlr4::tree::TerminalNode *CBRACKET();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnitContext* unit();

  class  DimensionContext : public antlr4::ParserRuleContext {
  public:
    DimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OBRACKET();
    antlr4::tree::TerminalNode* OBRACKET(size_t i);
    TypeRValueContext *typeRValue();
    std::vector<antlr4::tree::TerminalNode *> CBRACKET();
    antlr4::tree::TerminalNode* CBRACKET(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DimensionContext* dimension();

  class  TypeRValueContext : public antlr4::ParserRuleContext {
  public:
    TypeRValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeMultiplyOperationContext *typeMultiplyOperation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeRValueContext* typeRValue();

  class  TypeMultiplyOperationContext : public antlr4::ParserRuleContext {
  public:
    TypeMultiplyOperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypePowerOperationContext *typePowerOperation();
    TypeMultiplyOperationContext *typeMultiplyOperation();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeMultiplyOperationContext* typeMultiplyOperation();

  class  TypePowerOperationContext : public antlr4::ParserRuleContext {
  public:
    TypePowerOperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeAtomContext *typeAtom();
    antlr4::tree::TerminalNode *CARROT();
    TypePowerOperationContext *typePowerOperation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypePowerOperationContext* typePowerOperation();

  class  TypeAtomContext : public antlr4::ParserRuleContext {
  public:
    TypeAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeLiteralContext *typeLiteral();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *OPAREN();
    TypeRValueContext *typeRValue();
    antlr4::tree::TerminalNode *CPAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAtomContext* typeAtom();

  class  TypeLiteralContext : public antlr4::ParserRuleContext {
  public:
    TypeLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCIENTIFIC_FLOAT_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *INT_LITERAL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeLiteralContext* typeLiteral();

  class  LvalueContext : public antlr4::ParserRuleContext {
  public:
    LvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LvalueContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LvalueContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ListDecompositionLValueContext : public LvalueContext {
  public:
    ListDecompositionLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *OBRACKET();
    antlr4::tree::TerminalNode *CBRACKET();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<LvalueContext *> lvalue();
    LvalueContext* lvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatrixDecompositionLValueContext : public LvalueContext {
  public:
    MatrixDecompositionLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<LvalueContext *> lvalue();
    LvalueContext* lvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DiscardLValueContext : public LvalueContext {
  public:
    DiscardLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *UNDERSCORE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubsetLValueContext : public LvalueContext {
  public:
    SubsetLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    LArgListContext *lArgList();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NameLValueContext : public LvalueContext {
  public:
    NameLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LvalueContext* lvalue();

  class  LArgListContext : public antlr4::ParserRuleContext {
  public:
    LArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    std::vector<LvalueContext *> lvalue();
    LvalueContext* lvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LArgListContext* lArgList();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool rvalueSempred(RvalueContext *_localctx, size_t predicateIndex);
  bool invokeSempred(InvokeContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

