//
// Created by Joel Courtney on 2019-03-13.
//

#include <Interpreter/MuonInterpreter.h>

#include "Interpreter/MuonInterpreter.h"
#include "Values/ValueFactory.h"

antlrcpp::Any MuonInterpreter::visitRValueStatement(MuonParser::RValueStatementContext* ctx) {
    auto res = visit(ctx->rvalue());
    env.pushAns(res.as<Value*>());
    return 0;
}

antlrcpp::Any MuonInterpreter::visitStringLiteral(MuonParser::StringLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Value*) ValueFactory::from(s.substr(1,s.size()-2));
}

antlrcpp::Any MuonInterpreter::visitPrint(MuonParser::PrintContext* ctx) {
    std::cout << visitChildren(ctx).as<Value*>()->toString() << std::endl;
    return 0;
}
