// parse_statment
// lvalue::parse
// rvalue::parse
// control::parse
// parse_scope

use ast::*;

mod traverse;
mod rvalue;
mod lvalue;
mod statement;
mod control;
mod scope;
mod list;

pub fn parse(lexemes: Vec<Lexeme>) -> Vec<Control> {
    let mut controls = Vec::new();
    let l = lexemes.len();
    let mut i = 0;
    while i < l-1 {
        let (control,length) = control::parse(&lexemes[i..]);
        // println!("{:?}",control);
        controls.push(*control);
        i += length;
    }
    controls
}

lazy_static! {
    static ref PRECEDENCE: Vec<Vec<BOP>> = vec![
        vec![BOP::Or, BOP::NOr],
        vec![BOP::XOr],
        vec![BOP::And, BOP::NAnd],
        vec![BOP::Is, BOP::Isnt],
        vec![BOP::Less, BOP::LessOrEqual, BOP::Greater, BOP::GreaterOrEqual],
        vec![BOP::Range],
        vec![BOP::Plus, BOP::Minus],
        vec![BOP::Times, BOP::ElemTimes, BOP::Divide, BOP::ElemDivide, BOP::Modulus],
        vec![BOP::Power, BOP::ElemPower],
        vec![BOP::StripUnit, BOP::ConcatUnit, BOP::Convert],
    ];
    static ref OPENERS: [Lexeme; 6] = [
        Lexeme::OArgList,
        Lexeme::OScope,
        Lexeme::OMatrix,
        Lexeme::OUnit,
        Lexeme::OList,
        Lexeme::OParen,
    ];
    static ref CLOSERS: [Lexeme; 3] = [
        Lexeme::CParen,
        Lexeme::CBraket,
        Lexeme::CBrace,
    ];
}
