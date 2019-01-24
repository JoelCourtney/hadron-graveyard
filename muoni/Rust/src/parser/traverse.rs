use ast::Lexeme;
use super::{OPENERS,CLOSERS};

pub fn atom(lexemes: &[Lexeme]) -> usize {
    let mut i = 0;
    let mut level = 0;
    let mut in_cap = false;
    loop {
        let lexeme = lexemes.get(i).unwrap();
        if OPENERS.contains(lexeme) {
            level += 1;
        } else if CLOSERS.contains(lexeme) {
            level -= 1;
            if !in_cap && level == 0 {
                return i + 1;
            }
        } else if lexeme == &Lexeme::Pipe {
            in_cap = !in_cap;
            if !in_cap && level == 0 {
                return i + 1;
            }
        }
        i += 1;
    }
}

pub fn atom_reverse(lexemes: &[Lexeme]) -> usize {
    let mut i = lexemes.len() - 1;
    let mut level = 1;
    let mut in_cap = false;
    loop {
        i -= 1;
        let lexeme = lexemes.get(i).unwrap();
        if CLOSERS.contains(lexeme) {
            level += 1;
        } else if OPENERS.contains(lexeme) {
            level -= 1;
            if !in_cap && level == 0 {
                return lexemes.len() - i - 1;
            }
        } else if lexeme == &Lexeme::Pipe {
            in_cap = !in_cap;
        }
    }
}

pub fn separators(lexemes: &[Lexeme]) -> usize {
    let mut i = 0;
    loop {
        match lexemes.get(i) {
            Some(Lexeme::NewLine) | Some(Lexeme::Semicolon) => {
                i += 1;
            }
            _ => return i,
        }
    }
}
