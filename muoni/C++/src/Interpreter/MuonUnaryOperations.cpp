//
// Created by joel on 8/4/19.
//

#include "Interpreter/MuonInterpreter.h"

Any MuonInterpreter::visitNegateOperation(MuonParser::NegateOperationContext* ctx) {
    return visit(ctx->r).as<Data*>()->negate();
}