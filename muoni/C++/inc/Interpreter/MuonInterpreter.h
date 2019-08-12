//
// Created by Joel Courtney on 2019-03-13.
//

#ifndef C_MUONINTERPRETER_H
#define C_MUONINTERPRETER_H

#include "Grammar/MuonBaseVisitor.h"
#include "Environment/Environment.h"

using namespace antlrcpp;

class MuonInterpreter : public MuonBaseVisitor {
    Environment env;
    Data* valueToAssign;
    bool mutabilityToDeclare;
    bool inDeclare = false;

public:
    Any visitFile(MuonParser::FileContext*) override;

    Any visitRValueStatement(MuonParser::RValueStatementContext*) override;
    Any visitAssign(MuonParser::AssignContext*) override;
    Any visitDeclare(MuonParser::DeclareContext*) override;
    Any visitDeclareAssign(MuonParser::DeclareAssignContext*) override;
    Any visitPrint(MuonParser::PrintContext*) override;


    // MuonLiterals.cpp
    Any visitFloatLiteral(MuonParser::FloatLiteralContext*) override;
    Any visitImaginaryFloatLiteral(MuonParser::ImaginaryFloatLiteralContext*) override;
    Any visitIntLiteral(MuonParser::IntLiteralContext*) override;
    Any visitImaginaryIntLiteral(MuonParser::ImaginaryIntLiteralContext*) override;
    Any visitStringLiteral(MuonParser::StringLiteralContext*) override;
    Any visitBoolLiteral(MuonParser::BoolLiteralContext*) override;
    Any visitNullLiteral(MuonParser::NullLiteralContext*) override;

    // MuonLValues.cpp
    Any visitNameLValue(MuonParser::NameLValueContext*) override;
    
    // MuonBinaryOperations.cpp
    Any visitAddSubOperation(MuonParser::AddSubOperationContext*) override;
    
    // MuonAtoms.cpp
    Any visitNameAtom(MuonParser::NameAtomContext*) override;
    Any visitMatrix(MuonParser::MatrixContext*) override;
    Any visitMatrixRow(MuonParser::MatrixRowContext*) override;
    Any visitList(MuonParser::ListContext*) override;
    
    // MuonControls.cpp
    Any visitScope(MuonParser::ScopeContext*) override;
    Any visitForLoop(MuonParser::ForLoopContext*) override;
    Any visitForAsLoop(MuonParser::ForAsLoopContext*) override;
};

#endif //C_MUONINTERPRETER_H
