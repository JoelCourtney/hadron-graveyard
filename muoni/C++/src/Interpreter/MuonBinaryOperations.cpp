//
// Created by joel on 8/4/19.
//

#include "Interpreter/MuonInterpreter.h"
#include "Data/DataFactory.h"

Any MuonInterpreter::visitAddSubOperation(MuonParser::AddSubOperationContext* ctx) {
    Data* v1 = visit(ctx->r1);
    Data* v2 = visit(ctx->r2);
    std::string bopText = ctx->bop->getText();
    switch (bopText[0]) {
        case '+':
            return v1->add(v2);
        case '-':
            return v1->subtract(v2);
        default:
            throw NotImplementedError();
    }
}