#include <iostream>
#include <cstdio>
#include <ctime>

#include "antlr4-runtime.h"
#include "Grammar/MuonLexer.h"
#include "Grammar/MuonParser.h"
#include "Interpreter/MuonInterpreter.h"

void doStuffs(int argc, char* argv[]) {
    std::ifstream stream("../test/small.mu");
    if (stream.is_open()) {
        antlr4::ANTLRInputStream input(stream);

        MuonLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        MuonParser parser(&tokens);
        parser.setBuildParseTree(true);

        antlr4::tree::ParseTree* tree = parser.file();

        std::cout << "parse tree: " << tree->toStringTree(&parser) << std::endl;

        MuonInterpreter muon;
        muon.visit(tree);
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
