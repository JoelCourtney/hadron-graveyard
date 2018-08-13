use ast::{RValue,Lexeme};
use super::{OPENERS,CLOSERS,PRECEDENCE,REVERSE_PRECEDENCE,scope,lvalue,traverse,statement};

pub fn delimit(lexemes: &[Lexeme]) -> usize {
    let mut complete = false;
    let mut i = 0;
    loop {
        match lexemes.get(i) {
            Some(Lexeme::OScope) if complete => {
                return i;
            }
            Some(l) if OPENERS.contains(l) => {
                i += traverse::atom(&lexemes[i..]);
                complete = true;
            }
            Some(Lexeme::BinaryOp(_))
                | Some(Lexeme::UnaryOp(_))
                | Some(Lexeme::Func)
                | Some(Lexeme::RightArrow)
                | Some(Lexeme::Dot) => {
                    complete = false;
                    i += 1;
                }
            Some(Lexeme::Handle(_))
                | Some(Lexeme::Number(_))
                | Some(Lexeme::StringLiteral(_))
                | Some(Lexeme::Return)
                | Some(Lexeme::BreakSeries(_)) => {
                    complete = true;
                    i += 1;
                }
            Some(Lexeme::Semicolon)
                | Some(Lexeme::Comma)
                | None => {
                    if complete {
                        return i;
                    } else {
                        panic!("unexpected end of rvalue");
                    }
                }
            Some(l) if CLOSERS.contains(l) => {
                if complete {
                    return i;
                } else {
                    panic!("unexpected end of rvalue");
                }
            }
            Some(Lexeme::NewLine)
                | Some(Lexeme::As)
                | Some(Lexeme::At) => {
                    if complete {
                        return i;
                    } else {
                        i += 1;
                    }
                }
            l => {
                panic!("unexpected character in rvalue: {:?}",l);
            }
        }
    }
}

pub fn parse(lexemes: &[Lexeme]) -> (Box<RValue>, usize) {
    let length = delimit(&lexemes);
    (parse_search(&lexemes[..length], 0),length)
}

pub fn parse_contained(lexemes: &[Lexeme]) -> Box<RValue> {
    parse_search(lexemes, 0)
}

pub fn parse_search(lexemes: &[Lexeme], level: usize) -> Box<RValue> {
    let l = lexemes.len();
    match lexemes.get(0) {
        Some(Lexeme::Func) => {
            let mut i = 1;
            let name;
            match lexemes.get(1) {
                Some(Lexeme::Handle(s)) => {
                    name = s.clone();
                    i += 1;
                }
                _ => {
                    name = String::from("");
                }
            }
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
                        _ => panic!("expected right arrow"),
                    }
                }
                l => panic!("expected -> or capture block: {:?}",l),
            }
            let (body,length) = statement::parse(&lexemes[i..]);
            if name.len() == 0 {
                return Box::new(RValue::AnonFunction(
                        args,
                        caps,
                        body,
                        ))
            } else {
                return Box::new(RValue::Function(
                        name,
                        args,
                        caps,
                        body,
                        ))
            }
        }
        _ => {}
    }
    if level < 9 {
        let mut i = 0;
        while i < l {
            let lexeme = lexemes.get(i).unwrap();
            match lexeme {
                Lexeme::BinaryOp(bop) => {
                    if PRECEDENCE[level].contains(bop) {
                        let e1 = parse_search(&lexemes[..i], level + 1);
                        let e2 = parse_search(&lexemes[i+1..], level);
                        return Box::new(RValue::Binary(*bop,e1,e2));
                    }
                    i += 1;
                }
                _ if OPENERS.contains(lexeme) => {
                    i += traverse::atom(&lexemes[i..]);
                }
                _ => {
                    i += 1;
                }
            }
        }
    } else if level == 9 {
        let mut i = l-1;
        while i > 0 {
            let lexeme = lexemes.get(i).unwrap();
            match lexeme {
                Lexeme::BinaryOp(bop) if REVERSE_PRECEDENCE.contains(bop) => {
                    let e1 = parse_search(&lexemes[..i],level);
                    let e2 = parse_search(&lexemes[i+1..],level+1);
                    return Box::new(RValue::Binary(*bop,e1,e2));
                }
                _ if CLOSERS.contains(lexeme) => {
                    i -= traverse::atom_reverse(&lexemes[..=i]);
                }
                _ => {
                    i -= 1;
                }
            }
        }
        match lexemes.get(0) {
            Some(Lexeme::BinaryOp(_)) => {
                panic!("expected something before operator");
            }
            _ => {}
        }
    } else if level == 10 {
        let lexeme = lexemes.get(0).unwrap();
        match lexeme {
            Lexeme::UnaryOp(uop) => {
                let e1 = parse_search(&lexemes[1..], level);
                return Box::new(RValue::Unary(*uop,e1));
            }
            _ => {
                return parse_search(&lexemes, level + 1);
            }
        }
    } else if level == 11 {
        let start = lexemes.get(0).unwrap();
        match start {
            Lexeme::Handle(s) => {
                if lexemes.len() == 1 {
                    return Box::new(RValue::Name(s.clone()));
                } else {
                    let mut i = lexemes.len() - 1;
                    while i > 0 {
                        let lex = lexemes.get(i);
                        match lex {
                            Some(Lexeme::Handle(s)) => {
                                match lexemes.get(i-1) {
                                    Some(Lexeme::Dot) => {
                                        let obj = parse_search(&lexemes[..i-1],11);
                                        return Box::new(RValue::Access(
                                                obj,
                                                s.clone(),
                                                ));
                                    }
                                    _ => panic!("expected dot"),
                                }
                            }
                            Some(l) if CLOSERS.contains(l) => {
                                i -= traverse::atom_reverse(&lexemes[..i+1]);
                            }
                            Some(Lexeme::OArgList)
                                | Some(Lexeme::OList) => {
                                    let func = parse_search(&lexemes[..i],11);
                                    let call = parse_search(&lexemes[i..],11);
                                    return Box::new(RValue::Call(
                                            func,
                                            call,
                                            ));
                                }
                            Some(_) => {
                                i -= 1;
                            }
                            None => panic!("something has gone horribly wrong"),
                        }
                    }
                }
            }
            Lexeme::Number(n) => {
                if lexemes.len() == 1 {
                    return Box::new(RValue::Number(*n));
                } else {
                    match lexemes.get(1) {
                        Some(Lexeme::OUnit) => {
                            let u = parse_contained(&lexemes[2..lexemes.len()-1]);
                            return Box::new(
                                RValue::UnitTag(
                                    Box::new(RValue::Number(*n)),
                                    u
                                    )
                                );
                        }
                        _ => panic!("unexpected character in rvalue"),
                    }
                }
            }
            Lexeme::StringLiteral(s) => {
                return Box::new(RValue::StringLiteral(s.clone()));
            }
            Lexeme::OArgList => {
                return Box::new(RValue::ArgList(
                        parse_list(&lexemes)
                        ))
            }
            Lexeme::OScope => {
                let (scope,length) = scope::parse(lexemes);
                if length != lexemes.len() {
                    panic!("how why what: {} {}",length,lexemes.len());
                }
                return Box::new(
                    RValue::Scope(scope)
                    )
            }
            Lexeme::Pipe => {
                let length = lvalue::delimit(lexemes);
                println!("{:?}",lexemes);
                println!("{},{:?}",length,lexemes.get(length));
                let caps = lvalue::parse_list(&lexemes[..length]);
                match lexemes.get(length) {
                    Some(Lexeme::OScope) => {
                        let (scope,slength) = scope::parse(&lexemes[length..]);
                        if slength + length != lexemes.len() {
                            panic!("{},{},{}",length,slength,lexemes.len());
                        }
                        return Box::new(
                            RValue::CaptureScope(caps,scope)
                            )
                    }
                    _ => panic!("expected {"),
                }
            }
            Lexeme::OMatrix => {
                let mut i = 1;
                let mut outer_vec = Vec::new();
                match lexemes.get(1) {
                    Some(Lexeme::CParen) => {
                        return Box::new(RValue::Matrix(outer_vec));
                    }
                    _ => {}
                }
                let mut inner_vec = Vec::new();
                while i < l {
                    let (rv,length) = parse(&lexemes[i..]);
                    inner_vec.push(*rv);
                    i += length;
                    match lexemes.get(i) {
                        Some(Lexeme::Comma) => {
                            i += 1;
                        }
                        Some(Lexeme::Semicolon) => {
                            i += 1;
                            outer_vec.push(inner_vec);
                            inner_vec = Vec::new();
                        }
                        Some(Lexeme::CParen) => {
                            outer_vec.push(inner_vec);
                            i += 1;
                            break;
                        }
                        None => panic!("matrix incomplete"),
                        _ => {
                            panic!("invalid matrix structure");
                        }
                    }
                }
                if i == l {
                    return Box::new(RValue::Matrix(outer_vec));
                } else {
                    match lexemes.get(i) {
                        Some(Lexeme::OUnit) => {
                            let u = parse_contained(&lexemes[i+1..lexemes.len()-1]);
                            return Box::new(
                                RValue::UnitTag(
                                    Box::new(RValue::Matrix(outer_vec)),
                                    u
                                    )
                                );
                        }
                        _ => panic!("expected unit annotation"),
                    }
                }
            }
            Lexeme::OUnit => {
                let contents = parse_contained(&lexemes[1..lexemes.len()-1]);
                return Box::new(RValue::Unit(contents));
            }
            Lexeme::OList => {
                return Box::new(RValue::List(
                        parse_list(&lexemes)
                        ))
            }
            Lexeme::OParen => {
                return parse_contained(&lexemes[1..lexemes.len()-1]);
            }
            _ => {}
        }
    }
    if level == 11 {
        panic!("rvalue search reached level 12");
    }
    parse_search(lexemes, level + 1)
}

fn parse_list(lexemes: &[Lexeme]) -> Vec<RValue> {
    let l = lexemes.len();
    match lexemes.get(0) {
        Some(Lexeme::OArgList) => {
            if lexemes.get(l-1) != Some(&Lexeme::CParen) {
                panic!("expected close paren");
            }
        }
        Some(Lexeme::OList) => {
            if lexemes.get(l-1) != Some(&Lexeme::CBraket) {
                panic!("expected close braket");
            }
        }
        _ => {
            panic!("expected ( or [");
        }
    }
    let mut vec = Vec::new();
    match lexemes.get(1) {
        Some(Lexeme::CParen) | Some(Lexeme::CBraket) => {
            return vec;
        }
        _ => {}
    }
    let mut i = 1;
    while i < l {
        let (rv,length) = parse(&lexemes[i..]);
        vec.push(*rv);
        i += length;
        match lexemes.get(i) {
            Some(Lexeme::Comma) => {
                i += 1;
            }
            Some(Lexeme::CParen) | Some(Lexeme::CBraket) => {
                return vec;
            }
            _ => panic!("expected , ) or ]"),
        }
    }
    panic!("list was not closed");
}
