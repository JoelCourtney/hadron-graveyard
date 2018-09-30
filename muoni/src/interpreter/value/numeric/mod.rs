use nb::BigInt;
use super::D;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use std::fmt;
use interpreter::env::Environment;

#[derive(Copy,Clone,PartialEq,Debug)]
pub enum NT {
    RI,
    RF,
    RB,
    RIM,
    RFM,
    URI,
    URF,
    URB,
    URIM,
    URFM,
    CI,
    CF,
    CB,
    CIM,
    CFM,
    UCI,
    UCF,
    UCB,
    UCIM,
    UCFM,
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
