use super::values;

pub struct Scope {
    pub statements: Vec<Box<Control>>,
}

pub enum Control {
    State {
        statement: Box<Statement>,
    },
    If {
        condition: Box<RValue>,
        body: Box<RValue>,
    },
    IfElse {
        condition: Box<RValue>,
        if_body: Box<RValue>,
        else_body: Box<RValue>,
    },
    IfSeries {
        conditions: Vec<RValue>,
        bodies: Vec<RValue>,
    },
    IfSeriesElse {
        conditions: Vec<RValue>,
        if_bodies: Vec<RValue>,
        else_body: Box<RValue>,
    },
    For {
        range: Box<RValue>,
        body: Box<RValue>,
    },
    ForAs {
        range: Box<RValue>,
        target: Box<LValue>,
        body: Box<RValue>,
    },
    ForAt {
        range: Box<RValue>,
        index: Box<LValue>,
        body: Box<RValue>,
    },
    ForAsAt {
        range: Box<RValue>,
        target: Box<LValue>,
        index: Box<LValue>,
        body: Box<RValue>,
    },
    While {
        condition: Box<RValue>,
        body: Box<RValue>,
    },
    Empty,
}

pub enum Statement {
    Assign {
        name: Box<LValue>,
        e1: Box<RValue>,
    },
    AssignBOP {
        name: Box<LValue>,
        op: BOP,
        e1: Box<RValue>,
    },
    Let {
        name: Box<LValue>,
        e1: Box<RValue>,
    },
    LazyAssign {
        name: Box<LValue>,
        e1: Box<RValue>,
    },
    StateValue {
        e1: Box<RValue>,
    },
    AssignFunction {
        name: String,
        args: Vec<String>,
        body: Box<RValue>,
    },
    Return {
        e1: Box<RValue>,
    },
}

pub enum LValue {
    Name(String),
    MatrixDecomp(Vec<Vec<LValue>>),
    ListDecomp(Vec<LValue>),
    Subset(String,RValue),
}

pub enum RValue {
    Binary {
        op: BOP,
        e1: Box<RValue>,
        e2: Box<RValue>,
    },
    Unary {
        op: UOP,
        e1: Box<RValue>,
    },
    Call {
        f: String,
        args: Vec<RValue>,
    },
    Name {
        n: String,
    },
    Value {
        v: values::Value,
    },
    Unit {
        u: values::Unit,
    },
    Scope {
        s: Box<Scope>,
    }
}

#[derive(Debug)]
#[derive(PartialEq)]
pub enum Lexeme {
    BinaryOp(BOP),
    UnaryOp(UOP),
    Assign,
    AssignOp(BOP),
    Let,
    RightArrow,
    LeftArrow,
    Colon,
    Comma,
    Semicolon,
    NewLine,
    Dot,
    Number(f64),
    Handle(String),
    StringLiteral(String),
    If,
    ElseIf,
    Else,
    While,
    For,
    As,
    At,
    OParen,
    OScope,
    OMatrix,
    ORange(bool),
    OUnit,
    OList,
    CParen,
    CBraket,
    CBrace,
    Print,
    None,
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum BOP {
    Plus,
    Minus,
    Times,
    ElemTimes,
    Divide,
    ElemDivide,
    Power,
    ElemPower,
    Modulus,
    And,
    NAnd,
    Or,
    NOr,
    XOr,
    Is,
    Isnt,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    StripUnit,
    ConcatUnit,
    Convert,
    Guard,
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum UOP {
    Negate,
    Factorial,
    Shape,
    Size,
    Not,
}
