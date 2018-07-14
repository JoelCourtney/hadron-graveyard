use super::lexer;
use super::ast::*;
use super::values::*;

pub fn parse<'a>(lexemes: Vec<lexer::Lexeme>) -> Scope<'a> {
    let mut statements = Vec::new();
    Scope {
        statements
    }
}
