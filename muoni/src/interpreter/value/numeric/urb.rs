use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::env::Environment;

impl Numeric for URB {
    fn type_of(&self) -> NT {
        NT::URB
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
            self.0.to_i64().expect("number to big")
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rf(self: Box<Self>) -> RF {
        if self.1.is_empty() {
            self.0.to_f64().expect("number to big")
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rb(self: Box<Self>) -> RB {
        if self.1.is_empty() {
            self.0
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        if self.1.is_empty() {
            DMatrix::from_element(1,1,self.0.to_i64().expect("number to big"))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        if self.1.is_empty() {
            DMatrix::from_element(1,1,self.0.to_f64().expect("number to big"))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_uri(self: Box<Self>) -> URI {
        UT(self.0.to_i64().expect("number to big"),self.1)
    }
    fn to_urf(self: Box<Self>) -> URF {
        UT(self.0.to_f64().expect("number to big"),self.1)
    }
    fn to_urb(self: Box<Self>) -> URB {
        *self
    }
    fn to_urim(self: Box<Self>) -> URIM {
        UT(DMatrix::from_element(1,1,self.0.to_i64().expect("number to big")),self.1)
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        UT(DMatrix::from_element(1,1,self.0.to_f64().expect("number to big")),self.1)
    }
    fn to_ci(self: Box<Self>) -> CI {
        if self.1.is_empty() {
            Complex::from(self.0.to_i64().expect("number to big"))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cf(self: Box<Self>) -> CF {
        if self.1.is_empty() {
            Complex::from(self.0.to_f64().expect("number to big"))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cb(self: Box<Self>) -> CB {
        if self.1.is_empty() {
            Complex::from(self.0)
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cim(self: Box<Self>) -> CIM {
        if self.1.is_empty() {
            DMatrix::from_element(1,1,Complex::from(self.0.to_i64().expect("number to big")))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        if self.1.is_empty() {
            DMatrix::from_element(1,1,Complex::from(self.0.to_f64().expect("number to big")))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_uci(self: Box<Self>) -> UCI {
        UT(Complex::from(self.0.to_i64().expect("number to big")),self.1)
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        UT(Complex::from(self.0.to_f64().expect("number to big")),self.1)
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        let s = *self;
        UT(Complex::from(s.0),s.1)
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(DMatrix::from_element(1,1,Complex::from(self.0.to_i64().expect("number to big"))),self.1)
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(DMatrix::from_element(1,1,Complex::from(self.0.to_f64().expect("number to big"))),self.1)
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.0.to_string() + &self.1.to_string(env)
    }
}
