use super::{OPENERS,CLOSERS,traverse,rvalue,lvalue};
use ast::{Statement,Lexeme,Assign};

pub fn parse(lexemes: &[Lexeme]) -> (Box<Statement>,usize) {
    let mut i = traverse::separators(lexemes);
    match lexemes.get(i) {
        Some(Lexeme::Var) | Some(Lexeme::Val) => {
            let tag = lexemes.get(i).unwrap();
            let (length,assign) = delimit(&lexemes[i..]);
            if assign != -1 {
                let assign = assign as usize;
                let op = match lexemes.get(i+assign) {
                    Some(Lexeme::Assign) => Assign::Equal,
                    Some(Lexeme::AssignOp(o)) => Assign::OpEqual(*o),
                    _ => panic!("illegal assignment"),
                };
                let name = lvalue::parse_contained(&lexemes[i+1..i+assign]);
                let e1 = rvalue::parse_contained(&lexemes[i+assign+1 .. i+length]);
                i += length;
                if tag == &Lexeme::Var {
                    (
                        Box::new(Statement::VarAssign {
                            name,
                            op,
                            e1,
                        }),
                        i,
                        )
                } else {
                    (
                        Box::new(Statement::ValAssign {
                            name,
                            op,
                            e1,
                        }),
                        i,
                        )
                }
            } else {
                let name = lvalue::parse_contained(&lexemes[i+1..i+length]);
                i += length;
                if tag == &Lexeme::Var {
                    (
                        Box::new(Statement::VarDecl {
                            name,
                        }),
                        i,
                        )
                } else {
                    (
                        Box::new(Statement::ValDecl {
                            name,
                        }),
                        i,
                        )
                }
            }
        }
        Some(Lexeme::Sym) => {
            let (length,_) = delimit(&lexemes[i..]);
            let name = lvalue::parse_contained(&lexemes[i+1..i+length]);
            i += length;
            (
                Box::new(Statement::Sym {
                    name,
                }),
                i,
                )
        }
        Some(Lexeme::Func) => {
            let name;
            match lexemes.get(1+i) {
                Some(Lexeme::Handle(s)) => {
                    name = s.clone();
                }
                _ => panic!("expected function name"),
            }
            i += 2;
            let args;
            match lexemes.get(i) {
                Some(Lexeme::OArgList) => {
                    let length = lvalue::delimit(&lexemes[i..]);
                    args = lvalue::parse_list(&lexemes[i..i+length]);
                    i += length;
                }
                _ => panic!("expected arg list"),
            }
            let caps;
            match lexemes.get(i) {
                Some(Lexeme::RightArrow) => {
                    caps = Vec::new();
                    i += 1;
                }
                Some(Lexeme::Pipe) => {
                    let length = lvalue::delimit(&lexemes[i..]);
                    caps = lvalue::parse_list(&lexemes[i..i+length]);
                    i += length;
                    match lexemes.get(i) {
                        Some(Lexeme::RightArrow) => {
                            i += 1;
                        }
                        l => panic!("expected right arrow, got {:?}",l),
                    }
                }
                l => panic!("expected -> or capture block: {:?}",l),
            }
            let (body,length) = parse(&lexemes[i..]);
            (
                Box::new(Statement::AssignFunction {
                    name,
                    args,
                    caps,
                    body,
                }),
                i + length,
                )
        }
        Some(Lexeme::Print) => {
            i += 1;
            let (e1, length) = rvalue::parse(&lexemes[i..]);
            i += length;
            (
                Box::new(Statement::Print {
                    e1,
                }),
                i,
                )
        }
        Some(Lexeme::Collapse) => {
            i += 1;
            let (name,length) = lvalue::parse(&lexemes[i..]);
            i += length;
            (
                Box::new(Statement::Collapse {
                    name,
                }),
                i,
                )
        }
        Some(_) => {
            let (length,assign) = delimit(&lexemes[i..]);
            if assign != -1 {
                let assign = assign as usize;
                let op = match lexemes.get(i+assign) {
                    Some(Lexeme::Assign) => Assign::Equal,
                    Some(Lexeme::AssignOp(o)) => Assign::OpEqual(*o),
                    _ => panic!("illegal assignment"),
                };
                let name = lvalue::parse_contained(&lexemes[i..i+assign]);
                let e1 = rvalue::parse_contained(&lexemes[i+assign+1 .. i+length]);
                i += length;
                (
                    Box::new(Statement::Assign {
                        name,
                        op,
                        e1,
                    }),
                    i,
                    )
            } else {
                let e1 = rvalue::parse_contained(&lexemes[i..i+length]);
                i += length;
                (
                    Box::new(Statement::StateValue {
                        e1,
                    }),
                    i,
                    )
            }
        }
        None => {
            panic!("expected statement");
        }
    }
}

pub fn delimit(lexemes: &[Lexeme]) -> (usize,i32) {
    let mut complete = false;
    let mut i = 0;
    let mut s = -1;
    loop {
        let cursor = lexemes.get(i);
        match cursor {
            Some(Lexeme::OScope) if complete => {
                return (i,s);
            }
            Some(lexeme) if OPENERS.contains(lexeme) => {
                i += traverse::atom(&lexemes[i..]);
                complete = true;
            }
            Some(Lexeme::Pipe) => {
                i += traverse::atom(&lexemes[i..]);
                complete = false;
            }
            Some(Lexeme::BinaryOp(_))
                | Some(Lexeme::UnaryOp(_))
                | Some(Lexeme::Dot) => {
                    complete = false;
                    i += 1;
                }
            Some(Lexeme::Assign)
                | Some(Lexeme::AssignOp(_))
                | Some(Lexeme::RightArrow) => {
                    complete = false;
                    if s == -1 {
                        s = i as i32;
                    } else {
                        panic!("invalid second assignment");
                    }
                    i += 1;
                }
            Some(Lexeme::Handle(_))
                | Some(Lexeme::Number(_))
                | Some(Lexeme::BreakSeries(_))
                | Some(Lexeme::StringLiteral(_))
                | Some(Lexeme::Bool(_))
                | Some(Lexeme::Question) => {
                    complete = true;
                    i += 1;
                }
            Some(Lexeme::Var)
                | Some(Lexeme::Val)
                | Some(Lexeme::Sym) => {
                    complete = false;
                    i += 1;
                }
            None
                | Some(Lexeme::Semicolon)
                | Some(Lexeme::Else)
                | Some(Lexeme::ElseIf) => {
                    if complete {
                        return (i,s);
                    } else {
                        panic!("unexpected end of input");
                    }
                }
            Some(l) if CLOSERS.contains(l) => {
                if complete {
                    return (i,s);
                } else {
                    panic!("unexpected end of input")
                }
            }
            Some(Lexeme::NewLine) => {
                if complete {
                    return (i,s);
                } else {
                    i += 1;
                }
            }
            Some(l) => panic!("unexpected lexeme: {:?},{:?}",i,l),
        }
    }
}
