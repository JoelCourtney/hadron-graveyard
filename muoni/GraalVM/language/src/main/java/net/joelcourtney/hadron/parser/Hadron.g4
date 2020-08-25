grammar Hadron;

@parser::header
{
// DO NOT MODIFY - generated from Hadron.g4 using "mx create-sl-parser"

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import com.oracle.truffle.api.source.Source;
import com.oracle.truffle.api.RootCallTarget;
import net.joelcourtney.hadron.HadronLanguage;
import net.joelcourtney.hadron.nodes.HadronExpressionNode;
import net.joelcourtney.hadron.nodes.HadronRootNode;
import net.joelcourtney.hadron.nodes.HadronStatementNode;
import net.joelcourtney.hadron.parser.HadronParseError;
}

@lexer::header
{
// DO NOT MODIFY - generated from Hadron.g4 using "mx create-sl-parser"
}

@parser::members
{
private HadronNodeFactory factory;
private Source source;

private int loopDepth = 0;
private int blockDepth = 0;

private static final class BailoutErrorListener extends BaseErrorListener {
    private final Source source;
    BailoutErrorListener(Source source) {
        this.source = source;
    }
    @Override
    public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol, int line, int charPositionInLine, String msg, RecognitionException e) {
        throwParseError(source, line, charPositionInLine, (Token) offendingSymbol, msg);
    }
}

public void SemErr(Token token, String message) {
    assert token != null;
    throwParseError(source, token.getLine(), token.getCharPositionInLine(), token, message);
}

private static void throwParseError(Source source, int line, int charPositionInLine, Token token, String message) {
    int col = charPositionInLine + 1;
    String location = "-- line " + line + " col " + col + ": ";
    int length = token == null ? 1 : Math.max(token.getStopIndex() - token.getStartIndex(), 0);
    throw new HadronParseError(source, line, col, length, String.format("Error(s) parsing script:%n" + location + message));
}

public static Map<String, RootCallTarget> parseHadron(HadronLanguage language, Source source) {
    HadronLexer lexer = new HadronLexer(CharStreams.fromString(source.getCharacters().toString()));
    HadronParser parser = new HadronParser(new CommonTokenStream(lexer));
    lexer.removeErrorListeners();
    parser.removeErrorListeners();
    BailoutErrorListener listener = new BailoutErrorListener(source);
    lexer.addErrorListener(listener);
    parser.addErrorListener(listener);
    parser.factory = new HadronNodeFactory(language, source);
    parser.source = source;
    parser.hadron();
    return parser.factory.getAllFunctions();
}
}

hadron
    : NL* function (NL* function)* NL* EOF;

function
    : 'fn' NL* IDENTIFIER
    s='('                                       { factory.startFunction($IDENTIFIER, $s); }
    (    IDENTIFIER                             { factory.addFormalParameter($IDENTIFIER); }
        (
            ',' NL* IDENTIFIER                      { factory.addFormalParameter($IDENTIFIER); }
        )*
    )? NL* ')' NL*
    body=block                           { factory.finishFunction($body.result); };

statement returns [HadronStatementNode result]
    : b='break'                              { if (loopDepth > 0) $result = factory.createBreak($b); else SemErr($b, "break used outside of loop"); }
    | c='continue'                           { if (loopDepth > 0) $result = factory.createContinue($c); else SemErr($c, "continue used outside of loop"); }
    | return_statement                          { $result = $return_statement.result; }
    | expression                             { $result = $expression.result; }
    | d='debugger'                           { $result = factory.createDebugger($d); }
    | while_statement                             { $result = $while_statement.result; }
    | if_statement                      { $result = $if_statement.result; };

while_statement returns [HadronStatementNode result]
    : w='while' { loopDepth++; } NL* condition=expression sep? NL*
    body=statement                            { $result = factory.createWhile($w, $condition.result, $body.result); loopDepth--; };

if_statement returns [HadronStatementNode result]
    : i='if' NL* condition=expression NL*
    then=block                          { HadronStatementNode elsePart = null; }
    (
        NL* 'else' NL* block                    { elsePart = $block.result; }
    )?                                          { $result = factory.createIf($i, $condition.result, $then.result, elsePart); };

return_statement returns [HadronStatementNode result]
    : r='return' NL*                               { HadronExpressionNode value = null; }
    (
        expression                              { value = $expression.result; }
    )?                                          { $result = factory.createReturn($r, value); }
    ;

expression returns [HadronExpressionNode result]
    : left=expression bop='^' NL* right=expression
                                                { $result = factory.createBinary($bop, $left.result, $right.result); }
    | left=expression bop=('*'|'/') NL* right=expression
                                                { $result = factory.createBinary($bop, $left.result, $right.result); }
    | left=expression bop=('+' | '-') NL* right=expression
                                                { $result = factory.createBinary($bop, $left.result, $right.result); }
    | left=expression bop=('<' | '<=' | '>' | '>=') NL* right=expression
                                                { $result = factory.createBinary($bop, $left.result, $right.result); }
    | left=expression bop=('==' | '!=') NL* right=expression
                                                { $result = factory.createBinary($bop, $left.result, $right.result); }
    | left=expression bop='and' NL* right=expression{ $result = factory.createBinary($bop, $left.result, $right.result); }  // add nand
    | left=expression bop='or' NL* right=expression { $result = factory.createBinary($bop, $left.result, $right.result); } // add nor
    | unary_expression                          { $result = $unary_expression.result; };

unary_expression returns [HadronExpressionNode result]
    : uop='-' NL* exp=unary_expression              { $result = factory.createUnary($uop, $exp.result); }
    | exp=unary_expression uop='!'                    { $result = factory.createUnary($uop, $exp.result); }
    | factor                                    { $result = $factor.result; };

factor returns [HadronExpressionNode result]
    : BOOLEAN_LITERAL                           { $result = factory.createBooleanLiteral($BOOLEAN_LITERAL); }
    | IDENTIFIER                                { HadronExpressionNode assignmentName = factory.createStringLiteral($IDENTIFIER, false); }
    (
        member_expression[null, null, assignmentName]
                                                { $result = $member_expression.result; }
        |                                       { $result = factory.createRead(assignmentName); }
    )
    | STRING_LITERAL                            { $result = factory.createStringLiteral($STRING_LITERAL, true); }
    | NUMERIC_LITERAL                           { $result = factory.createNumericLiteral($NUMERIC_LITERAL); }
    | FLOAT_LITERAL                             { $result = factory.createFloatLiteral($FLOAT_LITERAL); }
    | SCIENTIFIC_FLOAT_LITERAL                  { $result = factory.createFloatLiteral($SCIENTIFIC_FLOAT_LITERAL); }
    | s='(' NL* expr=expression NL* e=')'               { $result = factory.createParenExpression($expr.result, $s.getStartIndex(), $e.getStopIndex() - $s.getStartIndex() + 1); }
    | b=block                                   { $result = $b.result; };

block returns [HadronExpressionNode result]
    :                                           { blockDepth++; factory.startBlock(); List<HadronStatementNode> body = new ArrayList<>(); }
    s='{'
    (
        NL*
        statement sep                       { body.add($statement.result); }
    )*
    NL*
    (statement                       { body.add($statement.result); })?
    NL*
    e='}'                                       { blockDepth--; $result = factory.finishBlock(body, $s.getStartIndex(), $e.getStopIndex() - $s.getStartIndex() + 1); };

member_expression [HadronExpressionNode r, HadronExpressionNode assignmentReceiver, HadronExpressionNode assignmentName] returns [HadronExpressionNode result]
    :                                           { HadronExpressionNode receiver = r; HadronExpressionNode nestedAssignmentName = null; }
    (
        '(' NL*                                     { List<HadronExpressionNode> parameters = new ArrayList<>();
                                                  if (receiver == null) {
                                                      receiver = factory.createRead(assignmentName);
                                                  } }
        (
            expression NL*                         { parameters.add($expression.result); }
            (
                ',' NL* expression NL*                 { parameters.add($expression.result); }
            )*
        )?
        e=')'
                                                { $result = factory.createCall(receiver, parameters, $e); }
        | NL* '=' NL* expression                        { if (assignmentName == null) {
                                                      SemErr($expression.start, "invalid assignment target");
                                                  } else if (assignmentReceiver == null) {
                                                      $result = factory.createAssignment(assignmentName, $expression.result);
                                                  } else {
                                                      $result = factory.createWriteProperty(assignmentReceiver, assignmentName, $expression.result);
                                                  } }
        | '.'                                   { if (receiver == null) {
                                                       receiver = factory.createRead(assignmentName);
                                                  } }
        IDENTIFIER                              { nestedAssignmentName = factory.createStringLiteral($IDENTIFIER, false);
                                                  $result = factory.createReadProperty(receiver, nestedAssignmentName); }
        | '[' NL*                                         { if (receiver == null) {
                                                      receiver = factory.createRead(assignmentName);
                                                  } }
        expression NL*
                                                { nestedAssignmentName = $expression.result;
                                                  $result = factory.createReadProperty(receiver, nestedAssignmentName); }
        ']'
    )
    (
        member_expression[$result, receiver, nestedAssignmentName]
                                                { $result = $member_expression.result; }
    )?;

sep : ';' NL* | NL+;

WS : [ \t\u000C]+ -> skip;
COMMENT : '/*' .*? '*/' -> skip;
LINE_COMMENT : '//' ~[\r\n]* -> skip;
NL : '\n' | '\r';

fragment LETTER : [A-Z] | [a-z] | '_' | '$';
fragment NON_ZERO_DIGIT : [1-9];
fragment DIGIT : [0-9];
fragment HEX_DIGIT : [0-9] | [a-f] | [A-F];
fragment OCT_DIGIT : [0-7];
fragment BINARY_DIGIT : '0' | '1';
fragment TAB : '\t';
fragment STRING_CHAR : ~('"' | '\\' | '\r' | '\n');
fragment E : 'E' | 'e';
fragment DASH : '-';

BOOLEAN_LITERAL : 'true' | 'false';
STRING_LITERAL : '"' STRING_CHAR* '"';
SCIENTIFIC_FLOAT_LITERAL : (DIGIT+ | DIGIT+ '.' DIGIT* | DIGIT* '.' DIGIT+) E DASH? DIGIT+;
FLOAT_LITERAL : DIGIT+ '.' DIGIT* | DIGIT* '.' DIGIT+;
NUMERIC_LITERAL : DIGIT+;
IDENTIFIER : LETTER (LETTER | DIGIT)*;
