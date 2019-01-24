use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::value::EMPTY;
use interpreter::env::Environment;

impl Numeric for RIM {
    fn type_of(&self) -> NT {
        NT::RIM
    }
    fn get_unit(&self) -> D {
        D::empty()
    }
    fn get_unit_ref(&self) -> &D {
        &EMPTY
    }
    fn get_shape(&self) -> (usize,usize) {
        (self.nrows(),self.ncols())
    }
    fn get_size(&self) -> usize {
        self.data.len()
    }
    fn to_ri(self: Box<Self>) -> RI {
        if self.data.len() == 1 {
            unsafe {
                *self.data.get_unchecked(0)
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rf(self: Box<Self>) -> RF {
        if self.data.len() == 1 {
            unsafe {
                *self.data.get_unchecked(0) as RF
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rb(self: Box<Self>) -> RB {
        if self.data.len() == 1 {
            unsafe {
                BigInt::from(*self.data.get_unchecked(0))
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        *self
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        self.map(|x| x as RF)
    }
    fn to_uri(self: Box<Self>) -> URI {
        if self.data.len() == 1 {
            unsafe {
                UT(*self.data.get_unchecked(0),D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urf(self: Box<Self>) -> URF {
        if self.data.len() == 1 {
            unsafe {
                UT(*self.data.get_unchecked(0) as RF,D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urb(self: Box<Self>) -> URB {
        if self.data.len() == 1 {
            unsafe {
                UT(BigInt::from(*self.data.get_unchecked(0)),D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urim(self: Box<Self>) -> URIM {
        UT(*self,D::empty())
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        UT(self.map(|x| x as RF),D::empty())
    }
    fn to_ci(self: Box<Self>) -> CI {
        if self.data.len() == 1 {
            unsafe {
                Complex::from(*self.data.get_unchecked(0))
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cf(self: Box<Self>) -> CF {
        if self.data.len() == 1 {
            unsafe {
                Complex::from(*self.data.get_unchecked(0) as RF)
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cb(self: Box<Self>) -> CB {
        if self.data.len() == 1 {
            unsafe {
                Complex::from(BigInt::from(*self.data.get_unchecked(0)))
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cim(self: Box<Self>) -> CIM {
        self.map(|x| Complex::from(x))
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        self.map(|x| Complex::from(x as RF))
    }
    fn to_uci(self: Box<Self>) -> UCI {
        if self.data.len() == 1 {
            unsafe {
                UT(Complex::from(*self.data.get_unchecked(0)),D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        if self.data.len() == 1 {
            unsafe {
                UT(Complex::from(*self.data.get_unchecked(0) as RF),D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        if self.data.len() == 1 {
            unsafe {
                UT(Complex::from(BigInt::from(*self.data.get_unchecked(0))),D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(self.map(|x| Complex::from(x)),D::empty())
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(self.map(|x| Complex::from(x as RF)),D::empty())
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.to_string()
    }
}
