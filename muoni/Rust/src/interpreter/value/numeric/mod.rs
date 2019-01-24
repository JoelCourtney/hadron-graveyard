use nb::BigInt;
use super::D;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use std::fmt;
use interpreter::env::Environment;
use std::ops::{BitOr,BitAnd};

pub const REAL: i8 = 0b0000000;
pub const COMPLEX: i8 = 0b0000001;
pub const QUATERNION: i8 = 0b0000011;
pub const OCTONION: i8 = 0b0000111;
pub const INTEGER: i8 = 0b0000000;
pub const BIGINT: i8 = 0b00001000;
pub const FLOAT: i8 = 0b0011000;
pub const SCALAR: i8 = 0b0000000;
pub const MATRIX: i8 = 0b0100000;
pub const DIMENSIONLESS: i8 = 0b0000000;
pub const DIMENSIONAL: i8 = 0b1000000;

#[derive(Copy,Clone,PartialEq,Debug)]
#[repr(i8)]
pub enum NT {
    RI = REAL,
    RF = FLOAT,
    RB = BIGINT,
    RIM = MATRIX,
    RFM = FLOAT | MATRIX,
    URI = DIMENSIONAL,
    URF = DIMENSIONAL | FLOAT,
    URB = DIMENSIONAL | BIGINT,
    URIM = DIMENSIONAL | MATRIX,
    URFM = DIMENSIONAL | FLOAT | MATRIX,
    CI = COMPLEX,
    CF = COMPLEX | FLOAT,
    CB = COMPLEX | BIGINT,
    CIM = COMPLEX | MATRIX,
    CFM = COMPLEX | FLOAT | MATRIX,
    UCI = DIMENSIONAL | COMPLEX,
    UCF = DIMENSIONAL | COMPLEX | FLOAT,
    UCB = DIMENSIONAL | COMPLEX | BIGINT,
    UCIM = DIMENSIONAL | COMPLEX | MATRIX,
    UCFM = DIMENSIONAL | COMPLEX | FLOAT | MATRIX,
}
 
impl From<i8> for NT {
    fn from(i: i8) -> Self {
        if i == NT::RI as i8 {
            NT::RI
        } else if i == NT::RF as i8 {
            NT::RF
        } else if i == NT::RB as i8 {
            NT::RB
        } else if i == NT::RIM as i8 {
            NT::RIM
        } else if i == NT::RFM as i8 {
            NT::RFM
        } else if i == NT::URI as i8 {
            NT::URI
        } else if i == NT::URF as i8 {
            NT::URF
        } else if i == NT::URB as i8 {
            NT::URB
        } else if i == NT::URIM as i8 {
            NT::URIM
        } else if i == NT::URFM as i8 {
            NT::URFM
        } else if i == NT::CI as i8 {
            NT::CI
        } else if i == NT::CF as i8 {
            NT::CF
        } else if i == NT::CB as i8 {
            NT::CB
        } else if i == NT::CIM as i8 {
            NT::CIM
        } else if i == NT::CFM as i8 {
            NT::CFM
        } else if i == NT::UCI as i8 {
            NT::UCI
        } else if i == NT::UCF as i8 {
            NT::UCF
        } else if i == NT::UCB as i8 {
            NT::UCB
        } else if i == NT::UCIM as i8 {
            NT::UCIM
        } else if i == NT::UCFM as i8 {
            NT::UCFM
        } else {
            panic!("something has gone terribly wrong")
        }
    }
}

impl BitOr<NT> for NT {
    type Output = NT;
    fn bitor(self, rhs: NT) -> Self::Output {
        NT::from(self as i8 | rhs as i8)
    }
}
impl BitOr<i8> for NT {
    type Output = NT;
    fn bitor(self, rhs: i8) -> Self::Output {
        NT::from(self as i8 | rhs)
    }
}
impl BitAnd<NT> for NT {
    type Output = NT;
    fn bitand(self, rhs: NT) -> Self::Output {
        NT::from(self as i8 & rhs as i8)
    }
}
impl BitAnd<i8> for NT {
    type Output = NT;
    fn bitand(self, rhs: i8) -> Self::Output {
        NT::from(self as i8 & rhs)
    }
}
impl PartialEq<i8> for NT {
    fn eq(&self, rhs: &i8) -> bool {
        *self as i8 == *rhs
    }
}

#[derive(Clone,PartialEq,Debug)]
pub struct UT<N>(pub N,pub D);
impl<N> UT<N> {
    pub fn new(n: N, u: D) -> UT<N> {
        UT(n,u)
    }
}

pub type RI = i64;
pub type RF = f64;
pub type RB = BigInt;
pub type RIM = DMatrix<i64>;
pub type RFM = DMatrix<f64>;
pub type URI = UT<i64>;
pub type URF = UT<f64>;
pub type URB = UT<BigInt>;
pub type URIM = UT<DMatrix<i64>>;
pub type URFM = UT<DMatrix<f64>>;
pub type CI = Complex<i64>;
pub type CF = Complex<f64>;
pub type CB = Complex<BigInt>;
pub type CIM = DMatrix<Complex<i64>>;
pub type CFM = DMatrix<Complex<f64>>;
pub type UCI = UT<Complex<i64>>;
pub type UCF = UT<Complex<f64>>;
pub type UCB = UT<Complex<BigInt>>;
pub type UCIM = UT<DMatrix<Complex<i64>>>;
pub type UCFM = UT<DMatrix<Complex<f64>>>;

pub trait Numeric {
    fn type_of(&self) -> NT;
    fn get_unit(&self) -> D;
    fn get_unit_ref(&self) -> &D;
    fn get_shape(&self) -> (usize,usize);
    fn get_size(&self) -> usize;
    fn to_ri(self: Box<Self>) -> RI;
    fn to_rf(self: Box<Self>) -> RF;
    fn to_rb(self: Box<Self>) -> RB;
    fn to_rim(self: Box<Self>) -> RIM;
    fn to_rfm(self: Box<Self>) -> RFM;
    fn to_uri(self: Box<Self>) -> URI;
    fn to_urf(self: Box<Self>) -> URF;
    fn to_urb(self: Box<Self>) -> URB;
    fn to_urim(self: Box<Self>) -> URIM;
    fn to_urfm(self: Box<Self>) -> URFM;
    fn to_ci(self: Box<Self>) -> CI;
    fn to_cf(self: Box<Self>) -> CF;
    fn to_cb(self: Box<Self>) -> CB;
    fn to_cim(self: Box<Self>) -> CIM;
    fn to_cfm(self: Box<Self>) -> CFM;
    fn to_uci(self: Box<Self>) -> UCI;
    fn to_ucf(self: Box<Self>) -> UCF;
    fn to_ucb(self: Box<Self>) -> UCB;
    fn to_ucim(self: Box<Self>) -> UCIM;
    fn to_ucfm(self: Box<Self>) -> UCFM;
    fn box_clone(&self) -> Box<Numeric>;
    fn to_basic_string(&self, env: &Environment) -> String;
}

impl Clone for Box<Numeric> {
    fn clone(&self) -> Self {
        self.box_clone()
    }
}
impl Box<Numeric> {
    fn add_ref(&self, with: &Box<Numeric>) -> Box<Numeric> {
        let t1 = self.type_of();
        let t2 = with.type_of();
        let t3 = t1 | t2;
        match t3 {
            NT::RI => Box::new(self.box_clone().to_ri() + with.box_clone().to_ri()),
            _ => unimplemented!(),
        }
    }
}

mod ri;
mod rf;
mod rb;
mod rim;
mod rfm;
mod uri;
mod urf;
mod urb;
mod urim;
mod urfm;
mod ci;
mod cf;
mod cb;
mod cim;
mod cfm;
mod uci;
mod ucf;
mod ucb;
mod ucim;
mod ucfm;
