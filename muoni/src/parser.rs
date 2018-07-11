use super::lexer;

enum Token {
    Plus,
    BinaryMinus,
    Times,
    Divide,
    Power,
    Modulo,
    Factorial,
    Determinant,
    Norm,
    Cardinality,
    And,
    NAnd,
    Or,
    NOr,
    Xor,
    NXor,
    Is,
    Isnt,
    Not,
    Assign,
    Let,
    RightArrow,
    LeftArrow,
    Number(f64),
    Variable(String),
    Unit(String),
    StringLiteral(String),
    Range(bool,bool,f64,f64,f64),
    Function(i32),
    If,
    While,
    ForAs,
    ForAsAt,
    Scope,
    EndScope,
    Return,
}

pub fn parse(lexemes: Vec<lexer::Lexeme>) -> i32 {
    let tokens = tokenize(lexemes);
    let tokens = prefix(tokens);
    create_trees(tokens)
}

fn tokenize(lexemes: Vec<lexer::Lexeme>) -> Vec<Token> {
    let mut tokens = Vec<Token>::new();

}
