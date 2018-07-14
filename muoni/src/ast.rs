use super::values;

pub struct Scope {
    pub statements: Vec<Box<Control>>,
}

pub enum Control {
    AssignVariable {
        name: String,
        e1: Box<Arith>,
    },
    AssignVariableBOP {
        name: String,
        op: BOP,
        e1: Box<Arith>,
    },
    AssignConstant {
        name: String,
        e1: Box<Arith>,
    },
    StateValue {
        e1: Box<Arith>,
    },
    AssignFunction {
        name: String,
        args: Vec<String>,
        body: Box<Arith>,
    },
    Return {
        e1: Box<Arith>,
    },
    If {
        condition: Box<Arith>,
        body: Box<Arith>,
    },
    IfElse {
        condition: Box<Arith>,
        if_body: Box<Arith>,
        else_body: Box<Arith>,
    },
    IfSeries {
        conditions: Vec<Arith>,
        bodies: Vec<Arith>,
    },
    IfSeriesElse {
        conditions: Vec<Arith>,
        if_bodies: Vec<Arith>,
        else_body: Box<Arith>,
    },
    ForAs {
        range: Box<Arith>,
        target: Box<Arith>,
        body: Box<Arith>,
    },
    ForAsAt {
        range: Box<Arith>,
        target: Box<Arith>,
        index: Box<Arith>,
        body: Box<Arith>,
    },
    While {
        condition: Box<Arith>,
        body: Box<Arith>,
    },
    Empty,
}

pub enum Decomposition {
    Singular {
        n: String,
    },
    Matrix {
    },
}

pub enum Arith {
    Binary {
        op: BOP,
        e1: Box<Arith>,
        e2: Box<Arith>,
    },
    Unary {
        op: UOP,
        e1: Box<Arith>,
    },
    Call {
        f: String,
        args: Vec<Arith>,
    },
    Name {
        n: String,
    },
    Value {
        v: values::Value,
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
    OArgList,
    OScope,
    OMatrix,
    ORangeIn,
    ORangeEx,
    OUnit,
    OList,
    ONorm,
    ODeterminant,
    CParen,
    CBraket,
    CBrace,
    CNorm,
    CDeterminant,
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
}

#[derive(Debug)]
#[derive(PartialEq)]
pub enum UOP {
    Negate,
    Factorial,
    Norm,
    Determinant,
    Cardinality,
    Not,
}
