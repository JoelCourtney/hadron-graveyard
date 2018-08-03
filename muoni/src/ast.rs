use super::values;

#[derive(Debug,PartialEq)]
pub struct Scope {
    pub statements: Vec<Box<Control>>,
}

#[derive(Debug,PartialEq)]
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
    Print {
        e1: Box<RValue>,
    },
    Break,
    BreakCount(i32),
    Continue,
    ContinueCount(i32),
    Fallthrough,
    Empty,
}

#[derive(Debug,PartialEq)]
pub enum Statement {
    VarDecl {
        name: Box<LValue>,
    },
    VarAssign {
        name: Box<LValue>,
        op: Assign,
        e1: Box<RValue>,
    },
    Assign {
        name: Box<LValue>,
        op: Assign,
        e1: Box<RValue>,
    },
    ValDecl {
        name: Box<LValue>,
    },
    ValAssign {
        name: Box<LValue>,
        op: Assign,
        e1: Box<RValue>,
    },
    Sym {
        name: Box<LValue>,
    },
    StateValue {
        e1: Box<RValue>,
    },
    AssignFunction {
        name: String,
        caps: Vec<String>,
        args: Vec<String>,
        body: Box<RValue>,
    },
    Return {
        e1: Box<RValue>,
    },
}

#[derive(Debug,PartialEq)]
pub enum Assign {
    Equal,
    Lazy,
    OpEqual(BOP),
}

#[derive(Debug,PartialEq)]
pub enum LValue {
    Name(String),
    MatrixDecomp(Vec<Vec<LValue>>),
    ListDecomp(Vec<LValue>),
    Subset(String,RValue),
    Discard,
}

#[derive(Debug,PartialEq)]
pub enum RValue {
    Binary(BOP,Box<RValue>,Box<RValue>),
    Unary(op: UOP,Box<RValue>),
    Call(Box<RValue>,Vec<RValue>),
    Access(Box<RValue>,String),
    Name(String),
    Number(f64),
    List(Vec<RValue>),
    Matrix(Vec<Vec<RValue>>),
    Bool(bool),
    Range(bool,f64,f64,f64,bool),
    RangeList(Vec<(i32,i32)>),
    Unit(Box<RValue>),
    UnitTag(Box<RValue>,Box<RValue>),
    Scope(Box<Scope>),
}

#[derive(Debug,PartialEq)]
pub enum Lexeme {
    BinaryOp(BOP),
    UnaryOp(UOP),
    Assign,
    AssignOp(BOP),
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
    Var,
    Val,
    Sym,
    Func,
    OParen,
    OArgList,
    OList,
    OScope,
    OMatrix,
    ORange(bool),
    OUnit,
    CParen,
    CBraket,
    CBrace,
    Pipe,
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
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum UOP {
    Negate,
    Shape,
    Size,
    Not,
}
