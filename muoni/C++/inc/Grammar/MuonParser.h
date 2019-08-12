
// Generated from Muon.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "Data/Data.h"




class  MuonParser : public antlr4::Parser {
public:
Data* cache = nullptr;
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
    DOLLAR = 63, PERCENT = 64, AMPERSAND = 65, DOT = 66, STAR = 67, MATSTAR = 68, 
    SLASH = 69, MATSLASH = 70, CARROT = 71, MATCARROT = 72, BLOCK_COMMENT = 73, 
    WHITESPACE = 74
  };

  enum {
    RuleFile = 0, RuleControl = 1, RuleStatement = 2, RuleUnitDeclaration = 3, 
    RuleRvalue = 4, RuleAtom = 5, RuleLiteral = 6, RuleInvoke = 7, RuleMatrix = 8, 
    RuleMatrixRow = 9, RuleList = 10, RuleScope = 11, RuleRArgList = 12, 
    RuleType = 13, RuleUnit = 14, RuleDimension = 15, RuleTypeRValue = 16, 
    RuleTypeMultiplyOperation = 17, RuleTypePowerOperation = 18, RuleTypeAtom = 19, 
    RuleTypeLiteral = 20, RuleLvalue = 21, RuleLArgList = 22
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
  class MatrixRowContext;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    ControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ControlContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ControlContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LoopContext : public ControlContext {
  public:
Data* cache = nullptr;
    LoopContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *LOOP();
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementControlContext : public ControlContext {
  public:
Data* cache = nullptr;
    StatementControlContext(ControlContext *ctx);

    StatementContext *statement();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForAtLoopContext : public ControlContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrintContext : public StatementContext {
  public:
Data* cache = nullptr;
    PrintContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PRINT();
    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionDeclareContext : public StatementContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
    DropNameContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DROP();
    LvalueContext *lvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclareAssignContext : public StatementContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    RValueStatementContext(StatementContext *ctx);

    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignContext : public StatementContext {
  public:
Data* cache = nullptr;
    AssignContext(StatementContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *EQUAL();
    RvalueContext *rvalue();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclareContext : public StatementContext {
  public:
Data* cache = nullptr;
    DeclareContext(StatementContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *VAL();
    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  UnitDeclarationContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
    RvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RvalueContext() : antlr4::ParserRuleContext() { }
    void copyFrom(RvalueContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OrOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    OrOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *NOR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
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

  class  AddSubOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    AddSubOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *DASH();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    CompOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *OHAIRPIN();
    antlr4::tree::TerminalNode *OHAIRPINEQUAL();
    antlr4::tree::TerminalNode *CHAIRPIN();
    antlr4::tree::TerminalNode *CHAIRPINEQUAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConvertOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
    AtomRValueContext(RvalueContext *ctx);

    MuonParser::AtomContext *a = nullptr;
    AtomContext *atom();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    ExpOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *CARROT();
    antlr4::tree::TerminalNode *MATCARROT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  XOrOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    XOrOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *XOR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IsOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    IsOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *ISNT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    AndOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *NAND();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultDivOperationContext : public RvalueContext {
  public:
Data* cache = nullptr;
    MultDivOperationContext(RvalueContext *ctx);

    MuonParser::RvalueContext *r1 = nullptr;
    antlr4::Token *bop = nullptr;
    MuonParser::RvalueContext *r2 = nullptr;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MATSTAR();
    antlr4::tree::TerminalNode *MATSLASH();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RvalueContext* rvalue();
  RvalueContext* rvalue(int precedence);
  class  AtomContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() : antlr4::ParserRuleContext() { }
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ScopeAtomContext : public AtomContext {
  public:
Data* cache = nullptr;
    ScopeAtomContext(AtomContext *ctx);

    ScopeContext *scope();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InvokeAtomContext : public AtomContext {
  public:
Data* cache = nullptr;
    InvokeAtomContext(AtomContext *ctx);

    InvokeContext *invoke();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatrixAtomContext : public AtomContext {
  public:
Data* cache = nullptr;
    MatrixAtomContext(AtomContext *ctx);

    MatrixContext *matrix();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListAtomContext : public AtomContext {
  public:
Data* cache = nullptr;
    ListAtomContext(AtomContext *ctx);

    ListContext *list();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NameAtomContext : public AtomContext {
  public:
Data* cache = nullptr;
    NameAtomContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralAtomContext : public AtomContext {
  public:
Data* cache = nullptr;
    LiteralAtomContext(AtomContext *ctx);

    LiteralContext *literal();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    StringLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *STRING_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    BoolLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *BOOL_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    FloatLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *SCIENTIFIC_FLOAT_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImaginaryIntLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    ImaginaryIntLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *IMAGINARY_INT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImaginaryFloatLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    ImaginaryFloatLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *IMAGINARY_SCIENTIFIC_FLOAT_LITERAL();
    antlr4::tree::TerminalNode *IMAGINARY_FLOAT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    IntLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *INT_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullLiteralContext : public LiteralContext {
  public:
Data* cache = nullptr;
    NullLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *NULL_LITERAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext* literal();

  class  InvokeContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
    MatrixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    std::vector<MatrixRowContext *> matrixRow();
    MatrixRowContext* matrixRow(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatrixContext* matrix();

  class  MatrixRowContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
    MatrixRowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatrixRowContext* matrixRow();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    DimensionContext *dimension();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  UnitContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    TypeRValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeMultiplyOperationContext *typeMultiplyOperation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeRValueContext* typeRValue();

  class  TypeMultiplyOperationContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    LvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LvalueContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LvalueContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ListDecompositionLValueContext : public LvalueContext {
  public:
Data* cache = nullptr;
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
Data* cache = nullptr;
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
Data* cache = nullptr;
    DiscardLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *UNDERSCORE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubsetLValueContext : public LvalueContext {
  public:
Data* cache = nullptr;
    SubsetLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    LArgListContext *lArgList();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NameLValueContext : public LvalueContext {
  public:
Data* cache = nullptr;
    NameLValueContext(LvalueContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LvalueContext* lvalue();

  class  LArgListContext : public antlr4::ParserRuleContext {
  public:
Data* cache = nullptr;
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

