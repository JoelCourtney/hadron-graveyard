use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::{ToPrimitive,Zero};
use interpreter::env::Environment;

impl Numeric for UCB {
    fn type_of(&self) -> NT {
        NT::UCB
    }
    fn get_unit(&self) -> D {
        self.1.clone()
    }
    fn get_unit_ref(&self) -> &D {
        &self.1
    }
    fn get_shape(&self) -> (usize,usize) {
        (1,1)
    }
    fn get_size(&self) -> usize {
        1
    }
    fn to_ri(self: Box<Self>) -> RI {
        if self.1.is_empty() {
            if self.0.im.is_zero() {
                self.0.re.to_i64().expect("number to big")
            } else {
                panic!("cannot discard imaginary part")
            }
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rf(self: Box<Self>) -> RF {
        if self.1.is_empty() {
            if self.0.im.is_zero() {
                self.0.re.to_f64().expect("number to big")
            } else {
                panic!("cannot discard imaginary part")
            }
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rb(self: Box<Self>) -> RB {
        if self.1.is_empty() {
            if self.0.im.is_zero() {
                self.0.re
            } else {
                panic!("cannot discard imaginary part")
            }
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        if self.1.is_empty() {
            if self.0.im.is_zero() {
                DMatrix::from_element(1,1,self.0.re.to_i64().expect("number to big"))
            } else {
                panic!("cannot discard imaginary part")
            }
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        if self.1.is_empty() {
            if self.0.im.is_zero() {
                DMatrix::from_element(1,1,self.0.re.to_f64().expect("number to big"))
            } else {
                panic!("cannot discard imaginary part")
            }
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_uri(self: Box<Self>) -> URI {
        if self.0.im.is_zero() {
            UT(self.0.re.to_i64().expect("number to big"),self.1)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urf(self: Box<Self>) -> URF {
        if self.0.im.is_zero() {
            UT(self.0.re.to_f64().expect("number to big"),self.1)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urb(self: Box<Self>) -> URB {
        if self.0.im.is_zero() {
            let s = *self;
            UT(s.0.re,s.1)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urim(self: Box<Self>) -> URIM {
        if self.0.im.is_zero() {
            UT(DMatrix::from_element(1,1,self.0.re.to_i64().expect("number to big")),self.1)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        if self.0.im.is_zero() {
            UT(DMatrix::from_element(1,1,self.0.re.to_f64().expect("number to big")),self.1)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_ci(self: Box<Self>) -> CI {
        if self.1.is_empty() {
            Complex::new(self.0.re.to_i64().expect("number to big"), self.0.im.to_i64().expect("number to big"))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cf(self: Box<Self>) -> CF {
        if self.1.is_empty() {
            Complex::new(self.0.re.to_f64().expect("number to big"), self.0.im.to_f64().expect("number to big"))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cb(self: Box<Self>) -> CB {
        if self.1.is_empty() {
            self.0
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cim(self: Box<Self>) -> CIM {
        if self.1.is_empty() {
            DMatrix::from_element(1,1,Complex::new(self.0.re.to_i64().expect("number to big"), self.0.im.to_i64().expect("number to big")))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        if self.1.is_empty() {
            DMatrix::from_element(1,1,Complex::new(self.0.re.to_f64().expect("number to big"), self.0.im.to_f64().expect("number to big")))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_uci(self: Box<Self>) -> UCI {
        UT(Complex::new(self.0.re.to_i64().expect("number to big"), self.0.im.to_i64().expect("number to big")),self.1)
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        UT(Complex::new(self.0.re.to_f64().expect("number to big"), self.0.im.to_f64().expect("number to big")),self.1)
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        *self
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(DMatrix::from_element(1,1,Complex::new(self.0.re.to_i64().expect("number to big"), self.0.im.to_i64().expect("number to big"))),self.1)
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(DMatrix::from_element(1,1,Complex::new(self.0.re.to_f64().expect("number to big"), self.0.im.to_f64().expect("number to big"))),self.1)
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.0.to_string() + &self.1.to_string(env)
    }
}
