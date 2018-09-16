use nc::{Complex,Complex64};
use na::DMatrix;
use ast::{Statement,LValue,RValue};
use interpreter::env::Scope;
use std::collections::HashMap;

#[derive(Debug,Clone,PartialEq)]
pub enum V {
    RI(i64,U),
    RF(f64,U),
    RM(DMatrix<f64>,U),
    CI(Complex<i64>,U),
    CF(Complex64,U),
    CM(DMatrix<Complex64>,U),
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
pub struct TypeFraction {
    components: HashMap<u64,f64>,
}

impl TypeFraction {
    fn add(self, with: TypeFraction) -> Self {
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
    fn multiply(mut self, with: TypeFraction) -> Self {
        for (u,e1) in with.components {
            let e2 = self.components.entry(u).or_insert(0.);
            *e2 += e1;
        }
        self.components.retain(|_,e| *e != 0.);
        self
    }
    fn divide(mut self, with: TypeFraction) -> Self {
        for (u,e1) in with.components {
            let e2 = self.components.entry(u).or_insert(0.);
            *e2 -= e1;
        }
        self.components.retain(|_,e| *e != 0.);
        self
    }
    fn invert(mut self) -> Self {
        for e in self.components.values_mut() {
            *e = -*e;
        }
        self
    }
    pub fn equal(&self, with: &TypeFraction) -> bool {
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
    pub fn from_base(b: u64) -> TypeFraction {
        let mut h = HashMap::new();
        h.insert(b,1.);
        TypeFraction {
            components: h,
        }
    }
}

pub type U = TypeFraction;
pub type Q = TypeFraction;

impl U {
    pub fn is_empty(&self) -> bool {
        self.components.len() == 0
    }
    pub fn empty() -> U {
        U { components: HashMap::new() }
    }
    pub fn to_str(&self) -> String {
        if self.is_empty() {
            String::from("")
        } else {
            unimplemented!()
        }
    }
}

#[derive(Debug,PartialEq,Clone)]
pub struct Converter {
    unit: U,
    mult: f64,
    add: f64,
}

pub type C = Converter;

impl C {
    pub fn base_unit_converter(unit: U) -> C {
        C {
            unit,
            mult: 1.,
            add: 1.,
        }
    }
    pub fn convert(self, v: V) -> V {
        let old_unit = v.get_unit();
        v.add(V::RF(self.add,old_unit)).times(V::RF(self.mult,self.unit))
    }
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
