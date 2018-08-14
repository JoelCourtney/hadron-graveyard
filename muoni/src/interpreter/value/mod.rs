use ast::{RValue,LValue,Statement};
use self::{Value::*,Number::*};

#[derive(Debug,PartialEq)]
pub struct Unit {
    n: i64,
    d: i64,
}

#[derive(Debug,PartialEq)]
pub enum Number {
    RI(i64),
    RD(f64),
    RM(Vec<Vec<f64>>),
    CI(i64,i64),
    CD(i64,i64),
    CM(Vec<Vec<(f64,f64)>>),
    R(f64,f64,f64),
}

#[derive(Debug,PartialEq)]
pub enum Value {
    S(String),
    N(Number),
    U(Number,Unit),
    B(bool),
    L(Vec<Value>),
    Z(Box<RValue>),
    F(Vec<LValue>,Vec<LValue>,Box<Statement>),
}

impl<'a> From<&'a RValue> for Value {
    fn from(rv: &'a RValue) -> Self {
        match rv {
            RValue::Number(f) if f % 1. == 0. => {
                N(RI(*f as i64))
            }
            RValue::Number(f) => {
                N(RD(*f))
            }
            RValue::StringLiteral(s) => {
                S(s.clone())
            }
            RValue::Bool(b) => {
                B(*b)
            }
            RValue::AnonFunction(a,c,b) => {
                F(a.clone(),c.clone(),b.clone())
            }
            _ => panic!("i wasn't ready yet"),
        }
    }
}
