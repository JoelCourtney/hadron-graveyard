
// Generated from Muon.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  MuonLexer : public antlr4::Lexer {
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
    DOLLAR = 63, PERCENT = 64, AMPERSAND = 65, DOT = 66, STAR = 67, MATSTAR = 68, 
    SLASH = 69, MATSLASH = 70, CARROT = 71, MATCARROT = 72, BLOCK_COMMENT = 73, 
    WHITESPACE = 74
  };

  MuonLexer(antlr4::CharStream *input);
  ~MuonLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

