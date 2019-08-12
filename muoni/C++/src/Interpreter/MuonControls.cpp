//
// Created by Joel Courtney on 2019-08-11.
//

#include <Data/List.h>
#include <Environment/ExplicitScope.h>
#include <Environment/ImplicitScope.h>
#include "Interpreter/MuonInterpreter.h"

Any MuonInterpreter::visitScope(MuonParser::ScopeContext* ctx) {
    env.push(new ExplicitScope(env.topScope()));
    for (auto control : ctx->control()) {
        visit(control);
    }
    return env.pop();
}

Any MuonInterpreter::visitForLoop(MuonParser::ForLoopContext *ctx) {
    Data* over = visit(ctx->rvalue());
    switch (over->getType()) {
        case Type::LIST: {
            int size = reinterpret_cast<List*>(over)->l.size();
            for (int i = 0; i < size; i++) {
                visit(ctx->statement());
            }
        }
    }
    return 0;
}

Any MuonInterpreter::visitForAsLoop(MuonParser::ForAsLoopContext *ctx) {
    env.push(new ImplicitScope(env.topScope()));
    Data* over = visit(ctx->rvalue());
    switch (over->getType()) {
        case Type::LIST: {
            int size = reinterpret_cast<List*>(over)->l.size();
            for (int i = 0; i < size; i++) {
                visit(ctx->statement());
            }
        }
    }
    return 0;
}
