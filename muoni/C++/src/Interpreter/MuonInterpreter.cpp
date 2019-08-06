//
// Created by Joel Courtney on 2019-03-13.
//

#include "Interpreter/MuonInterpreter.h"
#include "Values/DataFactory.h"
#include <complex>
#include "Environment/FileScope.h"
#include "Errors/VarlNotFoundError.h"

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
    valueToAssign = visit(ctx->rvalue()).as<Data*>();
    visit(ctx->lvalue());
    return 0;
}

Any MuonInterpreter::visitDeclare(MuonParser::DeclareContext* ctx) {
    valueToAssign = DataFactory::from();
    mutabilityToDeclare = ctx->VAR() != nullptr;
    inDeclare = true;
    visit(ctx->lvalue());
    inDeclare = false;
    return 0;
}

Any MuonInterpreter::visitDeclareAssign(MuonParser::DeclareAssignContext* ctx) {
    valueToAssign = visit(ctx->rvalue()).as<Data*>();
    mutabilityToDeclare = ctx->VAR() != nullptr;
    inDeclare = true;
    visit(ctx->lvalue());
    inDeclare = false;
    return 0;
}

Any MuonInterpreter::visitPrint(MuonParser::PrintContext* ctx) {
    try {
        std::cout << visit(ctx->rvalue()).as<Data*>()->toString() << std::endl;
    } catch (const VarlNotFoundError& e) {
        std::cout << "not found" << std::endl;
    }
    return 0;
}

Any MuonInterpreter::visitNameAtom(MuonParser::NameAtomContext* ctx) {
        return env.getVarl(ctx->getText());
}


