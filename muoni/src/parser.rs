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
        println!("{:?}",control);
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
                    let (target,length) = parse_lvalue(&lexemes[i..]);
                    i += length;
                    let key2 = lexemes.get(i);
                    match key2 {
                        Some(Lexeme::At) => {
                            i += 1;
                            let (index,length) = parse_lvalue(&lexemes[i..]);
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
                    let (index,length) = parse_lvalue(&lexemes[i..]);
                    i += length;
                    let key2 = lexemes.get(i);
                    match key2 {
                        Some(Lexeme::As) => {
                            i += 1;
                            let (target,length) = parse_lvalue(&lexemes[i..]);
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
        Some(Lexeme::Print) => {
            i += 1;
            let (e1, length) = parse_rvalue(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::Print {
                    e1,
                }),
                i,
            )
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

const DECL_VAL:i32 = 0;
const DECL_VAR:i32 = 1;
const DECL_SYM:i32 = 2;
const DECL_FUN:i32 = 3;
const DECL_RET:i32 = 4;
const NO_DECL:i32 = 5;

fn parse_statement(lexemes: &[Lexeme]) -> (Box<Statement>,usize) {
    let mut complete = false;
    let mut level = 0;
    let decl = match lexemes.get(0) {
        Some(Lexeme::Val) => {
            DECL_VAL
        }
        Some(Lexeme::Var) => {
            DECL_VAR
        }
        Some(Lexeme::Sym) => {
            DECL_SYM
        }
        Some(Lexeme::Func) => {
            DECL_FUN
        }
        Some(Lexeme::LeftArrow) => {
            DECL_RET
        }
        Some(_) => {
            NO_DECL
        }
        None => {
            panic!("expected statement");
        }
    };
    
    match decl {
        DECL_VAR => {
            let (length,assign) = delimit_statement(&lexemes);
            if assign != -1 {
                let assign = assign as usize;
                let op = match lexemes.get(assign) {
                    Some(Lexeme::Assign) => Assign::Equal,
                    Some(Lexeme::RightArrow) => Assign::Lazy,
                    Some(Lexeme::AssignOp(o)) => Assign::OpEqual(*o),
                    _ => panic!("illegal assignment"),
                };
                let name = parse_lvalue_contained(&lexemes[1..assign]);
                let e1 = parse_rvalue_contained(&lexemes[assign+1 .. length]);
                (
                    Box::new(Statement::VarAssign {
                        name,
                        op,
                        e1,
                    }),
                    length + 1,
                )
            } else {
                let name = parse_lvalue_contained(&lexemes[1..length]);
                (
                    Box::new(Statement::VarDecl {
                        name,
                    }),
                    length,
                )
            }
        }
        DECL_VAL => {
            let (length,assign) = delimit_statement(&lexemes);
            if assign != -1 {
                let assign = assign as usize;
                let op = match lexemes.get(assign) {
                    Some(Lexeme::Assign) => Assign::Equal,
                    Some(Lexeme::RightArrow) => Assign::Lazy,
                    Some(Lexeme::AssignOp(o)) => Assign::OpEqual(*o),
                    _ => panic!("illegal assignment"),
                };
                let name = parse_lvalue_contained(&lexemes[1..assign]);
                let e1 = parse_rvalue_contained(&lexemes[assign+1 .. length]);
                (
                    Box::new(Statement::ValAssign {
                        name,
                        op,
                        e1,
                    }),
                    length + 1,
                )
            } else {
                let name = parse_lvalue_contained(&lexemes[1..length]);
                (
                    Box::new(Statement::ValDecl {
                        name,
                    }),
                    length,
                )
            }
        }
        DECL_SYM => {
            let (length,_) = delimit_statement(&lexemes);
            let name = parse_lvalue_contained(&lexemes[1..length]);
            (
                Box::new(Statement::Sym {
                    name,
                }),
                length,
            )
        }
        DECL_FUN => {
            unimplemented!();
        }
        DECL_RET => {
            let (length,_) = delimit_statement(&lexemes);
            let e1 = parse_rvalue_contained(&lexemes[1..length]);
            (
                Box::new(Statement::Return {
                    e1,
                }),
                length,
            )
        }
        NO_DECL => {
            let (length,assign) = delimit_statement(&lexemes);
            if assign != -1 {
                let assign = assign as usize;
                let op = match lexemes.get(assign) {
                    Some(Lexeme::Assign) => Assign::Equal,
                    Some(Lexeme::RightArrow) => Assign::Lazy,
                    Some(Lexeme::AssignOp(o)) => Assign::OpEqual(*o),
                    _ => panic!("illegal assignment"),
                };
                let name = parse_lvalue_contained(&lexemes[..assign]);
                let e1 = parse_rvalue_contained(&lexemes[assign+1 .. length]);
                (
                    Box::new(Statement::Assign {
                        name,
                        op,
                        e1,
                    }),
                    length + 1,
                )
            } else {
                let e1 = parse_rvalue_contained(&lexemes[..length]);
                (
                    Box::new(Statement::StateValue {
                        e1,
                    }),
                    length,
                )
            }
        }
        _ => {panic!("howd you even mess that up")}
    }
}

fn delimit_statement(lexemes: &[Lexeme]) -> (usize,i32) {
    let mut complete = false;
    let mut i = 0;
    let mut s = -1;
    loop {
        let cursor = lexemes.get(i);
        match cursor {
            Some(lexeme) if OPENERS.contains(lexeme) => {
                i += traverse_atom(&lexemes[i..]);
                complete = true;
            }
            Some(Lexeme::BinaryOp(_))
                | Some(Lexeme::UnaryOp(_))
                | Some(Lexeme::Dot)
                | Some(Lexeme::Colon) => {
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
                | Some(Lexeme::StringLiteral(_)) => {
                complete = true;
                i += 1;
            }
            Some(Lexeme::Var)
                | Some(Lexeme::Val)
                | Some(Lexeme::Sym) => {
                complete = false;
                i += 1;
            }
            None | Some(Lexeme::Semicolon) => {
                if complete {
                    return (i,s);
                } else {
                    panic!("unexpected end of input");
                }
            }
            Some(Lexeme::NewLine) => {
                if complete {
                    return (i,s);
                } else {
                    i += 1;
                }
            }
            Some(l) => panic!("unexpected lexeme: {:?}",l),
        }
    }
}

fn delimit_lvalue(lexemes: &[Lexeme]) -> usize {
    unimplemented!();
}

fn delimit_rvalue(lexemes: &[Lexeme]) -> usize {
    let mut complete = false;
    let mut i = 0;
    loop {
        match lexemes.get(i) {
            Some(l) if OPENERS.contains(l) => {
                i += traverse_atom(&lexemes[i..]);
                complete = true;
            }
            Some(Lexeme::BinaryOp(_))
                | Some(Lexeme::UnaryOp(_))
                | Some(Lexeme::Dot) => {
                complete = false;
                i += 1;
            }
            Some(Lexeme::Handle(_))
                | Some(Lexeme::Number(_))
                | Some(Lexeme::StringLiteral(_)) => {
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
            Some(Lexeme::NewLine) => {
                if complete {
                    return i;
                } else {
                    i += 1;
                }
            }
            _ => {
                panic!("unexpected character in rvalue");
            }
        }
    }
}

fn parse_lvalue(lexemes: &[Lexeme]) -> (Box<LValue>,usize) {
    let length = delimit_lvalue(&lexemes);
    (parse_lvalue_contained(&lexemes[..length]),length)
}


fn parse_lvalue_contained(lexemes: &[Lexeme]) -> Box<LValue> {
    let mut i = 0;
    let first = lexemes.get(0);
    match first {
        Some(Lexeme::Handle(s)) => {
            match s.as_ref() {
                "_" => {
                    Box::new(LValue::Discard)
                }
                _ => {
                    if lexemes.len() > 1 {
                        unimplemented!();
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
                let (lv,length) = parse_lvalue(&lexemes[i..]);
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
                let (lv,length) = parse_lvalue(&lexemes[i..]);
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

lazy_static! {
    static ref PRECEDENCE: Vec<Vec<BOP>> = vec![
        vec![BOP::Or, BOP::NOr],
        vec![BOP::XOr],
        vec![BOP::And, BOP::NAnd],
        vec![BOP::Is, BOP::Isnt],
        vec![BOP::Less, BOP::LessOrEqual, BOP::Greater, BOP::GreaterOrEqual],
        vec![BOP::Plus, BOP::Minus],
        vec![BOP::Times, BOP::ElemTimes, BOP::Divide, BOP::ElemDivide, BOP::Modulus],
        vec![BOP::Power, BOP::ElemPower],
    ];
    static ref REVERSE_PRECEDENCE: [BOP; 3] = [
        BOP::StripUnit,
        BOP::ConcatUnit,
        BOP::Convert,
    ];
    static ref OPENERS: [Lexeme; 7] = [
        Lexeme::OArgList,
        Lexeme::OScope,
        Lexeme::OMatrix,
        Lexeme::ORange(true),
        Lexeme::ORange(false),
        Lexeme::OUnit,
        Lexeme::OList,
    ];
    static ref CLOSERS: [Lexeme; 3] = [
        Lexeme::CParen,
        Lexeme::CBraket,
        Lexeme::CBrace,
    ];
}

fn parse_rvalue(lexemes: &[Lexeme]) -> (Box<RValue>, usize) {
    let length = delimit_rvalue(&lexemes);
    (parse_rvalue_search(&lexemes[..length], 0),length)
}

fn parse_rvalue_contained(lexemes: &[Lexeme]) -> Box<RValue> {
    parse_rvalue_search(lexemes, 0)
}

fn parse_rvalue_search(lexemes: &[Lexeme], level: usize) -> Box<RValue> {
    let l = lexemes.len();
    if level < 8 {
        let mut i = 0;
        while i < l {
            let lexeme = lexemes.get(i).unwrap();
            match lexeme {
                Lexeme::BinaryOp(bop) => {
                    if PRECEDENCE[level].contains(bop) {
                        let e1 = parse_rvalue_search(&lexemes[..i], level + 1);
                        let e2 = parse_rvalue_search(&lexemes[i+1..], level);
                        return Box::new(RValue::Binary(*bop,e1,e2));
                    }
                    i += 1;
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
        let mut i = l-1;
        while i > 0 {
            let lexeme = lexemes.get(i).unwrap();
            match lexeme {
                Lexeme::BinaryOp(bop) if REVERSE_PRECEDENCE.contains(bop) => {
                    let e1 = parse_rvalue_search(&lexemes[..i],level);
                    let e2 = parse_rvalue_search(&lexemes[i+1..],level+1);
                    return Box::new(RValue::Binary(*bop,e1,e2));
                }
                _ if CLOSERS.contains(lexeme) => {
                    i -= traverse_atom_reverse(&lexemes[..=i]);
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
    } else if level == 9 {
        let lexeme = lexemes.get(0).unwrap();
        match lexeme {
            Lexeme::UnaryOp(uop) => {
                let e1 = parse_rvalue_search(&lexemes[1..], level);
                return Box::new(RValue::Unary(*uop,e1));
            }
            _ => {
                return parse_rvalue_search(&lexemes, level + 1);
            }
        }
    } else if level == 10 {
        let start = lexemes.get(0).unwrap();
        match start {
            Lexeme::Handle(s) => {
                if lexemes.len() == 1 {
                    return Box::new(RValue::Name(s.clone()));
                } else {
                    let i = lexemes.len() - 1;
                    while i > 0 {
                        match lexemes.get(i)
            }
            Lexeme::Number(n) => {
                if lexemes.len() == 1 {
                    return Box::new(RValue::Number(*n));
                } else {
                    match lexemes.get(1) {
                        Some(Lexeme::OUnit) => {
                            let u = parse_rvalue_contained(&lexemes[2..lexemes.len()-1]);
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
                unimplemented!();
            }
            Lexeme::OArgList => {
                unimplemented!();
            }
            Lexeme::OScope => {
                unimplemented!();
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
                    let (rv,length) = parse_rvalue(&lexemes[i..]);
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
                            let u = parse_rvalue_contained(&lexemes[i+1..lexemes.len()-1]);
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
            Lexeme::ORange(inc) => {
                unimplemented!(); }
            Lexeme::OUnit => {
                let contents = parse_rvalue_contained(&lexemes[1..lexemes.len()-1]);
                return Box::new(RValue::Unit(contents));
            }
            Lexeme::OList => {
                unimplemented!();
            }
            _ => {}
        }
    }
    parse_rvalue_search(lexemes, level + 1)
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

fn traverse_atom_reverse(lexemes: &[Lexeme]) -> usize {
    let mut i = lexemes.len() - 1;
    let mut level = 1;
    loop {
        i -= 1;
        let lexeme = lexemes.get(i).unwrap();
        if CLOSERS.contains(lexeme) {
            level += 1;
        } else if OPENERS.contains(lexeme) {
            level -= 1;
            if level == 0 {
                return lexemes.len() - i - 1;
            }
        }
    }
}
