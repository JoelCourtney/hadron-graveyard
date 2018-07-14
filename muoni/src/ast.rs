use super::values;

pub struct Scope<'a> {
    pub statements: Vec<Control<'a>>,
}

pub enum Control<'a> {
    AssignVariable {
        name: String,
        e1: &'a Arith<'a>,
    },
    AssignVariableBOP {
        name: String,
        op: BOP,
        e1: &'a Arith<'a>,
    },
    AssignConstant {
        name: String,
        e1: &'a Arith<'a>,
    },
    StateValue {
        e1: &'a Arith<'a>,
    },
    AssignFunction {
        name: String,
        args: Vec<String>,
        body: &'a Scope<'a>,
    },
    If {
        condition: &'a Arith<'a>,
        body: &'a Scope<'a>,
    },
    IfElse {
        condition: &'a Arith<'a>,
        if_body: &'a Scope<'a>,
        else_body: &'a Scope<'a>,
    },
    IfSeries {
        conditions: Vec<Arith<'a>>,
        bodies: Vec<Scope<'a>>,
    },
    IfSeriesElse {
        conditions: Vec<Arith<'a>>,
        if_bodies: Vec<Scope<'a>>,
        else_body: &'a Scope<'a>,
    },
    ForAs {
        range: &'a Arith<'a>,
        target: String,
        body: &'a Scope<'a>,
    },
    ForAsAt {
        range: &'a Arith<'a>,
        target: String,
        index: String,
        body: &'a Scope<'a>,
    },
    While {
        condition: &'a Arith<'a>,
        body: &'a Scope<'a>,
    },
}

pub enum Arith<'a> {
    Binary {
        op: BOP,
        e1: &'a Arith<'a>,
        e2: &'a Arith<'a>,
    },
    Unary {
        op: UOP,
        e1: &'a Arith<'a>,
    },
    Call {
        f: String,
        args: Vec<Arith<'a>>,
    },
    Name {
        n: String,
    },
    Value {
        v: values::Value<'a>,
    },
}

pub enum BOP {
    Plus,
    Minus,
    Times,
    Divide,
    Power,
    Modulus,
    And,
    NAnd,
    Or,
    NOr,
    Xor,
    NXor,
    Is,
    Isnt,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
}

pub enum UOP {
    Negate,
    Factorial,
    Norm,
    Determinant,
    Cardinality,
    Not,
}
