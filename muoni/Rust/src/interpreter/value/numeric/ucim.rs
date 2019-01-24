use nb::BigInt;
use super::*;
use na::DMatrix;
use nc::Complex;
use num_traits::ToPrimitive;
use interpreter::env::Environment;

impl Numeric for UCIM {
    fn type_of(&self) -> NT {
        NT::UCIM
    }
    fn get_unit(&self) -> D {
        self.1.clone()
    }
    fn get_unit_ref(&self) -> &D {
        &self.1
    }
    fn get_shape(&self) -> (usize,usize) {
        (self.0.nrows(),self.0.ncols())
    }
    fn get_size(&self) -> usize {
        self.0.data.len()
    }
    fn to_ri(self: Box<Self>) -> RI {
        if self.0.data.len() == 1 {
            if self.1.is_empty() {
                unsafe {
                    let n = *self.0.data.get_unchecked(0);
                    if n.im == 0 {
                        n.re
                    } else {
                        panic!("cannot discard imaginary part")
                    }
                }
            } else {
                panic!("cannot discard units")
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rf(self: Box<Self>) -> RF {
        if self.0.data.len() == 1 {
            if self.1.is_empty() {
                unsafe {
                    let n = *self.0.data.get_unchecked(0);
                    if n.im == 0 {
                        n.re as RF
                    } else {
                        panic!("cannot discard imaginary part")
                    }
                }
            } else {
                panic!("cannot discard units")
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rb(self: Box<Self>) -> RB {
        if self.0.data.len() == 1 {
            if self.1.is_empty() {
                unsafe {
                    let n = *self.0.data.get_unchecked(0);
                    if n.im == 0 {
                        BigInt::from(n.re)
                    } else {
                        panic!("cannot discard imaginary part")
                    }
                }
            } else {
                panic!("cannot discard units")
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_rim(self: Box<Self>) -> RIM {
        if self.1.is_empty() {
            self.0.map(|x| if x.im == 0 {x.re} else {panic!("cannot discard imaginary part")})
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_rfm(self: Box<Self>) -> RFM {
        if self.1.is_empty() {
            self.0.map(|x| if x.im == 0 {x.re as RF} else {panic!("cannot discard imaginary part")})
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_uri(self: Box<Self>) -> URI {
        if self.0.data.len() == 1 {
            unsafe {
                let n = *self.0.data.get_unchecked(0);
                if n.im == 0 {
                    UT(n.re,self.1)
                } else {
                    panic!("cannot discard imaginary part")
                }
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urf(self: Box<Self>) -> URF {
        if self.0.data.len() == 1 {
            unsafe {
                let n = *self.0.data.get_unchecked(0);
                if n.im == 0 {
                    UT(n.re as RF,self.1)
                } else {
                    panic!("cannot discard imaginary part")
                }
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urb(self: Box<Self>) -> URB {
        if self.0.data.len() == 1 {
            unsafe {
                let n = *self.0.data.get_unchecked(0);
                if n.im == 0 {
                    UT(BigInt::from(n.re),self.1)
                } else {
                    panic!("cannot discard imaginary part")
                }
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_urim(self: Box<Self>) -> URIM {
        UT(self.0.map(|x| if x.im == 0 {x.re} else {panic!("cannot discard imaginary part")}),self.1)
    }
    fn to_urfm(self: Box<Self>) -> URFM {
        UT(self.0.map(|x| if x.im == 0 {x.re as RF} else {panic!("cannot discard imaginary part")}),self.1)
    }
    fn to_ci(self: Box<Self>) -> CI {
        if self.0.data.len() == 1 {
            if self.1.is_empty() {
                unsafe {
                    *self.0.data.get_unchecked(0)
                }
            } else {
                panic!("cannot discard units")
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cf(self: Box<Self>) -> CF {
        if self.0.data.len() == 1 {
            if self.1.is_empty() {
                unsafe {
                    let n = *self.0.data.get_unchecked(0);
                    Complex::new(n.re as RF, n.im as RF)
                }
            } else {
                panic!("cannot discard units")
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cb(self: Box<Self>) -> CB {
        if self.0.data.len() == 1 {
            if self.1.is_empty() {
                unsafe {
                    let n = *self.0.data.get_unchecked(0);
                    Complex::new(BigInt::from(n.re), BigInt::from(n.im))
                }
            } else {
                panic!("cannot discard units")
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_cim(self: Box<Self>) -> CIM {
        if self.1.is_empty() {
            self.0
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_cfm(self: Box<Self>) -> CFM {
        if self.1.is_empty() {
            self.0.map(|x| Complex::new(x.re as RF, x.im as RF))
        } else {
            panic!("cannot discard units")
        }
    }
    fn to_uci(self: Box<Self>) -> UCI {
        if self.0.data.len() == 1 {
            unsafe {
                UT(*self.0.data.get_unchecked(0),self.1)
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucf(self: Box<Self>) -> UCF {
        if self.0.data.len() == 1 {
            unsafe {
                let n = *self.0.data.get_unchecked(0);
                UT(Complex::new(n.re as RF, n.im as RF),self.1)
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucb(self: Box<Self>) -> UCB {
        if self.0.data.len() == 1 {
            unsafe {
                let n = *self.0.data.get_unchecked(0);
                UT(Complex::new(BigInt::from(n.re), BigInt::from(n.im)),self.1)
            }
        } else if self.0.data.len() == 0 {
            panic!("cannot convert empty matrix")
        } else {
            panic!("cannot discard data")
        }
    }
    fn to_ucim(self: Box<Self>) -> UCIM {
        *self
    }
    fn to_ucfm(self: Box<Self>) -> UCFM {
        UT(self.0.map(|x| Complex::new(x.re as RF, x.im as RF)),self.1)
    }
    fn box_clone(&self) -> Box<Numeric> {
        Box::new(self.clone())
    }
    fn to_basic_string(&self, env: &Environment) -> String {
        self.0.to_string() + &self.1.to_string(env)
    }
}
