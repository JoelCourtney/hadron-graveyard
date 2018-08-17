use ast::{RValue,LValue,Statement};
use na::*;
use nc::{Complex,Complex64};
use ni::{BigInt,ToBigInt};
use num_traits::{ToPrimitive,Zero};

mod calc;
use self::calc::*;

pub fn from<'a>(rv: &'a RValue) -> V<Box<Calc>> {
    match rv {
        RValue::Number(f) if f % 1. == 0. => {
            RI::new(*f as i64)
        }
        RValue::Number(f) => {
            RF::new(*f)
        }
        RValue::StringLiteral(s) => {
            S::new(s.clone())
        }
        RValue::Bool(b) => {
            B::new(*b)
        }
        _ => panic!("i wasn't ready yet"),
    }
}

#[derive(Debug,Copy,Clone)]
pub struct V<T>(T);

impl<T> V<T> {
    fn unwrap(self) -> T {
        self.0
    }
    pub fn from<'a>(rv: &'a RValue) -> V<Box<Calc>> {
        match rv {
            RValue::Number(f) if f % 1. == 0. => {
                RI::new(*f as i64)
            }
            RValue::Number(f) => {
                RF::new(*f)
            }
            RValue::StringLiteral(s) => {
                S::new(s.clone())
            }
            RValue::Bool(b) => {
                B::new(*b)
            }
            _ => panic!("i wasn't ready yet"),
        }
    }
    pub fn new<T1: Calc+'static>(n: T1) -> V<Box<Calc>> {
        let result: Box<Calc> = Box::new(n);
        V(result)
    }
}

use std::ops::Add;
impl Add<V<Box<Calc>>> for V<Box<Calc>> {
    type Output = V<Box<Calc>>;

    fn add(self, other: V<Box<Calc>>) -> Self::Output {
        let v1 = self.unwrap();
        let v2 = other.unwrap();
        let t1 = v1.type_of();
        let t2 = v2.type_of();
        if t1.list {
            unimplemented!();
        }
        if t1.string || t2.string {
            return S::new(v1.to_str() + &v2.to_str());
        }

        unimplemented!()
    }
}


type RI = V<i64>;
type RF = V<f64>;
type RB = V<BigInt>;
type RM = V<DMatrix<f64>>;
type CI = V<Complex<i64>>;
type CF = V<Complex64>;
type CM = V<DMatrix<Complex64>>;
type S = V<String>;
pub type B = V<bool>;

use std::fmt::{Debug,Formatter,Display,Result};

impl Debug for Calc {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f,"{}",self.to_str())
    }
}

impl Display for Calc {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f,"{}",5)
    }
}
