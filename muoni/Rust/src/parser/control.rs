use ast::{Control,Lexeme};
use super::{rvalue,lvalue,statement,traverse,list};

pub fn parse(lexemes: &[Lexeme]) -> (Box<Control>,usize) {
    let mut i = 0;
    let mut start = lexemes.get(i);
    while start == Some(&Lexeme::NewLine) {
        i += 1;
        start = lexemes.get(i);
    }
    match start {
        Some(Lexeme::For) => {
            i += 1;
            let (range,length) = rvalue::parse(&lexemes[i..]);
            i += length;
            let key1 = lexemes.get(i);
            match key1 {
                Some(Lexeme::As) => {
                    i += 1;
                    let (target,length) = lvalue::parse(&lexemes[i..]);
                    i += length;
                    let key2 = lexemes.get(i);
                    match key2 {
                        Some(Lexeme::At) => {
                            i += 1;
                            let (index,length) = lvalue::parse(&lexemes[i..]);
                            i += length;
                            let (body,length) = statement::parse(&lexemes[i..]);
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
                            let (body,length) = statement::parse(&lexemes[i..]);
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
                    let (index,length) = lvalue::parse(&lexemes[i..]);
                    i += length;
                    let key2 = lexemes.get(i);
                    match key2 {
                        Some(Lexeme::As) => {
                            i += 1;
                            let (target,length) = lvalue::parse(&lexemes[i..]);
                            i += length;
                            let (body,length) = statement::parse(&lexemes[i..]);
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
                            let (body,length) = statement::parse(&lexemes[i..]);
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
                    let (body,length) = statement::parse(&lexemes[i..]);
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
            i += 1;
            let (condition,length) = rvalue::parse(&lexemes[i..]);
            i += length;
            let (body,length) = statement::parse(&lexemes[i..]);
            i += length;
            i += traverse::separators(&lexemes[i..]);
            match lexemes.get(i) {
                Some(Lexeme::Else) => {
                    i += 1;
                    let (else_body,length) = statement::parse(&lexemes[i..]);
                    i += length;
                    (
                        Box::new(Control::IfElse {
                            condition,
                            if_body: body,
                            else_body,
                        }),
                        i,
                        )
                }
                Some(Lexeme::ElseIf) => {
                    let mut conditions = vec![*condition];
                    let mut bodies = vec![*body];
                    while lexemes.get(i) == Some(&Lexeme::ElseIf) {
                        i += 1;
                        let (elif_condition,length) = rvalue::parse(&lexemes[i..]);
                        i += length;
                        let (elif_body,length) = statement::parse(&lexemes[i..]);
                        i += length;
                        conditions.push(*elif_condition);
                        bodies.push(*elif_body);
                        i += traverse::separators(&lexemes[i..]);
                    }
                    match lexemes.get(i) {
                        Some(Lexeme::Else) => {
                            i += 1;
                            let (else_body,length) = statement::parse(&lexemes[i..]);
                            i += length;
                            (
                                Box::new(Control::IfSeriesElse {
                                    conditions,
                                    if_bodies: bodies,
                                    else_body,
                                }),
                                i,
                                )
                        }
                        _ => {
                            (
                                Box::new(Control::IfSeries {
                                    conditions,
                                    bodies,
                                }),
                                i,
                                )
                        }
                    }
                }
                _ => {
                    (
                        Box::new(Control::If {
                            condition,
                            body,
                        }),
                        i,
                        )
                }
            }
        }
        Some(Lexeme::While) => {
            i += 1;
            let (condition,length) = rvalue::parse(&lexemes[i..]);
            i += length;
            let (body,length) = statement::parse(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::While {
                    condition,
                    body,
                }),
                i,
                )
        }
        Some(Lexeme::Loop) => {
            i += 1;
            let (body,length) = statement::parse(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::Loop {
                    body,
                }),
                i,
            )
        }
        Some(Lexeme::Dimension) => {
            i += 1;
            let name = match lexemes.get(i) {
                Some(Lexeme::Handle(n)) => {
                    i += 1;
                    n.clone()
                }
                _ => panic!("missing dimension name"),
            };
            let (units,length) = list::parse(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::Dimension {
                    name,
                    units,
                }),
                i,
            )
        }
        Some(_) => {
            let (statement,length) = statement::parse(&lexemes[i..]);
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
