use super::values;

#[derive(Debug,PartialEq)]
pub enum Control {
    State {
        statement: Box<Statement>,
    },
    If {
        condition: Box<RValue>,
        body: Box<Statement>,
    },
    IfElse {
        condition: Box<RValue>,
        if_body: Box<Statement>,
        else_body: Box<Statement>,
    },
    IfSeries {
        conditions: Vec<RValue>,
        bodies: Vec<Statement>,
    },
    IfSeriesElse {
        conditions: Vec<RValue>,
        if_bodies: Vec<Statement>,
        else_body: Box<Statement>,
    },
    For {
        range: Box<RValue>,
        body: Box<Statement>,
    },
    ForAs {
        range: Box<RValue>,
        target: Box<LValue>,
        body: Box<Statement>,
    },
    ForAt {
        range: Box<RValue>,
        index: Box<LValue>,
        body: Box<Statement>,
    },
    ForAsAt {
        range: Box<RValue>,
        target: Box<LValue>,
        index: Box<LValue>,
        body: Box<Statement>,
    },
    While {
        condition: Box<RValue>,
        body: Box<Statement>,
    },
    Print {
        e1: Box<RValue>,
    },
    Return {
        e1: Box<RValue>,
    },
    ReturnEmpty,
    Break {
        series: Vec<Break>,
        e1: Box<RValue>
    },
    BreakEmpty {
        series: Vec<Break>
    },
    Collapse {
        name: Box<LValue>,
    },
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
        args: Vec<LValue>,
        caps: Vec<LValue>,
        body: Box<Statement>,
    },
}

#[derive(Debug,PartialEq)]
pub enum Assign {
    Equal,
    OpEqual(BOP),
}

#[derive(Debug,PartialEq)]
pub enum LValue {
    Name(String),
    Lazy(Box<LValue>),
    MatrixDecomp(Vec<Vec<LValue>>),
    ListDecomp(Vec<LValue>),
    Subset(Box<RValue>),
    Discard,
}

#[derive(Debug,PartialEq)]
pub enum RValue {
    Binary(BOP,Box<RValue>,Box<RValue>),
    Unary(UOP,Box<RValue>),
    Call(Box<RValue>,Box<RValue>),
    Access(Box<RValue>,String),
    Name(String),
    Number(f64),
    StringLiteral(String),
    List(Vec<RValue>),
    Matrix(Vec<Vec<RValue>>),
    ArgList(Vec<RValue>),
    Bool(bool),
    Range(Box<RValue>,Box<RValue>,Box<RValue>),
    Unit(Box<RValue>),
    UnitTag(Box<RValue>,Box<RValue>),
    CaptureScope(Vec<LValue>,Vec<Control>),
    Scope(Vec<Control>),
    Function(String,Vec<LValue>,Vec<LValue>,Box<Statement>),
    AnonFunction(Vec<LValue>,Vec<LValue>,Box<Statement>),
}

#[derive(Debug,PartialEq)]
pub enum Lexeme {
    BinaryOp(BOP),
    UnaryOp(UOP),
    Assign,
    AssignOp(BOP),
    RightArrow,
    Return,
    BreakSeries(Vec<Break>),
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
    Question,
    OParen,
    OArgList,
    OList,
    OScope,
    OMatrix,
    OUnit,
    CParen,
    CBraket,
    CBrace,
    Pipe,
    Print,
    Collapse,
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
    Range,
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum UOP {
    Negate,
    Shape,
    Size,
    Not,
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum Break {
    Dash,
    Tilde,
}
