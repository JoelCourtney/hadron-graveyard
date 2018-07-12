use super::lexer;

enum Token {
    Plus,
    BinaryMinus,
    Times,
    Divide,
    Power,
    Modulo,
    UnaryMinus,
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
    Name(String),
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
//    let tokens = tokenize(lexemes);
//    let tokens = prefix(tokens);
//    create_trees(tokens)
0
}
