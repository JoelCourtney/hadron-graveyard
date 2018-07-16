// parse_statment
// parse_lvalue
// parse_rvalue
// parse_control
// parse_scope

use super::ast::*;
use super::values::*;

pub fn parse(lexemes: Vec<Lexeme>) -> Box<Scope> {
    let mut statements = Vec::new();
    let l = lexemes.len();
    let mut i = 0;
    while i < l {
        let (control,length) = parse_control(&lexemes[i..]);
        statements.push(control);
        i += length;
    }
    Box::new(Scope {
        statements
    })
}

fn parse_scope(lexemes: &[Lexeme]) -> (Box<Scope>,usize) {
    unimplemented!();
}

fn parse_control(lexemes: &[Lexeme]) -> (Box<Control>,usize) {
    let mut i = 0;
    let mut start = lexemes.get(i);
    while start == Some(&Lexeme::NewLine) {
        i += 1;
        start = lexemes.get(i);
    }
    match start {
        Some(Lexeme::For) => {
            i += 1;
            let (range,length) = parse_rvalue(&lexemes[i..]);
            i += length;
            let key1 = lexemes.get(i);
            match key1 {
                Some(Lexeme::As) => {
                    i += 1;
                    let (target,length) = parse_decomposition(&lexemes[i..]);
                    i += length;
                    let key2 = lexemes.get(i);
                    match key2 {
                        Some(Lexeme::At) => {
                            i += 1;
                            let (index,length) = parse_decomposition(&lexemes[i..]);
                            i += length;
                            let (body,length) = parse_rvalue(&lexemes[i..]);
                            i += length;
                            (
                                Box::new(Control::ForAsAt {
                                    range,
                                    target,
                                    index,
                                    body,
                                }),
                                i,
                            )
                        }
                        Some(_) => {
                            let (body,length) = parse_rvalue(&lexemes[i..]);
                            i += length;
                            (
                                Box::new(Control::ForAs {
                                    range,
                                    target,
                                    body,
                                }),
                                i,
                            )
                        }
                        None => panic!("ya dun fuqd up"),
                    }
                }
                Some(Lexeme::At) => {
                    i += 1;
                    let (index,length) = parse_decomposition(&lexemes[i..]);
                    i += length;
                    let key2 = lexemes.get(i);
                    match key2 {
                        Some(Lexeme::As) => {
                            i += 1;
                            let (target,length) = parse_decomposition(&lexemes[i..]);
                            i += length;
                            let (body,length) = parse_rvalue(&lexemes[i..]);
                            i += length;
                            (
                                Box::new(Control::ForAsAt {
                                    range,
                                    target,
                                    index,
                                    body,
                                }),
                                i,
                            )
                        }
                        Some(_) => {
                            let (body,length) = parse_rvalue(&lexemes[i..]);
                            i += length;
                            (
                                Box::new(Control::ForAt {
                                    range,
                                    index,
                                    body,
                                }),
                                i,
                            )
                        }
                        None => panic!("ya dun fuqd up"),
                    }
                }
                Some(_) => {
                    let (body,length) = parse_rvalue(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::For {
                            range,
                            body,
                        }),
                        i,
                    )
                }
                None => {
                    panic!("ya dun fuqd up")
                }
            }
        }
        Some(Lexeme::If) => {
            unimplemented!();
        }
        Some(Lexeme::While) => {
            unimplemented!();
        }
        Some(_) => {
            let (statement,length) = parse_statement(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::State {
                    statement,
                }),
                i,
            )
        }
        None => (Box::new(Control::Empty),0)
    }
}

fn parse_statement(lexemes: &[Lexeme]) -> (Box<Statement>,usize) {
    let mut complete = false;
    let mut level = 0;
    let mut i = 0;
    let mut assignmentLoc = -1;
    loop {
        let lexeme = lexemes.get(i);
        match lexeme {
            Some(lex) if OPENERS.contains(lex) => {
                level += traverse_atom(&lexemes[i..]);
                complete = true;
            }
            Some(lex) if CLOSERS.contains(lex) => {
                panic!("unexpected closing character");
            }
            Some(Lexeme::Assign) | Some(Lexeme::AssignOp(_)) | Some(Lexeme::Let) => {
                complete = false;
                if assignmentLoc == -1 {
                    assignmentLoc = i;
                }
                i += 1;
            }
            Some(Lexeme::BinaryOp(_)) => {
                complete = false;
                i += 1;
            }
            Some(Lexeme::UnaryOp(o)) if o != &UOP::Factorial => {
                complete = false;
                i += 1;
            }
            Some(Lexeme::Handle(_)) | Some(Lexeme::Number(_)) | Some(Lexeme::StringLiteral(_)) => {
                if level == 0 {
                    complete = true;
                }
                i += 1;
            }
            Some(Lexeme::Semicolon) | Some(Lexeme::NewLine) => {
                if complete {
                    break;
                }
                i += 1;
            }
            Some(_) => {}               
            None => {
                if complete {
                    break;
                } else {
                    panic!("Unexpected end of input.");
                }
            }
        }
    }
    if assignmentLoc != -1 {
        let lvalue = parse_lvalue(&lexemes[..assignmentLoc]);
        let rvalue = parse_rvalue(&lexemes[assignmentLoc+1 .. i]);
        let assign = lexemes.get(i);
        match assign {
            Some(Lexeme::Assign) => {
                (
                    Box::new( Statement::
}

fn parse_lvalue(lexemes: &[Lexeme]) -> (Box<Decomposition>,usize) {
    unimplemented!();
}

lazy_static! {
    static ref PRECEDENCE: Vec<Vec<BOP>> = vec![
        vec![BOP::Or, BOP::NOr],
        vec![BOP::XOr],
        vec![BOP::And, BOP::NAnd],
        vec![BOP::Is, BOP::Isnt],
        vec![BOP::Less, BOP::LessOrEqual, BOP::Greater, BOP::GreaterOrEqual],
        vec![BOP::Plus, BOP::Minus],
        vec![BOP::Times, BOP::ElemTimes, BOP::Divide, BOP::ElemDivide, BOP::Modulus],
        vec![BOP::Power, BOP::ElemPower]
    ];
    static ref OPENERS: [Lexeme; 9] = [
        Lexeme::OArgList,
        Lexeme::OScope,
        Lexeme::OMatrix,
        Lexeme::ORangeIn,
        Lexeme::ORangeEx,
        Lexeme::OUnit,
        Lexeme::OList,
        Lexeme::ONorm,
        Lexeme::ODeterminant
    ];
    static ref CLOSERS: [Lexeme; 5] = [
        Lexeme::CParen,
        Lexeme::CBraket,
        Lexeme::CBrace,
        Lexeme::CNorm,
        Lexeme::CDeterminant,
    ];
}

fn parse_rvalue(lexemes: &[Lexeme], level: usize) -> Box<RValue> {
    let l = lexemes.len();
    if level < 8 {
        let mut i = 0;
        while i < l {
            let lexeme = lexemes.get(i).unwrap();
            match lexeme {
                Lexeme::BinaryOp(bop) => {
                    if PRECEDENCE[level].contains(bop) {
                        let e1 = parse_rvalue(&lexemes[..i], level + 1);
                        let e2 = parse_rvalue(&lexemes[i+1..], level);
                        return Box::new( RValue::Binary {
                            op: *bop,
                            e1,
                            e2,
                        });
                    }
                    break;
                }
                _ if OPENERS.contains(lexeme) => {
                    i += traverse_atom(&lexemes[i..]);
                }
                _ => {
                    i += 1;
                }
            }
        }
    } else if level == 8 {
        let lexeme = lexemes.get(0).unwrap();
        match lexeme {
            Lexeme::UnaryOp(uop) => {
                let e1 = parse_rvalue(&lexemes[1..], level);
                return Box::new( RValue::Unary {
                    op: *uop,
                    e1,
                });
            }
            _ => {
                return parse_rvalue(&lexemes[..], level + 1);
            }
        }
    } else if level == 9 {
        let start = lexemes.get(0).unwrap();
        match start {
            Lexeme::Handle(s) => {
                if lexemes.len() == 1 {
                    unimplemented!();
                }
                unimplemented!();
            }
            Lexeme::Number(n) => {
                unimplemented!();
            }
            Lexeme::StringLiteral(s) => {
                unimplemented!();
            }
            Lexeme::OArgList => {
                unimplemented!();
            }
            Lexeme::OScope => {
                unimplemented!();
            }
            Lexeme::OMatrix => {
                unimplemented!();
            }
            Lexeme::ORangeIn => {
                unimplemented!();
            }
            Lexeme::ORangeEx => {
                unimplemented!();
            }
            Lexeme::OUnit => {
                unimplemented!();
            }
            Lexeme::OList => {
                unimplemented!();
            }
            Lexeme::ODeterminant => {
                unimplemented!();
            }
            _ => {}
        }
    }
    parse_rvalue(lexemes, level + 1)
}

fn traverse_atom(lexemes: &[Lexeme]) -> usize {
    let mut i = 0;
    let mut level = 1;
    loop {
        i += 1;
        let lexeme = lexemes.get(i).unwrap();
        if OPENERS.contains(lexeme) {
            level += 1;
        } else if CLOSERS.contains(lexeme) {
            level -= 1;
            if level == 0 {
                return i + 1;
            }
        }
    }
}
