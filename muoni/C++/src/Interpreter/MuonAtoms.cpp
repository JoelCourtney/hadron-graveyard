//
// Created by Joel Courtney on 2019-08-07.
//

#include <Data/DataFactory.h>
#include "Interpreter/MuonInterpreter.h"

Any MuonInterpreter::visitNameAtom(MuonParser::NameAtomContext* ctx) {
    return env.getVarl(ctx->getText());
}

Any MuonInterpreter::visitMatrix(MuonParser::MatrixContext* ctx) {
    auto rows = ctx->matrixRow();
    int rowCount = rows.size();
    switch (rowCount) {
        case 0: {
            Eigen::MatrixXd m(0,0);
            return (Data*) DataFactory::from((Eigen::MatrixXd) m);
        }
        case 1:
            return dynamic_cast<Data*>(visitMatrixRow(rows[0]).as<Numeric*>());
        default: {
            std::vector<Numeric*> elems(rowCount);
            Type type = Type::INT_MATRIX;
            int height = 0;
            int width = -1;
            for (int i = 0; i < rowCount; i++) {
                Numeric* elem = visitMatrixRow(rows[i]).as<Numeric*>();
                if (width == -1) {
                    width = elem->getCols();
                } else if (width != elem->getCols()) {
                    throw InvalidOperationError();
                }
                height += elem->getRows();
                Type newType = elem->getType();
                switch (type) {
                    case Type::INT_MATRIX:
                        switch (newType) {
                            case Type::FLOAT:
                            case Type::FLOAT_MATRIX:
                                type = Type::FLOAT_MATRIX;
                                break;
                            case Type::BOOL:
                            case Type::INT:
                            case Type::BIG_INT:
                            case Type::INT_MATRIX:
                                break;
                            case Type::STRING:
                            case Type::NULL_TYPE:
                            case Type::LIST:
                                throw InvalidConversionError();
                            case Type::COMPLEX_INT:
                            case Type::COMPLEX_FLOAT:
                                throw NotImplementedError();
                        }
                        break;
                    case Type::FLOAT_MATRIX:
                        switch (newType) {
                            case Type::STRING:
                            case Type::NULL_TYPE:
                            case Type::LIST:
                                throw InvalidConversionError();
                            case Type::COMPLEX_INT:
                            case Type::COMPLEX_FLOAT:
                                throw NotImplementedError();
                            default:
                                break;
                        }
                        break;
                    default:
                        throw NotImplementedError();
                }
                elems[i] = elem;
            }
            switch (type) {
                case Type::INT_MATRIX: {
                    Eigen::MatrixXi m(height, width);
                    int accum = 0;
                    for (Numeric* d : elems) {
                        int r = d->getRows();
                        m.block(accum, 0, r, width) = d->toIntMatrix();
                        accum += r;
                    }
                    return (Data*) DataFactory::from(m);
                }
                case Type::FLOAT_MATRIX: {
                    Eigen::MatrixXd m(height, width);
                    int accum = 0;
                    for (Numeric* d : elems) {
                        int r = d->getRows();
                        m.block(accum, 0, r, width) = d->toFloatMatrix();
                        accum += r;
                    }
                    return (Data*) DataFactory::from(m);
                }
                default:
                    throw NotImplementedError();
            }
        }
    }
}

Any MuonInterpreter::visitMatrixRow(MuonParser::MatrixRowContext* ctx) {
    auto cols = ctx->rvalue();
    int numCols = cols.size();
    int height = -1;
    int width = 0;
    Type type = Type::NULL_TYPE;
    std::vector<Numeric*> elems(numCols);
    for (int i = 0; i < numCols; i++) {
        Data* elem = visit(cols[i]).as<Data*>();
        if (elem->isNumeric()) {
            Numeric* num = reinterpret_cast<Numeric*>(elem);
            width += num->getCols();
            if (height == -1) {
                height = num->getRows();
            } else if (height != num->getRows()) {
                throw InvalidOperationError();
            }
            Type newType = num->getType();
            switch (type) {
                case Type::NULL_TYPE:
                    type = newType;
                    break;
                case Type::BOOL:
                    type = newType;
                    break;
                case Type::INT:
                    switch (newType) {
                        case Type::BOOL:
                        case Type::INT:
                            break;
                        default:
                            type = newType;
                            break;
                    }
                    break;
                case Type::BIG_INT:
                    switch (newType) {
                        case Type::BOOL:
                        case Type::INT:
                        case Type::BIG_INT:
                            break;
                        default:
                            type = newType;
                            break;
                    }
                    break;
                case Type::FLOAT:
                    switch (newType) {
                        case Type::BOOL:
                        case Type::INT:
                        case Type::BIG_INT:
                        case Type::FLOAT:
                            break;
                        case Type::INT_MATRIX:
                            type = Type::FLOAT_MATRIX;
                            break;
                        case Type::COMPLEX_INT:
                            type = Type::COMPLEX_FLOAT;
                            break;
                        default:
                            type = newType;
                            break;
                    }
                    break;
                case Type::COMPLEX_INT:
                    switch (newType) {
                        case Type::BOOL:
                        case Type::INT:
                        case Type::BIG_INT:
                        case Type::COMPLEX_INT:
                            break;
                        case Type::FLOAT:
                        case Type::COMPLEX_FLOAT:
                            type = Type::COMPLEX_FLOAT;
                            break;
                        case Type::INT_MATRIX:
                        case Type::FLOAT_MATRIX:
                            throw NotImplementedError();
                        default:
                            type = newType;
                            break;
                    }
                    break;
                case Type::COMPLEX_FLOAT:
                    switch (newType) {
                        case Type::INT_MATRIX:
                        case Type::FLOAT_MATRIX:
                            throw NotImplementedError();
                        default:
                            break;
                    }
                    break;
                case Type::INT_MATRIX:
                    switch (newType) {
                        case Type::FLOAT:
                        case Type::FLOAT_MATRIX:
                            type = Type::FLOAT_MATRIX;
                            break;
                        case Type::COMPLEX_INT:
                        case Type::COMPLEX_FLOAT:
                            throw NotImplementedError();
                        default:
                            break;
                    }
                    break;
                case Type::FLOAT_MATRIX:
                    switch (newType) {
                        case Type::COMPLEX_INT:
                        case Type::COMPLEX_FLOAT:
                            throw NotImplementedError();
                        default:
                            break;
                    }
                    break;
                default:
                    throw NotImplementedError();
            }
            elems[i] = num;
        } else {
            throw InvalidConversionError();
        }
    }
    if (elems.size() == 1)
        return (Numeric*) elems[0];
    switch (type) {
        case Type::INT:
        case Type::BIG_INT:
        case Type::BOOL:
        case Type::INT_MATRIX: {
            Eigen::MatrixXi m(height, width);
            int accum = 0;
            for (Numeric* d : elems) {
                int c = d->getCols();
                m.block(0, accum, height, c) = d->toIntMatrix();
                accum += c;
            }
            return (Numeric*) DataFactory::from(m);
        }
        default: {
            Eigen::MatrixXd m(height, width);
            int accum = 0;
            for (Numeric* d : elems) {
                int c = d->getCols();
                m.block(0, accum, height, c) = d->toFloatMatrix();
                accum += c;
            }
            return (Numeric*) DataFactory::from(m);
        }
    }
}

Any MuonInterpreter::visitList(MuonParser::ListContext* ctx) {
    int size = ctx->COMMA().size() + 1;
    std::vector<Data*> l(size);
    for (int i = 0; i < size; i++) {
        l[i] = visit(ctx->rvalue(i)).as<Data*>();
    }
    return (Data*) DataFactory::from(l);
}