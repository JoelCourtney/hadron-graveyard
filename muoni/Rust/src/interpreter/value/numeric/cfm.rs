use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::value::EMPTY;
use interpreter::env::Environment;

impl Numeric for CFM {
    fn type_of(&self) -> NT {
        NT::CFM
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
                let n = *self.data.get_unchecked(0);
                if n.im == 0. {
                    n.re as RI
                } else {
                    panic!("cannot discard imaginary part")
                }
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
                let n = *self.data.get_unchecked(0);
                if n.im == 0. {
                    n.re
                } else {
                    panic!("cannot discard imaginary part")
                }
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
                let n = *self.data.get_unchecked(0);
                if n.im == 0. {
                    BigInt::from(n.re as RI)
                } else {
                    panic!("cannot discard imaginary part")
                }
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        self.map(|x| if x.im == 0. {x.re as RI} else {panic!("cannot discard imaginary part")})
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        self.map(|x| if x.im == 0. {x.re} else {panic!("cannot discard imaginary part")})
    }
    fn to_uri(self: Box<Self>) -> URI {
        if self.data.len() == 1 {
            unsafe {
                let n = *self.data.get_unchecked(0);
                if n.im == 0. {
                    UT(n.re as RI,D::empty())
                } else {
                    panic!("cannot discard imaginary part")
                }
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
                let n = *self.data.get_unchecked(0);
                if n.im == 0. {
                    UT(n.re,D::empty())
                } else {
                    panic!("cannot discard imaginary part")
                }
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
                let n = *self.data.get_unchecked(0);
                if n.im == 0. {
                    UT(BigInt::from(n.re as RI),D::empty())
                } else {
                    panic!("cannot discard imaginary part")
                }
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urim(self: Box<Self>) -> URIM {
        UT(self.map(|x| if x.im == 0. {x.re as RI} else {panic!("cannot discard imaginary part")}),D::empty())
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        UT(self.map(|x| if x.im == 0. {x.re} else {panic!("cannot discard imaginary part")}),D::empty())
    }
    fn to_ci(self: Box<Self>) -> CI {
        if self.data.len() == 1 {
            unsafe {
                let n = *self.data.get_unchecked(0);
                Complex::new(n.re as RI, n.im as RI)
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
                *self.data.get_unchecked(0)
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
                let n = *self.data.get_unchecked(0);
                Complex::new(BigInt::from(n.re as RI), BigInt::from(n.im as RI))
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cim(self: Box<Self>) -> CIM {
        self.map(|x| Complex::new(x.re as RI, x.im as RI))
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        *self
    }
    fn to_uci(self: Box<Self>) -> UCI {
        if self.data.len() == 1 {
            unsafe {
                let n = *self.data.get_unchecked(0);
                UT(Complex::new(n.re as RI, n.im as RI),D::empty())
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
                UT(*self.data.get_unchecked(0),D::empty())
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
                let n = *self.data.get_unchecked(0);
                UT(Complex::new(BigInt::from(n.re as RI), BigInt::from(n.im as RI)),D::empty())
            }
        } else if self.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        UT(self.map(|x| Complex::new(x.re as RI, x.im as RI)),D::empty())
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(*self,D::empty())
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.to_string()
    }
}
