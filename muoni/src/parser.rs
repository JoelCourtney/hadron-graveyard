// parse_statment
// parse_lvalue
// parse_rvalue
// parse_control
// parse_scope

use super::ast::*;
use super::values::*;

pub fn parse(lexemes: Vec<Lexeme>) -> Vec<Control> {
    let mut controls = Vec::new();
    let l = lexemes.len();
    let mut i = 0;
    while i < l-1 {
        let (control,length) = parse_control(&lexemes[i..]);
        match *control {
            Control::Empty => {
                println!("{},{}",i,l);
            }
            _ => {}
        }
        println!("{:?}",control);
        controls.push(*control);
        i += length;
    }
    controls
}

fn parse_scope(lexemes: &[Lexeme]) -> (Vec<Control>,usize) {
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
        let (control,length) = parse_control(&lexemes[i..]);
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
                            let (body,length) = parse_statement(&lexemes[i..]);
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
                            let (body,length) = parse_statement(&lexemes[i..]);
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
                            let (body,length) = parse_statement(&lexemes[i..]);
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
                            let (body,length) = parse_statement(&lexemes[i..]);
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
                    let (body,length) = parse_statement(&lexemes[i..]);
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
        Some(Lexeme::Return) => {
            let length = delimit_rvalue(&lexemes[i..]);
            if length > 1 {
                let e1 = parse_rvalue_contained(&lexemes[i+1..i+length]);
                i += length;
                (
                    Box::new(Control::Return {
                        e1,
                    }),
                    i,
                )
            } else {
                (
                    Box::new(Control::ReturnEmpty),
                    i,
                )
            }
        }
        Some(Lexeme::BreakSeries(series)) => {
            let length = delimit_rvalue(&lexemes[i..]);
            if length > 1 {
                let e1 = parse_rvalue_contained(&lexemes[i+1..i+length]);
                i += length;
                (
                    Box::new(Control::Break {
                        series: (*series).clone(),
                        e1,
                    }),
                    i,
                )
            } else {
                (
                    Box::new(Control::BreakEmpty {
                        series: (*series).clone(),
                    }),
                    i,
                )
            }
        }
        Some(Lexeme::Collapse) => {
            i += 1;
            let (name,length) = parse_lvalue(&lexemes[i..]);
            i += length;
            (
                Box::new(Control::Collapse {
                    name,
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
            let name;
            match lexemes.get(1) {
                Some(Lexeme::Handle(s)) => {
                    name = s.clone();
                }
                _ => panic!("expected function name"),
            }
            let mut i = 2;
            let args;
            match lexemes.get(i) {
                Some(Lexeme::OArgList) => {
                    let length = delimit_lvalue(&lexemes[i..]);
                    args = parse_lvalue_list(&lexemes[i..i+length]);
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
                    let length = delimit_lvalue(&lexemes[i..]);
                    caps = parse_lvalue_list(&lexemes[i..i+length]);
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
            let (body,length) = parse_statement(&lexemes[i..]);
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
        NO_DECL => {
            let (length,assign) = delimit_statement(&lexemes);
            if assign != -1 {
                let assign = assign as usize;
                let op = match lexemes.get(assign) {
                    Some(Lexeme::Assign) => Assign::Equal,
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
                | Some(Lexeme::Return)
                | Some(Lexeme::BreakSeries(_))
                | Some(Lexeme::StringLiteral(_))
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
            Some(l) => panic!("unexpected lexeme: {:?},{:?}",i,l),
        }
    }
}

fn delimit_lvalue(lexemes: &[Lexeme]) -> usize {
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
                    i += traverse_atom(&lexemes[i..]);
                    return i;
                } else if complete {
                    return i;
                } else {
                    panic!("unexpected pipe in lvalue");
                }
            }
            Some(l) if OPENERS.contains(l) => {
                i += traverse_atom(&lexemes[i..]);
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

fn parse_lvalue(lexemes: &[Lexeme]) -> (Box<LValue>,usize) {
    let length = delimit_lvalue(&lexemes);
    (parse_lvalue_contained(&lexemes[..length]),length)
}


fn parse_lvalue_contained(lexemes: &[Lexeme]) -> Box<LValue> {
    let mut i = 0;
    match lexemes.last() {
        Some(Lexeme::Question) => {
            return Box::new(LValue::Lazy(parse_lvalue_contained(&lexemes[..lexemes.len()-1])));
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
                        let lv = parse_rvalue_search(&lexemes,11);
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

fn parse_lvalue_list(lexemes: &[Lexeme]) -> Vec<LValue> {
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
        let (lv,length) = parse_lvalue(&lexemes[i..]);
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
    ];
    static ref REVERSE_PRECEDENCE: [BOP; 3] = [
        BOP::StripUnit,
        BOP::ConcatUnit,
        BOP::Convert,
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

fn parse_rvalue(lexemes: &[Lexeme]) -> (Box<RValue>, usize) {
    let length = delimit_rvalue(&lexemes);
    (parse_rvalue_search(&lexemes[..length], 0),length)
}

fn parse_rvalue_contained(lexemes: &[Lexeme]) -> Box<RValue> {
    parse_rvalue_search(lexemes, 0)
}

fn parse_rvalue_search(lexemes: &[Lexeme], level: usize) -> Box<RValue> {
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
                    let length = delimit_lvalue(&lexemes[i..]);
                    args = parse_lvalue_list(&lexemes[i..i+length]);
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
                    let length = delimit_lvalue(&lexemes[i..]);
                    caps = parse_lvalue_list(&lexemes[i..i+length]);
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
            let (body,length) = parse_statement(&lexemes[i..]);
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
    } else if level == 9 {
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
    } else if level == 10 {
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
                                        let obj = parse_rvalue_search(&lexemes[..i-1],11);
                                        return Box::new(RValue::Access(
                                            obj,
                                            s.clone(),
                                        ));
                                    }
                                    _ => panic!("expected dot"),
                                }
                            }
                            Some(l) if CLOSERS.contains(l) => {
                                i -= traverse_atom_reverse(&lexemes[..i+1]);
                            }
                            Some(Lexeme::OArgList)
                                | Some(Lexeme::OList) => {
                                    let func = parse_rvalue_search(&lexemes[..i],11);
                                    let call = parse_rvalue_search(&lexemes[i..],11);
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
                return Box::new(RValue::StringLiteral(s.clone()));
            }
            Lexeme::OArgList => {
                return Box::new(RValue::ArgList(
                    parse_list(&lexemes)
                ))
            }
            Lexeme::OScope => {
                let (scope,length) = parse_scope(lexemes);
                if length != lexemes.len() {
                    panic!("how why what: {} {}",length,lexemes.len());
                }
                return Box::new(
                    RValue::Scope(scope)
                )
            }
            Lexeme::Pipe => {
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
            Lexeme::OUnit => {
                let contents = parse_rvalue_contained(&lexemes[1..lexemes.len()-1]);
                return Box::new(RValue::Unit(contents));
            }
            Lexeme::OList => {
                return Box::new(RValue::List(
                    parse_list(&lexemes)
                ))
            }
            Lexeme::OParen => {
                return parse_rvalue_contained(&lexemes[1..lexemes.len()-1]);
            }
            _ => {}
        }
    }
    if level == 11 {
        panic!("rvalue search reached level 12");
    }
    parse_rvalue_search(lexemes, level + 1)
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
        let (rv,length) = parse_rvalue(&lexemes[i..]);
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

fn traverse_atom(lexemes: &[Lexeme]) -> usize {
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

fn traverse_atom_reverse(lexemes: &[Lexeme]) -> usize {
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
