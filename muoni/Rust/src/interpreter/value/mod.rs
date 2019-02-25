mod convert;
mod calc;
mod types;
pub mod numeric;

use nc::{Complex,Complex64};
use na::DMatrix;
use ast::{Statement,LValue,RValue};
use interpreter::env::Scope;
use std::collections::HashMap;
use std::iter::Iterator;
use interpreter::env::Environment;
use self::numeric::*;

#[derive(Clone)]
pub enum V {
    N(Box<Numeric>),
    R(R),
    S(String),
    B(bool),
    L(Vec<V>),
    F(Box<F>),
    Null,
}

impl V {
    pub fn RI(ri: RI) -> V {
        V::N(Box::new(ri))
    }
    pub fn RF(rf: RF) -> V {
        V::N(Box::new(rf))
    }
    pub fn RB(rb: RB) -> V {
        V::N(Box::new(rb))
    }
    pub fn RIM(rim: RIM) -> V {
        V::N(Box::new(rim))
    }
    pub fn RFM(rfm: RFM) -> V {
        V::N(Box::new(rfm))
    }
    pub fn URI(ri: RI, u: D) -> V {
        V::N(Box::new(UT::new(ri,u)))
    }
    pub fn URF(rf: RF, u: D) -> V {
        V::N(Box::new(UT::new(rf,u)))
    }
    pub fn URB(rb: RB, u: D) -> V {
        V::N(Box::new(UT::new(rb,u)))
    }
    pub fn URIM(rim: RIM, u: D) -> V {
        V::N(Box::new(UT::new(rim,u)))
    }
    pub fn URFM(rfm: RFM, u: D) -> V {
        V::N(Box::new(UT::new(rfm,u)))
    }
    pub fn CI(ci: CI) -> V {
        V::N(Box::new(ci))
    }
    pub fn CF(cf: CF) -> V {
        V::N(Box::new(cf))
    }
    pub fn CB(cb: CB) -> V {
        V::N(Box::new(cb))
    }
    pub fn CIM(cim: CIM) -> V {
        V::N(Box::new(cim))
    }
    pub fn CFM(cfm: CFM) -> V {
        V::N(Box::new(cfm))
    }
    pub fn UCI(ci: CI, u: D) -> V {
        V::N(Box::new(UT::new(ci,u)))
    }
    pub fn UCF(cf: CF, u: D) -> V {
        V::N(Box::new(UT::new(cf,u)))
    }
    pub fn UCB(cb: CB, u: D) -> V {
        V::N(Box::new(UT::new(cb,u)))
    }
    pub fn UCIM(cim: CIM, u: D) -> V {
        V::N(Box::new(UT::new(cim,u)))
    }
    pub fn UCFM(cfm: CFM, u: D) -> V {
        V::N(Box::new(UT::new(cfm,u)))
    }
}

impl V {
    pub fn is_null(&self) -> bool {
        match self {
            V::Null => true,
            _ => false,
        }
    }
}

#[derive(Debug,PartialEq,Clone)]
pub struct Dimension {
    components: HashMap<u64,f64>,
}

lazy_static! {
    static ref EMPTY: Dimension = D::empty();
}

impl Dimension {
    pub fn add(self, with: Dimension) -> Self {
        for (u,e1) in self.components {
            if let Some(e2) = with.components.get(&u) {
                if *e2 != e1 {
                    panic!("cannot add different units")
                }
            } else {
                panic!("cannot add different units")
            }
        }
        with
    }
    pub fn multiply(mut self, with: Dimension) -> Self {
        for (u,e1) in with.components {
            let e2 = self.components.entry(u).or_insert(0.);
            *e2 += e1;
        }
        self.components.retain(|_,e| *e != 0.);
        self
    }
    pub fn divide(mut self, with: Dimension) -> Self {
        for (u,e1) in with.components {
            let e2 = self.components.entry(u).or_insert(0.);
            *e2 -= e1;
        }
        self.components.retain(|_,e| *e != 0.);
        self
    }
    pub fn raise(mut self, by: f64) -> Self {
        for e in self.components.values_mut() {
            *e *= by;
        }
        self
    }
    pub fn invert(mut self) -> Self {
        for e in self.components.values_mut() {
            *e = -*e;
        }
        self
    }
    pub fn equal(&self, with: &Dimension) -> bool {
        for (u,e1) in self.components.iter() {
            if let Some(e2) = with.components.get(&u) {
                if *e2 != *e1 {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
    pub fn from_base(b: u64) -> Dimension {
        let mut h = HashMap::new();
        h.insert(b,1.);
        Dimension {
            components: h,
        }
    }
    pub fn is_empty(&self) -> bool {
        self.components.len() == 0
    }
    pub fn empty() -> D {
        D { components: HashMap::new() }
    }
    pub fn to_string(&self, env: &Environment) -> String {
        if self.is_empty() {
            String::from("")
        } else {
            let mut s = String::from("[ ");
            let mut num = Vec::new();
            let mut den = Vec::new();
            for (u,e) in &self.components {
                if *e > 0. {
                    num.push((*u,*e));
                } else {
                    den.push((*u,*e));
                }
            }
            if num.len() > 0 {
                for (u,e) in num {
                    s.push_str(&env.get_unit_name(u));
                    if e > 1. {
                        s.push_str("^");
                        s.push_str(&e.to_string());
                    }
                    s.push_str(" ");
                }
            } else {
                s.push_str(" 1 ");
            }
            if den.len() > 0 {
                if den.len() > 1 {
                    s.push_str("/ ( ");
                    for (u,e) in den {
                        s.push_str(&env.get_unit_name(u));
                        if e < -1. {
                            s.push_str("^");
                            s.push_str(&(-e).to_string());
                        }
                        s.push_str(" ");
                    }
                    s.push_str(")");
                } else {
                    for (u,e) in den {
                        s.push_str("/ ");
                        s.push_str(&env.get_unit_name(u));
                        if e < -1. {
                            s.push_str("^");
                            s.push_str(&(-e).to_string());
                        }
                        s.push_str(" ");
                    }
                }
            }
            s.push_str("]");
            s
        }
    }
}

pub type D = Dimension;

#[derive(Debug,PartialEq,Clone)]
pub struct Converter {
    pub dim: D,
    pub mult: f64,
}

pub type C = Converter;

impl C {
    pub fn base_unit_converter(dim: D) -> C {
        C {
            dim,
            mult: 1.,
        }
    }
}

pub enum VI {
    RI(RI,bool),
    RF(RF,bool),
    RB(RB,bool),
    RIM(Box<Iterator<Item=RI>>),
    RFM(Box<Iterator<Item=RF>>),
    URI(URI,bool),
    URF(URF,bool),
    URB(URB,bool),
    URIM(Box<Iterator<Item=RI>>,D),
    URFM(Box<Iterator<Item=RF>>,D),
    CI(CI,bool),
    CF(CF,bool),
    CB(CB,bool),
    CIM(Box<Iterator<Item=CI>>),
    CFM(Box<Iterator<Item=CF>>),
    UCI(UCI,bool),
    UCF(UCF,bool),
    UCB(UCB,bool),
    UCIM(Box<Iterator<Item=CI>>,D),
    UCFM(Box<Iterator<Item=CF>>,D),
    L(Vec<V>,bool),
    S(String,bool),
    B(bool,bool),
    F(Box<F>,bool),
    R(R)
}

#[derive(Clone)]
pub struct Function {
    //pub name: String,
    pub args: Vec<LValue>,
    pub scope: Scope,
    pub body: Box<RValue>,
}

pub type F = Function;

#[derive(Clone)]
pub struct R {
    pub s: Box<Numeric>,
    pub b: Box<Numeric>,
    pub e: Box<Numeric>,
}

impl R {
    pub fn new(s: V, b: V, e: V) -> R {
        match (s,b,e) {
            (V::N(n1), V::N(n2), V::N(n3)) => {
                let t = n1.type_of() | n2.type_of() | n3.type_of();
                if (t & OCTONION) != 0 {
                    panic!("Ranges only use real scalars");
                }
                if (t & MATRIX) != 0 {
                    panic!("ranges only use real scalars");
                }
                if (t & DIMENSIONAL) != 0 {
                    let u1 = n1.get_unit();
                    let u2 = n2.get_unit();
                    let u3 = n3.get_unit();
                    if !(u1.equal(&u2) && u2.equal(&u3)) {
                        panic!("units in range must match");
                    }
                }
                R {
                    s: n1,
                    b: n2,
                    e: n3
                }
            }
            _ => unimplemented!(),
        }
    }
}

impl Iterator for R {
    type Item = V;

    fn next(&mut self) -> Option<V> {
        unimplemented!()
    }
}
