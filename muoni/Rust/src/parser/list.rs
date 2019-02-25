use super::statement;
use ast::{Statement,Lexeme};

pub fn parse(lexemes: &[Lexeme]) -> (Vec<Statement>, usize) {
    let mut i = 0;
    match lexemes.get(0) {
        Some(Lexeme::OList) => {
            i += 1;
        }
        _ => panic!("expected start of list"),
    }
    let mut v = Vec::new();
    loop {
        match lexemes.get(i) {
            Some(Lexeme::CBraket) => {
                return (v,i+1);
            }
            Some(_) => {
                let (state,length) = statement::parse(&lexemes[i..]);
                i += length;
                v.push(*state);
                while lexemes.get(i) == Some(&Lexeme::NewLine) {
                    i += 1;
                }
                match lexemes.get(i) {
                    Some(Lexeme::Comma) => {
                        i += 1;
                    }
                    Some(Lexeme::CBraket) => {
                        return (v,i+1);
                    }
                    _ => panic!("wut"),
                }
            }
            None => panic!("wut"),
        }
    }
}
