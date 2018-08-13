use ast::{Control,Lexeme};
use super::control;

pub fn parse(lexemes: &[Lexeme]) -> (Vec<Control>,usize) {
    let mut controls = Vec::new();
    let l = lexemes.len();
    let mut i = 0;
    match lexemes.get(0) {
        Some(Lexeme::OScope) => {
            i = 1;
        }
        _ => panic!("expected {"),
    }
    while i < l {
        let (control,length) = control::parse(&lexemes[i..]);
        controls.push(*control);
        i += length;
        match lexemes.get(i) {
            Some(Lexeme::CBrace) => {
                return (
                    controls,
                    i+1
                    )
            }
            Some(Lexeme::NewLine) => {
                i += 1;
                match lexemes.get(i) {
                    Some(Lexeme::CBrace) => {
                        return (
                            controls,
                            i+1
                            )
                    }
                    _ => {}
                }
            }
            _ => {}
        }
    }
    panic!("something has gone horribly wrong");
}

