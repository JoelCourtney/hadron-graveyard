use ast::{RValue,LValue,Statement};
use na::*;
use nc::{Complex,Complex64};
use ni::{BigInt,ToBigInt};
use num_traits::{ToPrimitive,Zero};

mod calc;
use self::calc::*;

#[derive(Debug,Copy,Clone,PartialEq)]
pub struct Val<T>(T);

type RI = Val<i64>;
type RF = Val<f64>;
type RB = Val<BigInt>;
type RM = Val<DMatrix<f64>>;
type CI = Val<Complex<i64>>;
type CF = Val<Complex64>;
type CM = Val<DMatrix<Complex64>>;
type S = Val<String>;
type B = Val<bool>;
pub type V = Val<Box<Calc>>;

impl<T> Val<T> {
    fn unwrap(&self) -> &T {
        &self.0
    }
    pub fn from<'a>(rv: &'a RValue) -> V {
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
    pub fn new<T1: Calc+'static>(n: T1) -> V {
        let result: Box<Calc> = Box::new(n);
        Val(result)
    }
}

impl V {
    pub fn add(&self, with: &V) -> V {
        let v1 = self.unwrap();
        let v2 = with.unwrap();
        let t1 = v1.type_of();
        let t2 = v2.type_of();
        match t1.add_type(t2) {
            ValEnum::L => {
                unimplemented!();
            }
            ValEnum::S => {
                return V::new(v1.to_str() + &v2.to_str());
            }
            ValEnum::B => {
                panic!("cannot add booleans")
            }
            ValEnum::RI => {
                return V::new(v1.to_ri() + v2.to_ri());
            }
            ValEnum::RF => {
                return V::new(v1.to_rf() + v2.to_rf());
            }
            ValEnum::RB => {
                return V::new(v1.to_rb() + v2.to_rb());
            }
            ValEnum::CI => {
                return V::new(v1.to_ci() + v2.to_ci());
            }
            ValEnum::CF => {
                return V::new(v1.to_cf() + v2.to_cf());
            }
            ValEnum::CB => {
                return V::new(v1.to_cb() + v2.to_cb());
            }
            _ => unimplemented!(),
        }
        unimplemented!()
    }
    pub fn sub(&self, with: &V) -> V {
        let v1 = self.unwrap();
        let v2 = with.unwrap();
        let t1 = v1.type_of();
        let t2 = v2.type_of();
        match t1.sub_type(t2) {
            ValEnum::L => {
                unimplemented!();
            }
            ValEnum::S => {
                panic!("cannot subtract strings");
            }
            ValEnum::B => {
                panic!("cannot subtract booleans");
            }
            ValEnum::RI => {
                return V::new(v1.to_ri() - v2.to_ri());
            }
            ValEnum::RF => {
                return V::new(v1.to_rf() - v2.to_rf());
            }
            ValEnum::RB => {
                return V::new(v1.to_rb() - v2.to_rb());
            }
            ValEnum::CI => {
                return V::new(v1.to_ci() - v2.to_ci());
            }
            ValEnum::CF => {
                return V::new(v1.to_cf() - v2.to_cf());
            }
            ValEnum::CB => {
                return V::new(v1.to_cb() - v2.to_cb());
            }
            _ => unimplemented!(),
        }
        unimplemented!()
    }
}

use std::fmt::{Debug,Formatter,Display,Result};

impl Debug for Calc {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f,"{}",self.to_str())
    }
}

impl Display for Calc {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f,"{}",self.to_str())
    }
}
