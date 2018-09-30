use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::{ToPrimitive,Zero};
use interpreter::value::EMPTY;
use interpreter::env::Environment;

impl Numeric for CB {
    fn type_of(&self) -> NT {
        NT::CB
    }
    fn get_unit(&self) -> D {
        D::empty()
    }
    fn get_unit_ref(&self) -> &D {
        &EMPTY
    }
    fn get_shape(&self) -> (usize,usize) {
        (1,1)
    }
    fn get_size(&self) -> usize {
        1
    }
    fn to_ri(self: Box<Self>) -> RI {
        if self.im.is_zero() {
            self.re.to_i64().expect("number to big")
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rf(self: Box<Self>) -> RF {
        if self.im.is_zero() {
            self.re.to_f64().expect("number to big")
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rb(self: Box<Self>) -> RB {
        if self.im.is_zero() {
            self.re
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        if self.im.is_zero() {
            DMatrix::from_element(1,1,self.re.to_i64().expect("number to big"))
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        if self.im.is_zero() {
            DMatrix::from_element(1,1,self.re.to_f64().expect("number to big"))
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_uri(self: Box<Self>) -> URI {
        if self.im.is_zero() {
            UT(self.re.to_i64().expect("number to big"),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urf(self: Box<Self>) -> URF {
        if self.im.is_zero() {
            UT(self.re.to_f64().expect("number to big"),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urb(self: Box<Self>) -> URB {
        if self.im.is_zero() {
            UT(self.re,D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urim(self: Box<Self>) -> URIM {
        if self.im.is_zero() {
            UT(DMatrix::from_element(1,1,self.re.to_i64().expect("number to big")),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        if self.im.is_zero() {
            UT(DMatrix::from_element(1,1,self.re.to_f64().expect("number to big")),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_ci(self: Box<Self>) -> CI {
        Complex::new(self.re.to_i64().expect("number to big"),self.im.to_i64().expect("number too big"))
    }
    fn to_cf(self: Box<Self>) -> CF {
        Complex::new(self.re.to_f64().expect("number to big"),self.im.to_f64().expect("number too big"))
    }
    fn to_cb(self: Box<Self>) -> CB {
        *self
    }
    fn to_cim(self: Box<Self>) -> CIM {
        DMatrix::from_element(1,1,Complex::new(self.re.to_i64().expect("number to big"),self.im.to_i64().expect("number too big")))
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        DMatrix::from_element(1,1,Complex::new(self.re.to_f64().expect("number to big"),self.im.to_f64().expect("number too big")))
    }
    fn to_uci(self: Box<Self>) -> UCI {
        UT(Complex::new(self.re.to_i64().expect("number to big"),self.im.to_i64().expect("number too big")),D::empty())
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        UT(Complex::new(self.re.to_f64().expect("number to big"),self.im.to_f64().expect("number too big")),D::empty())
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        UT(*self,D::empty())
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(DMatrix::from_element(1,1,Complex::new(self.re.to_i64().expect("number to big"),self.im.to_i64().expect("number too big"))),D::empty())
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(DMatrix::from_element(1,1,Complex::new(self.re.to_f64().expect("number to big"),self.im.to_f64().expect("number too big"))),D::empty())
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.to_string()
    }
}
