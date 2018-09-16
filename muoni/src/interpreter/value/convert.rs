use interpreter::value::{V,U};
use V::*;
use nc::{Complex,Complex64};
use na::DMatrix;

impl V {
    fn to_ri(self) -> Self {
        match self {
            RI(_,_) => self,
            RF(rf,u) => RI(rf as i64,u),
            RM(rm,u) => {
                if rm.len() == 1 {
                    RI(*rm.data.get(0).unwrap() as i64,u)
                } else {
                    panic!("cannot reduce matrix to single value")
                }
            }
            CI(ci,u) => {
                if ci.im == 0 {
                    RI(ci.re,u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CF(cf,u) => {
                if cf.im == 0. {
                    RI(cf.re as i64,u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CM(cm,u) => {
                if cm.len() == 0 {
                    let cf = *cm.data.get(0).unwrap();
                    if cf.im == 0. {
                        RI(cf.re as i64,u)
                    } else {
                        panic!("cannot strip non-zero imaginary component")
                    }
                } else {
                    panic!("cannot reduce matrix to single value")
                }
            }
            S(s) => {
                let ri = s.parse::<i64>();
                let u = U::empty();
                match ri {
                    Ok(ri) => RI(ri,u),
                    Err(_) => panic!("cannot parse string as int"),
                }
            }
            B(b) => {
                let u = U::empty();
                if b {
                    RI(1,u)
                } else {
                    RI(0,u)
                }
            }
            L(l) => {
                panic!("nah thanks");
            }
            N => panic!("that's a null"),
            F(_) => {
                panic!("cannot convert functions to any other type");
            }
            _ => unimplemented!(),
        }
    }
    fn to_ri_unwrap(self) -> i64 {
        match self.to_ri() {
            RI(i,u) => {
                if u.is_empty() {
                    i
                } else {
                    panic!("cannot unwrap number with units.")
                }
            }
            _ => panic!("conversion to ri failed"),
        }
    }
    fn to_rf(self) -> Self {
        match self {
            RI(ri,u) => RF(ri as f64,u),
            RF(_,_) => self,
            RM(rm,u) => {
                if rm.len() == 1 {
                    RF(*rm.data.get(0).unwrap(),u)
                } else {
                    panic!("cannot reduce matrix to single value")
                }
            }
            CI(ci,u) => {
                if ci.im == 0 {
                    RF(ci.re as f64,u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CF(cf,u) => {
                if cf.im == 0. {
                    RF(cf.re,u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CM(cm,u) => {
                if cm.len() == 0 {
                    let cf = *cm.data.get(0).unwrap();
                    if cf.im == 0. {
                        RF(cf.re,u)
                    } else {
                        panic!("cannot strip non-zero imaginary component")
                    }
                } else {
                    panic!("cannot reduce matrix to single value")
                }
            }
            S(s) => {
                let rf = s.parse::<f64>();
                let u = U::empty();
                match rf {
                    Ok(rf) => RF(rf,u),
                    Err(_) => panic!("cannot parse string as int"),
                }
            }
            B(b) => {
                let u = U::empty();
                if b {
                    RF(1.,u)
                } else {
                    RF(0.,u)
                }
            }
            L(l) => {
                panic!("nah thanks");
            }
            F(_) => {
                panic!("cannot convert functions to any other type");
            }
            _ => unimplemented!(),
        }
    }
    fn to_rm(self) -> Self {
        match self {
            RI(ri,u) => RM(DMatrix::from_element(1,1,ri as f64),u),
            RF(rf,u) => RM(DMatrix::from_element(1,1,rf),u),
            RM(_,_) => {
                self
            }
            CI(ci,u) => {
                if ci.im == 0 {
                    RM(DMatrix::from_element(1,1,ci.re as f64),u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CF(cf,u) => {
                if cf.im == 0. {
                    RM(DMatrix::from_element(1,1,cf.re),u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CM(cm,u) => {
                RM(cm.map(|x: Complex64| if x.im == 0. { x.re } else { panic!("cannot strip non-zero imaginary component") }),u)
            }
            S(s) => {
                panic!("not yet sorry");
            }
            B(b) => {
                let u = U::empty();
                if b {
                    RM(DMatrix::from_element(1,1,1.),u)
                } else {
                    RM(DMatrix::from_element(1,1,0.),u)
                }
            }
            L(l) => {
                panic!("nah thanks");
            }
            F(_) => {
                panic!("cannot convert functions to any other type");
            }
            _ => unimplemented!(),
        }
    }
    fn to_ci(self) -> Self {
        match self {
            RI(ri,u) => CI(Complex::from(ri),u),
            RF(rf,u) => CI(Complex::from(rf as i64),u),
            RM(rm,u) => {
                if rm.len() == 0 {
                    CI(Complex::from(*rm.data.get(0).unwrap() as i64),u)
                } else {
                    panic!("cannot reduce matrix to single value")
                }
            }
            CI(ci,u) => {
                if ci.im == 0 {
                    RM(DMatrix::from_element(1,1,ci.re as f64),u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CF(cf,u) => {
                if cf.im == 0. {
                    RM(DMatrix::from_element(1,1,cf.re),u)
                } else {
                    panic!("cannot strip non-zero imaginary component")
                }
            }
            CM(cm,u) => {
                RM(cm.map(|x: Complex64| if x.im == 0. { x.re } else { panic!("cannot strip non-zero imaginary component") }),u)
            }
            S(s) => {
                panic!("not yet sorry");
            }
            B(b) => {
                let u = U::empty();
                if b {
                    RM(DMatrix::from_element(1,1,1.),u)
                } else {
                    RM(DMatrix::from_element(1,1,0.),u)
                }
            }
            L(l) => {
                panic!("nah thanks");
            }
            F(_) => {
                panic!("cannot convert functions to any other type");
            }
            _ => unimplemented!(),
        }
    }
    pub fn to_bool(self) -> Self {
        match self {
            RI(ri,u) => {
                if u.is_empty() {
                    B(ri != 0)
                } else {
                    panic!("only unitless numbers can be converted to boolean")
                }
            }
            RF(rf,u) => {
                if u.is_empty() {
                    B(rf != 0.)
                } else {
                    panic!("only unitless numbers can be converted to boolean")
                }
            }
            RM(rm,u) => {
                panic!("meh not yet");
            }
            CI(ci,u) => {
                if u.is_empty() {
                    B(ci.re == 0 && ci.im == 0)
                } else {
                    panic!("only unitless numbers can be converted to boolean")
                }
            }
            CF(cf,u) => {
                if u.is_empty() {
                    B(cf.re == 0. && cf.im == 0.)
                } else {
                    panic!("only unitless numbers can be converted to boolean")
                }
            }
            CM(cm,u) => {
                panic!("nope")
            }
            S(s) => {
                B(s.len() > 0)
            }
            B(b) => {
                self
            }
            L(_) => {
                unimplemented!();
            }
            R(_,_,_) => {
                unimplemented!();
            }
            F(_) => {
                panic!("cannot convert functions to any other type");
            }
            N => panic!("cannot convert null to boolean"),
        }
    }
    pub fn to_bool_unwrap(self) -> bool {
        match self.to_bool() {
            B(b) => b,
            _ => panic!("ya dun fuqd up"),
        }
    }
    pub fn to_numeric(self) -> Self {
        self // very much no
    }
    pub fn to_str(self) -> Self {
        match self {
            RI(ri,u) => {
                S(format!("{}{}",ri,u.to_str()))
            }
            RF(rf,u) => {
                S(format!("{}{}",rf,u.to_str()))
            }
            RM(m,u) => {
                S(
                    m.to_string()
                        .replace("┌","╭")
                        .replace("┐","╮")
                        .replace("└","╰")
                        .replace("┘","╯")
                )
                // let mut s = String::from("(");
                // let c = m.ncols();
                // for (i,v) in m.into_iter().enumerate() {
                //     s.push_str(&v.to_string());
                //     if i % c == c-1 {
                //         s.push_str("; ");
                //     } else {
                //         s.push_str(", ");
                //     }
                // }
                // s.pop();
                // s.push_str(")");
                // s.push_str(&format!("{}",u.to_str()));
                // S(s)
            }
            CI(ci,u) => {
                if u.is_empty() {
                    S(format!("{}",ci.to_string()))
                } else {
                    S(format!("({}){}",ci.to_string(),u.to_str()))
                }
            }
            CF(cf,u) => {
                if u.is_empty() {
                    S(format!("{}",cf.to_string()))
                } else {
                    S(format!("({}){}",cf.to_string(),u.to_str()))
                }
            }
            CM(m,u) => {
                let mut s = String::from("(");
                let c = m.ncols();
                for (i,v) in m.into_iter().enumerate() {
                    s.push_str(&v.to_string());
                    if i % c == c-1 {
                        s.push_str("; ");
                    } else {
                        s.push_str(", ");
                    }
                }
                s.pop();
                s.push_str(")");
                s.push_str(&u.to_str());
                S(s)
            }
            S(_) => {
                self
            }
            B(b) => {
                if b {
                    S(String::from("true"))
                } else {
                    S(String::from("false"))
                }
            }
            L(l) => {
                let mut s = String::from("[ ");
                for v in l.into_iter() {
                    s.push_str(&v.to_str_unwrap());
                    s.push_str(", ");
                }
                s.pop(); s.pop();
                s.push_str(" ]");
                S(s)
            }
            _ => unimplemented!(),
        }
    }
    pub fn to_str_unwrap(self) -> String {
        match self.to_str() {
            S(s) => s,
            _ => panic!("ya dun fuqd up"),
        }
    }

    pub fn get_unit(&self) -> U {
        match self {
            RI(_,u) | RF(_,u) | RM(_,u) | CI(_,u) | CF(_,u) | CM(_,u) => {
                return u.clone();
            }
            _ => unimplemented!(),
        }
    }
}
