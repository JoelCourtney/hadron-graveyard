
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
    setState(51);
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
      setState(46);
      control();
      setState(47);
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
      setState(53);
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

MuonParser::StatementContext* MuonParser::ForAtLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

MuonParser::LvalueContext* MuonParser::ForAtLoopContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
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

std::vector<tree::TerminalNode *> MuonParser::IfSeriesContext::ELSEIF() {
  return getTokens(MuonParser::ELSEIF);
}

tree::TerminalNode* MuonParser::IfSeriesContext::ELSEIF(size_t i) {
  return getToken(MuonParser::ELSEIF, i);
}

tree::TerminalNode* MuonParser::IfSeriesContext::ELSE() {
  return getToken(MuonParser::ELSE, 0);
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

MuonParser::StatementContext* MuonParser::ForAsLoopContext::statement() {
  return getRuleContext<MuonParser::StatementContext>(0);
}

MuonParser::LvalueContext* MuonParser::ForAsLoopContext::lvalue() {
  return getRuleContext<MuonParser::LvalueContext>(0);
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
    setState(142);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::StatementControlContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(54);
      statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::IfSeriesContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(55);
      match(MuonParser::IF);
      setState(56);
      rvalue(0);
      setState(58);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
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
      }
      setState(60);
      statement();
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(62);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON) {
            setState(61);
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
          setState(64);
          match(MuonParser::ELSEIF);
          setState(65);
          rvalue(0);
          setState(67);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON) {
            setState(66);
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
          setState(69);
          statement(); 
        }
        setState(75);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      }
      setState(81);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(77);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MuonParser::NEWLINE

        || _la == MuonParser::SEMICOLON) {
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
        }
        setState(79);
        match(MuonParser::ELSE);
        setState(80);
        statement();
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::LoopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(83);
      match(MuonParser::LOOP);
      setState(85);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(84);
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
      setState(87);
      statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(88);
      match(MuonParser::WHILE);
      setState(89);
      rvalue(0);
      setState(91);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
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
      }
      setState(93);
      statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForLoopContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(95);
      match(MuonParser::FOR);
      setState(96);
      rvalue(0);
      setState(98);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
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
      }
      setState(100);
      statement();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsLoopContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(102);
      match(MuonParser::FOR);
      setState(103);
      rvalue(0);
      setState(104);
      match(MuonParser::AS);
      setState(105);
      dynamic_cast<ForAsLoopContext *>(_localctx)->as = lvalue();
      setState(107);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
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
      }
      setState(109);
      statement();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(111);
      match(MuonParser::FOR);
      setState(112);
      rvalue(0);
      setState(113);
      match(MuonParser::AT);
      setState(114);
      dynamic_cast<ForAtLoopContext *>(_localctx)->at = lvalue();
      setState(116);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
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
      }
      setState(118);
      statement();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(120);
      match(MuonParser::FOR);
      setState(121);
      rvalue(0);
      setState(122);
      match(MuonParser::AS);
      setState(123);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->as = lvalue();
      setState(124);
      match(MuonParser::AT);
      setState(125);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->at = lvalue();
      setState(127);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(126);
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
      setState(129);
      statement();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<MuonParser::ForAsAtLoopContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(131);
      match(MuonParser::FOR);
      setState(132);
      rvalue(0);
      setState(133);
      match(MuonParser::AT);
      setState(134);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->at = lvalue();
      setState(135);
      match(MuonParser::AS);
      setState(136);
      dynamic_cast<ForAsAtLoopContext *>(_localctx)->as = lvalue();
      setState(138);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(137);
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
      setState(140);
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
    setState(201);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::RValueStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(144);
      rvalue(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(145);
      lvalue();
      setState(146);
      match(MuonParser::EQUAL);
      setState(147);
      rvalue(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(149);
      _la = _input->LA(1);
      if (!(_la == MuonParser::VAL

      || _la == MuonParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(150);
      lvalue();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DeclareAssignContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(151);
      _la = _input->LA(1);
      if (!(_la == MuonParser::VAL

      || _la == MuonParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(152);
      lvalue();
      setState(153);
      match(MuonParser::EQUAL);
      setState(154);
      rvalue(0);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::DropNameContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(156);
      match(MuonParser::DROP);
      setState(157);
      lvalue();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::FunctionDeclareContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(158);
      match(MuonParser::FN);
      setState(159);
      match(MuonParser::NAME);
      setState(160);
      lArgList();
      setState(161);
      match(MuonParser::EQUAL);
      setState(162);
      match(MuonParser::CHAIRPIN);
      setState(163);
      rvalue(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::PrintContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(165);
      match(MuonParser::PRINT);
      setState(166);
      rvalue(0);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MuonParser::BreakSnakeContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(167);
      match(MuonParser::OHAIRPIN);
      setState(169); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(168);
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
        setState(171); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(175);
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
          setState(173);
          rvalue(0);
          break;
        }

        case MuonParser::VOID_LITERAL: {
          setState(174);
          match(MuonParser::VOID_LITERAL);
          break;
        }

        case MuonParser::EOF:
        case MuonParser::ELSEIF:
        case MuonParser::ELSE:
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
      setState(178);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::UNITY) {
        setState(177);
        match(MuonParser::UNITY);
      }
      setState(180);
      match(MuonParser::DIMENSION);
      setState(182);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NAME) {
        setState(181);
        match(MuonParser::NAME);
      }
      setState(184);
      match(MuonParser::OBRACKET);
      setState(186);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(185);
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
      setState(188);
      unitDeclaration();
      setState(193);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(189);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(190);
          unitDeclaration(); 
        }
        setState(195);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      }
      setState(197);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(196);
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
      setState(199);
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
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(203);
      match(MuonParser::NAME);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(204);
      match(MuonParser::NAME);
      setState(205);
      match(MuonParser::EQUAL);
      setState(206);
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

//----------------- ShapeOperationContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::ShapeOperationContext::DOLLAR() {
  return getToken(MuonParser::DOLLAR, 0);
}

MuonParser::RvalueContext* MuonParser::ShapeOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::ShapeOperationContext::ShapeOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ShapeOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitShapeOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::AddSubOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::AddSubOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::AddSubOperationContext::PLUS() {
  return getToken(MuonParser::PLUS, 0);
}

tree::TerminalNode* MuonParser::AddSubOperationContext::DASH() {
  return getToken(MuonParser::DASH, 0);
}

MuonParser::AddSubOperationContext::AddSubOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::AddSubOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitAddSubOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::CompOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::CompOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::CompOperationContext::OHAIRPIN() {
  return getToken(MuonParser::OHAIRPIN, 0);
}

tree::TerminalNode* MuonParser::CompOperationContext::OHAIRPINEQUAL() {
  return getToken(MuonParser::OHAIRPINEQUAL, 0);
}

tree::TerminalNode* MuonParser::CompOperationContext::CHAIRPIN() {
  return getToken(MuonParser::CHAIRPIN, 0);
}

tree::TerminalNode* MuonParser::CompOperationContext::CHAIRPINEQUAL() {
  return getToken(MuonParser::CHAIRPINEQUAL, 0);
}

MuonParser::CompOperationContext::CompOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::CompOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitCompOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::ExpOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::ExpOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::ExpOperationContext::CARROT() {
  return getToken(MuonParser::CARROT, 0);
}

tree::TerminalNode* MuonParser::ExpOperationContext::MATCARROT() {
  return getToken(MuonParser::MATCARROT, 0);
}

MuonParser::ExpOperationContext::ExpOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::ExpOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitExpOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- XOrOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::XOrOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::XOrOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::XOrOperationContext::XOR() {
  return getToken(MuonParser::XOR, 0);
}

MuonParser::XOrOperationContext::XOrOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::XOrOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitXOrOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotOperationContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::NotOperationContext::NOT() {
  return getToken(MuonParser::NOT, 0);
}

MuonParser::RvalueContext* MuonParser::NotOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::NotOperationContext::NotOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::NotOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitNotOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegateOperationContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::NegateOperationContext::DASH() {
  return getToken(MuonParser::DASH, 0);
}

MuonParser::RvalueContext* MuonParser::NegateOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::NegateOperationContext::NegateOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::NegateOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitNegateOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::AndOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::AndOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::AndOperationContext::AND() {
  return getToken(MuonParser::AND, 0);
}

tree::TerminalNode* MuonParser::AndOperationContext::NAND() {
  return getToken(MuonParser::NAND, 0);
}

MuonParser::AndOperationContext::AndOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::AndOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitAndOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::OrOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::OrOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::OrOperationContext::OR() {
  return getToken(MuonParser::OR, 0);
}

tree::TerminalNode* MuonParser::OrOperationContext::NOR() {
  return getToken(MuonParser::NOR, 0);
}

MuonParser::OrOperationContext::OrOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::OrOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitOrOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NoOperationContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::NoOperationContext::PLUS() {
  return getToken(MuonParser::PLUS, 0);
}

MuonParser::RvalueContext* MuonParser::NoOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::NoOperationContext::NoOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::NoOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitNoOperation(this);
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
//----------------- IsOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::IsOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::IsOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::IsOperationContext::IS() {
  return getToken(MuonParser::IS, 0);
}

tree::TerminalNode* MuonParser::IsOperationContext::ISNT() {
  return getToken(MuonParser::ISNT, 0);
}

MuonParser::IsOperationContext::IsOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::IsOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitIsOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SizeOperationContext ------------------------------------------------------------------

tree::TerminalNode* MuonParser::SizeOperationContext::HASH() {
  return getToken(MuonParser::HASH, 0);
}

MuonParser::RvalueContext* MuonParser::SizeOperationContext::rvalue() {
  return getRuleContext<MuonParser::RvalueContext>(0);
}

MuonParser::SizeOperationContext::SizeOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::SizeOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitSizeOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultDivOperationContext ------------------------------------------------------------------

std::vector<MuonParser::RvalueContext *> MuonParser::MultDivOperationContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::MultDivOperationContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

tree::TerminalNode* MuonParser::MultDivOperationContext::STAR() {
  return getToken(MuonParser::STAR, 0);
}

tree::TerminalNode* MuonParser::MultDivOperationContext::SLASH() {
  return getToken(MuonParser::SLASH, 0);
}

tree::TerminalNode* MuonParser::MultDivOperationContext::MATSTAR() {
  return getToken(MuonParser::MATSTAR, 0);
}

tree::TerminalNode* MuonParser::MultDivOperationContext::MATSLASH() {
  return getToken(MuonParser::MATSLASH, 0);
}

MuonParser::MultDivOperationContext::MultDivOperationContext(RvalueContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MuonParser::MultDivOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitMultDivOperation(this);
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
    setState(221);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::PLUS: {
        _localctx = _tracker.createInstance<NoOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(210);
        dynamic_cast<NoOperationContext *>(_localctx)->uop = match(MuonParser::PLUS);
        setState(211);
        dynamic_cast<NoOperationContext *>(_localctx)->r = rvalue(15);
        break;
      }

      case MuonParser::DASH: {
        _localctx = _tracker.createInstance<NegateOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(212);
        dynamic_cast<NegateOperationContext *>(_localctx)->uop = match(MuonParser::DASH);
        setState(213);
        dynamic_cast<NegateOperationContext *>(_localctx)->r = rvalue(14);
        break;
      }

      case MuonParser::DOLLAR: {
        _localctx = _tracker.createInstance<ShapeOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(214);
        dynamic_cast<ShapeOperationContext *>(_localctx)->uop = match(MuonParser::DOLLAR);
        setState(215);
        dynamic_cast<ShapeOperationContext *>(_localctx)->r = rvalue(13);
        break;
      }

      case MuonParser::HASH: {
        _localctx = _tracker.createInstance<SizeOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(216);
        dynamic_cast<SizeOperationContext *>(_localctx)->uop = match(MuonParser::HASH);
        setState(217);
        dynamic_cast<SizeOperationContext *>(_localctx)->r = rvalue(12);
        break;
      }

      case MuonParser::NOT: {
        _localctx = _tracker.createInstance<NotOperationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(218);
        dynamic_cast<NotOperationContext *>(_localctx)->uop = match(MuonParser::NOT);
        setState(219);
        dynamic_cast<NotOperationContext *>(_localctx)->r = rvalue(11);
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
        setState(220);
        dynamic_cast<AtomRValueContext *>(_localctx)->a = atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(252);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(250);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExpOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(223);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(224);
          dynamic_cast<ExpOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::CARROT

          || _la == MuonParser::MATCARROT)) {
            dynamic_cast<ExpOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(225);
          dynamic_cast<ExpOperationContext *>(_localctx)->r2 = rvalue(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultDivOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(226);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(227);
          dynamic_cast<MultDivOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (MuonParser::STAR - 67))
            | (1ULL << (MuonParser::MATSTAR - 67))
            | (1ULL << (MuonParser::SLASH - 67))
            | (1ULL << (MuonParser::MATSLASH - 67)))) != 0))) {
            dynamic_cast<MultDivOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(228);
          dynamic_cast<MultDivOperationContext *>(_localctx)->r2 = rvalue(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddSubOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(229);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(230);
          dynamic_cast<AddSubOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::DASH

          || _la == MuonParser::PLUS)) {
            dynamic_cast<AddSubOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(231);
          dynamic_cast<AddSubOperationContext *>(_localctx)->r2 = rvalue(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(232);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(233);
          dynamic_cast<CompOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MuonParser::OHAIRPIN)
            | (1ULL << MuonParser::CHAIRPIN)
            | (1ULL << MuonParser::OHAIRPINEQUAL)
            | (1ULL << MuonParser::CHAIRPINEQUAL))) != 0))) {
            dynamic_cast<CompOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(234);
          dynamic_cast<CompOperationContext *>(_localctx)->r2 = rvalue(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<IsOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(235);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(236);
          dynamic_cast<IsOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::IS

          || _la == MuonParser::ISNT)) {
            dynamic_cast<IsOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(237);
          dynamic_cast<IsOperationContext *>(_localctx)->r2 = rvalue(6);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AndOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(238);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(239);
          dynamic_cast<AndOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::AND

          || _la == MuonParser::NAND)) {
            dynamic_cast<AndOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(240);
          dynamic_cast<AndOperationContext *>(_localctx)->r2 = rvalue(5);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<XOrOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(241);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(242);
          dynamic_cast<XOrOperationContext *>(_localctx)->bop = match(MuonParser::XOR);
          setState(243);
          dynamic_cast<XOrOperationContext *>(_localctx)->r2 = rvalue(4);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<OrOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r1 = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(244);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(245);
          dynamic_cast<OrOperationContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MuonParser::OR

          || _la == MuonParser::NOR)) {
            dynamic_cast<OrOperationContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(246);
          dynamic_cast<OrOperationContext *>(_localctx)->r2 = rvalue(3);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ConvertOperationContext>(_tracker.createInstance<RvalueContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->r = previousContext;
          pushNewRecursionContext(newContext, startState, RuleRvalue);
          setState(247);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(248);
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
          setState(249);
          dynamic_cast<ConvertOperationContext *>(_localctx)->t = type();
          break;
        }

        } 
      }
      setState(254);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
    setState(261);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::LiteralAtomContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(255);
      literal();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::NameAtomContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(256);
      match(MuonParser::NAME);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::InvokeAtomContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(257);
      invoke(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::MatrixAtomContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(258);
      matrix();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::ListAtomContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(259);
      list();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<MuonParser::ScopeAtomContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(260);
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
    setState(272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::SCIENTIFIC_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::FloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(263);
        match(MuonParser::SCIENTIFIC_FLOAT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryFloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(264);
        match(MuonParser::IMAGINARY_SCIENTIFIC_FLOAT_LITERAL);
        break;
      }

      case MuonParser::FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::FloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(265);
        match(MuonParser::FLOAT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_FLOAT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryFloatLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(266);
        match(MuonParser::IMAGINARY_FLOAT_LITERAL);
        break;
      }

      case MuonParser::INT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::IntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(267);
        match(MuonParser::INT_LITERAL);
        break;
      }

      case MuonParser::IMAGINARY_INT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::ImaginaryIntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(268);
        match(MuonParser::IMAGINARY_INT_LITERAL);
        break;
      }

      case MuonParser::STRING_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::StringLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(269);
        match(MuonParser::STRING_LITERAL);
        break;
      }

      case MuonParser::BOOL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::BoolLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(270);
        match(MuonParser::BOOL_LITERAL);
        break;
      }

      case MuonParser::NULL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MuonParser::NullLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(271);
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
    setState(288);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::NAME: {
        setState(275);
        match(MuonParser::NAME);
        setState(278);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(276);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(277);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case MuonParser::OBRACKET: {
        setState(280);
        list();
        setState(281);
        list();
        break;
      }

      case MuonParser::OPAREN: {
        setState(283);
        matrix();
        setState(286);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(284);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(285);
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
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InvokeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInvoke);
        setState(290);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(293);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MuonParser::OBRACKET: {
            setState(291);
            list();
            break;
          }

          case MuonParser::OPAREN: {
            setState(292);
            matrix();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
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

std::vector<MuonParser::MatrixRowContext *> MuonParser::MatrixContext::matrixRow() {
  return getRuleContexts<MuonParser::MatrixRowContext>();
}

MuonParser::MatrixRowContext* MuonParser::MatrixContext::matrixRow(size_t i) {
  return getRuleContext<MuonParser::MatrixRowContext>(i);
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
    setState(300);
    match(MuonParser::OPAREN);
    setState(309);
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
      setState(301);
      matrixRow();
      setState(306);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::NEWLINE

      || _la == MuonParser::SEMICOLON) {
        setState(302);
        _la = _input->LA(1);
        if (!(_la == MuonParser::NEWLINE

        || _la == MuonParser::SEMICOLON)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(303);
        matrixRow();
        setState(308);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(311);
    match(MuonParser::CPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatrixRowContext ------------------------------------------------------------------

MuonParser::MatrixRowContext::MatrixRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MuonParser::RvalueContext *> MuonParser::MatrixRowContext::rvalue() {
  return getRuleContexts<MuonParser::RvalueContext>();
}

MuonParser::RvalueContext* MuonParser::MatrixRowContext::rvalue(size_t i) {
  return getRuleContext<MuonParser::RvalueContext>(i);
}

std::vector<tree::TerminalNode *> MuonParser::MatrixRowContext::COMMA() {
  return getTokens(MuonParser::COMMA);
}

tree::TerminalNode* MuonParser::MatrixRowContext::COMMA(size_t i) {
  return getToken(MuonParser::COMMA, i);
}


size_t MuonParser::MatrixRowContext::getRuleIndex() const {
  return MuonParser::RuleMatrixRow;
}

antlrcpp::Any MuonParser::MatrixRowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MuonVisitor*>(visitor))
    return parserVisitor->visitMatrixRow(this);
  else
    return visitor->visitChildren(this);
}

MuonParser::MatrixRowContext* MuonParser::matrixRow() {
  MatrixRowContext *_localctx = _tracker.createInstance<MatrixRowContext>(_ctx, getState());
  enterRule(_localctx, 18, MuonParser::RuleMatrixRow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    rvalue(0);
    setState(318);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MuonParser::COMMA) {
      setState(314);
      match(MuonParser::COMMA);
      setState(315);
      rvalue(0);
      setState(320);
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
  enterRule(_localctx, 20, MuonParser::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(MuonParser::OBRACKET);
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
  enterRule(_localctx, 22, MuonParser::RuleScope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(334);
    match(MuonParser::OBRACE);
    setState(336);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(335);
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
    setState(346);
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
      setState(338);
      control();
      setState(343);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(339);
          _la = _input->LA(1);
          if (!(_la == MuonParser::NEWLINE

          || _la == MuonParser::SEMICOLON)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(340);
          control(); 
        }
        setState(345);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      }
    }
    setState(349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MuonParser::NEWLINE

    || _la == MuonParser::SEMICOLON) {
      setState(348);
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
    setState(351);
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
  enterRule(_localctx, 24, MuonParser::RuleRArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(MuonParser::OPAREN);
    setState(362);
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
      setState(354);
      rvalue(0);
      setState(359);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(355);
        match(MuonParser::COMMA);
        setState(356);
        rvalue(0);
        setState(361);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(364);
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
  enterRule(_localctx, 26, MuonParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(368);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(366);
      unit();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(367);
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
  enterRule(_localctx, 28, MuonParser::RuleUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(MuonParser::OBRACKET);
    setState(371);
    typeRValue();
    setState(372);
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
  enterRule(_localctx, 30, MuonParser::RuleDimension);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(MuonParser::OBRACKET);
    setState(375);
    match(MuonParser::OBRACKET);
    setState(376);
    typeRValue();
    setState(377);
    match(MuonParser::CBRACKET);
    setState(378);
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
  enterRule(_localctx, 32, MuonParser::RuleTypeRValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
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
  enterRule(_localctx, 34, MuonParser::RuleTypeMultiplyOperation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(387);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(382);
      typePowerOperation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(383);
      typePowerOperation();
      setState(384);
      _la = _input->LA(1);
      if (!(_la == MuonParser::STAR

      || _la == MuonParser::SLASH)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(385);
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
  enterRule(_localctx, 36, MuonParser::RuleTypePowerOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(389);
      typeAtom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(390);
      typeAtom();
      setState(391);
      match(MuonParser::CARROT);
      setState(392);
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
  enterRule(_localctx, 38, MuonParser::RuleTypeAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(402);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MuonParser::SCIENTIFIC_FLOAT_LITERAL:
      case MuonParser::FLOAT_LITERAL:
      case MuonParser::INT_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(396);
        typeLiteral();
        break;
      }

      case MuonParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(397);
        match(MuonParser::NAME);
        break;
      }

      case MuonParser::OPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(398);
        match(MuonParser::OPAREN);
        setState(399);
        typeRValue();
        setState(400);
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
  enterRule(_localctx, 40, MuonParser::RuleTypeLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
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
  enterRule(_localctx, 42, MuonParser::RuleLvalue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(443);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::NameLValueContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(406);
      match(MuonParser::NAME);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::MatrixDecompositionLValueContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(407);
      match(MuonParser::OPAREN);
      setState(409);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE) {
        setState(408);
        match(MuonParser::NEWLINE);
      }
      setState(422);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MuonParser::NAME)
        | (1ULL << MuonParser::OPAREN)
        | (1ULL << MuonParser::OBRACKET)
        | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
        setState(411);
        lvalue();
        setState(416);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(412);
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
            setState(413);
            lvalue(); 
          }
          setState(418);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
        }
        setState(420);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MuonParser::NEWLINE) {
          setState(419);
          match(MuonParser::NEWLINE);
        }
      }
      setState(424);
      match(MuonParser::CPAREN);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::ListDecompositionLValueContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(425);
      match(MuonParser::OBRACKET);
      setState(427);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MuonParser::NEWLINE) {
        setState(426);
        match(MuonParser::NEWLINE);
      }
      setState(437);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MuonParser::NAME)
        | (1ULL << MuonParser::OPAREN)
        | (1ULL << MuonParser::OBRACKET)
        | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
        setState(429);
        lvalue();
        setState(434);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MuonParser::COMMA) {
          setState(430);
          match(MuonParser::COMMA);
          setState(431);
          lvalue();
          setState(436);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(439);
      match(MuonParser::CBRACKET);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::SubsetLValueContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(440);
      match(MuonParser::NAME);
      setState(441);
      lArgList();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<LvalueContext *>(_tracker.createInstance<MuonParser::DiscardLValueContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(442);
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
  enterRule(_localctx, 44, MuonParser::RuleLArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    match(MuonParser::OPAREN);
    setState(454);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MuonParser::NAME)
      | (1ULL << MuonParser::OPAREN)
      | (1ULL << MuonParser::OBRACKET)
      | (1ULL << MuonParser::UNDERSCORE))) != 0)) {
      setState(446);
      lvalue();
      setState(451);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MuonParser::COMMA) {
        setState(447);
        match(MuonParser::COMMA);
        setState(448);
        lvalue();
        setState(453);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(456);
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
  "invoke", "matrix", "matrixRow", "list", "scope", "rArgList", "type", 
  "unit", "dimension", "typeRValue", "typeMultiplyOperation", "typePowerOperation", 
  "typeAtom", "typeLiteral", "lvalue", "lArgList"
};

std::vector<std::string> MuonParser::_literalNames = {
  "", "'val'", "'var'", "'drop'", "'fn'", "'if'", "'elseif'", "'else'", 
  "'for'", "'as'", "'at'", "'while'", "'loop'", "'dimension'", "'unity'", 
  "'struct'", "'class'", "'enum'", "'print'", "'or'", "'nor'", "'xor'", 
  "'and'", "'nand'", "", "", "'mod'", "'to'", "'not'", "", "", "", "", "", 
  "", "", "", "'null'", "'void'", "", "'='", "", "", "':'", "','", "'('", 
  "')'", "'['", "']'", "'{'", "'}'", "'_'", "'-'", "'~'", "'+'", "'<'", 
  "'>'", "'<='", "'>='", "'!'", "'`'", "'@'", "'#'", "'$'", "'%'", "'&'", 
  "'.'", "'*'", "'(*)'", "'/'", "'(/)'", "'^'", "'(^)'", "", "' '"
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
  "DOLLAR", "PERCENT", "AMPERSAND", "DOT", "STAR", "MATSTAR", "SLASH", "MATSLASH", 
  "CARROT", "MATCARROT", "BLOCK_COMMENT", "WHITESPACE"
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
    0x3, 0x4c, 0x1cd, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x3d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x41, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x46, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x4a, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4d, 0xb, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x50, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x54, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x58, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x5e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x65, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x6e, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x77, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x82, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x8d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x91, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 
    0xac, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0xad, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0xb2, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb5, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0xb9, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xbd, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xc2, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0xc5, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0xc8, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0xcc, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xd2, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0xe0, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xfd, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x100, 
    0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x108, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x113, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x119, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x121, 
    0xa, 0x9, 0x5, 0x9, 0x123, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x128, 0xa, 0x9, 0x7, 0x9, 0x12a, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
    0x12d, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x133, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x136, 0xb, 0xa, 0x5, 0xa, 0x138, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x13f, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x142, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x7, 0xc, 0x148, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x14b, 
    0xb, 0xc, 0x5, 0xc, 0x14d, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x5, 0xd, 0x153, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x158, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x15b, 0xb, 0xd, 0x5, 0xd, 0x15d, 
    0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x160, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x168, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x16b, 0xb, 0xe, 0x5, 0xe, 0x16d, 0xa, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x173, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x186, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x18d, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 
    0x15, 0x195, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x19c, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x7, 0x17, 0x1a1, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x1a4, 0xb, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x1a7, 0xa, 0x17, 0x5, 0x17, 0x1a9, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1ae, 0xa, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x1b3, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0x1b6, 0xb, 0x17, 0x5, 0x17, 0x1b8, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1be, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x1c4, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0x1c7, 0xb, 0x18, 0x5, 0x18, 0x1c9, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x2, 0x4, 0xa, 0x10, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x11, 0x3, 0x3, 0x2b, 0x2c, 0x3, 
    0x2, 0x2b, 0x2c, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x2a, 0x2a, 0x36, 0x37, 
    0x3, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x45, 0x48, 0x4, 0x2, 0x36, 0x36, 0x38, 
    0x38, 0x3, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x18, 0x19, 
    0x3, 0x2, 0x15, 0x16, 0x5, 0x2, 0x1d, 0x1d, 0x3f, 0x3f, 0x43, 0x43, 
    0x4, 0x2, 0x45, 0x45, 0x47, 0x47, 0x5, 0x2, 0x1f, 0x1f, 0x21, 0x21, 
    0x23, 0x23, 0x4, 0x2, 0x2b, 0x2c, 0x2e, 0x2e, 0x2, 0x21a, 0x2, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x90, 0x3, 0x2, 0x2, 0x2, 0x6, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xa, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x107, 0x3, 0x2, 0x2, 0x2, 0xe, 0x112, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x12, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x143, 0x3, 0x2, 0x2, 0x2, 0x18, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x163, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x172, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x174, 0x3, 0x2, 0x2, 0x2, 0x20, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x185, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x28, 0x194, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x196, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1bf, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x4, 0x3, 0x2, 0x31, 0x32, 0x9, 
    0x2, 0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 0x33, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x91, 0x5, 0x6, 0x4, 0x2, 0x39, 
    0x3a, 0x7, 0x7, 0x2, 0x2, 0x3a, 0x3c, 0x5, 0xa, 0x6, 0x2, 0x3b, 0x3d, 
    0x9, 0x3, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x4b, 0x5, 0x6, 
    0x4, 0x2, 0x3f, 0x41, 0x9, 0x3, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x7, 0x8, 0x2, 0x2, 0x43, 0x45, 0x5, 0xa, 0x6, 0x2, 0x44, 
    0x46, 0x9, 0x3, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x5, 
    0x6, 0x4, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x9, 0x3, 0x2, 0x2, 0x4f, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x9, 0x2, 0x2, 0x52, 0x54, 0x5, 
    0x6, 0x4, 0x2, 0x53, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x91, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0x7, 0xe, 0x2, 
    0x2, 0x56, 0x58, 0x9, 0x3, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x91, 0x5, 0x6, 0x4, 0x2, 0x5a, 0x5b, 0x7, 0xd, 0x2, 0x2, 0x5b, 0x5d, 
    0x5, 0xa, 0x6, 0x2, 0x5c, 0x5e, 0x9, 0x3, 0x2, 0x2, 0x5d, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x60, 0x5, 0x6, 0x4, 0x2, 0x60, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0xa, 0x2, 0x2, 0x62, 0x64, 0x5, 0xa, 0x6, 0x2, 
    0x63, 0x65, 0x9, 0x3, 0x2, 0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x5, 0x6, 0x4, 0x2, 0x67, 0x91, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 
    0xa, 0x2, 0x2, 0x69, 0x6a, 0x5, 0xa, 0x6, 0x2, 0x6a, 0x6b, 0x7, 0xb, 
    0x2, 0x2, 0x6b, 0x6d, 0x5, 0x2c, 0x17, 0x2, 0x6c, 0x6e, 0x9, 0x3, 0x2, 
    0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x6, 0x4, 0x2, 0x70, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0xa, 0x2, 0x2, 0x72, 0x73, 
    0x5, 0xa, 0x6, 0x2, 0x73, 0x74, 0x7, 0xc, 0x2, 0x2, 0x74, 0x76, 0x5, 
    0x2c, 0x17, 0x2, 0x75, 0x77, 0x9, 0x3, 0x2, 0x2, 0x76, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x79, 0x5, 0x6, 0x4, 0x2, 0x79, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7b, 0x7, 0xa, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0xa, 0x6, 0x2, 0x7c, 
    0x7d, 0x7, 0xb, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x2c, 0x17, 0x2, 0x7e, 0x7f, 
    0x7, 0xc, 0x2, 0x2, 0x7f, 0x81, 0x5, 0x2c, 0x17, 0x2, 0x80, 0x82, 0x9, 
    0x3, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x5, 0x6, 0x4, 
    0x2, 0x84, 0x91, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0xa, 0x2, 0x2, 
    0x86, 0x87, 0x5, 0xa, 0x6, 0x2, 0x87, 0x88, 0x7, 0xc, 0x2, 0x2, 0x88, 
    0x89, 0x5, 0x2c, 0x17, 0x2, 0x89, 0x8a, 0x7, 0xb, 0x2, 0x2, 0x8a, 0x8c, 
    0x5, 0x2c, 0x17, 0x2, 0x8b, 0x8d, 0x9, 0x3, 0x2, 0x2, 0x8c, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8f, 0x5, 0x6, 0x4, 0x2, 0x8f, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x38, 0x3, 0x2, 0x2, 0x2, 0x90, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x55, 0x3, 0x2, 0x2, 0x2, 0x90, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x90, 0x68, 0x3, 0x2, 0x2, 0x2, 0x90, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x90, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x5, 0x3, 0x2, 0x2, 0x2, 0x92, 0xcc, 0x5, 0xa, 
    0x6, 0x2, 0x93, 0x94, 0x5, 0x2c, 0x17, 0x2, 0x94, 0x95, 0x7, 0x2a, 0x2, 
    0x2, 0x95, 0x96, 0x5, 0xa, 0x6, 0x2, 0x96, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x9, 0x4, 0x2, 0x2, 0x98, 0xcc, 0x5, 0x2c, 0x17, 0x2, 0x99, 
    0x9a, 0x9, 0x4, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x2c, 0x17, 0x2, 0x9b, 0x9c, 
    0x7, 0x2a, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0xa, 0x6, 0x2, 0x9d, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x5, 0x2, 0x2, 0x9f, 0xcc, 0x5, 0x2c, 
    0x17, 0x2, 0xa0, 0xa1, 0x7, 0x6, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x29, 0x2, 
    0x2, 0xa2, 0xa3, 0x5, 0x2e, 0x18, 0x2, 0xa3, 0xa4, 0x7, 0x2a, 0x2, 0x2, 
    0xa4, 0xa5, 0x7, 0x3a, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0xa, 0x6, 0x2, 0xa6, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x14, 0x2, 0x2, 0xa8, 0xcc, 
    0x5, 0xa, 0x6, 0x2, 0xa9, 0xab, 0x7, 0x39, 0x2, 0x2, 0xaa, 0xac, 0x9, 
    0x5, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb2, 0x5, 0xa, 0x6, 0x2, 
    0xb0, 0xb2, 0x7, 0x28, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x7, 0x10, 0x2, 0x2, 0xb4, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb8, 0x7, 0xf, 0x2, 0x2, 0xb7, 0xb9, 0x7, 0x29, 0x2, 
    0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x7, 0x31, 0x2, 0x2, 0xbb, 
    0xbd, 0x9, 0x3, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc3, 0x5, 
    0x8, 0x5, 0x2, 0xbf, 0xc0, 0x9, 0x3, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x8, 
    0x5, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc8, 0x9, 0x3, 0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 
    0x32, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0x93, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0x99, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xd2, 0x7, 0x29, 0x2, 0x2, 0xce, 0xcf, 0x7, 
    0x29, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x2a, 0x2, 0x2, 0xd0, 0xd2, 0x5, 0xa, 
    0x6, 0x2, 0xd1, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0x9, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x8, 0x6, 0x1, 0x2, 
    0xd4, 0xd5, 0x7, 0x38, 0x2, 0x2, 0xd5, 0xe0, 0x5, 0xa, 0x6, 0x11, 0xd6, 
    0xd7, 0x7, 0x36, 0x2, 0x2, 0xd7, 0xe0, 0x5, 0xa, 0x6, 0x10, 0xd8, 0xd9, 
    0x7, 0x41, 0x2, 0x2, 0xd9, 0xe0, 0x5, 0xa, 0x6, 0xf, 0xda, 0xdb, 0x7, 
    0x40, 0x2, 0x2, 0xdb, 0xe0, 0x5, 0xa, 0x6, 0xe, 0xdc, 0xdd, 0x7, 0x1e, 
    0x2, 0x2, 0xdd, 0xe0, 0x5, 0xa, 0x6, 0xd, 0xde, 0xe0, 0x5, 0xc, 0x7, 
    0x2, 0xdf, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xfe, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0xc, 0xb, 0x2, 0x2, 0xe2, 0xe3, 0x9, 
    0x6, 0x2, 0x2, 0xe3, 0xfd, 0x5, 0xa, 0x6, 0xc, 0xe4, 0xe5, 0xc, 0xa, 
    0x2, 0x2, 0xe5, 0xe6, 0x9, 0x7, 0x2, 0x2, 0xe6, 0xfd, 0x5, 0xa, 0x6, 
    0xb, 0xe7, 0xe8, 0xc, 0x9, 0x2, 0x2, 0xe8, 0xe9, 0x9, 0x8, 0x2, 0x2, 
    0xe9, 0xfd, 0x5, 0xa, 0x6, 0xa, 0xea, 0xeb, 0xc, 0x8, 0x2, 0x2, 0xeb, 
    0xec, 0x9, 0x9, 0x2, 0x2, 0xec, 0xfd, 0x5, 0xa, 0x6, 0x9, 0xed, 0xee, 
    0xc, 0x7, 0x2, 0x2, 0xee, 0xef, 0x9, 0xa, 0x2, 0x2, 0xef, 0xfd, 0x5, 
    0xa, 0x6, 0x8, 0xf0, 0xf1, 0xc, 0x6, 0x2, 0x2, 0xf1, 0xf2, 0x9, 0xb, 
    0x2, 0x2, 0xf2, 0xfd, 0x5, 0xa, 0x6, 0x7, 0xf3, 0xf4, 0xc, 0x5, 0x2, 
    0x2, 0xf4, 0xf5, 0x7, 0x17, 0x2, 0x2, 0xf5, 0xfd, 0x5, 0xa, 0x6, 0x6, 
    0xf6, 0xf7, 0xc, 0x4, 0x2, 0x2, 0xf7, 0xf8, 0x9, 0xc, 0x2, 0x2, 0xf8, 
    0xfd, 0x5, 0xa, 0x6, 0x5, 0xf9, 0xfa, 0xc, 0xc, 0x2, 0x2, 0xfa, 0xfb, 
    0x9, 0xd, 0x2, 0x2, 0xfb, 0xfd, 0x5, 0x1c, 0xf, 0x2, 0xfc, 0xe1, 0x3, 
    0x2, 0x2, 0x2, 0xfc, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xea, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xfc, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfd, 
    0x100, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0xb, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x108, 0x5, 0xe, 0x8, 0x2, 0x102, 0x108, 0x7, 
    0x29, 0x2, 0x2, 0x103, 0x108, 0x5, 0x10, 0x9, 0x2, 0x104, 0x108, 0x5, 
    0x12, 0xa, 0x2, 0x105, 0x108, 0x5, 0x16, 0xc, 0x2, 0x106, 0x108, 0x5, 
    0x18, 0xd, 0x2, 0x107, 0x101, 0x3, 0x2, 0x2, 0x2, 0x107, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x103, 0x3, 0x2, 0x2, 0x2, 0x107, 0x104, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0xd, 0x3, 0x2, 0x2, 0x2, 0x109, 0x113, 0x7, 0x1f, 
    0x2, 0x2, 0x10a, 0x113, 0x7, 0x20, 0x2, 0x2, 0x10b, 0x113, 0x7, 0x21, 
    0x2, 0x2, 0x10c, 0x113, 0x7, 0x22, 0x2, 0x2, 0x10d, 0x113, 0x7, 0x23, 
    0x2, 0x2, 0x10e, 0x113, 0x7, 0x24, 0x2, 0x2, 0x10f, 0x113, 0x7, 0x25, 
    0x2, 0x2, 0x110, 0x113, 0x7, 0x26, 0x2, 0x2, 0x111, 0x113, 0x7, 0x27, 
    0x2, 0x2, 0x112, 0x109, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x114, 0x115, 0x8, 0x9, 0x1, 0x2, 0x115, 0x118, 0x7, 0x29, 0x2, 
    0x2, 0x116, 0x119, 0x5, 0x16, 0xc, 0x2, 0x117, 0x119, 0x5, 0x12, 0xa, 
    0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x123, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x5, 0x16, 0xc, 
    0x2, 0x11b, 0x11c, 0x5, 0x16, 0xc, 0x2, 0x11c, 0x123, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x120, 0x5, 0x12, 0xa, 0x2, 0x11e, 0x121, 0x5, 0x16, 0xc, 
    0x2, 0x11f, 0x121, 0x5, 0x12, 0xa, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x114, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x123, 0x12b, 0x3, 0x2, 0x2, 
    0x2, 0x124, 0x127, 0xc, 0x5, 0x2, 0x2, 0x125, 0x128, 0x5, 0x16, 0xc, 
    0x2, 0x126, 0x128, 0x5, 0x12, 0xa, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x124, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 
    0x2, 0x12c, 0x11, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x137, 0x7, 0x2f, 0x2, 0x2, 0x12f, 0x134, 0x5, 0x14, 0xb, 0x2, 
    0x130, 0x131, 0x9, 0x3, 0x2, 0x2, 0x131, 0x133, 0x5, 0x14, 0xb, 0x2, 
    0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 
    0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x138, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x30, 0x2, 0x2, 
    0x13a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x140, 0x5, 0xa, 0x6, 0x2, 0x13c, 
    0x13d, 0x7, 0x2e, 0x2, 0x2, 0x13d, 0x13f, 0x5, 0xa, 0x6, 0x2, 0x13e, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x142, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x143, 0x14c, 
    0x7, 0x31, 0x2, 0x2, 0x144, 0x149, 0x5, 0xa, 0x6, 0x2, 0x145, 0x146, 
    0x7, 0x2e, 0x2, 0x2, 0x146, 0x148, 0x5, 0xa, 0x6, 0x2, 0x147, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x7, 0x32, 0x2, 0x2, 0x14f, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x152, 0x7, 0x33, 0x2, 0x2, 0x151, 0x153, 
    0x9, 0x3, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x154, 0x159, 
    0x5, 0x4, 0x3, 0x2, 0x155, 0x156, 0x9, 0x3, 0x2, 0x2, 0x156, 0x158, 
    0x5, 0x4, 0x3, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 
    0x3, 0x2, 0x2, 0x2, 0x15a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x154, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x160, 
    0x9, 0x3, 0x2, 0x2, 0x15f, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 
    0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 
    0x7, 0x34, 0x2, 0x2, 0x162, 0x19, 0x3, 0x2, 0x2, 0x2, 0x163, 0x16c, 
    0x7, 0x2f, 0x2, 0x2, 0x164, 0x169, 0x5, 0xa, 0x6, 0x2, 0x165, 0x166, 
    0x7, 0x2e, 0x2, 0x2, 0x166, 0x168, 0x5, 0xa, 0x6, 0x2, 0x167, 0x165, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 
    0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16d, 
    0x3, 0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 
    0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x30, 0x2, 0x2, 0x16f, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x173, 0x5, 0x1e, 0x10, 0x2, 0x171, 0x173, 
    0x5, 0x20, 0x11, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x173, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x7, 
    0x31, 0x2, 0x2, 0x175, 0x176, 0x5, 0x22, 0x12, 0x2, 0x176, 0x177, 0x7, 
    0x32, 0x2, 0x2, 0x177, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 
    0x31, 0x2, 0x2, 0x179, 0x17a, 0x7, 0x31, 0x2, 0x2, 0x17a, 0x17b, 0x5, 
    0x22, 0x12, 0x2, 0x17b, 0x17c, 0x7, 0x32, 0x2, 0x2, 0x17c, 0x17d, 0x7, 
    0x32, 0x2, 0x2, 0x17d, 0x21, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x5, 
    0x24, 0x13, 0x2, 0x17f, 0x23, 0x3, 0x2, 0x2, 0x2, 0x180, 0x186, 0x5, 
    0x26, 0x14, 0x2, 0x181, 0x182, 0x5, 0x26, 0x14, 0x2, 0x182, 0x183, 0x9, 
    0xe, 0x2, 0x2, 0x183, 0x184, 0x5, 0x24, 0x13, 0x2, 0x184, 0x186, 0x3, 
    0x2, 0x2, 0x2, 0x185, 0x180, 0x3, 0x2, 0x2, 0x2, 0x185, 0x181, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x25, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18d, 0x5, 0x28, 
    0x15, 0x2, 0x188, 0x189, 0x5, 0x28, 0x15, 0x2, 0x189, 0x18a, 0x7, 0x49, 
    0x2, 0x2, 0x18a, 0x18b, 0x5, 0x26, 0x14, 0x2, 0x18b, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x18c, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x18d, 0x27, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x195, 0x5, 0x2a, 
    0x16, 0x2, 0x18f, 0x195, 0x7, 0x29, 0x2, 0x2, 0x190, 0x191, 0x7, 0x2f, 
    0x2, 0x2, 0x191, 0x192, 0x5, 0x22, 0x12, 0x2, 0x192, 0x193, 0x7, 0x30, 
    0x2, 0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 0x18e, 0x3, 0x2, 
    0x2, 0x2, 0x194, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x194, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x195, 0x29, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x9, 0xf, 0x2, 
    0x2, 0x197, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x198, 0x1be, 0x7, 0x29, 0x2, 
    0x2, 0x199, 0x19b, 0x7, 0x2f, 0x2, 0x2, 0x19a, 0x19c, 0x7, 0x2b, 0x2, 
    0x2, 0x19b, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a2, 0x5, 0x2c, 0x17, 
    0x2, 0x19e, 0x19f, 0x9, 0x10, 0x2, 0x2, 0x19f, 0x1a1, 0x5, 0x2c, 0x17, 
    0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a4, 0x3, 0x2, 0x2, 
    0x2, 0x1a2, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x1a3, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a2, 0x3, 0x2, 0x2, 
    0x2, 0x1a5, 0x1a7, 0x7, 0x2b, 0x2, 0x2, 0x1a6, 0x1a5, 0x3, 0x2, 0x2, 
    0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1a9, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1be, 0x7, 0x30, 0x2, 
    0x2, 0x1ab, 0x1ad, 0x7, 0x31, 0x2, 0x2, 0x1ac, 0x1ae, 0x7, 0x2b, 0x2, 
    0x2, 0x1ad, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b4, 0x5, 0x2c, 0x17, 
    0x2, 0x1b0, 0x1b1, 0x7, 0x2e, 0x2, 0x2, 0x1b1, 0x1b3, 0x5, 0x2c, 0x17, 
    0x2, 0x1b2, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1b4, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 
    0x2, 0x1b5, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1be, 0x7, 0x32, 0x2, 
    0x2, 0x1ba, 0x1bb, 0x7, 0x29, 0x2, 0x2, 0x1bb, 0x1be, 0x5, 0x2e, 0x18, 
    0x2, 0x1bc, 0x1be, 0x7, 0x35, 0x2, 0x2, 0x1bd, 0x198, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x199, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c8, 0x7, 0x2f, 0x2, 
    0x2, 0x1c0, 0x1c5, 0x5, 0x2c, 0x17, 0x2, 0x1c1, 0x1c2, 0x7, 0x2e, 0x2, 
    0x2, 0x1c2, 0x1c4, 0x5, 0x2c, 0x17, 0x2, 0x1c3, 0x1c1, 0x3, 0x2, 0x2, 
    0x2, 0x1c4, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c5, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 0x2, 
    0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c0, 0x3, 0x2, 0x2, 
    0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1cb, 0x7, 0x30, 0x2, 0x2, 0x1cb, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x35, 0x3c, 0x40, 0x45, 0x4b, 0x4f, 0x53, 0x57, 0x5d, 0x64, 
    0x6d, 0x76, 0x81, 0x8c, 0x90, 0xad, 0xb1, 0xb4, 0xb8, 0xbc, 0xc3, 0xc7, 
    0xcb, 0xd1, 0xdf, 0xfc, 0xfe, 0x107, 0x112, 0x118, 0x120, 0x122, 0x127, 
    0x12b, 0x134, 0x137, 0x140, 0x149, 0x14c, 0x152, 0x159, 0x15c, 0x15f, 
    0x169, 0x16c, 0x172, 0x185, 0x18c, 0x194, 0x19b, 0x1a2, 0x1a6, 0x1a8, 
    0x1ad, 0x1b4, 0x1b7, 0x1bd, 0x1c5, 0x1c8, 
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
