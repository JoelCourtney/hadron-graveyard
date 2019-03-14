
// Generated from Muon.g4 by ANTLR 4.7.1


#include "MuonVisitor.h"

#include "MuonParser.h"


using namespace antlrcpp;
using namespace antlr4;

MuonParser::MuonParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MuonParser::~MuonParser() {
  delete _interpreter;
}

std::string MuonParser::getGrammarFileName() const {
  return "Muon.g4";
}

const std::vector<std::string>& MuonParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MuonParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

MuonParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MuonParser::ControlContext *> MuonParser::FileContext::control() {
  return getRuleContexts<MuonParser::ControlContext>();
}

MuonParser::ControlContext* MuonParser::FileContext::control(size_t i) {
  return getRuleContext<MuonParser::ControlContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::FileContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::FileContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> MuonParser::FileContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::FileContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}

std::vector<tree::TerminalNode *> MuonParser::FileContext::EOF() {
  return getTokens(MuonParser::EOF);
}

tree::TerminalNode* MuonParser::FileContext::EOF(size_t i) {
  return getToken(MuonParser::EOF, i);
}


size_t MuonParser::FileContext::getRuleIndex() const {
  return MuonParser::RuleFile;
}

antlrcpp::Any MuonParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::FileContext* MuonParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, MuonParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::VAL)
      | (1ULL << MuonParser::VAR)
      | (1ULL << MuonParser::DROP)
      | (1ULL << MuonParser::FN)
      | (1ULL << MuonParser::IF)
      | (1ULL << MuonParser::FOR)
      | (1ULL << MuonParser::WHILE)
      | (1ULL << MuonParser::LOOP)
      | (1ULL << MuonParser::DIMENSION)
      | (1ULL << MuonParser::UNITY)
      | (1ULL << MuonParser::PRINT)
      | (1ULL << MuonParser::NOT)
      | (1ULL << MuonParser::SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_FLOAT_LITERAL)
      | (1ULL << MuonParser::INT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_INT_LITERAL)
      | (1ULL << MuonParser::STRING_LITERAL)
      | (1ULL << MuonParser::BOOL_LITERAL)
      | (1ULL << MuonParser::NULL_LITERAL)
      | (1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::OBRACE)
      | (1ULL << MuonParser::UNDERSCORE)
      | (1ULL << MuonParser::DASH)
      | (1ULL << MuonParser::PLUS)
      | (1ULL << MuonParser::OHAIRPIN)
      | (1ULL << MuonParser::HASH)
      | (1ULL << MuonParser::DOLLAR))) != 0)) {
      setState(52);
      control();
      setState(53);
      _la = _input->LA(1);
      if (!(((((_la - -1) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - -1)) & ((1ULL << (MuonParser::EOF - -1))
        | (1ULL << (MuonParser::NEWLINE - -1))
        | (1ULL << (MuonParser::SEMICOLON - -1)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlContext ------------------------------------------------------------------

MuonParser::ControlContext::ControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MuonParser::ControlContext::getRuleIndex() const {
  return MuonParser::RuleControl;
}

void MuonParser::ControlContext::copyFrom(ControlContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LoopContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::LoopContext::LOOP() {
  return getToken(MuonParser::LOOP, 0);
}

MuonParser::StatementContext* MuonParser::LoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

tree::TerminalNode* MuonParser::LoopContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

tree::TerminalNode* MuonParser::LoopContext::SEMICOLON() {
  return getToken(MuonParser::SEMICOLON, 0);
}

MuonParser::LoopContext::LoopContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementControlContext ------------------------------------------------------------------

MuonParser::StatementContext* MuonParser::StatementControlContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

MuonParser::StatementControlContext::StatementControlContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::StatementControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitStatementControl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForAtLoopContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ForAtLoopContext::FOR() {
  return getToken(MuonParser::FOR, 0);
}

MuonParser::RvalueContext* MuonParser::ForAtLoopContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

tree::TerminalNode* MuonParser::ForAtLoopContext::AT() {
  return getToken(MuonParser::AT, 0);
}

MuonParser::LvalueContext* MuonParser::ForAtLoopContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
}

MuonParser::StatementContext* MuonParser::ForAtLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

tree::TerminalNode* MuonParser::ForAtLoopContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

tree::TerminalNode* MuonParser::ForAtLoopContext::SEMICOLON() {
  return getToken(MuonParser::SEMICOLON, 0);
}

MuonParser::ForAtLoopContext::ForAtLoopContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ForAtLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitForAtLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForLoopContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ForLoopContext::FOR() {
  return getToken(MuonParser::FOR, 0);
}

MuonParser::RvalueContext* MuonParser::ForLoopContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::StatementContext* MuonParser::ForLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

tree::TerminalNode* MuonParser::ForLoopContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

tree::TerminalNode* MuonParser::ForLoopContext::SEMICOLON() {
  return getToken(MuonParser::SEMICOLON, 0);
}

MuonParser::ForLoopContext::ForLoopContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForAsAtLoopContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ForAsAtLoopContext::FOR() {
  return getToken(MuonParser::FOR, 0);
}

MuonParser::RvalueContext* MuonParser::ForAsAtLoopContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

tree::TerminalNode* MuonParser::ForAsAtLoopContext::AS() {
  return getToken(MuonParser::AS, 0);
}

tree::TerminalNode* MuonParser::ForAsAtLoopContext::AT() {
  return getToken(MuonParser::AT, 0);
}

MuonParser::StatementContext* MuonParser::ForAsAtLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

std::vector<MuonParser::LvalueContext *> MuonParser::ForAsAtLoopContext::lvalue() {
  return getRuleContexts<MuonParser::LvalueContext>();
}

MuonParser::LvalueContext* MuonParser::ForAsAtLoopContext::lvalue(size_t i) {
  return getRuleContext<MuonParser::LvalueContext>(i);
}

tree::TerminalNode* MuonParser::ForAsAtLoopContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

tree::TerminalNode* MuonParser::ForAsAtLoopContext::SEMICOLON() {
  return getToken(MuonParser::SEMICOLON, 0);
}

MuonParser::ForAsAtLoopContext::ForAsAtLoopContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ForAsAtLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitForAsAtLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfSeriesContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::IfSeriesContext::IF() {
  return getToken(MuonParser::IF, 0);
}

std::vector<MuonParser::RvalueContext *> MuonParser::IfSeriesContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::IfSeriesContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

std::vector<MuonParser::StatementContext *> MuonParser::IfSeriesContext::statement() {
  return getRuleContexts<MuonParser::StatementContext>();
}

MuonParser::StatementContext* MuonParser::IfSeriesContext::statement(size_t i) {
  return getRuleContext<MuonParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::IfSeriesContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::IfSeriesContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> MuonParser::IfSeriesContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::IfSeriesContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}

std::vector<tree::TerminalNode *> MuonParser::IfSeriesContext::ELSEIF() {
  return getTokens(MuonParser::ELSEIF);
}

tree::TerminalNode* MuonParser::IfSeriesContext::ELSEIF(size_t i) {
  return getToken(MuonParser::ELSEIF, i);
}

tree::TerminalNode* MuonParser::IfSeriesContext::ELSE() {
  return getToken(MuonParser::ELSE, 0);
}

MuonParser::IfSeriesContext::IfSeriesContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::IfSeriesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitIfSeries(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileLoopContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::WhileLoopContext::WHILE() {
  return getToken(MuonParser::WHILE, 0);
}

MuonParser::RvalueContext* MuonParser::WhileLoopContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::StatementContext* MuonParser::WhileLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

tree::TerminalNode* MuonParser::WhileLoopContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

tree::TerminalNode* MuonParser::WhileLoopContext::SEMICOLON() {
  return getToken(MuonParser::SEMICOLON, 0);
}

MuonParser::WhileLoopContext::WhileLoopContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForAsLoopContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ForAsLoopContext::FOR() {
  return getToken(MuonParser::FOR, 0);
}

MuonParser::RvalueContext* MuonParser::ForAsLoopContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

tree::TerminalNode* MuonParser::ForAsLoopContext::AS() {
  return getToken(MuonParser::AS, 0);
}

MuonParser::LvalueContext* MuonParser::ForAsLoopContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
}

MuonParser::StatementContext* MuonParser::ForAsLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

tree::TerminalNode* MuonParser::ForAsLoopContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

tree::TerminalNode* MuonParser::ForAsLoopContext::SEMICOLON() {
  return getToken(MuonParser::SEMICOLON, 0);
}

MuonParser::ForAsLoopContext::ForAsLoopContext(ControlContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ForAsLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitForAsLoop(this);
  else
    return visitor->visitChildren(this);
}
MuonParser::ControlContext* MuonParser::control() {
  ControlContext *_localctx = _tracker.createInstance<ControlContext>(_ctx, getState());
  enterRule(_localctx, 2, MuonParser::RuleControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::StatementControlContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(60);
      statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::IfSeriesContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(61);
      match(MuonParser::IF);
      setState(62);
      rvalue(0);
      setState(63);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(64);
      statement();
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(65);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(66);
          match(MuonParser::ELSEIF);
          setState(67);
          rvalue(0);
          setState(68);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(69);
          statement(); 
        }
        setState(75);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(79);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(76);
        _la = _input->LA(1);
        if (!(_la == MuonParser::NEWLINE

        || _la == MuonParser::SEMICOLON)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(77);
        match(MuonParser::ELSE);
        setState(78);
        statement();
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::LoopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(81);
      match(MuonParser::LOOP);
      setState(82);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(83);
      statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(84);
      match(MuonParser::WHILE);
      setState(85);
      rvalue(0);
      setState(86);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(87);
      statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForLoopContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(89);
      match(MuonParser::FOR);
      setState(90);
      rvalue(0);
      setState(91);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(92);
      statement();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsLoopContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(94);
      match(MuonParser::FOR);
      setState(95);
      rvalue(0);
      setState(96);
      match(MuonParser::AS);
      setState(97);
      lvalue();
      setState(98);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(99);
      statement();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(101);
      match(MuonParser::FOR);
      setState(102);
      rvalue(0);
      setState(103);
      match(MuonParser::AT);
      setState(104);
      lvalue();
      setState(105);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(106);
      statement();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(108);
      match(MuonParser::FOR);
      setState(109);
      rvalue(0);
      setState(110);
      match(MuonParser::AS);
      setState(111);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->as = lvalue();
      setState(112);
      match(MuonParser::AT);
      setState(113);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->at = lvalue();
      setState(114);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(115);
      statement();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(117);
      match(MuonParser::FOR);
      setState(118);
      rvalue(0);
      setState(119);
      match(MuonParser::AT);
      setState(120);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->at = lvalue();
      setState(121);
      match(MuonParser::AS);
      setState(122);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->as = lvalue();
      setState(123);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(124);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MuonParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MuonParser::StatementContext::getRuleIndex() const {
  return MuonParser::RuleStatement;
}

void MuonParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrintContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::PrintContext::PRINT() {
  return getToken(MuonParser::PRINT, 0);
}

MuonParser::RvalueContext* MuonParser::PrintContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::PrintContext::PrintContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDeclareContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::FunctionDeclareContext::FN() {
  return getToken(MuonParser::FN, 0);
}

tree::TerminalNode* MuonParser::FunctionDeclareContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

MuonParser::LArgListContext* MuonParser::FunctionDeclareContext::lArgList() {
  return getRuleContext<MuonParser::LArgListContext>(0);
}

tree::TerminalNode* MuonParser::FunctionDeclareContext::EQUAL() {
  return getToken(MuonParser::EQUAL, 0);
}

tree::TerminalNode* MuonParser::FunctionDeclareContext::CHAIRPIN() {
  return getToken(MuonParser::CHAIRPIN, 0);
}

MuonParser::RvalueContext* MuonParser::FunctionDeclareContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::FunctionDeclareContext::FunctionDeclareContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::FunctionDeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclare(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DropNameContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::DropNameContext::DROP() {
  return getToken(MuonParser::DROP, 0);
}

MuonParser::LvalueContext* MuonParser::DropNameContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
}

MuonParser::DropNameContext::DropNameContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::DropNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDropName(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareAssignContext ------------------------------------------------------------------

MuonParser::LvalueContext* MuonParser::DeclareAssignContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
}

tree::TerminalNode* MuonParser::DeclareAssignContext::EQUAL() {
  return getToken(MuonParser::EQUAL, 0);
}

MuonParser::RvalueContext* MuonParser::DeclareAssignContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

tree::TerminalNode* MuonParser::DeclareAssignContext::VAL() {
  return getToken(MuonParser::VAL, 0);
}

tree::TerminalNode* MuonParser::DeclareAssignContext::VAR() {
  return getToken(MuonParser::VAR, 0);
}

MuonParser::DeclareAssignContext::DeclareAssignContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::DeclareAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDeclareAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakSnakeContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::BreakSnakeContext::OHAIRPIN() {
  return getToken(MuonParser::OHAIRPIN, 0);
}

MuonParser::RvalueContext* MuonParser::BreakSnakeContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

tree::TerminalNode* MuonParser::BreakSnakeContext::VOID_LITERAL() {
  return getToken(MuonParser::VOID_LITERAL, 0);
}

std::vector<tree::TerminalNode *> MuonParser::BreakSnakeContext::DASH() {
  return getTokens(MuonParser::DASH);
}

tree::TerminalNode* MuonParser::BreakSnakeContext::DASH(size_t i) {
  return getToken(MuonParser::DASH, i);
}

std::vector<tree::TerminalNode *> MuonParser::BreakSnakeContext::TILDE() {
  return getTokens(MuonParser::TILDE);
}

tree::TerminalNode* MuonParser::BreakSnakeContext::TILDE(size_t i) {
  return getToken(MuonParser::TILDE, i);
}

std::vector<tree::TerminalNode *> MuonParser::BreakSnakeContext::EQUAL() {
  return getTokens(MuonParser::EQUAL);
}

tree::TerminalNode* MuonParser::BreakSnakeContext::EQUAL(size_t i) {
  return getToken(MuonParser::EQUAL, i);
}

MuonParser::BreakSnakeContext::BreakSnakeContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::BreakSnakeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitBreakSnake(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareDimensionContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::DeclareDimensionContext::DIMENSION() {
  return getToken(MuonParser::DIMENSION, 0);
}

tree::TerminalNode* MuonParser::DeclareDimensionContext::OBRACKET() {
  return getToken(MuonParser::OBRACKET, 0);
}

std::vector<MuonParser::UnitDeclarationContext *> MuonParser::DeclareDimensionContext::unitDeclaration() {
  return getRuleContexts<MuonParser::UnitDeclarationContext>();
}

MuonParser::UnitDeclarationContext* MuonParser::DeclareDimensionContext::unitDeclaration(size_t i) {
  return getRuleContext<MuonParser::UnitDeclarationContext>(i);
}

tree::TerminalNode* MuonParser::DeclareDimensionContext::CBRACKET() {
  return getToken(MuonParser::CBRACKET, 0);
}

tree::TerminalNode* MuonParser::DeclareDimensionContext::UNITY() {
  return getToken(MuonParser::UNITY, 0);
}

tree::TerminalNode* MuonParser::DeclareDimensionContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

std::vector<tree::TerminalNode *> MuonParser::DeclareDimensionContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::DeclareDimensionContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> MuonParser::DeclareDimensionContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::DeclareDimensionContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}

MuonParser::DeclareDimensionContext::DeclareDimensionContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::DeclareDimensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDeclareDimension(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RValueStatementContext ------------------------------------------------------------------

MuonParser::RvalueContext* MuonParser::RValueStatementContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::RValueStatementContext::RValueStatementContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::RValueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitRValueStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

MuonParser::LvalueContext* MuonParser::AssignContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
}

tree::TerminalNode* MuonParser::AssignContext::EQUAL() {
  return getToken(MuonParser::EQUAL, 0);
}

MuonParser::RvalueContext* MuonParser::AssignContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::AssignContext::AssignContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareContext ------------------------------------------------------------------

MuonParser::LvalueContext* MuonParser::DeclareContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
}

tree::TerminalNode* MuonParser::DeclareContext::VAL() {
  return getToken(MuonParser::VAL, 0);
}

tree::TerminalNode* MuonParser::DeclareContext::VAR() {
  return getToken(MuonParser::VAR, 0);
}

MuonParser::DeclareContext::DeclareContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::DeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDeclare(this);
  else
    return visitor->visitChildren(this);
}
MuonParser::StatementContext* MuonParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, MuonParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::RValueStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(128);
      rvalue(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(129);
      lvalue();
      setState(130);
      match(MuonParser::EQUAL);
      setState(131);
      rvalue(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(133);
      _la = _input->LA(1);
      if (!(_la == MuonParser::VAL

      || _la == MuonParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(134);
      lvalue();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareAssignContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(135);
      _la = _input->LA(1);
      if (!(_la == MuonParser::VAL

      || _la == MuonParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(136);
      lvalue();
      setState(137);
      match(MuonParser::EQUAL);
      setState(138);
      rvalue(0);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DropNameContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(140);
      match(MuonParser::DROP);
      setState(141);
      lvalue();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::FunctionDeclareContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(142);
      match(MuonParser::FN);
      setState(143);
      match(MuonParser::NAME);
      setState(144);
      lArgList();
      setState(145);
      match(MuonParser::EQUAL);
      setState(146);
      match(MuonParser::CHAIRPIN);
      setState(147);
      rvalue(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::PrintContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(149);
      match(MuonParser::PRINT);
      setState(150);
      rvalue(0);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::BreakSnakeContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(151);
      match(MuonParser::OHAIRPIN);
      setState(153); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(152);
                _la = _input->LA(1);
                if (!((((_la & ~ 0x3fULL) == 0) &&
                  ((1ULL << _la) & ((1ULL << MuonParser::EQUAL)
                  | (1ULL << MuonParser::DASH)
                  | (1ULL << MuonParser::TILDE))) != 0))) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(155); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(159);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MuonParser::NOT:
        case MuonParser::SCIENTIFIC_FLOAT_LITERAL:
        case MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL:
        case MuonParser::FLOAT_LITERAL:
        case MuonParser::IMAGINARY_FLOAT_LITERAL:
        case MuonParser::INT_LITERAL:
        case MuonParser::IMAGINARY_INT_LITERAL:
        case MuonParser::STRING_LITERAL:
        case MuonParser::BOOL_LITERAL:
        case MuonParser::NULL_LITERAL:
        case MuonParser::NAME:
        case MuonParser::OPAREN:
        case MuonParser::OBRACKET:
        case MuonParser::OBRACE:
        case MuonParser::DASH:
        case MuonParser::PLUS:
        case MuonParser::HASH:
        case MuonParser::DOLLAR: {
          setState(157);
          rvalue(0);
          break;
        }

        case MuonParser::VOID_LITERAL: {
          setState(158);
          match(MuonParser::VOID_LITERAL);
          break;
        }

        case MuonParser::EOF:
        case MuonParser::NEWLINE:
        case MuonParser::SEMICOLON:
        case MuonParser::CBRACE: {
          break;
        }

      default:
        break;
      }
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareDimensionContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(162);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::UNITY) {
        setState(161);
        match(MuonParser::UNITY);
      }
      setState(164);
      match(MuonParser::DIMENSION);
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NAME) {
        setState(165);
        match(MuonParser::NAME);
      }
      setState(168);
      match(MuonParser::OBRACKET);
      setState(170);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(169);
        _la = _input->LA(1);
        if (!(_la == MuonParser::NEWLINE

        || _la == MuonParser::SEMICOLON)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(172);
      unitDeclaration();
      setState(177);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(173);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(174);
          unitDeclaration(); 
        }
        setState(179);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(180);
        _la = _input->LA(1);
        if (!(_la == MuonParser::NEWLINE

        || _la == MuonParser::SEMICOLON)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(183);
      match(MuonParser::CBRACKET);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitDeclarationContext ------------------------------------------------------------------

MuonParser::UnitDeclarationContext::UnitDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::UnitDeclarationContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

tree::TerminalNode* MuonParser::UnitDeclarationContext::EQUAL() {
  return getToken(MuonParser::EQUAL, 0);
}

MuonParser::RvalueContext* MuonParser::UnitDeclarationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}


size_t MuonParser::UnitDeclarationContext::getRuleIndex() const {
  return MuonParser::RuleUnitDeclaration;
}

antlrcpp::Any MuonParser::UnitDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitUnitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::UnitDeclarationContext* MuonParser::unitDeclaration() {
  UnitDeclarationContext *_localctx = _tracker.createInstance<UnitDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, MuonParser::RuleUnitDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(187);
      match(MuonParser::NAME);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(188);
      match(MuonParser::NAME);
      setState(189);
      match(MuonParser::EQUAL);
      setState(190);
      rvalue(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RvalueContext ------------------------------------------------------------------

MuonParser::RvalueContext::RvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MuonParser::RvalueContext::getRuleIndex() const {
  return MuonParser::RuleRvalue;
}

void MuonParser::RvalueContext::copyFrom(RvalueContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOperationContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::UnaryOperationContext::PLUS() {
  return getToken(MuonParser::PLUS, 0);
}

MuonParser::RvalueContext* MuonParser::UnaryOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

tree::TerminalNode* MuonParser::UnaryOperationContext::DASH() {
  return getToken(MuonParser::DASH, 0);
}

tree::TerminalNode* MuonParser::UnaryOperationContext::DOLLAR() {
  return getToken(MuonParser::DOLLAR, 0);
}

tree::TerminalNode* MuonParser::UnaryOperationContext::HASH() {
  return getToken(MuonParser::HASH, 0);
}

tree::TerminalNode* MuonParser::UnaryOperationContext::NOT() {
  return getToken(MuonParser::NOT, 0);
}

MuonParser::UnaryOperationContext::UnaryOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::UnaryOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitUnaryOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::BinaryOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::BinaryOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::CARROT() {
  return getToken(MuonParser::CARROT, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::DOTCARROT() {
  return getToken(MuonParser::DOTCARROT, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::STAR() {
  return getToken(MuonParser::STAR, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::SLASH() {
  return getToken(MuonParser::SLASH, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::DOTSTAR() {
  return getToken(MuonParser::DOTSTAR, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::DOTSLASH() {
  return getToken(MuonParser::DOTSLASH, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::PLUS() {
  return getToken(MuonParser::PLUS, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::DASH() {
  return getToken(MuonParser::DASH, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::OHAIRPIN() {
  return getToken(MuonParser::OHAIRPIN, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::OHAIRPINEQUAL() {
  return getToken(MuonParser::OHAIRPINEQUAL, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::CHAIRPIN() {
  return getToken(MuonParser::CHAIRPIN, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::CHAIRPINEQUAL() {
  return getToken(MuonParser::CHAIRPINEQUAL, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::IS() {
  return getToken(MuonParser::IS, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::ISNT() {
  return getToken(MuonParser::ISNT, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::AND() {
  return getToken(MuonParser::AND, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::NAND() {
  return getToken(MuonParser::NAND, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::XOR() {
  return getToken(MuonParser::XOR, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::OR() {
  return getToken(MuonParser::OR, 0);
}

tree::TerminalNode* MuonParser::BinaryOperationContext::NOR() {
  return getToken(MuonParser::NOR, 0);
}

MuonParser::BinaryOperationContext::BinaryOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::BinaryOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitBinaryOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConvertOperationContext ------------------------------------------------------------------

MuonParser::RvalueContext* MuonParser::ConvertOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::TypeContext* MuonParser::ConvertOperationContext::type() {
  return getRuleContext<MuonParser::TypeContext>(0);
}

tree::TerminalNode* MuonParser::ConvertOperationContext::AT_SYMBOL() {
  return getToken(MuonParser::AT_SYMBOL, 0);
}

tree::TerminalNode* MuonParser::ConvertOperationContext::AMPERSAND() {
  return getToken(MuonParser::AMPERSAND, 0);
}

tree::TerminalNode* MuonParser::ConvertOperationContext::TO() {
  return getToken(MuonParser::TO, 0);
}

MuonParser::ConvertOperationContext::ConvertOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ConvertOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitConvertOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomRValueContext ------------------------------------------------------------------

MuonParser::AtomContext* MuonParser::AtomRValueContext::atom() {
  return getRuleContext<MuonParser::AtomContext>(0);
}

MuonParser::AtomRValueContext::AtomRValueContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::AtomRValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitAtomRValue(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::RvalueContext* MuonParser::rvalue() {
   return rvalue(0);
}

MuonParser::RvalueContext* MuonParser::rvalue(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MuonParser::RvalueContext *_localctx = _tracker.createInstance<RvalueContext>(_ctx, parentState);
  MuonParser::RvalueContext *previousContext = _localctx;
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, MuonParser::RuleRvalue, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::PLUS: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(194);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::PLUS);
        setState(195);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(15);
        break;
      }

      case MuonParser::DASH: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(196);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::DASH);
        setState(197);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(14);
        break;
      }

      case MuonParser::DOLLAR: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(198);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::DOLLAR);
        setState(199);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(13);
        break;
      }

      case MuonParser::HASH: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(200);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::HASH);
        setState(201);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(12);
        break;
      }

      case MuonParser::NOT: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(202);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::NOT);
        setState(203);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(11);
        break;
      }

      case MuonParser::SCIENTIFIC_FLOAT_LITERAL:
      case MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL:
      case MuonParser::FLOAT_LITERAL:
      case MuonParser::IMAGINARY_FLOAT_LITERAL:
      case MuonParser::INT_LITERAL:
      case MuonParser::IMAGINARY_INT_LITERAL:
      case MuonParser::STRING_LITERAL:
      case MuonParser::BOOL_LITERAL:
      case MuonParser::NULL_LITERAL:
      case MuonParser::NAME:
      case MuonParser::OPAREN:
      case MuonParser::OBRACKET:
      case MuonParser::OBRACE: {
        _localctx = _tracker.createInstance<AtomRValueContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(204);
        dynamic_cast<AtomRValueContext *>(_localctx)->a = atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(236);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(234);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(207);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(208);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::CARROT

          || _la == MuonParser::DOTCARROT)) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(209);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(210);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(211);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (MuonParser::STAR - 67))
            | (1ULL << (MuonParser::DOTSTAR - 67))
            | (1ULL << (MuonParser::SLASH - 67))
            | (1ULL << (MuonParser::DOTSLASH - 67)))) != 0))) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(212);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(213);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(214);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::DASH

          || _la == MuonParser::PLUS)) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(215);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(216);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(217);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MuonParser::OHAIRPIN)
            | (1ULL << MuonParser::CHAIRPIN)
            | (1ULL << MuonParser::OHAIRPINEQUAL)
            | (1ULL << MuonParser::CHAIRPINEQUAL))) != 0))) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(218);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(219);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(220);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::IS

          || _la == MuonParser::ISNT)) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(221);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(6);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(222);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(223);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::AND

          || _la == MuonParser::NAND)) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(224);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(5);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(225);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(226);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = match(MuonParser::XOR);
          setState(227);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(4);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(228);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(229);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::OR

          || _la == MuonParser::NOR)) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(230);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(3);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ConvertOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(231);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(232);
          dynamic_cast<ConvertOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 27) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 27)) & ((1ULL << (MuonParser::TO - 27))
            | (1ULL << (MuonParser::AT_SYMBOL - 27))
            | (1ULL << (MuonParser::AMPERSAND - 27)))) != 0))) {
            dynamic_cast<ConvertOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(233);
          dynamic_cast<ConvertOperationContext *>(_localctx)->t = type();
          break;
        }

        } 
      }
      setState(238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

MuonParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MuonParser::AtomContext::getRuleIndex() const {
  return MuonParser::RuleAtom;
}

void MuonParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ScopeAtomContext ------------------------------------------------------------------

MuonParser::ScopeContext* MuonParser::ScopeAtomContext::scope() {
  return getRuleContext<MuonParser::ScopeContext>(0);
}

MuonParser::ScopeAtomContext::ScopeAtomContext(AtomContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ScopeAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitScopeAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InvokeAtomContext ------------------------------------------------------------------

MuonParser::InvokeContext* MuonParser::InvokeAtomContext::invoke() {
  return getRuleContext<MuonParser::InvokeContext>(0);
}

MuonParser::InvokeAtomContext::InvokeAtomContext(AtomContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::InvokeAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitInvokeAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatrixAtomContext ------------------------------------------------------------------

MuonParser::MatrixContext* MuonParser::MatrixAtomContext::matrix() {
  return getRuleContext<MuonParser::MatrixContext>(0);
}

MuonParser::MatrixAtomContext::MatrixAtomContext(AtomContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::MatrixAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitMatrixAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListAtomContext ------------------------------------------------------------------

MuonParser::ListContext* MuonParser::ListAtomContext::list() {
  return getRuleContext<MuonParser::ListContext>(0);
}

MuonParser::ListAtomContext::ListAtomContext(AtomContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ListAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitListAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NameAtomContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::NameAtomContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

MuonParser::NameAtomContext::NameAtomContext(AtomContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::NameAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitNameAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralAtomContext ------------------------------------------------------------------

MuonParser::LiteralContext* MuonParser::LiteralAtomContext::literal() {
  return getRuleContext<MuonParser::LiteralContext>(0);
}

MuonParser::LiteralAtomContext::LiteralAtomContext(AtomContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::LiteralAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitLiteralAtom(this);
  else
    return visitor->visitChildren(this);
}
MuonParser::AtomContext* MuonParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 10, MuonParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::LiteralAtomContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(239);
      literal();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::NameAtomContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(240);
      match(MuonParser::NAME);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::InvokeAtomContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(241);
      invoke(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::MatrixAtomContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(242);
      matrix();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::ListAtomContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(243);
      list();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::ScopeAtomContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(244);
      scope();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MuonParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MuonParser::LiteralContext::getRuleIndex() const {
  return MuonParser::RuleLiteral;
}

void MuonParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::StringLiteralContext::STRING_LITERAL() {
  return getToken(MuonParser::STRING_LITERAL, 0);
}

MuonParser::StringLiteralContext::StringLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::BoolLiteralContext::BOOL_LITERAL() {
  return getToken(MuonParser::BOOL_LITERAL, 0);
}

MuonParser::BoolLiteralContext::BoolLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::FloatLiteralContext::SCIENTIFIC_FLOAT_LITERAL() {
  return getToken(MuonParser::SCIENTIFIC_FLOAT_LITERAL, 0);
}

tree::TerminalNode* MuonParser::FloatLiteralContext::FLOAT_LITERAL() {
  return getToken(MuonParser::FLOAT_LITERAL, 0);
}

MuonParser::FloatLiteralContext::FloatLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImaginaryIntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ImaginaryIntLiteralContext::IMAGINARY_INT_LITERAL() {
  return getToken(MuonParser::IMAGINARY_INT_LITERAL, 0);
}

MuonParser::ImaginaryIntLiteralContext::ImaginaryIntLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ImaginaryIntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitImaginaryIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImaginaryFloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ImaginaryFloatLiteralContext::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL() {
  return getToken(MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL, 0);
}

tree::TerminalNode* MuonParser::ImaginaryFloatLiteralContext::IMAGINARY_FLOAT_LITERAL() {
  return getToken(MuonParser::IMAGINARY_FLOAT_LITERAL, 0);
}

MuonParser::ImaginaryFloatLiteralContext::ImaginaryFloatLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ImaginaryFloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitImaginaryFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::IntLiteralContext::INT_LITERAL() {
  return getToken(MuonParser::INT_LITERAL, 0);
}

MuonParser::IntLiteralContext::IntLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::IntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::NullLiteralContext::NULL_LITERAL() {
  return getToken(MuonParser::NULL_LITERAL, 0);
}

MuonParser::NullLiteralContext::NullLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::NullLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitNullLiteral(this);
  else
    return visitor->visitChildren(this);
}
MuonParser::LiteralContext* MuonParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 12, MuonParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(256);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::SCIENTIFIC_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::FloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(247);
        match(MuonParser::SCIENTIFIC_FLOAT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryFloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(248);
        match(MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL);
        break;
      }

      case MuonParser::FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::FloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(249);
        match(MuonParser::FLOAT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryFloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(250);
        match(MuonParser::IMAGINARY_FLOAT_LITERAL);
        break;
      }

      case MuonParser::INT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::IntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(251);
        match(MuonParser::INT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_INT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryIntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(252);
        match(MuonParser::IMAGINARY_INT_LITERAL);
        break;
      }

      case MuonParser::STRING_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::StringLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(253);
        match(MuonParser::STRING_LITERAL);
        break;
      }

      case MuonParser::BOOL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::BoolLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(254);
        match(MuonParser::BOOL_LITERAL);
        break;
      }

      case MuonParser::NULL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::NullLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(255);
        match(MuonParser::NULL_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvokeContext ------------------------------------------------------------------

MuonParser::InvokeContext::InvokeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::InvokeContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

std::vector<MuonParser::ListContext *> MuonParser::InvokeContext::list() {
  return getRuleContexts<MuonParser::ListContext>();
}

MuonParser::ListContext* MuonParser::InvokeContext::list(size_t i) {
  return getRuleContext<MuonParser::ListContext>(i);
}

std::vector<MuonParser::MatrixContext *> MuonParser::InvokeContext::matrix() {
  return getRuleContexts<MuonParser::MatrixContext>();
}

MuonParser::MatrixContext* MuonParser::InvokeContext::matrix(size_t i) {
  return getRuleContext<MuonParser::MatrixContext>(i);
}

MuonParser::InvokeContext* MuonParser::InvokeContext::invoke() {
  return getRuleContext<MuonParser::InvokeContext>(0);
}


size_t MuonParser::InvokeContext::getRuleIndex() const {
  return MuonParser::RuleInvoke;
}

antlrcpp::Any MuonParser::InvokeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitInvoke(this);
  else
    return visitor->visitChildren(this);
}


MuonParser::InvokeContext* MuonParser::invoke() {
   return invoke(0);
}

MuonParser::InvokeContext* MuonParser::invoke(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MuonParser::InvokeContext *_localctx = _tracker.createInstance<InvokeContext>(_ctx, parentState);
  MuonParser::InvokeContext *previousContext = _localctx;
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, MuonParser::RuleInvoke, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::NAME: {
        setState(259);
        match(MuonParser::NAME);
        setState(262);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(260);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(261);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case MuonParser::OBRACKET: {
        setState(264);
        list();
        setState(265);
        list();
        break;
      }

      case MuonParser::OPAREN: {
        setState(267);
        matrix();
        setState(270);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(268);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(269);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InvokeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInvoke);
        setState(274);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(277);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(275);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(276);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MatrixContext ------------------------------------------------------------------

MuonParser::MatrixContext::MatrixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::MatrixContext::OPAREN() {
  return getToken(MuonParser::OPAREN, 0);
}

tree::TerminalNode* MuonParser::MatrixContext::CPAREN() {
  return getToken(MuonParser::CPAREN, 0);
}

std::vector<MuonParser::RvalueContext *> MuonParser::MatrixContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::MatrixContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::MatrixContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::MatrixContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::MatrixContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}


size_t MuonParser::MatrixContext::getRuleIndex() const {
  return MuonParser::RuleMatrix;
}

antlrcpp::Any MuonParser::MatrixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitMatrix(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::MatrixContext* MuonParser::matrix() {
  MatrixContext *_localctx = _tracker.createInstance<MatrixContext>(_ctx, getState());
  enterRule(_localctx, 16, MuonParser::RuleMatrix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(MuonParser::OPAREN);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NOT)
      | (1ULL << MuonParser::SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_FLOAT_LITERAL)
      | (1ULL << MuonParser::INT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_INT_LITERAL)
      | (1ULL << MuonParser::STRING_LITERAL)
      | (1ULL << MuonParser::BOOL_LITERAL)
      | (1ULL << MuonParser::NULL_LITERAL)
      | (1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::OBRACE)
      | (1ULL << MuonParser::DASH)
      | (1ULL << MuonParser::PLUS)
      | (1ULL << MuonParser::HASH)
      | (1ULL << MuonParser::DOLLAR))) != 0)) {
      setState(285);
      rvalue(0);
      setState(290);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MuonParser::NEWLINE)
        | (1ULL << MuonParser::SEMICOLON)
        | (1ULL << MuonParser::COMMA))) != 0)) {
        setState(286);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MuonParser::NEWLINE)
          | (1ULL << MuonParser::SEMICOLON)
          | (1ULL << MuonParser::COMMA))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(287);
        rvalue(0);
        setState(292);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(295);
    match(MuonParser::CPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListContext ------------------------------------------------------------------

MuonParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::ListContext::OBRACKET() {
  return getToken(MuonParser::OBRACKET, 0);
}

tree::TerminalNode* MuonParser::ListContext::CBRACKET() {
  return getToken(MuonParser::CBRACKET, 0);
}

std::vector<MuonParser::RvalueContext *> MuonParser::ListContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::ListContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::ListContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::ListContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}


size_t MuonParser::ListContext::getRuleIndex() const {
  return MuonParser::RuleList;
}

antlrcpp::Any MuonParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::ListContext* MuonParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 18, MuonParser::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(MuonParser::OBRACKET);
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NOT)
      | (1ULL << MuonParser::SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_FLOAT_LITERAL)
      | (1ULL << MuonParser::INT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_INT_LITERAL)
      | (1ULL << MuonParser::STRING_LITERAL)
      | (1ULL << MuonParser::BOOL_LITERAL)
      | (1ULL << MuonParser::NULL_LITERAL)
      | (1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::OBRACE)
      | (1ULL << MuonParser::DASH)
      | (1ULL << MuonParser::PLUS)
      | (1ULL << MuonParser::HASH)
      | (1ULL << MuonParser::DOLLAR))) != 0)) {
      setState(298);
      rvalue(0);
      setState(303);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(299);
        match(MuonParser::COMMA);
        setState(300);
        rvalue(0);
        setState(305);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(308);
    match(MuonParser::CBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

MuonParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::ScopeContext::OBRACE() {
  return getToken(MuonParser::OBRACE, 0);
}

tree::TerminalNode* MuonParser::ScopeContext::CBRACE() {
  return getToken(MuonParser::CBRACE, 0);
}

std::vector<MuonParser::ControlContext *> MuonParser::ScopeContext::control() {
  return getRuleContexts<MuonParser::ControlContext>();
}

MuonParser::ControlContext* MuonParser::ScopeContext::control(size_t i) {
  return getRuleContext<MuonParser::ControlContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::ScopeContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::ScopeContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> MuonParser::ScopeContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::ScopeContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}


size_t MuonParser::ScopeContext::getRuleIndex() const {
  return MuonParser::RuleScope;
}

antlrcpp::Any MuonParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::ScopeContext* MuonParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 20, MuonParser::RuleScope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(MuonParser::OBRACE);
    setState(312);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(311);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
    setState(322);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::VAL)
      | (1ULL << MuonParser::VAR)
      | (1ULL << MuonParser::DROP)
      | (1ULL << MuonParser::FN)
      | (1ULL << MuonParser::IF)
      | (1ULL << MuonParser::FOR)
      | (1ULL << MuonParser::WHILE)
      | (1ULL << MuonParser::LOOP)
      | (1ULL << MuonParser::DIMENSION)
      | (1ULL << MuonParser::UNITY)
      | (1ULL << MuonParser::PRINT)
      | (1ULL << MuonParser::NOT)
      | (1ULL << MuonParser::SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_FLOAT_LITERAL)
      | (1ULL << MuonParser::INT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_INT_LITERAL)
      | (1ULL << MuonParser::STRING_LITERAL)
      | (1ULL << MuonParser::BOOL_LITERAL)
      | (1ULL << MuonParser::NULL_LITERAL)
      | (1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::OBRACE)
      | (1ULL << MuonParser::UNDERSCORE)
      | (1ULL << MuonParser::DASH)
      | (1ULL << MuonParser::PLUS)
      | (1ULL << MuonParser::OHAIRPIN)
      | (1ULL << MuonParser::HASH)
      | (1ULL << MuonParser::DOLLAR))) != 0)) {
      setState(314);
      control();
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(315);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(316);
          control(); 
        }
        setState(321);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
    }
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MuonParser::NEWLINE

    || _la == MuonParser::SEMICOLON) {
      setState(324);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(327);
    match(MuonParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RArgListContext ------------------------------------------------------------------

MuonParser::RArgListContext::RArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::RArgListContext::OPAREN() {
  return getToken(MuonParser::OPAREN, 0);
}

tree::TerminalNode* MuonParser::RArgListContext::CPAREN() {
  return getToken(MuonParser::CPAREN, 0);
}

std::vector<MuonParser::RvalueContext *> MuonParser::RArgListContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::RArgListContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::RArgListContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::RArgListContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}


size_t MuonParser::RArgListContext::getRuleIndex() const {
  return MuonParser::RuleRArgList;
}

antlrcpp::Any MuonParser::RArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitRArgList(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::RArgListContext* MuonParser::rArgList() {
  RArgListContext *_localctx = _tracker.createInstance<RArgListContext>(_ctx, getState());
  enterRule(_localctx, 22, MuonParser::RuleRArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    match(MuonParser::OPAREN);
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NOT)
      | (1ULL << MuonParser::SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::FLOAT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_FLOAT_LITERAL)
      | (1ULL << MuonParser::INT_LITERAL)
      | (1ULL << MuonParser::IMAGINARY_INT_LITERAL)
      | (1ULL << MuonParser::STRING_LITERAL)
      | (1ULL << MuonParser::BOOL_LITERAL)
      | (1ULL << MuonParser::NULL_LITERAL)
      | (1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::OBRACE)
      | (1ULL << MuonParser::DASH)
      | (1ULL << MuonParser::PLUS)
      | (1ULL << MuonParser::HASH)
      | (1ULL << MuonParser::DOLLAR))) != 0)) {
      setState(330);
      rvalue(0);
      setState(335);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(331);
        match(MuonParser::COMMA);
        setState(332);
        rvalue(0);
        setState(337);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(340);
    match(MuonParser::CPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MuonParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MuonParser::UnitContext* MuonParser::TypeContext::unit() {
  return getRuleContext<MuonParser::UnitContext>(0);
}

MuonParser::DimensionContext* MuonParser::TypeContext::dimension() {
  return getRuleContext<MuonParser::DimensionContext>(0);
}


size_t MuonParser::TypeContext::getRuleIndex() const {
  return MuonParser::RuleType;
}

antlrcpp::Any MuonParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::TypeContext* MuonParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 24, MuonParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(342);
      unit();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(343);
      dimension();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

MuonParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::UnitContext::OBRACKET() {
  return getToken(MuonParser::OBRACKET, 0);
}

MuonParser::TypeRValueContext* MuonParser::UnitContext::typeRValue() {
  return getRuleContext<MuonParser::TypeRValueContext>(0);
}

tree::TerminalNode* MuonParser::UnitContext::CBRACKET() {
  return getToken(MuonParser::CBRACKET, 0);
}


size_t MuonParser::UnitContext::getRuleIndex() const {
  return MuonParser::RuleUnit;
}

antlrcpp::Any MuonParser::UnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitUnit(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::UnitContext* MuonParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 26, MuonParser::RuleUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(MuonParser::OBRACKET);
    setState(347);
    typeRValue();
    setState(348);
    match(MuonParser::CBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DimensionContext ------------------------------------------------------------------

MuonParser::DimensionContext::DimensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MuonParser::DimensionContext::OBRACKET() {
  return getTokens(MuonParser::OBRACKET);
}

tree::TerminalNode* MuonParser::DimensionContext::OBRACKET(size_t i) {
  return getToken(MuonParser::OBRACKET, i);
}

MuonParser::TypeRValueContext* MuonParser::DimensionContext::typeRValue() {
  return getRuleContext<MuonParser::TypeRValueContext>(0);
}

std::vector<tree::TerminalNode *> MuonParser::DimensionContext::CBRACKET() {
  return getTokens(MuonParser::CBRACKET);
}

tree::TerminalNode* MuonParser::DimensionContext::CBRACKET(size_t i) {
  return getToken(MuonParser::CBRACKET, i);
}


size_t MuonParser::DimensionContext::getRuleIndex() const {
  return MuonParser::RuleDimension;
}

antlrcpp::Any MuonParser::DimensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDimension(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::DimensionContext* MuonParser::dimension() {
  DimensionContext *_localctx = _tracker.createInstance<DimensionContext>(_ctx, getState());
  enterRule(_localctx, 28, MuonParser::RuleDimension);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(MuonParser::OBRACKET);
    setState(351);
    match(MuonParser::OBRACKET);
    setState(352);
    typeRValue();
    setState(353);
    match(MuonParser::CBRACKET);
    setState(354);
    match(MuonParser::CBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeRValueContext ------------------------------------------------------------------

MuonParser::TypeRValueContext::TypeRValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MuonParser::TypeMultiplyOperationContext* MuonParser::TypeRValueContext::typeMultiplyOperation() {
  return getRuleContext<MuonParser::TypeMultiplyOperationContext>(0);
}


size_t MuonParser::TypeRValueContext::getRuleIndex() const {
  return MuonParser::RuleTypeRValue;
}

antlrcpp::Any MuonParser::TypeRValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitTypeRValue(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::TypeRValueContext* MuonParser::typeRValue() {
  TypeRValueContext *_localctx = _tracker.createInstance<TypeRValueContext>(_ctx, getState());
  enterRule(_localctx, 30, MuonParser::RuleTypeRValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    typeMultiplyOperation();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeMultiplyOperationContext ------------------------------------------------------------------

MuonParser::TypeMultiplyOperationContext::TypeMultiplyOperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MuonParser::TypePowerOperationContext* MuonParser::TypeMultiplyOperationContext::typePowerOperation() {
  return getRuleContext<MuonParser::TypePowerOperationContext>(0);
}

MuonParser::TypeMultiplyOperationContext* MuonParser::TypeMultiplyOperationContext::typeMultiplyOperation() {
  return getRuleContext<MuonParser::TypeMultiplyOperationContext>(0);
}

tree::TerminalNode* MuonParser::TypeMultiplyOperationContext::STAR() {
  return getToken(MuonParser::STAR, 0);
}

tree::TerminalNode* MuonParser::TypeMultiplyOperationContext::SLASH() {
  return getToken(MuonParser::SLASH, 0);
}


size_t MuonParser::TypeMultiplyOperationContext::getRuleIndex() const {
  return MuonParser::RuleTypeMultiplyOperation;
}

antlrcpp::Any MuonParser::TypeMultiplyOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitTypeMultiplyOperation(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::TypeMultiplyOperationContext* MuonParser::typeMultiplyOperation() {
  TypeMultiplyOperationContext *_localctx = _tracker.createInstance<TypeMultiplyOperationContext>(_ctx, getState());
  enterRule(_localctx, 32, MuonParser::RuleTypeMultiplyOperation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(358);
      typePowerOperation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359);
      typePowerOperation();
      setState(360);
      _la = _input->LA(1);
      if (!(_la == MuonParser::STAR

      || _la == MuonParser::SLASH)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(361);
      typeMultiplyOperation();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypePowerOperationContext ------------------------------------------------------------------

MuonParser::TypePowerOperationContext::TypePowerOperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MuonParser::TypeAtomContext* MuonParser::TypePowerOperationContext::typeAtom() {
  return getRuleContext<MuonParser::TypeAtomContext>(0);
}

tree::TerminalNode* MuonParser::TypePowerOperationContext::CARROT() {
  return getToken(MuonParser::CARROT, 0);
}

MuonParser::TypePowerOperationContext* MuonParser::TypePowerOperationContext::typePowerOperation() {
  return getRuleContext<MuonParser::TypePowerOperationContext>(0);
}


size_t MuonParser::TypePowerOperationContext::getRuleIndex() const {
  return MuonParser::RuleTypePowerOperation;
}

antlrcpp::Any MuonParser::TypePowerOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitTypePowerOperation(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::TypePowerOperationContext* MuonParser::typePowerOperation() {
  TypePowerOperationContext *_localctx = _tracker.createInstance<TypePowerOperationContext>(_ctx, getState());
  enterRule(_localctx, 34, MuonParser::RuleTypePowerOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(370);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(365);
      typeAtom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(366);
      typeAtom();
      setState(367);
      match(MuonParser::CARROT);
      setState(368);
      typePowerOperation();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAtomContext ------------------------------------------------------------------

MuonParser::TypeAtomContext::TypeAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MuonParser::TypeLiteralContext* MuonParser::TypeAtomContext::typeLiteral() {
  return getRuleContext<MuonParser::TypeLiteralContext>(0);
}

tree::TerminalNode* MuonParser::TypeAtomContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

tree::TerminalNode* MuonParser::TypeAtomContext::OPAREN() {
  return getToken(MuonParser::OPAREN, 0);
}

MuonParser::TypeRValueContext* MuonParser::TypeAtomContext::typeRValue() {
  return getRuleContext<MuonParser::TypeRValueContext>(0);
}

tree::TerminalNode* MuonParser::TypeAtomContext::CPAREN() {
  return getToken(MuonParser::CPAREN, 0);
}


size_t MuonParser::TypeAtomContext::getRuleIndex() const {
  return MuonParser::RuleTypeAtom;
}

antlrcpp::Any MuonParser::TypeAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitTypeAtom(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::TypeAtomContext* MuonParser::typeAtom() {
  TypeAtomContext *_localctx = _tracker.createInstance<TypeAtomContext>(_ctx, getState());
  enterRule(_localctx, 36, MuonParser::RuleTypeAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(378);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::SCIENTIFIC_FLOAT_LITERAL:
      case MuonParser::FLOAT_LITERAL:
      case MuonParser::INT_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(372);
        typeLiteral();
        break;
      }

      case MuonParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(373);
        match(MuonParser::NAME);
        break;
      }

      case MuonParser::OPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(374);
        match(MuonParser::OPAREN);
        setState(375);
        typeRValue();
        setState(376);
        match(MuonParser::CPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeLiteralContext ------------------------------------------------------------------

MuonParser::TypeLiteralContext::TypeLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::TypeLiteralContext::SCIENTIFIC_FLOAT_LITERAL() {
  return getToken(MuonParser::SCIENTIFIC_FLOAT_LITERAL, 0);
}

tree::TerminalNode* MuonParser::TypeLiteralContext::FLOAT_LITERAL() {
  return getToken(MuonParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* MuonParser::TypeLiteralContext::INT_LITERAL() {
  return getToken(MuonParser::INT_LITERAL, 0);
}


size_t MuonParser::TypeLiteralContext::getRuleIndex() const {
  return MuonParser::RuleTypeLiteral;
}

antlrcpp::Any MuonParser::TypeLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitTypeLiteral(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::TypeLiteralContext* MuonParser::typeLiteral() {
  TypeLiteralContext *_localctx = _tracker.createInstance<TypeLiteralContext>(_ctx, getState());
  enterRule(_localctx, 38, MuonParser::RuleTypeLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::SCIENTIFIC_FLOAT_LITERAL)
      | (1ULL << MuonParser::FLOAT_LITERAL)
      | (1ULL << MuonParser::INT_LITERAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LvalueContext ------------------------------------------------------------------

MuonParser::LvalueContext::LvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::LvalueContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

MuonParser::MatrixDecompositionContext* MuonParser::LvalueContext::matrixDecomposition() {
  return getRuleContext<MuonParser::MatrixDecompositionContext>(0);
}

MuonParser::ListDecompositionContext* MuonParser::LvalueContext::listDecomposition() {
  return getRuleContext<MuonParser::ListDecompositionContext>(0);
}

MuonParser::SubsetContext* MuonParser::LvalueContext::subset() {
  return getRuleContext<MuonParser::SubsetContext>(0);
}

MuonParser::DiscardContext* MuonParser::LvalueContext::discard() {
  return getRuleContext<MuonParser::DiscardContext>(0);
}


size_t MuonParser::LvalueContext::getRuleIndex() const {
  return MuonParser::RuleLvalue;
}

antlrcpp::Any MuonParser::LvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitLvalue(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::LvalueContext* MuonParser::lvalue() {
  LvalueContext *_localctx = _tracker.createInstance<LvalueContext>(_ctx, getState());
  enterRule(_localctx, 40, MuonParser::RuleLvalue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(387);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(382);
      match(MuonParser::NAME);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(383);
      matrixDecomposition();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(384);
      listDecomposition();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(385);
      subset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(386);
      discard();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatrixDecompositionContext ------------------------------------------------------------------

MuonParser::MatrixDecompositionContext::MatrixDecompositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::MatrixDecompositionContext::OPAREN() {
  return getToken(MuonParser::OPAREN, 0);
}

tree::TerminalNode* MuonParser::MatrixDecompositionContext::CPAREN() {
  return getToken(MuonParser::CPAREN, 0);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixDecompositionContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::MatrixDecompositionContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<MuonParser::LvalueContext *> MuonParser::MatrixDecompositionContext::lvalue() {
  return getRuleContexts<MuonParser::LvalueContext>();
}

MuonParser::LvalueContext* MuonParser::MatrixDecompositionContext::lvalue(size_t i) {
  return getRuleContext<MuonParser::LvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixDecompositionContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::MatrixDecompositionContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixDecompositionContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::MatrixDecompositionContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}


size_t MuonParser::MatrixDecompositionContext::getRuleIndex() const {
  return MuonParser::RuleMatrixDecomposition;
}

antlrcpp::Any MuonParser::MatrixDecompositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitMatrixDecomposition(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::MatrixDecompositionContext* MuonParser::matrixDecomposition() {
  MatrixDecompositionContext *_localctx = _tracker.createInstance<MatrixDecompositionContext>(_ctx, getState());
  enterRule(_localctx, 42, MuonParser::RuleMatrixDecomposition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(MuonParser::OPAREN);
    setState(391);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MuonParser::NEWLINE) {
      setState(390);
      match(MuonParser::NEWLINE);
    }
    setState(404);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
      setState(393);
      lvalue();
      setState(398);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(394);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MuonParser::NEWLINE)
            | (1ULL << MuonParser::SEMICOLON)
            | (1ULL << MuonParser::COMMA))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(395);
          lvalue(); 
        }
        setState(400);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      }
      setState(402);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE) {
        setState(401);
        match(MuonParser::NEWLINE);
      }
    }
    setState(406);
    match(MuonParser::CPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListDecompositionContext ------------------------------------------------------------------

MuonParser::ListDecompositionContext::ListDecompositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::ListDecompositionContext::OBRACKET() {
  return getToken(MuonParser::OBRACKET, 0);
}

tree::TerminalNode* MuonParser::ListDecompositionContext::CBRACKET() {
  return getToken(MuonParser::CBRACKET, 0);
}

tree::TerminalNode* MuonParser::ListDecompositionContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

std::vector<MuonParser::LvalueContext *> MuonParser::ListDecompositionContext::lvalue() {
  return getRuleContexts<MuonParser::LvalueContext>();
}

MuonParser::LvalueContext* MuonParser::ListDecompositionContext::lvalue(size_t i) {
  return getRuleContext<MuonParser::LvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::ListDecompositionContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::ListDecompositionContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}


size_t MuonParser::ListDecompositionContext::getRuleIndex() const {
  return MuonParser::RuleListDecomposition;
}

antlrcpp::Any MuonParser::ListDecompositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitListDecomposition(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::ListDecompositionContext* MuonParser::listDecomposition() {
  ListDecompositionContext *_localctx = _tracker.createInstance<ListDecompositionContext>(_ctx, getState());
  enterRule(_localctx, 44, MuonParser::RuleListDecomposition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(MuonParser::OBRACKET);
    setState(410);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MuonParser::NEWLINE) {
      setState(409);
      match(MuonParser::NEWLINE);
    }
    setState(420);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
      setState(412);
      lvalue();
      setState(417);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(413);
        match(MuonParser::COMMA);
        setState(414);
        lvalue();
        setState(419);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(422);
    match(MuonParser::CBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubsetContext ------------------------------------------------------------------

MuonParser::SubsetContext::SubsetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::SubsetContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

MuonParser::LArgListContext* MuonParser::SubsetContext::lArgList() {
  return getRuleContext<MuonParser::LArgListContext>(0);
}


size_t MuonParser::SubsetContext::getRuleIndex() const {
  return MuonParser::RuleSubset;
}

antlrcpp::Any MuonParser::SubsetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitSubset(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::SubsetContext* MuonParser::subset() {
  SubsetContext *_localctx = _tracker.createInstance<SubsetContext>(_ctx, getState());
  enterRule(_localctx, 46, MuonParser::RuleSubset);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(MuonParser::NAME);
    setState(425);
    lArgList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiscardContext ------------------------------------------------------------------

MuonParser::DiscardContext::DiscardContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::DiscardContext::UNDERSCORE() {
  return getToken(MuonParser::UNDERSCORE, 0);
}


size_t MuonParser::DiscardContext::getRuleIndex() const {
  return MuonParser::RuleDiscard;
}

antlrcpp::Any MuonParser::DiscardContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDiscard(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::DiscardContext* MuonParser::discard() {
  DiscardContext *_localctx = _tracker.createInstance<DiscardContext>(_ctx, getState());
  enterRule(_localctx, 48, MuonParser::RuleDiscard);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    match(MuonParser::UNDERSCORE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LArgListContext ------------------------------------------------------------------

MuonParser::LArgListContext::LArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MuonParser::LArgListContext::OPAREN() {
  return getToken(MuonParser::OPAREN, 0);
}

tree::TerminalNode* MuonParser::LArgListContext::CPAREN() {
  return getToken(MuonParser::CPAREN, 0);
}

std::vector<MuonParser::LvalueContext *> MuonParser::LArgListContext::lvalue() {
  return getRuleContexts<MuonParser::LvalueContext>();
}

MuonParser::LvalueContext* MuonParser::LArgListContext::lvalue(size_t i) {
  return getRuleContext<MuonParser::LvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::LArgListContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::LArgListContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}


size_t MuonParser::LArgListContext::getRuleIndex() const {
  return MuonParser::RuleLArgList;
}

antlrcpp::Any MuonParser::LArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitLArgList(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::LArgListContext* MuonParser::lArgList() {
  LArgListContext *_localctx = _tracker.createInstance<LArgListContext>(_ctx, getState());
  enterRule(_localctx, 50, MuonParser::RuleLArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    match(MuonParser::OPAREN);
    setState(438);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
      setState(430);
      lvalue();
      setState(435);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(431);
        match(MuonParser::COMMA);
        setState(432);
        lvalue();
        setState(437);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(440);
    match(MuonParser::CPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MuonParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return rvalueSempred(dynamic_cast<RvalueContext *>(context), predicateIndex);
    case 7: return invokeSempred(dynamic_cast<InvokeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MuonParser::rvalueSempred(RvalueContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

bool MuonParser::invokeSempred(InvokeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MuonParser::_decisionToDFA;
atn::PredictionContextCache MuonParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MuonParser::_atn;
std::vector<uint16_t> MuonParser::_serializedATN;

std::vector<std::string> MuonParser::_ruleNames = {
  "file", "control", "statement", "unitDeclaration", "rvalue", "atom", "literal", 
  "invoke", "matrix", "list", "scope", "rArgList", "type", "unit", "dimension", 
  "typeRValue", "typeMultiplyOperation", "typePowerOperation", "typeAtom", 
  "typeLiteral", "lvalue", "matrixDecomposition", "listDecomposition", "subset", 
  "discard", "lArgList"
};

std::vector<std::string> MuonParser::_literalNames = {
  "", "'val'", "'var'", "'drop'", "'fn'", "'if'", "'elseif'", "'else'", 
  "'for'", "'as'", "'at'", "'while'", "'loop'", "'dimension'", "'unity'", 
  "'struct'", "'class'", "'enum'", "'print'", "'or'", "'nor'", "'xor'", 
  "'and'", "'nand'", "'is'", "'isnt'", "'mod'", "'to'", "'not'", "", "", 
  "", "", "", "", "", "", "'null'", "'void'", "", "'='", "", "", "':'", 
  "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "'_'", "'-'", "'~'", 
  "'+'", "'<'", "'>'", "'<='", "'>='", "'!'", "'`'", "'@'", "'#'", "'$'", 
  "'%'", "'&'", "'.'", "'*'", "'.*'", "'/'", "'./'", "'^'", "'.^'", "", 
  "' '"
};

std::vector<std::string> MuonParser::_symbolicNames = {
  "", "VAL", "VAR", "DROP", "FN", "IF", "ELSEIF", "ELSE", "FOR", "AS", "AT", 
  "WHILE", "LOOP", "DIMENSION", "UNITY", "STRUCT", "CLASS", "ENUM", "PRINT", 
  "OR", "NOR", "XOR", "AND", "NAND", "IS", "ISNT", "MOD", "TO", "NOT", "SCIENTIFIC_FLOAT_LITERAL", 
  "IMAGINARY_SCIENTIFIC_FLOAT_LITERAL", "FLOAT_LITERAL", "IMAGINARY_FLOAT_LITERAL", 
  "INT_LITERAL", "IMAGINARY_INT_LITERAL", "STRING_LITERAL", "BOOL_LITERAL", 
  "NULL_LITERAL", "VOID_LITERAL", "NAME", "EQUAL", "NEWLINE", "SEMICOLON", 
  "COLON", "COMMA", "OPAREN", "CPAREN", "OBRACKET", "CBRACKET", "OBRACE", 
  "CBRACE", "UNDERSCORE", "DASH", "TILDE", "PLUS", "OHAIRPIN", "CHAIRPIN", 
  "OHAIRPINEQUAL", "CHAIRPINEQUAL", "BANG", "BACKTICK", "AT_SYMBOL", "HASH", 
  "DOLLAR", "PERCENT", "AMPERSAND", "DOT", "STAR", "DOTSTAR", "SLASH", "DOTSLASH", 
  "CARROT", "DOTCARROT", "BLOCK_COMMENT", "WHITESPACE"
};

dfa::Vocabulary MuonParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MuonParser::_tokenNames;

MuonParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x4c, 0x1bd, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3a, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x3d, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x4a, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4d, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x52, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x81, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 
    0x9c, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0x9d, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0xa2, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa5, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0xa9, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xad, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xb2, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0xb5, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb8, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0xbc, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xc2, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0xd0, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xed, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xf0, 
    0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xf8, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x103, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x109, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x111, 
    0xa, 0x9, 0x5, 0x9, 0x113, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x118, 0xa, 0x9, 0x7, 0x9, 0x11a, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
    0x11d, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x123, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x126, 0xb, 0xa, 0x5, 0xa, 0x128, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 
    0xb, 0x130, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x133, 0xb, 0xb, 0x5, 0xb, 
    0x135, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x13b, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x140, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x143, 0xb, 0xc, 0x5, 0xc, 0x145, 0xa, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x148, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x150, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x153, 
    0xb, 0xd, 0x5, 0xd, 0x155, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0x15b, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x16e, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x175, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x17d, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x186, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x18a, 0xa, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x18f, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x192, 0xb, 0x17, 0x3, 0x17, 0x5, 0x17, 0x195, 
    0xa, 0x17, 0x5, 0x17, 0x197, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x19d, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x7, 0x18, 0x1a2, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x1a5, 0xb, 0x18, 
    0x5, 0x18, 0x1a7, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x7, 0x1b, 0x1b4, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x1b7, 0xb, 
    0x1b, 0x5, 0x1b, 0x1b9, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x2, 0x4, 0xa, 0x10, 0x1c, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x2, 0x11, 0x3, 0x3, 0x2b, 0x2c, 
    0x3, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x2a, 0x2a, 0x36, 
    0x37, 0x3, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x45, 0x48, 0x4, 0x2, 0x36, 0x36, 
    0x38, 0x38, 0x3, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x18, 
    0x19, 0x3, 0x2, 0x15, 0x16, 0x5, 0x2, 0x1d, 0x1d, 0x3f, 0x3f, 0x43, 
    0x43, 0x4, 0x2, 0x2b, 0x2c, 0x2e, 0x2e, 0x4, 0x2, 0x45, 0x45, 0x47, 
    0x47, 0x5, 0x2, 0x1f, 0x1f, 0x21, 0x21, 0x23, 0x23, 0x2, 0x1fb, 0x2, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x80, 0x3, 0x2, 0x2, 0x2, 0x6, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xa, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xe, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x10, 0x112, 0x3, 0x2, 0x2, 0x2, 0x12, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x138, 0x3, 0x2, 0x2, 0x2, 0x18, 
    0x14b, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x15c, 
    0x3, 0x2, 0x2, 0x2, 0x1e, 0x160, 0x3, 0x2, 0x2, 0x2, 0x20, 0x166, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x24, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x28, 0x17e, 0x3, 0x2, 0x2, 
    0x2, 0x2a, 0x185, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x187, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x1ad, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x9, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x81, 0x5, 0x6, 0x4, 0x2, 0x3f, 0x40, 0x7, 0x7, 0x2, 0x2, 0x40, 
    0x41, 0x5, 0xa, 0x6, 0x2, 0x41, 0x42, 0x9, 0x3, 0x2, 0x2, 0x42, 0x4b, 
    0x5, 0x6, 0x4, 0x2, 0x43, 0x44, 0x9, 0x3, 0x2, 0x2, 0x44, 0x45, 0x7, 
    0x8, 0x2, 0x2, 0x45, 0x46, 0x5, 0xa, 0x6, 0x2, 0x46, 0x47, 0x9, 0x3, 
    0x2, 0x2, 0x47, 0x48, 0x5, 0x6, 0x4, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x43, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 
    0x9, 0x3, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x9, 0x2, 0x2, 0x50, 0x52, 0x5, 
    0x6, 0x4, 0x2, 0x51, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x81, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0xe, 0x2, 
    0x2, 0x54, 0x55, 0x9, 0x3, 0x2, 0x2, 0x55, 0x81, 0x5, 0x6, 0x4, 0x2, 
    0x56, 0x57, 0x7, 0xd, 0x2, 0x2, 0x57, 0x58, 0x5, 0xa, 0x6, 0x2, 0x58, 
    0x59, 0x9, 0x3, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x6, 0x4, 0x2, 0x5a, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xa, 0x2, 0x2, 0x5c, 0x5d, 0x5, 
    0xa, 0x6, 0x2, 0x5d, 0x5e, 0x9, 0x3, 0x2, 0x2, 0x5e, 0x5f, 0x5, 0x6, 
    0x4, 0x2, 0x5f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0xa, 0x2, 
    0x2, 0x61, 0x62, 0x5, 0xa, 0x6, 0x2, 0x62, 0x63, 0x7, 0xb, 0x2, 0x2, 
    0x63, 0x64, 0x5, 0x2a, 0x16, 0x2, 0x64, 0x65, 0x9, 0x3, 0x2, 0x2, 0x65, 
    0x66, 0x5, 0x6, 0x4, 0x2, 0x66, 0x81, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x7, 0xa, 0x2, 0x2, 0x68, 0x69, 0x5, 0xa, 0x6, 0x2, 0x69, 0x6a, 0x7, 
    0xc, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0x2a, 0x16, 0x2, 0x6b, 0x6c, 0x9, 0x3, 
    0x2, 0x2, 0x6c, 0x6d, 0x5, 0x6, 0x4, 0x2, 0x6d, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x7, 0xa, 0x2, 0x2, 0x6f, 0x70, 0x5, 0xa, 0x6, 0x2, 
    0x70, 0x71, 0x7, 0xb, 0x2, 0x2, 0x71, 0x72, 0x5, 0x2a, 0x16, 0x2, 0x72, 
    0x73, 0x7, 0xc, 0x2, 0x2, 0x73, 0x74, 0x5, 0x2a, 0x16, 0x2, 0x74, 0x75, 
    0x9, 0x3, 0x2, 0x2, 0x75, 0x76, 0x5, 0x6, 0x4, 0x2, 0x76, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0xa, 0x2, 0x2, 0x78, 0x79, 0x5, 0xa, 
    0x6, 0x2, 0x79, 0x7a, 0x7, 0xc, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x2a, 0x16, 
    0x2, 0x7b, 0x7c, 0x7, 0xb, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x2a, 0x16, 0x2, 
    0x7d, 0x7e, 0x9, 0x3, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x6, 0x4, 0x2, 0x7f, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x53, 0x3, 0x2, 0x2, 0x2, 0x80, 0x56, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x67, 0x3, 0x2, 0x2, 0x2, 0x80, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x77, 0x3, 0x2, 0x2, 0x2, 0x81, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0xbc, 0x5, 0xa, 0x6, 0x2, 0x83, 0x84, 0x5, 0x2a, 0x16, 0x2, 0x84, 
    0x85, 0x7, 0x2a, 0x2, 0x2, 0x85, 0x86, 0x5, 0xa, 0x6, 0x2, 0x86, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x9, 0x4, 0x2, 0x2, 0x88, 0xbc, 0x5, 
    0x2a, 0x16, 0x2, 0x89, 0x8a, 0x9, 0x4, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x2a, 
    0x16, 0x2, 0x8b, 0x8c, 0x7, 0x2a, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0xa, 0x6, 
    0x2, 0x8d, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x5, 0x2, 0x2, 
    0x8f, 0xbc, 0x5, 0x2a, 0x16, 0x2, 0x90, 0x91, 0x7, 0x6, 0x2, 0x2, 0x91, 
    0x92, 0x7, 0x29, 0x2, 0x2, 0x92, 0x93, 0x5, 0x34, 0x1b, 0x2, 0x93, 0x94, 
    0x7, 0x2a, 0x2, 0x2, 0x94, 0x95, 0x7, 0x3a, 0x2, 0x2, 0x95, 0x96, 0x5, 
    0xa, 0x6, 0x2, 0x96, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x14, 
    0x2, 0x2, 0x98, 0xbc, 0x5, 0xa, 0x6, 0x2, 0x99, 0x9b, 0x7, 0x39, 0x2, 
    0x2, 0x9a, 0x9c, 0x9, 0x5, 0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 
    0x5, 0xa, 0x6, 0x2, 0xa0, 0xa2, 0x7, 0x28, 0x2, 0x2, 0xa1, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa5, 0x7, 0x10, 0x2, 
    0x2, 0xa4, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x7, 0xf, 0x2, 0x2, 0xa7, 
    0xa9, 0x7, 0x29, 0x2, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xac, 0x7, 
    0x31, 0x2, 0x2, 0xab, 0xad, 0x9, 0x3, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0xb3, 0x5, 0x8, 0x5, 0x2, 0xaf, 0xb0, 0x9, 0x3, 0x2, 0x2, 
    0xb0, 0xb2, 0x5, 0x8, 0x5, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb8, 0x9, 0x3, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xba, 0x7, 0x32, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0x82, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x83, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x89, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0x90, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0x99, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0x7, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc2, 0x7, 0x29, 0x2, 
    0x2, 0xbe, 0xbf, 0x7, 0x29, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x2a, 0x2, 0x2, 
    0xc0, 0xc2, 0x5, 0xa, 0x6, 0x2, 0xc1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x9, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 
    0x8, 0x6, 0x1, 0x2, 0xc4, 0xc5, 0x7, 0x38, 0x2, 0x2, 0xc5, 0xd0, 0x5, 
    0xa, 0x6, 0x11, 0xc6, 0xc7, 0x7, 0x36, 0x2, 0x2, 0xc7, 0xd0, 0x5, 0xa, 
    0x6, 0x10, 0xc8, 0xc9, 0x7, 0x41, 0x2, 0x2, 0xc9, 0xd0, 0x5, 0xa, 0x6, 
    0xf, 0xca, 0xcb, 0x7, 0x40, 0x2, 0x2, 0xcb, 0xd0, 0x5, 0xa, 0x6, 0xe, 
    0xcc, 0xcd, 0x7, 0x1e, 0x2, 0x2, 0xcd, 0xd0, 0x5, 0xa, 0x6, 0xd, 0xce, 
    0xd0, 0x5, 0xc, 0x7, 0x2, 0xcf, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0xc, 0xb, 0x2, 
    0x2, 0xd2, 0xd3, 0x9, 0x6, 0x2, 0x2, 0xd3, 0xed, 0x5, 0xa, 0x6, 0xc, 
    0xd4, 0xd5, 0xc, 0xa, 0x2, 0x2, 0xd5, 0xd6, 0x9, 0x7, 0x2, 0x2, 0xd6, 
    0xed, 0x5, 0xa, 0x6, 0xb, 0xd7, 0xd8, 0xc, 0x9, 0x2, 0x2, 0xd8, 0xd9, 
    0x9, 0x8, 0x2, 0x2, 0xd9, 0xed, 0x5, 0xa, 0x6, 0xa, 0xda, 0xdb, 0xc, 
    0x8, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x9, 0x2, 0x2, 0xdc, 0xed, 0x5, 0xa, 
    0x6, 0x9, 0xdd, 0xde, 0xc, 0x7, 0x2, 0x2, 0xde, 0xdf, 0x9, 0xa, 0x2, 
    0x2, 0xdf, 0xed, 0x5, 0xa, 0x6, 0x8, 0xe0, 0xe1, 0xc, 0x6, 0x2, 0x2, 
    0xe1, 0xe2, 0x9, 0xb, 0x2, 0x2, 0xe2, 0xed, 0x5, 0xa, 0x6, 0x7, 0xe3, 
    0xe4, 0xc, 0x5, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x17, 0x2, 0x2, 0xe5, 0xed, 
    0x5, 0xa, 0x6, 0x6, 0xe6, 0xe7, 0xc, 0x4, 0x2, 0x2, 0xe7, 0xe8, 0x9, 
    0xc, 0x2, 0x2, 0xe8, 0xed, 0x5, 0xa, 0x6, 0x5, 0xe9, 0xea, 0xc, 0xc, 
    0x2, 0x2, 0xea, 0xeb, 0x9, 0xd, 0x2, 0x2, 0xeb, 0xed, 0x5, 0x1a, 0xe, 
    0x2, 0xec, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xec, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xec, 0xda, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe9, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf8, 0x5, 0xe, 0x8, 0x2, 
    0xf2, 0xf8, 0x7, 0x29, 0x2, 0x2, 0xf3, 0xf8, 0x5, 0x10, 0x9, 0x2, 0xf4, 
    0xf8, 0x5, 0x12, 0xa, 0x2, 0xf5, 0xf8, 0x5, 0x14, 0xb, 0x2, 0xf6, 0xf8, 
    0x5, 0x16, 0xc, 0x2, 0xf7, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf4, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x103, 0x7, 0x1f, 0x2, 0x2, 
    0xfa, 0x103, 0x7, 0x20, 0x2, 0x2, 0xfb, 0x103, 0x7, 0x21, 0x2, 0x2, 
    0xfc, 0x103, 0x7, 0x22, 0x2, 0x2, 0xfd, 0x103, 0x7, 0x23, 0x2, 0x2, 
    0xfe, 0x103, 0x7, 0x24, 0x2, 0x2, 0xff, 0x103, 0x7, 0x25, 0x2, 0x2, 
    0x100, 0x103, 0x7, 0x26, 0x2, 0x2, 0x101, 0x103, 0x7, 0x27, 0x2, 0x2, 
    0x102, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x102, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0x102, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x102, 0xfd, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x102, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0xf, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x8, 0x9, 
    0x1, 0x2, 0x105, 0x108, 0x7, 0x29, 0x2, 0x2, 0x106, 0x109, 0x5, 0x14, 
    0xb, 0x2, 0x107, 0x109, 0x5, 0x12, 0xa, 0x2, 0x108, 0x106, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x10b, 0x5, 0x14, 0xb, 0x2, 0x10b, 0x10c, 0x5, 0x14, 
    0xb, 0x2, 0x10c, 0x113, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x5, 0x12, 
    0xa, 0x2, 0x10e, 0x111, 0x5, 0x14, 0xb, 0x2, 0x10f, 0x111, 0x5, 0x12, 
    0xa, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10f, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x113, 0x3, 0x2, 0x2, 0x2, 0x112, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0xc, 0x5, 
    0x2, 0x2, 0x115, 0x118, 0x5, 0x14, 0xb, 0x2, 0x116, 0x118, 0x5, 0x12, 
    0xa, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x118, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x119, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x127, 0x7, 0x2f, 0x2, 
    0x2, 0x11f, 0x124, 0x5, 0xa, 0x6, 0x2, 0x120, 0x121, 0x9, 0xe, 0x2, 
    0x2, 0x121, 0x123, 0x5, 0xa, 0x6, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x123, 0x126, 0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x12a, 0x7, 0x30, 0x2, 0x2, 0x12a, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x12b, 0x134, 0x7, 0x31, 0x2, 0x2, 0x12c, 0x131, 0x5, 0xa, 0x6, 
    0x2, 0x12d, 0x12e, 0x7, 0x2e, 0x2, 0x2, 0x12e, 0x130, 0x5, 0xa, 0x6, 
    0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x135, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 
    0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x32, 0x2, 
    0x2, 0x137, 0x15, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13a, 0x7, 0x33, 0x2, 
    0x2, 0x139, 0x13b, 0x9, 0x3, 0x2, 0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x13c, 0x141, 0x5, 0x4, 0x3, 0x2, 0x13d, 0x13e, 0x9, 0x3, 0x2, 
    0x2, 0x13e, 0x140, 0x5, 0x4, 0x3, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x13c, 0x3, 0x2, 0x2, 
    0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x147, 0x3, 0x2, 0x2, 
    0x2, 0x146, 0x148, 0x9, 0x3, 0x2, 0x2, 0x147, 0x146, 0x3, 0x2, 0x2, 
    0x2, 0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x149, 0x14a, 0x7, 0x34, 0x2, 0x2, 0x14a, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x154, 0x7, 0x2f, 0x2, 0x2, 0x14c, 0x151, 0x5, 0xa, 0x6, 
    0x2, 0x14d, 0x14e, 0x7, 0x2e, 0x2, 0x2, 0x14e, 0x150, 0x5, 0xa, 0x6, 
    0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 0x153, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x3, 0x2, 0x2, 
    0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x154, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 
    0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x30, 0x2, 
    0x2, 0x157, 0x19, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x5, 0x1c, 0xf, 
    0x2, 0x159, 0x15b, 0x5, 0x1e, 0x10, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x15c, 0x15d, 0x7, 0x31, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x20, 0x11, 0x2, 
    0x15e, 0x15f, 0x7, 0x32, 0x2, 0x2, 0x15f, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x161, 0x7, 0x31, 0x2, 0x2, 0x161, 0x162, 0x7, 0x31, 0x2, 0x2, 
    0x162, 0x163, 0x5, 0x20, 0x11, 0x2, 0x163, 0x164, 0x7, 0x32, 0x2, 0x2, 
    0x164, 0x165, 0x7, 0x32, 0x2, 0x2, 0x165, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x166, 0x167, 0x5, 0x22, 0x12, 0x2, 0x167, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x168, 0x16e, 0x5, 0x24, 0x13, 0x2, 0x169, 0x16a, 0x5, 0x24, 0x13, 0x2, 
    0x16a, 0x16b, 0x9, 0xf, 0x2, 0x2, 0x16b, 0x16c, 0x5, 0x22, 0x12, 0x2, 
    0x16c, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x168, 0x3, 0x2, 0x2, 0x2, 
    0x16d, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x16f, 
    0x175, 0x5, 0x26, 0x14, 0x2, 0x170, 0x171, 0x5, 0x26, 0x14, 0x2, 0x171, 
    0x172, 0x7, 0x49, 0x2, 0x2, 0x172, 0x173, 0x5, 0x24, 0x13, 0x2, 0x173, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x174, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x174, 
    0x170, 0x3, 0x2, 0x2, 0x2, 0x175, 0x25, 0x3, 0x2, 0x2, 0x2, 0x176, 0x17d, 
    0x5, 0x28, 0x15, 0x2, 0x177, 0x17d, 0x7, 0x29, 0x2, 0x2, 0x178, 0x179, 
    0x7, 0x2f, 0x2, 0x2, 0x179, 0x17a, 0x5, 0x20, 0x11, 0x2, 0x17a, 0x17b, 
    0x7, 0x30, 0x2, 0x2, 0x17b, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x176, 
    0x3, 0x2, 0x2, 0x2, 0x17c, 0x177, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x178, 
    0x3, 0x2, 0x2, 0x2, 0x17d, 0x27, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x9, 
    0x10, 0x2, 0x2, 0x17f, 0x29, 0x3, 0x2, 0x2, 0x2, 0x180, 0x186, 0x7, 
    0x29, 0x2, 0x2, 0x181, 0x186, 0x5, 0x2c, 0x17, 0x2, 0x182, 0x186, 0x5, 
    0x2e, 0x18, 0x2, 0x183, 0x186, 0x5, 0x30, 0x19, 0x2, 0x184, 0x186, 0x5, 
    0x32, 0x1a, 0x2, 0x185, 0x180, 0x3, 0x2, 0x2, 0x2, 0x185, 0x181, 0x3, 
    0x2, 0x2, 0x2, 0x185, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x183, 0x3, 
    0x2, 0x2, 0x2, 0x185, 0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x189, 0x7, 0x2f, 0x2, 0x2, 0x188, 0x18a, 0x7, 0x2b, 
    0x2, 0x2, 0x189, 0x188, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x196, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x190, 0x5, 0x2a, 
    0x16, 0x2, 0x18c, 0x18d, 0x9, 0xe, 0x2, 0x2, 0x18d, 0x18f, 0x5, 0x2a, 
    0x16, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x195, 0x7, 0x2b, 0x2, 0x2, 0x194, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x197, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 
    0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x7, 0x30, 
    0x2, 0x2, 0x199, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19c, 0x7, 0x31, 
    0x2, 0x2, 0x19b, 0x19d, 0x7, 0x2b, 0x2, 0x2, 0x19c, 0x19b, 0x3, 0x2, 
    0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a6, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x1a3, 0x5, 0x2a, 0x16, 0x2, 0x19f, 0x1a0, 0x7, 0x2e, 
    0x2, 0x2, 0x1a0, 0x1a2, 0x5, 0x2a, 0x16, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 
    0x2, 0x2, 0x1a2, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a1, 0x3, 0x2, 
    0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a7, 0x3, 0x2, 
    0x2, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x19e, 0x3, 0x2, 
    0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 
    0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x32, 0x2, 0x2, 0x1a9, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0x29, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x34, 
    0x1b, 0x2, 0x1ac, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x35, 
    0x2, 0x2, 0x1ae, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b8, 0x7, 0x2f, 
    0x2, 0x2, 0x1b0, 0x1b5, 0x5, 0x2a, 0x16, 0x2, 0x1b1, 0x1b2, 0x7, 0x2e, 
    0x2, 0x2, 0x1b2, 0x1b4, 0x5, 0x2a, 0x16, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 
    0x2, 0x2, 0x1b4, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 0x3, 0x2, 
    0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b0, 0x3, 0x2, 
    0x2, 0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 
    0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x30, 0x2, 0x2, 0x1bb, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x3b, 0x4b, 0x51, 0x80, 0x9d, 0xa1, 0xa4, 0xa8, 0xac, 
    0xb3, 0xb7, 0xbb, 0xc1, 0xcf, 0xec, 0xee, 0xf7, 0x102, 0x108, 0x110, 
    0x112, 0x117, 0x11b, 0x124, 0x127, 0x131, 0x134, 0x13a, 0x141, 0x144, 
    0x147, 0x151, 0x154, 0x15a, 0x16d, 0x174, 0x17c, 0x185, 0x189, 0x190, 
    0x194, 0x196, 0x19c, 0x1a3, 0x1a6, 0x1b5, 0x1b8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MuonParser::Initializer MuonParser::_init;
