use super::ast;

pub enum Value {
    Integer(i32),
    BigInteger(i32),
    Complex(f64,f64),
    IntegerVector(Vec<i32>),
    BigIntegerVector(Vec<i32>),
    ComplexVector(Vec<(f64,f64)>),
    IntegerMatrix(Vec<Vec<i32>>),
    BigIntegerMatrix(Vec<Vec<i32>>),
    ComplexMatrix(Vec<Vec<(f64,f64)>>),
    StringLiteral(String),
    Boolean(bool),
    Range(bool,f64,f64,f64,bool),
    List(Vec<Value>),
    Function(Vec<String>,ast::Scope),
}

// fn do_unary, fn do_binary, etc. no impl necessary, or even viable.
