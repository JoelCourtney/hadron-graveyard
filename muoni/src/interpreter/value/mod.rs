use nc::{Complex,Complex64};
use na::DMatrix;
use ast::{Statement,LValue};
use interpreter::env::Scope;

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

#[derive(Debug,PartialEq,Eq,Hash,Copy,Clone)]
pub struct TypeFraction {
    pub n: u64,
    pub d: u64,
}

impl TypeFraction {
    fn reduce(mut self) -> Self {
        use ni::Integer;
        let mut gcd;
        loop {
            gcd = self.n.gcd(&self.d);
            if gcd == 1 {
                break;
            }
            self.n /= gcd;
            self.d /= gcd;
        }
        self
    }
    fn add(self, with: TypeFraction) -> Self {
        if self.n != with.n || self.d != with.d {
            panic!("incompatible units for addition")
        }
        self
    }
    fn multiply(self, with: TypeFraction) -> Self {
        (TypeFraction {
            n: self.n * with.n,
            d: self.d * with.d,
        }).reduce()
    }
    fn divide(self, with: TypeFraction) -> Self {
        self.multiply(with.invert())
    }
    fn invert(mut self) -> Self {
        let hold = self.d;
        self.d = self.n;
        self.n = hold;
        self
    }
    fn equal(&self, with: &TypeFraction) -> bool {
        self.n == with.n && self.d == with.d
    }
}

pub type U = TypeFraction;
pub type Q = TypeFraction;

impl U {
    pub fn is_empty(&self) -> bool {
        self.n == self.d
    }
    pub fn empty() -> U {
        U { n:1, d:1 }
    }
    pub fn to_str(&self) -> String {
        String::from(format!("[{}/{}]",self.n,self.d))
    }
}

#[derive(Debug,PartialEq,Clone)]
pub struct Converter {
    mult: f64,
    add: f64,
}

pub type C = Converter;

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
    pub body: Box<Statement>,
}

pub type F = Function;
