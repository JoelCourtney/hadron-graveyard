use nc::{Complex,Complex64};
use na::DMatrix;
use ast::{Statement,LValue,RValue};
use interpreter::env::Scope;
use std::collections::HashMap;
use interpreter::env::Environment;

#[derive(Debug,Clone,PartialEq)]
pub enum V {
    RI(i64,D),
    RF(f64,D),
    RM(DMatrix<f64>,D),
    CI(Complex<i64>,D),
    CF(Complex64,D),
    CM(DMatrix<Complex64>,D),
    R(Box<V>,Box<V>,Box<V>),
    S(String),
    B(bool),
    L(Vec<V>),
    F(Box<F>),
    N,
}

mod convert;
mod calc;
mod types;

#[derive(Debug,PartialEq,Clone)]
pub struct Dimension {
    components: HashMap<u64,f64>,
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
    pub fn to_str(&self, env: &Environment) -> String {
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
    // pub fn convert(self, v: V) -> V {
    //     let old_unit = v.get_unit();
    //     v.add(V::RF(self.add,old_unit)).times(V::RF(self.mult,self.unit))
    // }
}

pub struct ValueIterator {
    v: V,
    i: usize,
    c: V,
}
pub type VI = ValueIterator;

#[derive(Debug,PartialEq,Clone)]
pub struct Function {
    //pub name: String,
    pub args: Vec<LValue>,
    pub scope: Scope,
    pub body: Box<RValue>,
}

pub type F = Function;
