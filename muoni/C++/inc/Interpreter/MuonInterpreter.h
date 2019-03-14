//
// Created by Joel Courtney on 2019-03-13.
//

#ifndef C_MUONINTERPRETER_H
#define C_MUONINTERPRETER_H

#include "Grammar/MuonBaseVisitor.h"
#include "Environment/Environment.h"

class MuonInterpreter : public MuonBaseVisitor {
    Environment env;
public:
    antlrcpp::Any visitRValueStatement(MuonParser::RValueStatementContext*) override;
    antlrcpp::Any visitStringLiteral(MuonParser::StringLiteralContext*) override;
    antlrcpp::Any visitPrint(MuonParser::PrintContext*) override;
};

#endif //C_MUONINTERPRETER_H
