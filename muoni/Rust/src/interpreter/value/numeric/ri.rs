use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::value::EMPTY;
use interpreter::env::Environment;

impl Numeric for RI {
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
        *self
    }
    fn to_rf(self: Box<Self>) -> RF {
        *self as RF
    }
    fn to_rb(self: Box<Self>) -> RB {
        BigInt::from(*self)
    }
    fn to_rim(self: Box<Self>) -> RIM {
        DMatrix::from_element(1,1,*self)
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        DMatrix::from_element(1,1,*self as RF)
    }
    fn to_uri(self: Box<Self>) -> URI {
        UT(*self,D::empty())
    }
    fn to_urf(self: Box<Self>) -> URF {
        UT(*self as RF,D::empty())
    }
    fn to_urb(self: Box<Self>) -> URB {
        UT(BigInt::from(*self),D::empty())
    }
    fn to_urim(self: Box<Self>) -> URIM {
        UT(DMatrix::from_element(1,1,*self),D::empty())
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        UT(DMatrix::from_element(1,1,*self as RF),D::empty())
    }
    fn to_ci(self: Box<Self>) -> CI {
        Complex::from(*self)
    }
    fn to_cf(self: Box<Self>) -> CF {
        Complex::from(*self as RF)
    }
    fn to_cb(self: Box<Self>) -> CB {
        Complex::from(BigInt::from(*self))
    }
    fn to_cim(self: Box<Self>) -> CIM {
        DMatrix::from_element(1,1,Complex::from(*self))
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        DMatrix::from_element(1,1,Complex::from(*self as RF))
    }
    fn to_uci(self: Box<Self>) -> UCI {
        UT(Complex::from(*self),D::empty())
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        UT(Complex::from(*self as RF),D::empty())
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        UT(Complex::from(BigInt::from(*self)),D::empty())
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(DMatrix::from_element(1,1,Complex::from(*self)),D::empty())
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(DMatrix::from_element(1,1,Complex::from(*self as RF)),D::empty())
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(*self)
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.to_string()
    }
}
