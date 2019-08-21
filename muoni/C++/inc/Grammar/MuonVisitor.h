
// Generated from Muon.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MuonParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MuonParser.
 */
class  MuonVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MuonParser.
   */
    virtual antlrcpp::Any visitFile(MuonParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitStatementControl(MuonParser::StatementControlContext *context) = 0;

    virtual antlrcpp::Any visitIfSeries(MuonParser::IfSeriesContext *context) = 0;

    virtual antlrcpp::Any visitLoop(MuonParser::LoopContext *context) = 0;

    virtual antlrcpp::Any visitWhileLoop(MuonParser::WhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitForLoop(MuonParser::ForLoopContext *context) = 0;

    virtual antlrcpp::Any visitForAsLoop(MuonParser::ForAsLoopContext *context) = 0;

    virtual antlrcpp::Any visitForAtLoop(MuonParser::ForAtLoopContext *context) = 0;

    virtual antlrcpp::Any visitForAsAtLoop(MuonParser::ForAsAtLoopContext *context) = 0;

    virtual antlrcpp::Any visitRValueStatement(MuonParser::RValueStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssign(MuonParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitDeclare(MuonParser::DeclareContext *context) = 0;

    virtual antlrcpp::Any visitDeclareAssign(MuonParser::DeclareAssignContext *context) = 0;

    virtual antlrcpp::Any visitDropName(MuonParser::DropNameContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclare(MuonParser::FunctionDeclareContext *context) = 0;

    virtual antlrcpp::Any visitPrint(MuonParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitBreakSnake(MuonParser::BreakSnakeContext *context) = 0;

    virtual antlrcpp::Any visitDeclareDimension(MuonParser::DeclareDimensionContext *context) = 0;

    virtual antlrcpp::Any visitUnitDeclaration(MuonParser::UnitDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitShapeOperation(MuonParser::ShapeOperationContext *context) = 0;

    virtual antlrcpp::Any visitAddSubOperation(MuonParser::AddSubOperationContext *context) = 0;

    virtual antlrcpp::Any visitCompOperation(MuonParser::CompOperationContext *context) = 0;

    virtual antlrcpp::Any visitExpOperation(MuonParser::ExpOperationContext *context) = 0;

    virtual antlrcpp::Any visitXOrOperation(MuonParser::XOrOperationContext *context) = 0;

    virtual antlrcpp::Any visitNotOperation(MuonParser::NotOperationContext *context) = 0;

    virtual antlrcpp::Any visitNegateOperation(MuonParser::NegateOperationContext *context) = 0;

    virtual antlrcpp::Any visitAndOperation(MuonParser::AndOperationContext *context) = 0;

    virtual antlrcpp::Any visitOrOperation(MuonParser::OrOperationContext *context) = 0;

    virtual antlrcpp::Any visitNoOperation(MuonParser::NoOperationContext *context) = 0;

    virtual antlrcpp::Any visitConvertOperation(MuonParser::ConvertOperationContext *context) = 0;

    virtual antlrcpp::Any visitAtomRValue(MuonParser::AtomRValueContext *context) = 0;

    virtual antlrcpp::Any visitIsOperation(MuonParser::IsOperationContext *context) = 0;

    virtual antlrcpp::Any visitSizeOperation(MuonParser::SizeOperationContext *context) = 0;

    virtual antlrcpp::Any visitMultDivOperation(MuonParser::MultDivOperationContext *context) = 0;

    virtual antlrcpp::Any visitLiteralAtom(MuonParser::LiteralAtomContext *context) = 0;

    virtual antlrcpp::Any visitNameAtom(MuonParser::NameAtomContext *context) = 0;

    virtual antlrcpp::Any visitInvokeAtom(MuonParser::InvokeAtomContext *context) = 0;

    virtual antlrcpp::Any visitMatrixAtom(MuonParser::MatrixAtomContext *context) = 0;

    virtual antlrcpp::Any visitListAtom(MuonParser::ListAtomContext *context) = 0;

    virtual antlrcpp::Any visitScopeAtom(MuonParser::ScopeAtomContext *context) = 0;

    virtual antlrcpp::Any visitRangeAtom(MuonParser::RangeAtomContext *context) = 0;

    virtual antlrcpp::Any visitFloatLiteral(MuonParser::FloatLiteralContext *context) = 0;

    virtual antlrcpp::Any visitImaginaryFloatLiteral(MuonParser::ImaginaryFloatLiteralContext *context) = 0;

    virtual antlrcpp::Any visitIntLiteral(MuonParser::IntLiteralContext *context) = 0;

    virtual antlrcpp::Any visitImaginaryIntLiteral(MuonParser::ImaginaryIntLiteralContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteral(MuonParser::StringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBoolLiteral(MuonParser::BoolLiteralContext *context) = 0;

    virtual antlrcpp::Any visitNullLiteral(MuonParser::NullLiteralContext *context) = 0;

    virtual antlrcpp::Any visitInvoke(MuonParser::InvokeContext *context) = 0;

    virtual antlrcpp::Any visitMatrix(MuonParser::MatrixContext *context) = 0;

    virtual antlrcpp::Any visitMatrixRow(MuonParser::MatrixRowContext *context) = 0;

    virtual antlrcpp::Any visitList(MuonParser::ListContext *context) = 0;

    virtual antlrcpp::Any visitScope(MuonParser::ScopeContext *context) = 0;

    virtual antlrcpp::Any visitRArgList(MuonParser::RArgListContext *context) = 0;

    virtual antlrcpp::Any visitSingleRange(MuonParser::SingleRangeContext *context) = 0;

    virtual antlrcpp::Any visitDoubleRange(MuonParser::DoubleRangeContext *context) = 0;

    virtual antlrcpp::Any visitType(MuonParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitUnit(MuonParser::UnitContext *context) = 0;

    virtual antlrcpp::Any visitDimension(MuonParser::DimensionContext *context) = 0;

    virtual antlrcpp::Any visitTypeRValue(MuonParser::TypeRValueContext *context) = 0;

    virtual antlrcpp::Any visitTypeMultiplyOperation(MuonParser::TypeMultiplyOperationContext *context) = 0;

    virtual antlrcpp::Any visitTypePowerOperation(MuonParser::TypePowerOperationContext *context) = 0;

    virtual antlrcpp::Any visitTypeAtom(MuonParser::TypeAtomContext *context) = 0;

    virtual antlrcpp::Any visitTypeLiteral(MuonParser::TypeLiteralContext *context) = 0;

    virtual antlrcpp::Any visitNameLValue(MuonParser::NameLValueContext *context) = 0;

    virtual antlrcpp::Any visitMatrixDecompositionLValue(MuonParser::MatrixDecompositionLValueContext *context) = 0;

    virtual antlrcpp::Any visitListDecompositionLValue(MuonParser::ListDecompositionLValueContext *context) = 0;

    virtual antlrcpp::Any visitSubsetLValue(MuonParser::SubsetLValueContext *context) = 0;

    virtual antlrcpp::Any visitDiscardLValue(MuonParser::DiscardLValueContext *context) = 0;

    virtual antlrcpp::Any visitLArgList(MuonParser::LArgListContext *context) = 0;


};

