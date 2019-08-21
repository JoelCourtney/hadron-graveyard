//
// Created by Joel Courtney on 2019-08-11.
//

#include <Data/List.h>
#include <Environment/ExplicitScope.h>
#include <Environment/ImplicitScope.h>
#include <Data/DataFactory.h>
#include "Interpreter/MuonInterpreter.h"

Any MuonInterpreter::visitScope(MuonParser::ScopeContext* ctx) {
    env.push(new ExplicitScope(env.topScope()));
    for (auto control : ctx->control()) {
        visit(control);
    }
    return env.pop();
}

Any MuonInterpreter::visitLoop(MuonParser::LoopContext* ctx) {
    while (true) {
        visit(ctx->statement());
    }
    return 0;
}

Any MuonInterpreter::visitWhileLoop(MuonParser::WhileLoopContext* ctx) {
    while (visit(ctx->rvalue()).as<Data*>()->toBool()) {
        visit(ctx->statement());
    }
    return 0;
}

Any MuonInterpreter::visitForLoop(MuonParser::ForLoopContext *ctx) {
    Data* over = visit(ctx->rvalue());
    switch (over->type) {
        case Type::LIST: {
            int size = reinterpret_cast<List*>(over)->l.size();
            for (int i = 0; i < size; i++) {
                visit(ctx->statement());
            }
        } break;
        default:
            throw NotImplementedError();
    }
    return 0;
}

Any MuonInterpreter::visitForAsLoop(MuonParser::ForAsLoopContext *ctx) {
    ImplicitScope* scope = env.pushDefaultImplicitScope();
    Data* over = visit(ctx->rvalue());
    switch (over->type) {
        case Type::LIST: {
            auto list = reinterpret_cast<List*>(over)->l;
            inDeclare = true;
            for (auto item : list) {
                valueToAssign = item;
                visit(ctx->as);
                inDeclare = false;
                scope->lock();
                visit(ctx->statement());
            }
        } break;
        default:
            throw NotImplementedError();
    }
    env.pop();
    return 0;
}

Any MuonInterpreter::visitForAtLoop(MuonParser::ForAtLoopContext *ctx) {
    ImplicitScope* scope = env.pushDefaultImplicitScope();
    Data* over = visit(ctx->rvalue());
    switch (over->type) {
        case Type::LIST: {
            int size = reinterpret_cast<List*>(over)->l.size();
            inDeclare = true;
            for (int i = 0; i < size; i++) {
                valueToAssign = DataFactory::from(i);
                visit(ctx->at);
                inDeclare = false;
                scope->lock();
                visit(ctx->statement());
            }
        } break;
        default:
            throw NotImplementedError();
    }
    env.pop();
    return 0;
}