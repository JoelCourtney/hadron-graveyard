/*
 * Copyright (c) 2012, 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * The Universal Permissive License (UPL), Version 1.0
 *
 * Subject to the condition set forth below, permission is hereby granted to any
 * person obtaining a copy of this software, associated documentation and/or
 * data (collectively the "Software"), free of charge and under any and all
 * copyright rights in the Software, and any and all patent rights owned or
 * freely licensable by each licensor hereunder covering either (i) the
 * unmodified Software as contributed to or provided by such licensor, or (ii)
 * the Larger Works (as defined below), to deal in both
 *
 * (a) the Software, and
 *
 * (b) any piece of software and/or hardware listed in the lrgrwrks.txt file if
 * one is included with the Software each a "Larger Work" to which the Software
 * is contributed by such licensors),
 *
 * without restriction, including without limitation the rights to copy, create
 * derivative works of, display, perform, and distribute the Software and make,
 * use, sell, offer for sale, import, export, have made, and have sold the
 * Software and the Larger Work(s), and to sublicense the foregoing rights on
 * either these or other terms.
 *
 * This license is subject to the following condition:
 *
 * The above copyright notice and either this complete permission notice or at a
 * minimum a reference to the UPL must be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
package net.joelcourtney.hadron.parser;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.joelcourtney.hadron.HadronLanguage;
import net.joelcourtney.hadron.nodes.HadronExpressionNode;
import net.joelcourtney.hadron.nodes.HadronRootNode;
import net.joelcourtney.hadron.nodes.HadronStatementNode;
import net.joelcourtney.hadron.nodes.controlflow.*;
import net.joelcourtney.hadron.nodes.expression.*;
import net.joelcourtney.hadron.nodes.local.HadronReadArgumentNode;
import net.joelcourtney.hadron.nodes.local.HadronReadLocalVariableNode;
import net.joelcourtney.hadron.nodes.local.HadronWriteLocalVariableNode;
import net.joelcourtney.hadron.nodes.util.HadronUnboxNode;
import net.joelcourtney.hadron.nodes.util.HadronUnboxNodeGen;
import org.antlr.v4.runtime.Parser;
import org.antlr.v4.runtime.Token;

import com.oracle.truffle.api.RootCallTarget;
import com.oracle.truffle.api.Truffle;
import com.oracle.truffle.api.frame.FrameDescriptor;
import com.oracle.truffle.api.frame.FrameSlot;
import com.oracle.truffle.api.frame.FrameSlotKind;
import com.oracle.truffle.api.source.Source;
import com.oracle.truffle.api.source.SourceSection;
import net.joelcourtney.hadron.nodes.controlflow.HadronFunctionBodyNode;
import net.joelcourtney.hadron.nodes.expression.HadronInvokeNode;
import net.joelcourtney.hadron.nodes.local.HadronReadLocalVariableNodeGen;
import net.joelcourtney.hadron.nodes.local.HadronWriteLocalVariableNodeGen;
import sun.reflect.generics.reflectiveObjects.NotImplementedException;

/**
 * Helper class used by the SL {@link Parser} to create nodes. The code is factored out of the
 * automatically generated parser to keep the attributed grammar of SL small.
 */
public class HadronNodeFactory {

    /**
     * Local variable names that are visible in the current block. Variables are not visible outside
     * of their defining block, to prevent the usage of undefined variables. Because of that, we can
     * decide during parsing if a name references a local variable or is a function name.
     */
    static class LexicalScope {
        protected final LexicalScope outer;
        protected final Map<String, FrameSlot> locals;

        LexicalScope(LexicalScope outer) {
            this.outer = outer;
            this.locals = new HashMap<>();
            if (outer != null) {
                locals.putAll(outer.locals);
            }
        }
    }

    /* State while parsing a source unit. */
    private final Source source;
    private final Map<String, RootCallTarget> allFunctions;

    /* State while parsing a function. */
    private int functionStartPos;
    private String functionName;
    private int functionBodyStartPos; // includes parameter list
    private int parameterCount;
    private FrameDescriptor frameDescriptor;
    private List<HadronStatementNode> methodNodes;

    /* State while parsing a block. */
    private LexicalScope lexicalScope;
    private final HadronLanguage language;

    public HadronNodeFactory(HadronLanguage language, Source source) {
        this.language = language;
        this.source = source;
        this.allFunctions = new HashMap<>();
    }

    public Map<String, RootCallTarget> getAllFunctions() {
        return allFunctions;
    }

    public void startFunction(Token nameToken, Token bodyStartToken) {
        assert functionStartPos == 0;
        assert functionName == null;
        assert functionBodyStartPos == 0;
        assert parameterCount == 0;
        assert frameDescriptor == null;
        assert lexicalScope == null;

        functionStartPos = nameToken.getStartIndex();
        functionName = nameToken.getText();
        functionBodyStartPos = bodyStartToken.getStartIndex();
        frameDescriptor = new FrameDescriptor();
        methodNodes = new ArrayList<>();
        startBlock();
    }

    public void addFormalParameter(Token nameToken) {
        /*
         * Method parameters are assigned to local variables at the beginning of the method. This
         * ensures that accesses to parameters are specialized the same way as local variables are
         * specialized.
         */
        final HadronReadArgumentNode readArg = new HadronReadArgumentNode(parameterCount);
        HadronExpressionNode assignment = createAssignment(createStringLiteral(nameToken, false), readArg, parameterCount);
        methodNodes.add(assignment);
        parameterCount++;
    }

    public void finishFunction(HadronStatementNode bodyNode) {
        if (bodyNode == null) {
            // a state update that would otherwise be performed by finishBlock
            lexicalScope = lexicalScope.outer;
        } else {
            methodNodes.add(bodyNode);
            final int bodyEndPos = bodyNode.getSourceEndIndex();
            final SourceSection functionSrc = source.createSection(functionStartPos, bodyEndPos - functionStartPos);
            final HadronStatementNode methodBlock = finishBlock(methodNodes, functionBodyStartPos, bodyEndPos - functionBodyStartPos);
            assert lexicalScope == null : "Wrong scoping of blocks in parser";

            final HadronFunctionBodyNode functionBodyNode = new HadronFunctionBodyNode(methodBlock);
            functionBodyNode.setSourceSection(functionSrc.getCharIndex(), functionSrc.getCharLength());

            final HadronRootNode rootNode = new HadronRootNode(language, frameDescriptor, functionBodyNode, functionSrc, functionName);
            allFunctions.put(functionName, Truffle.getRuntime().createCallTarget(rootNode));
        }

        functionStartPos = 0;
        functionName = null;
        functionBodyStartPos = 0;
        parameterCount = 0;
        frameDescriptor = null;
        lexicalScope = null;
    }

    public void startBlock() {
        lexicalScope = new LexicalScope(lexicalScope);
    }

    public HadronExpressionNode finishBlock(List<HadronStatementNode> bodyNodes, int startPos, int length) {
        lexicalScope = lexicalScope.outer;

        if (containsNull(bodyNodes)) {
            return null;
        }

        List<HadronStatementNode> flattenedNodes = new ArrayList<>(bodyNodes.size());
        flattenBlocks(bodyNodes, flattenedNodes);
        for (HadronStatementNode statement : flattenedNodes) {
            if (statement.hasSource() && !isHaltInCondition(statement)) {
                statement.addStatementTag();
            }
        }
        HadronBlockNode blockNode = new HadronBlockNode(flattenedNodes.toArray(new HadronStatementNode[flattenedNodes.size()]));
        blockNode.setSourceSection(startPos, length);
        return blockNode;
    }

    private static boolean isHaltInCondition(HadronStatementNode statement) {
        return (statement instanceof HadronIfNode) || (statement instanceof HadronWhileNode);
    }

    private void flattenBlocks(Iterable<? extends HadronStatementNode> bodyNodes, List<HadronStatementNode> flattenedNodes) {
        for (HadronStatementNode n : bodyNodes) {
            if (n instanceof HadronBlockNode) {
                flattenBlocks(((HadronBlockNode) n).getStatements(), flattenedNodes);
            } else {
                flattenedNodes.add(n);
            }
        }
    }

    /**
     * Returns an {@link HadronDebuggerNode} for the given token.
     *
     * @param debuggerToken The token containing the debugger node's info.
     * @return A HadronDebuggerNode for the given token.
     */
    HadronStatementNode createDebugger(Token debuggerToken) {
        final HadronDebuggerNode debuggerNode = new HadronDebuggerNode();
        srcFromToken(debuggerNode, debuggerToken);
        return debuggerNode;
    }

    /**
     * Returns an {@link HadronBreakNode} for the given token.
     *
     * @param breakToken The token containing the break node's info.
     * @return A HadronBreakNode for the given token.
     */
    public HadronStatementNode createBreak(Token breakToken) {
        final HadronBreakNode breakNode = new HadronBreakNode();
        srcFromToken(breakNode, breakToken);
        return breakNode;
    }

    /**
     * Returns an {@link HadronContinueNode} for the given token.
     *
     * @param continueToken The token containing the continue node's info.
     * @return A HadronContinueNode built using the given token.
     */
    public HadronStatementNode createContinue(Token continueToken) {
        final HadronContinueNode continueNode = new HadronContinueNode();
        srcFromToken(continueNode, continueToken);
        return continueNode;
    }

    /**
     * Returns an {@link HadronWhileNode} for the given parameters.
     *
     * @param whileToken The token containing the while node's info
     * @param conditionNode The conditional node for this while loop
     * @param bodyNode The body of the while loop
     * @return A HadronWhileNode built using the given parameters. null if either conditionNode or
     *         bodyNode is null.
     */
    public HadronStatementNode createWhile(Token whileToken, HadronExpressionNode conditionNode, HadronStatementNode bodyNode) {
        if (conditionNode == null || bodyNode == null) {
            return null;
        }

        conditionNode.addStatementTag();
        final int start = whileToken.getStartIndex();
        final int end = bodyNode.getSourceEndIndex();
        final HadronWhileNode whileNode = new HadronWhileNode(conditionNode, bodyNode);
        whileNode.setSourceSection(start, end - start);
        return whileNode;
    }

    /**
     * Returns an {@link HadronIfNode} for the given parameters.
     *
     * @param ifToken The token containing the if node's info
     * @param conditionNode The condition node of this if statement
     * @param thenPartNode The then part of the if
     * @param elsePartNode The else part of the if (null if no else part)
     * @return An HadronIfNode for the given parameters. null if either conditionNode or thenPartNode is
     *         null.
     */
    public HadronStatementNode createIf(Token ifToken, HadronExpressionNode conditionNode, HadronStatementNode thenPartNode, HadronStatementNode elsePartNode) {
        if (conditionNode == null || thenPartNode == null) {
            return null;
        }

        conditionNode.addStatementTag();
        final int start = ifToken.getStartIndex();
        final int end = elsePartNode == null ? thenPartNode.getSourceEndIndex() : elsePartNode.getSourceEndIndex();
        final HadronIfNode ifNode = new HadronIfNode(conditionNode, thenPartNode, elsePartNode);
        ifNode.setSourceSection(start, end - start);
        return ifNode;
    }

    /**
     * Returns an {@link HadronReturnNode} for the given parameters.
     *
     * @param t The token containing the return node's info
     * @param valueNode The value of the return (null if not returning a value)
     * @return An HadronReturnNode for the given parameters.
     */
    public HadronStatementNode createReturn(Token t, HadronExpressionNode valueNode) {
        final int start = t.getStartIndex();
        final int length = valueNode == null ? t.getText().length() : valueNode.getSourceEndIndex() - start;
        final HadronReturnNode returnNode = new HadronReturnNode(valueNode);
        returnNode.setSourceSection(start, length);
        return returnNode;
    }

    public HadronExpressionNode createUnary(Token opToken, HadronExpressionNode expNode) {
        if (expNode == null) {
            return null;
        }
        final HadronExpressionNode expUnboxed = HadronUnboxNodeGen.create(expNode);
        final HadronExpressionNode result;
        switch (opToken.getText()) {
            case "-":
                result = HadronNegateNodeGen.create(expUnboxed);
                break;
            case "!":
                result = HadronFactorialNodeGen.create(expUnboxed);
                break;
            default:
                throw new RuntimeException("unexpected operation: " + opToken.getText());
        }

        int start = opToken.getStartIndex();
        int length = expNode.getSourceEndIndex() - start;
        result.setSourceSection(start, length);
        result.addExpressionTag();

        return result;
    }

    /**
     * Returns the corresponding subclass of {@link HadronExpressionNode} for binary expressions. </br>
     * These nodes are currently not instrumented.
     *
     * @param opToken The operator of the binary expression
     * @param leftNode The left node of the expression
     * @param rightNode The right node of the expression
     * @return A subclass of HadronExpressionNode using the given parameters based on the given opToken.
     *         null if either leftNode or rightNode is null.
     */
    public HadronExpressionNode createBinary(Token opToken, HadronExpressionNode leftNode, HadronExpressionNode rightNode) {
        if (leftNode == null || rightNode == null) {
            return null;
        }
        final HadronExpressionNode leftUnboxed = HadronUnboxNodeGen.create(leftNode);
        final HadronExpressionNode rightUnboxed = HadronUnboxNodeGen.create(rightNode);

        final HadronExpressionNode result;
        switch (opToken.getText()) {
            case "+":
                result = HadronAddNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case "*":
                result = HadronMulNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case "/":
                result = HadronDivNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case "-":
                result = HadronSubNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case "<":
                result = HadronLessThanNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case "<=":
                result = HadronLessOrEqualNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case ">":
                result = HadronLogicalNotNodeGen.create(HadronLessOrEqualNodeGen.create(leftUnboxed, rightUnboxed));
                break;
            case ">=":
                result = HadronLogicalNotNodeGen.create(HadronLessThanNodeGen.create(leftUnboxed, rightUnboxed));
                break;
            case "==":
                result = HadronEqualNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            case "!=":
                result = HadronLogicalNotNodeGen.create(HadronEqualNodeGen.create(leftUnboxed, rightUnboxed));
                break;
            case "and":
                result = new HadronLogicalAndNode(leftUnboxed, rightUnboxed);
                break;
            case "or":
                result = new HadronLogicalOrNode(leftUnboxed, rightUnboxed);
                break;
            case "^":
                result = HadronPowNodeGen.create(leftUnboxed, rightUnboxed);
                break;
            default:
                throw new RuntimeException("unexpected operation: " + opToken.getText());
        }

        int start = leftNode.getSourceCharIndex();
        int length = rightNode.getSourceEndIndex() - start;
        result.setSourceSection(start, length);
        result.addExpressionTag();

        return result;
    }

    /**
     * Returns an {@link HadronInvokeNode} for the given parameters.
     *
     * @param functionNode The function being called
     * @param parameterNodes The parameters of the function call
     * @param finalToken A token used to determine the end of the sourceSelection for this call
     * @return An HadronInvokeNode for the given parameters. null if functionNode or any of the
     *         parameterNodes are null.
     */
    public HadronExpressionNode createCall(HadronExpressionNode functionNode, List<HadronExpressionNode> parameterNodes, Token finalToken) {
        if (functionNode == null || containsNull(parameterNodes)) {
            return null;
        }

        final HadronExpressionNode result = new HadronInvokeNode(functionNode, parameterNodes.toArray(new HadronExpressionNode[parameterNodes.size()]));

        final int startPos = functionNode.getSourceCharIndex();
        final int endPos = finalToken.getStartIndex() + finalToken.getText().length();
        result.setSourceSection(startPos, endPos - startPos);
        result.addExpressionTag();

        return result;
    }

    /**
     * Returns an {@link HadronWriteLocalVariableNode} for the given parameters.
     *
     * @param nameNode The name of the variable being assigned
     * @param valueNode The value to be assigned
     * @return An HadronExpressionNode for the given parameters. null if nameNode or valueNode is null.
     */
    public HadronExpressionNode createAssignment(HadronExpressionNode nameNode, HadronExpressionNode valueNode) {
        return createAssignment(nameNode, valueNode, null);
    }

    /**
     * Returns an {@link HadronWriteLocalVariableNode} for the given parameters.
     *
     * @param nameNode The name of the variable being assigned
     * @param valueNode The value to be assigned
     * @param argumentIndex null or index of the argument the assignment is assigning
     * @return An HadronExpressionNode for the given parameters. null if nameNode or valueNode is null.
     */
    public HadronExpressionNode createAssignment(HadronExpressionNode nameNode, HadronExpressionNode valueNode, Integer argumentIndex) {
        if (nameNode == null || valueNode == null) {
            return null;
        }

        String name = ((HadronStringLiteralNode) nameNode).executeGeneric(null);
        FrameSlot frameSlot = frameDescriptor.findOrAddFrameSlot(
                        name,
                        argumentIndex,
                        FrameSlotKind.Illegal);
        lexicalScope.locals.put(name, frameSlot);
        final HadronExpressionNode result = HadronWriteLocalVariableNodeGen.create(valueNode, frameSlot);

        if (valueNode.hasSource()) {
            final int start = nameNode.getSourceCharIndex();
            final int length = valueNode.getSourceEndIndex() - start;
            result.setSourceSection(start, length);
        }
        result.addExpressionTag();

        return result;
    }

    /**
     * Returns a {@link HadronReadLocalVariableNode} if this read is a local variable or a
     * {@link HadronFunctionLiteralNode} if this read is global. In SL, the only global names are
     * functions.
     *
     * @param nameNode The name of the variable/function being read
     * @return either:
     *         <ul>
     *         <li>A HadronReadLocalVariableNode representing the local variable being read.</li>
     *         <li>A HadronFunctionLiteralNode representing the function definition.</li>
     *         <li>null if nameNode is null.</li>
     *         </ul>
     */
    public HadronExpressionNode createRead(HadronExpressionNode nameNode) {
        if (nameNode == null) {
            return null;
        }

        String name = ((HadronStringLiteralNode) nameNode).executeGeneric(null);
        final HadronExpressionNode result;
        final FrameSlot frameSlot = lexicalScope.locals.get(name);
        if (frameSlot != null) {
            /* Read of a local variable. */
            result = HadronReadLocalVariableNodeGen.create(frameSlot);
        } else {
            /* Read of a global name. In our language, the only global names are functions. */
            result = new HadronFunctionLiteralNode(language, name);
        }
        result.setSourceSection(nameNode.getSourceCharIndex(), nameNode.getSourceLength());
        result.addExpressionTag();
        return result;
    }

    public HadronExpressionNode createStringLiteral(Token literalToken, boolean removeQuotes) {
        /* Remove the trailing and ending " */
        String literal = literalToken.getText();
        if (removeQuotes) {
            assert literal.length() >= 2 && literal.startsWith("\"") && literal.endsWith("\"");
            literal = literal.substring(1, literal.length() - 1);
        }

        final HadronStringLiteralNode result = new HadronStringLiteralNode(literal.intern());
        srcFromToken(result, literalToken);
        result.addExpressionTag();
        return result;
    }

    public HadronExpressionNode createNumericLiteral(Token literalToken) {
        HadronExpressionNode result;
        try {
            /* Try if the literal is small enough to fit into a long value. */
            result = new HadronLongLiteralNode(Long.parseLong(literalToken.getText()));
        } catch (NumberFormatException ex) {
            /* Overflow of long value, so fall back to BigInteger. */
            result = new HadronBigIntegerLiteralNode(new BigInteger(literalToken.getText()));
        }
        srcFromToken(result, literalToken);
        result.addExpressionTag();
        return result;
    }

    public HadronExpressionNode createFloatLiteral(Token literalToken) {
        HadronExpressionNode result = new HadronDoubleLiteralNode(Double.parseDouble(literalToken.getText()));
        srcFromToken(result, literalToken);
        result.addExpressionTag();
        return result;
    }

    public HadronExpressionNode createBooleanLiteral(Token literalToken) {
        HadronExpressionNode result = new HadronBooleanLiteralNode(Boolean.parseBoolean(literalToken.getText()));
        srcFromToken(result, literalToken);
        result.addExpressionTag();
        return result;
    }

    public HadronExpressionNode createParenExpression(HadronExpressionNode expressionNode, int start, int length) {
        if (expressionNode == null) {
            return null;
        }

        final HadronParenExpressionNode result = new HadronParenExpressionNode(expressionNode);
        result.setSourceSection(start, length);
        return result;
    }

    /**
     * Returns an {@link HadronReadPropertyNode} for the given parameters.
     *
     * @param receiverNode The receiver of the property access
     * @param nameNode The name of the property being accessed
     * @return An HadronExpressionNode for the given parameters. null if receiverNode or nameNode is
     *         null.
     */
    public HadronExpressionNode createReadProperty(HadronExpressionNode receiverNode, HadronExpressionNode nameNode) {
        if (receiverNode == null || nameNode == null) {
            return null;
        }

        final HadronExpressionNode result = HadronReadPropertyNodeGen.create(receiverNode, nameNode);

        final int startPos = receiverNode.getSourceCharIndex();
        final int endPos = nameNode.getSourceEndIndex();
        result.setSourceSection(startPos, endPos - startPos);
        result.addExpressionTag();

        return result;
    }

    /**
     * Returns an {@link HadronWritePropertyNode} for the given parameters.
     *
     * @param receiverNode The receiver object of the property assignment
     * @param nameNode The name of the property being assigned
     * @param valueNode The value to be assigned
     * @return An HadronExpressionNode for the given parameters. null if receiverNode, nameNode or
     *         valueNode is null.
     */
    public HadronExpressionNode createWriteProperty(HadronExpressionNode receiverNode, HadronExpressionNode nameNode, HadronExpressionNode valueNode) {
        if (receiverNode == null || nameNode == null || valueNode == null) {
            return null;
        }

        final HadronExpressionNode result = HadronWritePropertyNodeGen.create(receiverNode, nameNode, valueNode);

        final int start = receiverNode.getSourceCharIndex();
        final int length = valueNode.getSourceEndIndex() - start;
        result.setSourceSection(start, length);
        result.addExpressionTag();

        return result;
    }

    /**
     * Creates source description of a single token.
     */
    private static void srcFromToken(HadronStatementNode node, Token token) {
        node.setSourceSection(token.getStartIndex(), token.getText().length());
    }

    /**
     * Checks whether a list contains a null.
     */
    private static boolean containsNull(List<?> list) {
        for (Object e : list) {
            if (e == null) {
                return true;
            }
        }
        return false;
    }

}
