
// Generated from Muon.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MuonVisitor.h"


/**
 * This class provides an empty implementation of MuonVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MuonBaseVisitor : public MuonVisitor {
public:

  virtual antlrcpp::Any visitFile(MuonParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementControl(MuonParser::StatementControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfSeries(MuonParser::IfSeriesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop(MuonParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLoop(MuonParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForLoop(MuonParser::ForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForAsLoop(MuonParser::ForAsLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForAtLoop(MuonParser::ForAtLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForAsAtLoop(MuonParser::ForAsAtLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRValueStatement(MuonParser::RValueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(MuonParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclare(MuonParser::DeclareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareAssign(MuonParser::DeclareAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropName(MuonParser::DropNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclare(MuonParser::FunctionDeclareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(MuonParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakSnake(MuonParser::BreakSnakeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareDimension(MuonParser::DeclareDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnitDeclaration(MuonParser::UnitDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrOperation(MuonParser::OrOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOperation(MuonParser::UnaryOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubOperation(MuonParser::AddSubOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompOperation(MuonParser::CompOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConvertOperation(MuonParser::ConvertOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomRValue(MuonParser::AtomRValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpOperation(MuonParser::ExpOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXOrOperation(MuonParser::XOrOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsOperation(MuonParser::IsOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndOperation(MuonParser::AndOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultDivOperation(MuonParser::MultDivOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralAtom(MuonParser::LiteralAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNameAtom(MuonParser::NameAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInvokeAtom(MuonParser::InvokeAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatrixAtom(MuonParser::MatrixAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListAtom(MuonParser::ListAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScopeAtom(MuonParser::ScopeAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatLiteral(MuonParser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImaginaryFloatLiteral(MuonParser::ImaginaryFloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntLiteral(MuonParser::IntLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImaginaryIntLiteral(MuonParser::ImaginaryIntLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLiteral(MuonParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolLiteral(MuonParser::BoolLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullLiteral(MuonParser::NullLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInvoke(MuonParser::InvokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatrix(MuonParser::MatrixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatrixRow(MuonParser::MatrixRowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList(MuonParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScope(MuonParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRArgList(MuonParser::RArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(MuonParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnit(MuonParser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDimension(MuonParser::DimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeRValue(MuonParser::TypeRValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeMultiplyOperation(MuonParser::TypeMultiplyOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypePowerOperation(MuonParser::TypePowerOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAtom(MuonParser::TypeAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeLiteral(MuonParser::TypeLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNameLValue(MuonParser::NameLValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatrixDecompositionLValue(MuonParser::MatrixDecompositionLValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListDecompositionLValue(MuonParser::ListDecompositionLValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubsetLValue(MuonParser::SubsetLValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiscardLValue(MuonParser::DiscardLValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLArgList(MuonParser::LArgListContext *ctx) override {
    return visitChildren(ctx);
  }


};

