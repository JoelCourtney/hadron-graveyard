use super::calc::{Calc,ValType,Precision};
use na::*;
use nc::{Complex,Complex64};
use ni::{BigInt,ToBigInt};

#[derive(Debug,PartialEq,Clone)]
pub struct UnitVal<T: Calc> {
    pub v: T,
    pub u: U,
}
pub type UV<T> = UnitVal<T>;

impl<T: Calc> UV<T> {
    pub fn from(v: T) -> UV<T> {
        UV {
            v: v,
            u: U::empty(),
        }
    }
}

#[derive(Debug,PartialEq,Eq,Hash,Copy,Clone)]
pub struct Fraction {
    pub n: u64,
    pub d: u64,
}
pub type U = Fraction;
pub type Q = Fraction;

impl U {
    pub fn is_unitless(&self) -> bool {
        self.n == self.d
    }
    fn empty() -> U {
        U { n:1, d:1 }
    }
    pub fn to_str(&self) -> String {
        String::from(format!("[{}/{}]",self.n,self.d))
    }
}

pub struct Converter {
    mult: f64,
    add: f64,
}

pub type C = Converter;
