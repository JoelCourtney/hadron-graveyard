//
// Created by joel on 8/4/19.
//

#include "Interpreter/MuonInterpreter.h"


Any MuonInterpreter::visitNameLValue(MuonParser::NameLValueContext* ctx) {
    std::string name = ctx->getText();
    if (inDeclare) {
        env.declareVarl(name, mutabilityToDeclare);
    }
    env.assignVarl(name, valueToAssign);
    return 0;
}