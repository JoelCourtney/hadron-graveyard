use ast::{Lexeme,LValue};
use super::{OPENERS,CLOSERS,rvalue,traverse};

pub fn delimit(lexemes: &[Lexeme]) -> usize {
    let mut complete = false;
    let mut i = 0;
    let starts_with_pipe = lexemes.get(0) == Some(&Lexeme::Pipe);
    loop {
        match lexemes.get(i) {
            Some(Lexeme::Comma)
                | Some(Lexeme::Semicolon)
                | Some(Lexeme::NewLine)
                | Some(Lexeme::RightArrow)
                | Some(Lexeme::Assign)
                | Some(Lexeme::AssignOp(_))
                | Some(Lexeme::OScope)
                | Some(Lexeme::As)
                | Some(Lexeme::At)
                | None => {
                    if complete {
                        return i;
                    } else {
                        panic!("unexpected end of lvalue");
                    }
                }
            Some(Lexeme::Pipe) => {
                if starts_with_pipe {
                    i += traverse::atom(&lexemes[i..]);
                    return i;
                } else if complete {
                    return i;
                } else {
                    panic!("unexpected pipe in lvalue");
                }
            }
            Some(l) if OPENERS.contains(l) => {
                i += traverse::atom(&lexemes[i..]);
                complete = true;
            }
            Some(Lexeme::BinaryOp(_))
                | Some(Lexeme::UnaryOp(_)) => {
                    panic!("unexpected operation in lvalue");
                }
            Some(Lexeme::Dot) => {
                i += 1;
                complete = false;
            }
            Some(Lexeme::Handle(_))
                | Some(Lexeme::Question) => {
                    complete = true;
                    i += 1;
                }
            Some(l) if CLOSERS.contains(l) => {
                if complete {
                    return i;
                } else {
                    panic!("unexpected end of lvalue");
                }
            }
            Some(l) => {
                panic!("unexpected term in lvalue: {:?}",l);
            }
        }
    }
}

pub fn parse(lexemes: &[Lexeme]) -> (Box<LValue>,usize) {
    let length = delimit(&lexemes);
    (parse_contained(&lexemes[..length]),length)
}

pub fn parse_contained(lexemes: &[Lexeme]) -> Box<LValue> {
    let mut i = 0;
    match lexemes.last() {
        Some(Lexeme::Question) => {
            return Box::new(LValue::Lazy(parse_contained(&lexemes[..lexemes.len()-1])));
        }
        _ => {}
    }
    let first = lexemes.get(0);
    match first {
        Some(Lexeme::Handle(s)) => {
            match s.as_ref() {
                "_" => {
                    Box::new(LValue::Discard)
                }
                _ => {
                    if lexemes.len() > 1 {
                        let lv = rvalue::parse_search(&lexemes,11);
                        return Box::new(LValue::Subset(lv));
                    } else {
                        Box::new(LValue::Name(s.clone()))
                    }
                }
            }
        }
        Some(Lexeme::OList) => {
            let mut vec = Vec::new();
            i += 1;
            loop {
                let (lv,length) = parse(&lexemes[i..]);
                i += length;
                vec.push(*lv);
                match lexemes.get(i) {
                    Some(Lexeme::Comma) => {
                        i += 1;
                    }
                    Some(Lexeme::CBraket) => {
                        return Box::new(LValue::ListDecomp(vec));
                    }
                    _ => panic!("invalid list decomposition"),
                }
            }
        }
        Some(Lexeme::OMatrix) => {
            let mut outer_vec = Vec::new();
            let mut inner_vec = Vec::new();
            i += 1;
            loop {
                let (lv,length) = parse(&lexemes[i..]);
                i += length;
                inner_vec.push(*lv);
                match lexemes.get(i) {
                    Some(Lexeme::Comma) => {
                        i += 1;
                    }
                    Some(Lexeme::Semicolon) => {
                        outer_vec.push(inner_vec);
                        inner_vec = Vec::new();
                        i += 1;
                    }
                    Some(Lexeme::CParen) => {
                        let l = inner_vec.len();
                        for v in &outer_vec {
                            if v.len() != l {
                                panic!("non-rectangular matrix decomposition");
                            }
                        }
                        outer_vec.push(inner_vec);
                        return Box::new(LValue::MatrixDecomp(outer_vec));
                    }
                    _ => panic!("invalid matrix decomposition"),
                }
            }
        }
        _ => panic!("expected lvalue"),
    }
}

pub fn parse_list(lexemes: &[Lexeme]) -> Vec<LValue> {
    let l = lexemes.len();
    match (lexemes.get(0),lexemes.get(l-1)) {
        (Some(Lexeme::OList),Some(c)) if c != &Lexeme::CBraket => {
            panic!("expected close braket");
        }
        (Some(Lexeme::OArgList),Some(c)) if c != &Lexeme::CParen => {
            panic!("expected close paren");
        }
        (Some(Lexeme::Pipe),Some(c)) if c != &Lexeme::Pipe => {
            panic!("expected pipe");
        }
        (Some(c),_) if *c != Lexeme::OList && *c != Lexeme::OArgList && *c != Lexeme::Pipe => {
            panic!("expected one of (, [, |");
        }
        (_,_) => {}
    }
    match lexemes.get(1) {
        Some(Lexeme::CBraket)
            | Some(Lexeme::CParen)
            | Some(Lexeme::Pipe) => {
                return Vec::new();
            }
        _ => {}
    }
    let mut i = 1;
    let mut vec = Vec::new();
    while i < l {
        let (lv,length) = parse(&lexemes[i..]);
        i += length;
        vec.push(*lv);
        match lexemes.get(i) {
            Some(Lexeme::Comma) => {
                i += 1;
            }
            Some(Lexeme::CBraket)
                | Some(Lexeme::CParen)
                | Some(Lexeme::Pipe) => {
                    return vec;
                }
            _ => panic!("invalid list structure"),
        }
    }
    panic!("invalid list structure");
}

