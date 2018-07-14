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
        Some(Lexeme::Handle(s)) => {
            let name = s.clone();
            let next = lexemes.get(i+1);
            match next {
                Some(Lexeme::Assign) => {
                    i += 2;
                    let (e1,length) = parse_arith(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::AssignVariable {
                            name,
                            e1,
                        }),
                        i,
                    )
                }
                Some(Lexeme::AssignOp(op)) => {
                    i += 2;
                    let (e1,length) = parse_arith(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::AssignVariableBOP {
                            name,
                            op: *op,
                            e1,
                        }),
                        i,
                    )
                }
                Some(Lexeme::Let) => {
                    i += 2;
                    let (e1,length) = parse_arith(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::AssignConstant {
                            name,
                            e1,
                        }),
                        i,
                    )
                }
                Some(Lexeme::OArgList) => {
                    let mut definition = false;
                    let mut cursor = i + 2;
                    let mut args = Vec::new();
                    loop {
                        let lexeme = lexemes.get(cursor);
                        match lexeme {
                            Some(Lexeme::Handle(s)) => {
                                args.push(s.clone());
                                let comma = lexemes.get(cursor+1);
                                match comma {
                                    Some(Lexeme::Comma) => {
                                        cursor += 2;
                                    }
                                    Some(Lexeme::CParen) => {
                                        let arrow = lexemes.get(cursor+2);
                                        match arrow {
                                            Some(Lexeme::RightArrow) => {
                                                definition = true;
                                                i = cursor + 3;
                                            }
                                            _ => {}
                                        }
                                        break;
                                    }
                                    _ => {
                                        break;
                                    }
                                }
                            }
                            Some(Lexeme::CParen) => {
                                let arrow = lexemes.get(cursor+1);
                                match arrow {
                                    Some(Lexeme::RightArrow) => {
                                        definition = true;
                                        i = cursor + 2;
                                    }
                                    _ => {}
                                }
                                break;
                            }
                            _ => {
                                break;
                            }
                        }
                    }
                    if definition {
                        let (body,length) = parse_arith(&lexemes[i..]);
                        i += length;
                        (
                            Box::new(Control::AssignFunction {
                                name,
                                args,
                                body,
                            }),
                            i,
                        )
                    } else {
                        let (e1,length) = parse_arith(&lexemes[i..]);
                        i += length;
                        (
                            Box::new(Control::StateValue {
                                e1,
                            }),
                            i,
                        )
                    }
                }
                Some(Lexeme::RightArrow) => {
                    i += 2;
                    let (body,length) = parse_arith(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::AssignFunction {
                            name,
                            args: Vec::new(),
                            body,
                        }),
                        i,
                    )
                }
                _ => {
                    let (e1,length) = parse_arith(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::StateValue {
                            e1,
                        }),
                        i,
                    )
                }
            }
        }
        Some(Lexeme::For) => {
            i += 1;
            let (range,length) = parse_arith(&lexemes[i..]);
            i += length;
            let key1 = lexemes.get(i);
            let mut target: Decomposition;
            match key1 {
                Some(Lexeme::As) => {
                    i += 1;
                    let (target,length) = parse_decomposition(&lexemes[i..]);
                    i += length;
                }
                _ => {}
            }
            unimplemented!();
        }
        Some(Lexeme::If) => {
            unimplemented!();
        }
        Some(Lexeme::While) => {
            unimplemented!();
        }
        Some(_) => {
            let (e1,length) = parse_arith(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::StateValue {
                    e1,
                }),
                i,
            )
        }
        None => (Box::new(Control::Empty),0)
    }
}

fn parse_decomposition(lexemes: &[Lexeme]) -> (Box<Decomposition>,usize) {
    unimplemented!();
}

fn parse_arith(lexemes: &[Lexeme]) -> (Box<Arith>,usize) {
    unimplemented!();
}
