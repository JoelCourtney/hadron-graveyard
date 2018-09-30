use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::value::EMPTY;
use interpreter::env::Environment;

impl Numeric for RB {
    fn type_of(&self) -> NT {
        NT::RI
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
        self.to_i64().expect("number to big")
    }
    fn to_rf(self: Box<Self>) -> RF {
        self.to_f64().expect("number to big")
    }
    fn to_rb(self: Box<Self>) -> RB {
        *self
    }
    fn to_rim(self: Box<Self>) -> RIM {
        DMatrix::from_element(1,1,self.to_i64().expect("number to big"))
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        DMatrix::from_element(1,1,self.to_f64().expect("number to big"))
    }
    fn to_uri(self: Box<Self>) -> URI {
        UT(self.to_i64().expect("number to big"),D::empty())
    }
    fn to_urf(self: Box<Self>) -> URF {
        UT(self.to_f64().expect("number to big"),D::empty())
    }
    fn to_urb(self: Box<Self>) -> URB {
        UT(*self,D::empty())
    }
    fn to_urim(self: Box<Self>) -> URIM {
        UT(DMatrix::from_element(1,1,self.to_i64().expect("number to big")),D::empty())
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        UT(DMatrix::from_element(1,1,self.to_f64().expect("number to big")),D::empty())
    }
    fn to_ci(self: Box<Self>) -> CI {
        Complex::from(self.to_i64().expect("number to big"))
    }
    fn to_cf(self: Box<Self>) -> CF {
        Complex::from(self.to_f64().expect("number to big"))
    }
    fn to_cb(self: Box<Self>) -> CB {
        Complex::from(*self)
    }
    fn to_cim(self: Box<Self>) -> CIM {
        DMatrix::from_element(1,1,Complex::from(self.to_i64().expect("number to big")))
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        DMatrix::from_element(1,1,Complex::from(self.to_f64().expect("number to big")))
    }
    fn to_uci(self: Box<Self>) -> UCI {
        UT(Complex::from(self.to_i64().expect("number to big")),D::empty())
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        UT(Complex::from(self.to_f64().expect("number to big")),D::empty())
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        UT(Complex::from(*self),D::empty())
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(DMatrix::from_element(1,1,Complex::from(self.to_i64().expect("number to big"))),D::empty())
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(DMatrix::from_element(1,1,Complex::from(self.to_f64().expect("number to big"))),D::empty())
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.to_string()
    }
}
