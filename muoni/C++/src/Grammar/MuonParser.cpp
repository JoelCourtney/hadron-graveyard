
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
    setState(49);
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
      setState(44);
      control();
      setState(45);
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
      setState(51);
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
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::StatementControlContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(52);
      statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::IfSeriesContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(53);
      match(MuonParser::IF);
      setState(54);
      rvalue(0);
      setState(55);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(56);
      statement();
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(57);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(58);
          match(MuonParser::ELSEIF);
          setState(59);
          rvalue(0);
          setState(60);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(61);
          statement(); 
        }
        setState(67);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(71);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
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
        match(MuonParser::ELSE);
        setState(70);
        statement();
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::LoopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(73);
      match(MuonParser::LOOP);
      setState(74);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(75);
      statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(76);
      match(MuonParser::WHILE);
      setState(77);
      rvalue(0);
      setState(78);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(79);
      statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForLoopContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(81);
      match(MuonParser::FOR);
      setState(82);
      rvalue(0);
      setState(83);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(84);
      statement();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsLoopContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(86);
      match(MuonParser::FOR);
      setState(87);
      rvalue(0);
      setState(88);
      match(MuonParser::AS);
      setState(89);
      lvalue();
      setState(90);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(91);
      statement();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(93);
      match(MuonParser::FOR);
      setState(94);
      rvalue(0);
      setState(95);
      match(MuonParser::AT);
      setState(96);
      lvalue();
      setState(97);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(98);
      statement();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(100);
      match(MuonParser::FOR);
      setState(101);
      rvalue(0);
      setState(102);
      match(MuonParser::AS);
      setState(103);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->as = lvalue();
      setState(104);
      match(MuonParser::AT);
      setState(105);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->at = lvalue();
      setState(106);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(107);
      statement();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(109);
      match(MuonParser::FOR);
      setState(110);
      rvalue(0);
      setState(111);
      match(MuonParser::AT);
      setState(112);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->at = lvalue();
      setState(113);
      match(MuonParser::AS);
      setState(114);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->as = lvalue();
      setState(115);
      _la = _input->LA(1);
      if (!(_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(116);
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
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::RValueStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(120);
      rvalue(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(121);
      lvalue();
      setState(122);
      match(MuonParser::EQUAL);
      setState(123);
      rvalue(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(125);
      _la = _input->LA(1);
      if (!(_la == MuonParser::VAL

      || _la == MuonParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(126);
      lvalue();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareAssignContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(127);
      _la = _input->LA(1);
      if (!(_la == MuonParser::VAL

      || _la == MuonParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(128);
      lvalue();
      setState(129);
      match(MuonParser::EQUAL);
      setState(130);
      rvalue(0);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DropNameContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(132);
      match(MuonParser::DROP);
      setState(133);
      lvalue();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::FunctionDeclareContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(134);
      match(MuonParser::FN);
      setState(135);
      match(MuonParser::NAME);
      setState(136);
      lArgList();
      setState(137);
      match(MuonParser::EQUAL);
      setState(138);
      match(MuonParser::CHAIRPIN);
      setState(139);
      rvalue(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::PrintContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(141);
      match(MuonParser::PRINT);
      setState(142);
      rvalue(0);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::BreakSnakeContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(143);
      match(MuonParser::OHAIRPIN);
      setState(145); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(144);
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
        setState(147); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(151);
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
          setState(149);
          rvalue(0);
          break;
        }

        case MuonParser::VOID_LITERAL: {
          setState(150);
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
      setState(154);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::UNITY) {
        setState(153);
        match(MuonParser::UNITY);
      }
      setState(156);
      match(MuonParser::DIMENSION);
      setState(158);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NAME) {
        setState(157);
        match(MuonParser::NAME);
      }
      setState(160);
      match(MuonParser::OBRACKET);
      setState(162);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(161);
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
      setState(164);
      unitDeclaration();
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(165);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(166);
          unitDeclaration(); 
        }
        setState(171);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(173);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(172);
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
      setState(175);
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
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(179);
      match(MuonParser::NAME);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(180);
      match(MuonParser::NAME);
      setState(181);
      match(MuonParser::EQUAL);
      setState(182);
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
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::PLUS: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(186);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::PLUS);
        setState(187);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(15);
        break;
      }

      case MuonParser::DASH: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(188);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::DASH);
        setState(189);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(14);
        break;
      }

      case MuonParser::DOLLAR: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(190);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::DOLLAR);
        setState(191);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(13);
        break;
      }

      case MuonParser::HASH: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(192);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::HASH);
        setState(193);
        dynamic_cast<UnaryOperationContext *>(_localctx)->r = rvalue(12);
        break;
      }

      case MuonParser::NOT: {
        _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(194);
        dynamic_cast<UnaryOperationContext *>(_localctx)->uop = match(MuonParser::NOT);
        setState(195);
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
        setState(196);
        dynamic_cast<AtomRValueContext *>(_localctx)->a = atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(228);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(226);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(199);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(200);
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
          setState(201);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(202);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(203);
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
          setState(204);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(205);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(206);
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
          setState(207);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(208);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(209);
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
          setState(210);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(211);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(212);
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
          setState(213);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(6);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(214);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(215);
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
          setState(216);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(5);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(217);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(218);
          dynamic_cast<BinaryOperationContext *>(_localctx)->bop = match(MuonParser::XOR);
          setState(219);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(4);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(220);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(221);
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
          setState(222);
          dynamic_cast<BinaryOperationContext *>(_localctx)->r2 = rvalue(3);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ConvertOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(223);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(224);
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
          setState(225);
          dynamic_cast<ConvertOperationContext *>(_localctx)->t = type();
          break;
        }

        } 
      }
      setState(230);
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
    setState(237);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::LiteralAtomContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(231);
      literal();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::NameAtomContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(232);
      match(MuonParser::NAME);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::InvokeAtomContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(233);
      invoke(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::MatrixAtomContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(234);
      matrix();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::ListAtomContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(235);
      list();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::ScopeAtomContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(236);
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
    setState(248);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::SCIENTIFIC_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::FloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(239);
        match(MuonParser::SCIENTIFIC_FLOAT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryFloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(240);
        match(MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL);
        break;
      }

      case MuonParser::FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::FloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(241);
        match(MuonParser::FLOAT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryFloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(242);
        match(MuonParser::IMAGINARY_FLOAT_LITERAL);
        break;
      }

      case MuonParser::INT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::IntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(243);
        match(MuonParser::INT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_INT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryIntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(244);
        match(MuonParser::IMAGINARY_INT_LITERAL);
        break;
      }

      case MuonParser::STRING_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::StringLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(245);
        match(MuonParser::STRING_LITERAL);
        break;
      }

      case MuonParser::BOOL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::BoolLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(246);
        match(MuonParser::BOOL_LITERAL);
        break;
      }

      case MuonParser::NULL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::NullLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(247);
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
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::NAME: {
        setState(251);
        match(MuonParser::NAME);
        setState(254);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(252);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(253);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case MuonParser::OBRACKET: {
        setState(256);
        list();
        setState(257);
        list();
        break;
      }

      case MuonParser::OPAREN: {
        setState(259);
        matrix();
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

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InvokeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInvoke);
        setState(266);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(269);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(267);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(268);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(275);
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
    setState(276);
    match(MuonParser::OPAREN);
    setState(285);
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
      setState(277);
      rvalue(0);
      setState(282);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MuonParser::NEWLINE)
        | (1ULL << MuonParser::SEMICOLON)
        | (1ULL << MuonParser::COMMA))) != 0)) {
        setState(278);
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
        setState(279);
        rvalue(0);
        setState(284);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(287);
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
    setState(289);
    match(MuonParser::OBRACKET);
    setState(298);
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
      setState(290);
      rvalue(0);
      setState(295);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(291);
        match(MuonParser::COMMA);
        setState(292);
        rvalue(0);
        setState(297);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(300);
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
    setState(302);
    match(MuonParser::OBRACE);
    setState(304);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(303);
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
    setState(314);
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
      setState(306);
      control();
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(307);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(308);
          control(); 
        }
        setState(313);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
    }
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MuonParser::NEWLINE

    || _la == MuonParser::SEMICOLON) {
      setState(316);
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
    setState(319);
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
    setState(321);
    match(MuonParser::OPAREN);
    setState(330);
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
      setState(322);
      rvalue(0);
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(323);
        match(MuonParser::COMMA);
        setState(324);
        rvalue(0);
        setState(329);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(332);
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
    setState(336);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(334);
      unit();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(335);
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
    setState(338);
    match(MuonParser::OBRACKET);
    setState(339);
    typeRValue();
    setState(340);
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
    setState(342);
    match(MuonParser::OBRACKET);
    setState(343);
    match(MuonParser::OBRACKET);
    setState(344);
    typeRValue();
    setState(345);
    match(MuonParser::CBRACKET);
    setState(346);
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
    setState(348);
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
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(350);
      typePowerOperation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(351);
      typePowerOperation();
      setState(352);
      _la = _input->LA(1);
      if (!(_la == MuonParser::STAR

      || _la == MuonParser::SLASH)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(353);
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
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      typeAtom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      typeAtom();
      setState(359);
      match(MuonParser::CARROT);
      setState(360);
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
    setState(370);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::SCIENTIFIC_FLOAT_LITERAL:
      case MuonParser::FLOAT_LITERAL:
      case MuonParser::INT_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(364);
        typeLiteral();
        break;
      }

      case MuonParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(365);
        match(MuonParser::NAME);
        break;
      }

      case MuonParser::OPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(366);
        match(MuonParser::OPAREN);
        setState(367);
        typeRValue();
        setState(368);
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
    setState(372);
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


size_t MuonParser::LvalueContext::getRuleIndex() const {
  return MuonParser::RuleLvalue;
}

void MuonParser::LvalueContext::copyFrom(LvalueContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ListDecompositionLValueContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ListDecompositionLValueContext::OBRACKET() {
  return getToken(MuonParser::OBRACKET, 0);
}

tree::TerminalNode* MuonParser::ListDecompositionLValueContext::CBRACKET() {
  return getToken(MuonParser::CBRACKET, 0);
}

tree::TerminalNode* MuonParser::ListDecompositionLValueContext::NEWLINE() {
  return getToken(MuonParser::NEWLINE, 0);
}

std::vector<MuonParser::LvalueContext *> MuonParser::ListDecompositionLValueContext::lvalue() {
  return getRuleContexts<MuonParser::LvalueContext>();
}

MuonParser::LvalueContext* MuonParser::ListDecompositionLValueContext::lvalue(size_t i) {
  return getRuleContext<MuonParser::LvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::ListDecompositionLValueContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::ListDecompositionLValueContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}

MuonParser::ListDecompositionLValueContext::ListDecompositionLValueContext(LvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ListDecompositionLValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitListDecompositionLValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatrixDecompositionLValueContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::MatrixDecompositionLValueContext::OPAREN() {
  return getToken(MuonParser::OPAREN, 0);
}

tree::TerminalNode* MuonParser::MatrixDecompositionLValueContext::CPAREN() {
  return getToken(MuonParser::CPAREN, 0);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixDecompositionLValueContext::NEWLINE() {
  return getTokens(MuonParser::NEWLINE);
}

tree::TerminalNode* MuonParser::MatrixDecompositionLValueContext::NEWLINE(size_t i) {
  return getToken(MuonParser::NEWLINE, i);
}

std::vector<MuonParser::LvalueContext *> MuonParser::MatrixDecompositionLValueContext::lvalue() {
  return getRuleContexts<MuonParser::LvalueContext>();
}

MuonParser::LvalueContext* MuonParser::MatrixDecompositionLValueContext::lvalue(size_t i) {
  return getRuleContext<MuonParser::LvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixDecompositionLValueContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::MatrixDecompositionLValueContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixDecompositionLValueContext::SEMICOLON() {
  return getTokens(MuonParser::SEMICOLON);
}

tree::TerminalNode* MuonParser::MatrixDecompositionLValueContext::SEMICOLON(size_t i) {
  return getToken(MuonParser::SEMICOLON, i);
}

MuonParser::MatrixDecompositionLValueContext::MatrixDecompositionLValueContext(LvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::MatrixDecompositionLValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitMatrixDecompositionLValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DiscardLValueContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::DiscardLValueContext::UNDERSCORE() {
  return getToken(MuonParser::UNDERSCORE, 0);
}

MuonParser::DiscardLValueContext::DiscardLValueContext(LvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::DiscardLValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitDiscardLValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubsetLValueContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::SubsetLValueContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

MuonParser::LArgListContext* MuonParser::SubsetLValueContext::lArgList() {
  return getRuleContext<MuonParser::LArgListContext>(0);
}

MuonParser::SubsetLValueContext::SubsetLValueContext(LvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::SubsetLValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitSubsetLValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NameLValueContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::NameLValueContext::NAME() {
  return getToken(MuonParser::NAME, 0);
}

MuonParser::NameLValueContext::NameLValueContext(LvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::NameLValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitNameLValue(this);
  else
    return visitor->visitChildren(this);
}
MuonParser::LvalueContext* MuonParser::lvalue() {
  LvalueContext *_localctx = _tracker.createInstance<LvalueContext>(_ctx, getState());
  enterRule(_localctx, 40, MuonParser::RuleLvalue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(411);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::NameLValueContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(374);
      match(MuonParser::NAME);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::MatrixDecompositionLValueContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(375);
      match(MuonParser::OPAREN);
      setState(377);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE) {
        setState(376);
        match(MuonParser::NEWLINE);
      }
      setState(390);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MuonParser::NAME)
        | (1ULL << MuonParser::OPAREN)
        | (1ULL << MuonParser::OBRACKET)
        | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
        setState(379);
        lvalue();
        setState(384);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(380);
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
            setState(381);
            lvalue(); 
          }
          setState(386);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
        }
        setState(388);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MuonParser::NEWLINE) {
          setState(387);
          match(MuonParser::NEWLINE);
        }
      }
      setState(392);
      match(MuonParser::CPAREN);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::ListDecompositionLValueContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(393);
      match(MuonParser::OBRACKET);
      setState(395);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE) {
        setState(394);
        match(MuonParser::NEWLINE);
      }
      setState(405);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MuonParser::NAME)
        | (1ULL << MuonParser::OPAREN)
        | (1ULL << MuonParser::OBRACKET)
        | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
        setState(397);
        lvalue();
        setState(402);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MuonParser::COMMA) {
          setState(398);
          match(MuonParser::COMMA);
          setState(399);
          lvalue();
          setState(404);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(407);
      match(MuonParser::CBRACKET);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::SubsetLValueContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(408);
      match(MuonParser::NAME);
      setState(409);
      lArgList();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::DiscardLValueContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(410);
      match(MuonParser::UNDERSCORE);
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
  enterRule(_localctx, 42, MuonParser::RuleLArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    match(MuonParser::OPAREN);
    setState(422);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
      setState(414);
      lvalue();
      setState(419);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(415);
        match(MuonParser::COMMA);
        setState(416);
        lvalue();
        setState(421);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(424);
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
  "typeLiteral", "lvalue", "lArgList"
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
    0x3, 0x4c, 0x1ad, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 0xb, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x42, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x45, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x4a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x79, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x94, 0xa, 0x4, 
    0xd, 0x4, 0xe, 0x4, 0x95, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x9a, 0xa, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x9d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa1, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa5, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0xaa, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xad, 0xb, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0xb0, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0xb4, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xba, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0xc8, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0xe5, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xe8, 0xb, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xf0, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xfb, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x101, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x109, 0xa, 0x9, 0x5, 
    0x9, 0x10b, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x110, 
    0xa, 0x9, 0x7, 0x9, 0x112, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x115, 0xb, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x11b, 0xa, 0xa, 
    0xc, 0xa, 0xe, 0xa, 0x11e, 0xb, 0xa, 0x5, 0xa, 0x120, 0xa, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x128, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x12b, 0xb, 0xb, 0x5, 0xb, 0x12d, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x133, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x138, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x13b, 0xb, 0xc, 0x5, 0xc, 0x13d, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x140, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0x148, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x14b, 0xb, 0xd, 
    0x5, 0xd, 0x14d, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x153, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x166, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x16d, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x175, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x17c, 0xa, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x181, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
    0x184, 0xb, 0x16, 0x3, 0x16, 0x5, 0x16, 0x187, 0xa, 0x16, 0x5, 0x16, 
    0x189, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x18e, 
    0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x193, 0xa, 0x16, 
    0xc, 0x16, 0xe, 0x16, 0x196, 0xb, 0x16, 0x5, 0x16, 0x198, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x19e, 0xa, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x1a4, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x1a7, 0xb, 0x17, 0x5, 0x17, 0x1a9, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x2, 0x4, 0xa, 0x10, 0x18, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 0x11, 0x3, 0x3, 0x2b, 
    0x2c, 0x3, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x2a, 0x2a, 
    0x36, 0x37, 0x3, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x45, 0x48, 0x4, 0x2, 0x36, 
    0x36, 0x38, 0x38, 0x3, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 
    0x18, 0x19, 0x3, 0x2, 0x15, 0x16, 0x5, 0x2, 0x1d, 0x1d, 0x3f, 0x3f, 
    0x43, 0x43, 0x4, 0x2, 0x2b, 0x2c, 0x2e, 0x2e, 0x4, 0x2, 0x45, 0x45, 
    0x47, 0x47, 0x5, 0x2, 0x1f, 0x1f, 0x21, 0x21, 0x23, 0x23, 0x2, 0x1ef, 
    0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x78, 0x3, 0x2, 0x2, 0x2, 0x6, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xef, 0x3, 0x2, 0x2, 0x2, 0xe, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x12, 0x116, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x16, 0x130, 0x3, 0x2, 0x2, 0x2, 0x18, 0x143, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x152, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x154, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x158, 0x3, 0x2, 0x2, 0x2, 0x20, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x165, 0x3, 0x2, 0x2, 0x2, 0x24, 0x16c, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x174, 0x3, 0x2, 0x2, 0x2, 0x28, 0x176, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2f, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x30, 0x9, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x3, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x79, 0x5, 0x6, 0x4, 0x2, 0x37, 0x38, 0x7, 0x7, 0x2, 0x2, 
    0x38, 0x39, 0x5, 0xa, 0x6, 0x2, 0x39, 0x3a, 0x9, 0x3, 0x2, 0x2, 0x3a, 
    0x43, 0x5, 0x6, 0x4, 0x2, 0x3b, 0x3c, 0x9, 0x3, 0x2, 0x2, 0x3c, 0x3d, 
    0x7, 0x8, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0xa, 0x6, 0x2, 0x3e, 0x3f, 0x9, 
    0x3, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x6, 0x4, 0x2, 0x40, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x49, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x9, 0x3, 0x2, 0x2, 0x47, 0x48, 0x7, 0x9, 0x2, 0x2, 0x48, 0x4a, 
    0x5, 0x6, 0x4, 0x2, 0x49, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xe, 
    0x2, 0x2, 0x4c, 0x4d, 0x9, 0x3, 0x2, 0x2, 0x4d, 0x79, 0x5, 0x6, 0x4, 
    0x2, 0x4e, 0x4f, 0x7, 0xd, 0x2, 0x2, 0x4f, 0x50, 0x5, 0xa, 0x6, 0x2, 
    0x50, 0x51, 0x9, 0x3, 0x2, 0x2, 0x51, 0x52, 0x5, 0x6, 0x4, 0x2, 0x52, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0xa, 0x2, 0x2, 0x54, 0x55, 
    0x5, 0xa, 0x6, 0x2, 0x55, 0x56, 0x9, 0x3, 0x2, 0x2, 0x56, 0x57, 0x5, 
    0x6, 0x4, 0x2, 0x57, 0x79, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0xa, 
    0x2, 0x2, 0x59, 0x5a, 0x5, 0xa, 0x6, 0x2, 0x5a, 0x5b, 0x7, 0xb, 0x2, 
    0x2, 0x5b, 0x5c, 0x5, 0x2a, 0x16, 0x2, 0x5c, 0x5d, 0x9, 0x3, 0x2, 0x2, 
    0x5d, 0x5e, 0x5, 0x6, 0x4, 0x2, 0x5e, 0x79, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x60, 0x7, 0xa, 0x2, 0x2, 0x60, 0x61, 0x5, 0xa, 0x6, 0x2, 0x61, 0x62, 
    0x7, 0xc, 0x2, 0x2, 0x62, 0x63, 0x5, 0x2a, 0x16, 0x2, 0x63, 0x64, 0x9, 
    0x3, 0x2, 0x2, 0x64, 0x65, 0x5, 0x6, 0x4, 0x2, 0x65, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x7, 0xa, 0x2, 0x2, 0x67, 0x68, 0x5, 0xa, 0x6, 
    0x2, 0x68, 0x69, 0x7, 0xb, 0x2, 0x2, 0x69, 0x6a, 0x5, 0x2a, 0x16, 0x2, 
    0x6a, 0x6b, 0x7, 0xc, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x2a, 0x16, 0x2, 0x6c, 
    0x6d, 0x9, 0x3, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x6, 0x4, 0x2, 0x6e, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0xa, 0x2, 0x2, 0x70, 0x71, 0x5, 
    0xa, 0x6, 0x2, 0x71, 0x72, 0x7, 0xc, 0x2, 0x2, 0x72, 0x73, 0x5, 0x2a, 
    0x16, 0x2, 0x73, 0x74, 0x7, 0xb, 0x2, 0x2, 0x74, 0x75, 0x5, 0x2a, 0x16, 
    0x2, 0x75, 0x76, 0x9, 0x3, 0x2, 0x2, 0x76, 0x77, 0x5, 0x6, 0x4, 0x2, 
    0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x36, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x78, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x78, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x53, 0x3, 0x2, 0x2, 0x2, 0x78, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x78, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x79, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0xb4, 0x5, 0xa, 0x6, 0x2, 0x7b, 0x7c, 0x5, 0x2a, 0x16, 0x2, 
    0x7c, 0x7d, 0x7, 0x2a, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0xa, 0x6, 0x2, 0x7e, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x9, 0x4, 0x2, 0x2, 0x80, 0xb4, 
    0x5, 0x2a, 0x16, 0x2, 0x81, 0x82, 0x9, 0x4, 0x2, 0x2, 0x82, 0x83, 0x5, 
    0x2a, 0x16, 0x2, 0x83, 0x84, 0x7, 0x2a, 0x2, 0x2, 0x84, 0x85, 0x5, 0xa, 
    0x6, 0x2, 0x85, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x5, 0x2, 
    0x2, 0x87, 0xb4, 0x5, 0x2a, 0x16, 0x2, 0x88, 0x89, 0x7, 0x6, 0x2, 0x2, 
    0x89, 0x8a, 0x7, 0x29, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x2c, 0x17, 0x2, 0x8b, 
    0x8c, 0x7, 0x2a, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x3a, 0x2, 0x2, 0x8d, 0x8e, 
    0x5, 0xa, 0x6, 0x2, 0x8e, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 
    0x14, 0x2, 0x2, 0x90, 0xb4, 0x5, 0xa, 0x6, 0x2, 0x91, 0x93, 0x7, 0x39, 
    0x2, 0x2, 0x92, 0x94, 0x9, 0x5, 0x2, 0x2, 0x93, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x99, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x9a, 0x5, 0xa, 0x6, 0x2, 0x98, 0x9a, 0x7, 0x28, 0x2, 0x2, 0x99, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x7, 0x10, 
    0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0xf, 0x2, 0x2, 
    0x9f, 0xa1, 0x7, 0x29, 0x2, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 
    0x7, 0x31, 0x2, 0x2, 0xa3, 0xa5, 0x9, 0x3, 0x2, 0x2, 0xa4, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0xab, 0x5, 0x8, 0x5, 0x2, 0xa7, 0xa8, 0x9, 0x3, 0x2, 
    0x2, 0xa8, 0xaa, 0x5, 0x8, 0x5, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 
    0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xb0, 0x9, 0x3, 0x2, 0x2, 0xaf, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0xb2, 0x7, 0x32, 0x2, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0x7a, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x81, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x88, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0x91, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0x7, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xba, 0x7, 0x29, 
    0x2, 0x2, 0xb6, 0xb7, 0x7, 0x29, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x2a, 0x2, 
    0x2, 0xb8, 0xba, 0x5, 0xa, 0x6, 0x2, 0xb9, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xba, 0x9, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x8, 0x6, 0x1, 0x2, 0xbc, 0xbd, 0x7, 0x38, 0x2, 0x2, 0xbd, 0xc8, 
    0x5, 0xa, 0x6, 0x11, 0xbe, 0xbf, 0x7, 0x36, 0x2, 0x2, 0xbf, 0xc8, 0x5, 
    0xa, 0x6, 0x10, 0xc0, 0xc1, 0x7, 0x41, 0x2, 0x2, 0xc1, 0xc8, 0x5, 0xa, 
    0x6, 0xf, 0xc2, 0xc3, 0x7, 0x40, 0x2, 0x2, 0xc3, 0xc8, 0x5, 0xa, 0x6, 
    0xe, 0xc4, 0xc5, 0x7, 0x1e, 0x2, 0x2, 0xc5, 0xc8, 0x5, 0xa, 0x6, 0xd, 
    0xc6, 0xc8, 0x5, 0xc, 0x7, 0x2, 0xc7, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xc7, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0xc, 0xb, 
    0x2, 0x2, 0xca, 0xcb, 0x9, 0x6, 0x2, 0x2, 0xcb, 0xe5, 0x5, 0xa, 0x6, 
    0xc, 0xcc, 0xcd, 0xc, 0xa, 0x2, 0x2, 0xcd, 0xce, 0x9, 0x7, 0x2, 0x2, 
    0xce, 0xe5, 0x5, 0xa, 0x6, 0xb, 0xcf, 0xd0, 0xc, 0x9, 0x2, 0x2, 0xd0, 
    0xd1, 0x9, 0x8, 0x2, 0x2, 0xd1, 0xe5, 0x5, 0xa, 0x6, 0xa, 0xd2, 0xd3, 
    0xc, 0x8, 0x2, 0x2, 0xd3, 0xd4, 0x9, 0x9, 0x2, 0x2, 0xd4, 0xe5, 0x5, 
    0xa, 0x6, 0x9, 0xd5, 0xd6, 0xc, 0x7, 0x2, 0x2, 0xd6, 0xd7, 0x9, 0xa, 
    0x2, 0x2, 0xd7, 0xe5, 0x5, 0xa, 0x6, 0x8, 0xd8, 0xd9, 0xc, 0x6, 0x2, 
    0x2, 0xd9, 0xda, 0x9, 0xb, 0x2, 0x2, 0xda, 0xe5, 0x5, 0xa, 0x6, 0x7, 
    0xdb, 0xdc, 0xc, 0x5, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x17, 0x2, 0x2, 0xdd, 
    0xe5, 0x5, 0xa, 0x6, 0x6, 0xde, 0xdf, 0xc, 0x4, 0x2, 0x2, 0xdf, 0xe0, 
    0x9, 0xc, 0x2, 0x2, 0xe0, 0xe5, 0x5, 0xa, 0x6, 0x5, 0xe1, 0xe2, 0xc, 
    0xc, 0x2, 0x2, 0xe2, 0xe3, 0x9, 0xd, 0x2, 0x2, 0xe3, 0xe5, 0x5, 0x1a, 
    0xe, 0x2, 0xe4, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xe4, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xf0, 0x5, 0xe, 0x8, 
    0x2, 0xea, 0xf0, 0x7, 0x29, 0x2, 0x2, 0xeb, 0xf0, 0x5, 0x10, 0x9, 0x2, 
    0xec, 0xf0, 0x5, 0x12, 0xa, 0x2, 0xed, 0xf0, 0x5, 0x14, 0xb, 0x2, 0xee, 
    0xf0, 0x5, 0x16, 0xc, 0x2, 0xef, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xef, 0xea, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xef, 0xec, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xfb, 0x7, 0x1f, 0x2, 
    0x2, 0xf2, 0xfb, 0x7, 0x20, 0x2, 0x2, 0xf3, 0xfb, 0x7, 0x21, 0x2, 0x2, 
    0xf4, 0xfb, 0x7, 0x22, 0x2, 0x2, 0xf5, 0xfb, 0x7, 0x23, 0x2, 0x2, 0xf6, 
    0xfb, 0x7, 0x24, 0x2, 0x2, 0xf7, 0xfb, 0x7, 0x25, 0x2, 0x2, 0xf8, 0xfb, 
    0x7, 0x26, 0x2, 0x2, 0xf9, 0xfb, 0x7, 0x27, 0x2, 0x2, 0xfa, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xfa, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x8, 0x9, 0x1, 0x2, 0xfd, 0x100, 
    0x7, 0x29, 0x2, 0x2, 0xfe, 0x101, 0x5, 0x14, 0xb, 0x2, 0xff, 0x101, 
    0x5, 0x12, 0xa, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x5, 
    0x14, 0xb, 0x2, 0x103, 0x104, 0x5, 0x14, 0xb, 0x2, 0x104, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x108, 0x5, 0x12, 0xa, 0x2, 0x106, 0x109, 0x5, 
    0x14, 0xb, 0x2, 0x107, 0x109, 0x5, 0x12, 0xa, 0x2, 0x108, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x10c, 0x10f, 0xc, 0x5, 0x2, 0x2, 0x10d, 0x110, 0x5, 0x14, 
    0xb, 0x2, 0x10e, 0x110, 0x5, 0x12, 0xa, 0x2, 0x10f, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x112, 0x115, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x11, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x11f, 0x7, 0x2f, 0x2, 0x2, 0x117, 0x11c, 0x5, 0xa, 0x6, 
    0x2, 0x118, 0x119, 0x9, 0xe, 0x2, 0x2, 0x119, 0x11b, 0x5, 0xa, 0x6, 
    0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11e, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x30, 0x2, 
    0x2, 0x122, 0x13, 0x3, 0x2, 0x2, 0x2, 0x123, 0x12c, 0x7, 0x31, 0x2, 
    0x2, 0x124, 0x129, 0x5, 0xa, 0x6, 0x2, 0x125, 0x126, 0x7, 0x2e, 0x2, 
    0x2, 0x126, 0x128, 0x5, 0xa, 0x6, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x128, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x12f, 0x7, 0x32, 0x2, 0x2, 0x12f, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x130, 0x132, 0x7, 0x33, 0x2, 0x2, 0x131, 0x133, 0x9, 0x3, 0x2, 
    0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x133, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x134, 0x139, 0x5, 0x4, 0x3, 
    0x2, 0x135, 0x136, 0x9, 0x3, 0x2, 0x2, 0x136, 0x138, 0x5, 0x4, 0x3, 
    0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 0x3, 0x2, 0x2, 
    0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x13c, 0x134, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x140, 0x9, 0x3, 0x2, 
    0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x7, 0x34, 0x2, 
    0x2, 0x142, 0x17, 0x3, 0x2, 0x2, 0x2, 0x143, 0x14c, 0x7, 0x2f, 0x2, 
    0x2, 0x144, 0x149, 0x5, 0xa, 0x6, 0x2, 0x145, 0x146, 0x7, 0x2e, 0x2, 
    0x2, 0x146, 0x148, 0x5, 0xa, 0x6, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 
    0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14f, 0x7, 0x30, 0x2, 0x2, 0x14f, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x150, 0x153, 0x5, 0x1c, 0xf, 0x2, 0x151, 0x153, 0x5, 0x1e, 0x10, 
    0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x153, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x7, 0x31, 0x2, 
    0x2, 0x155, 0x156, 0x5, 0x20, 0x11, 0x2, 0x156, 0x157, 0x7, 0x32, 0x2, 
    0x2, 0x157, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x7, 0x31, 0x2, 
    0x2, 0x159, 0x15a, 0x7, 0x31, 0x2, 0x2, 0x15a, 0x15b, 0x5, 0x20, 0x11, 
    0x2, 0x15b, 0x15c, 0x7, 0x32, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x32, 0x2, 
    0x2, 0x15d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x5, 0x22, 0x12, 
    0x2, 0x15f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x160, 0x166, 0x5, 0x24, 0x13, 
    0x2, 0x161, 0x162, 0x5, 0x24, 0x13, 0x2, 0x162, 0x163, 0x9, 0xf, 0x2, 
    0x2, 0x163, 0x164, 0x5, 0x22, 0x12, 0x2, 0x164, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x165, 0x160, 0x3, 0x2, 0x2, 0x2, 0x165, 0x161, 0x3, 0x2, 0x2, 
    0x2, 0x166, 0x23, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16d, 0x5, 0x26, 0x14, 
    0x2, 0x168, 0x169, 0x5, 0x26, 0x14, 0x2, 0x169, 0x16a, 0x7, 0x49, 0x2, 
    0x2, 0x16a, 0x16b, 0x5, 0x24, 0x13, 0x2, 0x16b, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x175, 0x5, 0x28, 0x15, 
    0x2, 0x16f, 0x175, 0x7, 0x29, 0x2, 0x2, 0x170, 0x171, 0x7, 0x2f, 0x2, 
    0x2, 0x171, 0x172, 0x5, 0x20, 0x11, 0x2, 0x172, 0x173, 0x7, 0x30, 0x2, 
    0x2, 0x173, 0x175, 0x3, 0x2, 0x2, 0x2, 0x174, 0x16e, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x174, 0x170, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x27, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x9, 0x10, 0x2, 
    0x2, 0x177, 0x29, 0x3, 0x2, 0x2, 0x2, 0x178, 0x19e, 0x7, 0x29, 0x2, 
    0x2, 0x179, 0x17b, 0x7, 0x2f, 0x2, 0x2, 0x17a, 0x17c, 0x7, 0x2b, 0x2, 
    0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x188, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x182, 0x5, 0x2a, 0x16, 
    0x2, 0x17e, 0x17f, 0x9, 0xe, 0x2, 0x2, 0x17f, 0x181, 0x5, 0x2a, 0x16, 
    0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 
    0x2, 0x183, 0x186, 0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x187, 0x7, 0x2b, 0x2, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x188, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x19e, 0x7, 0x30, 0x2, 
    0x2, 0x18b, 0x18d, 0x7, 0x31, 0x2, 0x2, 0x18c, 0x18e, 0x7, 0x2b, 0x2, 
    0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 
    0x2, 0x18e, 0x197, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x194, 0x5, 0x2a, 0x16, 
    0x2, 0x190, 0x191, 0x7, 0x2e, 0x2, 0x2, 0x191, 0x193, 0x5, 0x2a, 0x16, 
    0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x193, 0x196, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x195, 0x198, 0x3, 0x2, 0x2, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 
    0x2, 0x198, 0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19e, 0x7, 0x32, 0x2, 
    0x2, 0x19a, 0x19b, 0x7, 0x29, 0x2, 0x2, 0x19b, 0x19e, 0x5, 0x2c, 0x17, 
    0x2, 0x19c, 0x19e, 0x7, 0x35, 0x2, 0x2, 0x19d, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x19d, 0x179, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x19d, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a8, 0x7, 0x2f, 0x2, 
    0x2, 0x1a0, 0x1a5, 0x5, 0x2a, 0x16, 0x2, 0x1a1, 0x1a2, 0x7, 0x2e, 0x2, 
    0x2, 0x1a2, 0x1a4, 0x5, 0x2a, 0x16, 0x2, 0x1a3, 0x1a1, 0x3, 0x2, 0x2, 
    0x2, 0x1a4, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x1a5, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x3, 0x2, 0x2, 
    0x2, 0x1aa, 0x1ab, 0x7, 0x30, 0x2, 0x2, 0x1ab, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x33, 0x43, 0x49, 0x78, 0x95, 0x99, 0x9c, 0xa0, 0xa4, 0xab, 
    0xaf, 0xb3, 0xb9, 0xc7, 0xe4, 0xe6, 0xef, 0xfa, 0x100, 0x108, 0x10a, 
    0x10f, 0x113, 0x11c, 0x11f, 0x129, 0x12c, 0x132, 0x139, 0x13c, 0x13f, 
    0x149, 0x14c, 0x152, 0x165, 0x16c, 0x174, 0x17b, 0x182, 0x186, 0x188, 
    0x18d, 0x194, 0x197, 0x19d, 0x1a5, 0x1a8, 
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
