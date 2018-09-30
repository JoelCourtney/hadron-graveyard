use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::value::EMPTY;
use interpreter::env::Environment;

impl Numeric for CF {
    fn type_of(&self) -> NT {
        NT::CF
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
        if self.im == 0. {
            self.re as RI
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rf(self: Box<Self>) -> RF {
        if self.im == 0. {
            self.re
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rb(self: Box<Self>) -> RB {
        if self.im == 0. {
            BigInt::from(self.re as RI)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        if self.im == 0. {
            DMatrix::from_element(1,1,self.re as RI)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        if self.im == 0. {
            DMatrix::from_element(1,1,self.re)
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_uri(self: Box<Self>) -> URI {
        if self.im == 0. {
            UT(self.re as RI,D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urf(self: Box<Self>) -> URF {
        if self.im == 0. {
            UT(self.re,D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urb(self: Box<Self>) -> URB {
        if self.im == 0. {
            UT(BigInt::from(self.re as RI),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urim(self: Box<Self>) -> URIM {
        if self.im == 0. {
            UT(DMatrix::from_element(1,1,self.re as RI),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        if self.im == 0. {
            UT(DMatrix::from_element(1,1,self.re),D::empty())
        } else {
            panic!("cannot discard imaginary part")
        }
    }
    fn to_ci(self: Box<Self>) -> CI {
        Complex::new(self.re as RI, self.im as RI)
    }
    fn to_cf(self: Box<Self>) -> CF {
        *self
    }
    fn to_cb(self: Box<Self>) -> CB {
        Complex::new(BigInt::from(self.re as RI),BigInt::from(self.im as RI))
    }
    fn to_cim(self: Box<Self>) -> CIM {
        DMatrix::from_element(1,1,Complex::new(self.re as RI, self.im as RI))
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        DMatrix::from_element(1,1,*self)
    }
    fn to_uci(self: Box<Self>) -> UCI {
        UT(Complex::new(self.re as RI, self.im as RI),D::empty())
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        UT(*self,D::empty())
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        UT(Complex::new(BigInt::from(self.re as RI),BigInt::from(self.im as RI)),D::empty())
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(DMatrix::from_element(1,1,Complex::new(self.re as RI, self.im as RI)),D::empty())
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(DMatrix::from_element(1,1,*self),D::empty())
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.to_string()
    }
}
