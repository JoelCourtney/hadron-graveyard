//
// Created by joel on 8/4/19.
//

#include "Interpreter/MuonInterpreter.h"
#include "Data/DataFactory.h"
#include <complex>
#include "Environment/FileScope.h"
#include "Errors/VarlNotFoundError.h"

Any MuonInterpreter::visitFloatLiteral(MuonParser::FloatLiteralContext* ctx) {
    if (ctx->cache)
        return ctx->cache.as<Data*>()->clone();
    Data* res = (Data*) DataFactory::from(std::stod(ctx->getText()));
    ctx->cache = res->clone();
    return res;
}

Any MuonInterpreter::visitImaginaryFloatLiteral(MuonParser::ImaginaryFloatLiteralContext* ctx) {
    std::string s = ctx->getText();
    s.erase(std::remove(s.begin(), s.end(), 'i'), s.end());
    return (Data*) DataFactory::from(std::complex<double>(0,std::stod(s)));
}

Any MuonInterpreter::visitIntLiteral(MuonParser::IntLiteralContext* ctx) {
    return (Data*) DataFactory::from(std::stoi(ctx->getText()));
}

Any MuonInterpreter::visitImaginaryIntLiteral(MuonParser::ImaginaryIntLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Data*) DataFactory::from(std::complex<int>(0,std::stoi(s.substr(0,s.size()-1))));
}

Any MuonInterpreter::visitStringLiteral(MuonParser::StringLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Data*) DataFactory::from(s.substr(1,s.size()-2));
}

Any MuonInterpreter::visitBoolLiteral(MuonParser::BoolLiteralContext* ctx) {
    std::string s = ctx->getText();
    return (Data*) DataFactory::from(s == "true");
}

Any MuonInterpreter::visitNullLiteral(MuonParser::NullLiteralContext*) {
    return (Data*) DataFactory::from();
}
