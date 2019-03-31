//
// Created by Joel Courtney on 2019-03-13.
//

#include <Interpreter/MuonInterpreter.h>

#include "Interpreter/MuonInterpreter.h"
#include "Values/ValueFactory.h"
#include <complex>
#include "Environment/FileScope.h"

Any MuonInterpreter::visitFile(MuonParser::FileContext* ctx) {
    env.push(new FileScope());
    visitChildren(ctx);
    env.pop();
    return 0;
}

Any MuonInterpreter::visitRValueStatement(MuonParser::RValueStatementContext* ctx) {
    auto v = visit(ctx->rvalue());
    env.pushAns(v);
    return 0;
}

Any MuonInterpreter::visitAssign(MuonParser::AssignContext* ctx) {
    valueToAssign = visit(ctx->rvalue()).as<Value*>();
    visit(ctx->lvalue());
    return 0;
}

Any MuonInterpreter::visitDeclare(MuonParser::DeclareContext* ctx) {
    valueToAssign = ValueFactory::from();
    mutabilityToDeclare = ctx->VAR() != nullptr;
    inDeclare = true;
    visit(ctx->lvalue());
    inDeclare = false;
    return 0;
}

Any MuonInterpreter::visitDeclareAssign(MuonParser::DeclareAssignContext* ctx) {
    valueToAssign = visit(ctx->rvalue()).as<Value*>();
    mutabilityToDeclare = ctx->VAR() != nullptr;
    inDeclare = true;
    visit(ctx->lvalue());
    inDeclare = false;
    return 0;
}

Any MuonInterpreter::visitPrint(MuonParser::PrintContext* ctx) {
    std::cout << visit(ctx->rvalue()).as<Value*>()->toString() << std::endl;
    return 0;
}

Any MuonInterpreter::visitNameAtom(MuonParser::NameAtomContext* ctx) {
    return env.getVarl(ctx->getText());
}

Any MuonInterpreter::visitFloatLiteral(MuonParser::FloatLiteralContext* ctx) {
    return (Value*) ValueFactory::from(std::stod(ctx->getText()));
}

Any MuonInterpreter::visitImaginaryFloatLiteral(MuonParser::ImaginaryFloatLiteralContext* ctx) {
    std::string s = ctx->getText();
    s.erase(std::remove(s.begin(), s.end(), 'i'), s.end());
    return (Value*) ValueFactory::from(std::complex<double>(0,std::stod(s)));
}

Any MuonInterpreter::visitIntLiteral(MuonParser::IntLiteralContext* ctx) {
    return (Value*) ValueFactory::from(std::stoi(ctx->getText()));
}

Any MuonInterpreter::visitImaginaryIntLiteral(MuonParser::ImaginaryIntLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Value*) ValueFactory::from(std::complex<int>(0,std::stoi(s.substr(0,s.size()-1))));
}

Any MuonInterpreter::visitStringLiteral(MuonParser::StringLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Value*) ValueFactory::from(s.substr(1,s.size()-2));
}

Any MuonInterpreter::visitBoolLiteral(MuonParser::BoolLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Value*) ValueFactory::from(s == "true");
}

Any MuonInterpreter::visitNullLiteral(MuonParser::NullLiteralContext*) {
    return (Value*) ValueFactory::from();
}

Any MuonInterpreter::visitNameLValue(MuonParser::NameLValueContext* ctx) {
    std::string name = ctx->getText();
    if (inDeclare) {
        env.declareVarl(name, mutabilityToDeclare);
    }
    env.assignVarl(name, valueToAssign);
    return 0;
}
