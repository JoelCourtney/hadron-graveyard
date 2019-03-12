#include <iostream>
#include <cstdio>
#include <ctime>

#include "antlr4-runtime.h"

void doStuffs(int argc, char* argv[]) {
    std::ifstream stream("../test/basic.mu");
    if (stream.is_open()) {
        antlr4::misc::InterpreterData lexerData =
                antlr4::misc::InterpreterDataReader::parseFile("../grammar/antlr4-runtime/MuonLexer.interp");
        antlr4::misc::InterpreterData parserData =
                antlr4::misc::InterpreterDataReader::parseFile("../grammar/antlr4-runtime/Muon.interp");

        antlr4::ANTLRInputStream input(stream);
        antlr4::LexerInterpreter lexEngine("muon_lexer", lexerData.vocabulary, lexerData.ruleNames,
                lexerData.channels, lexerData.modes, lexerData.atn, &input);

        antlr4::CommonTokenStream tokens(&lexEngine);

        tokens.fill();
        std::cout << "INPUT:" << std::endl;
        for (auto token : tokens.getTokens()) {
            std::cout << token->toString() << std::endl;
        }

        antlr4::ParserInterpreter parser("muon_parser", parserData.vocabulary, parserData.ruleNames,
                                 parserData.atn, &tokens);
        antlr4::tree::ParseTree *tree = parser.parse(parser.getRuleIndex("control"));

        std::cout << "parse tree: " << tree->toStringTree(&parser) << std::endl;

    }
}

int main(int argc, char* argv[]) {
    std::cout << std::boolalpha;

    std::clock_t start = std::clock();

    doStuffs(argc,argv);

    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Time: "<< duration << std::endl;
    return 0;
}
