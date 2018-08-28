use ast::{RValue,LValue,Statement};
use na::*;
use nc::{Complex,Complex64};
use ni::{BigInt,ToBigInt};
use num_traits::{ToPrimitive,Zero};
use super::unit::{UV,U};
use super::Null;

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum Precision {
    Int,
    Float,
    Big,
    None,
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub struct ValType {
    pub list: bool,
    pub string: bool,
    pub complex: bool,
    pub matrix: (bool,usize),
    pub precision: Precision,
    pub boolean: bool,
    pub unitless: bool,
    pub null: bool,
}

#[derive(Debug,PartialEq,Copy,Clone)]
pub enum ValEnum {
    L,
    S,
    B,
    Z,
    RI,
    RF,
    RB,
    RM,
    CI,
    CF,
    CB,
    CM,
    N,
    None,
}

impl ValType {
    pub fn add_type(&self, with: ValType) -> ValEnum {
        if self.list || with.list {
            ValEnum::L
        } else if self.string || with.string {
            ValEnum::S
        } else if self.complex || with.complex {
            if self.matrix.0 || with.matrix.0 {
                ValEnum::CM
            } else {
                match (self.precision,with.precision) {
                    (Precision::Float,_) | (_,Precision::Float) => ValEnum::CF,
                    (Precision::Big,_) | (_,Precision::Big) => ValEnum::CB,
                    _ => ValEnum::CI,
                }
            }
        } else if !self.boolean && !with.boolean {
            if self.matrix.0 || with.matrix.0 {
                ValEnum::RM
            } else {
                match (self.precision,with.precision) {
                    (Precision::Float,_) | (_,Precision::Float) => ValEnum::RF,
                    (Precision::Big,_) | (_,Precision::Big) => ValEnum::RB,
                    _ => ValEnum::RI,
                }
            }
        } else {
            ValEnum::RI
        }
    }
    
    pub fn sub_type(&self, with: ValType) -> ValEnum {
        if self.list || with.list {
            panic!("cannot subtract by or from a list");
        } else if self.string || with.string {
            panic!("cannot subtract by or from a string");
        } else if self.complex || with.complex {
            if self.matrix.0 || with.matrix.0 {
                ValEnum::CM
            } else {
                match (self.precision,with.precision) {
                    (Precision::Float,_) | (_,Precision::Float) => ValEnum::CF,
                    (Precision::Big,_) | (_,Precision::Big) => ValEnum::CB,
                    _ => ValEnum::CI,
                }
            }
        } else if !self.boolean && !with.boolean {
            if self.matrix.0 || with.matrix.0 {
                ValEnum::RM
            } else {
                match (self.precision,with.precision) {
                    (Precision::Float,_) | (_,Precision::Float) => ValEnum::RF,
                    (Precision::Big,_) | (_,Precision::Big) => ValEnum::RB,
                    _ => ValEnum::RI,
                }
            }
        } else {
            ValEnum::RI
        }
    }
    pub fn eq_type(&self, with: ValType) -> ValEnum {
        if *self != with {
            ValEnum::None
        } else {
            if self.list {
                ValEnum::L
            } else if self.string {
                ValEnum::S
            } else if self.boolean {
                ValEnum::B
            } else if self.null {
                ValEnum::N
            } else {
                unimplemented!();
            }
        }
    }
}

pub trait Calc {
    fn type_of(&self) -> ValType;

    fn to_ri(&self) -> i64;
    fn to_rf(&self) -> f64;
    fn to_rb(&self) -> BigInt;
    fn to_rm(&self) -> DMatrix<f64>;
    fn to_ci(&self) -> Complex<i64>;
    fn to_cf(&self) -> Complex64;
    fn to_cb(&self) -> Complex<BigInt>;
    fn to_cm(&self) -> DMatrix<Complex64>;

    fn to_uri(&self) -> UV<i64>;
    fn to_urf(&self) -> UV<f64>;
    fn to_urb(&self) -> UV<BigInt>;
    fn to_urm(&self) -> UV<DMatrix<f64>>;
    fn to_uci(&self) -> UV<Complex<i64>>;
    fn to_ucf(&self) -> UV<Complex64>;
    fn to_ucb(&self) -> UV<Complex<BigInt>>;
    fn to_ucm(&self) -> UV<DMatrix<Complex64>>;

    fn to_str(&self) -> String;
    fn to_bool(&self) -> bool;
}

impl Calc for i64 {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (false,0),
            precision: Precision::Int,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        *self
    }
    fn to_rf(&self) -> f64 {
        *self as f64
    }
    fn to_rb(&self) -> BigInt {
        self.to_bigint().unwrap()
    }
    fn to_rm(&self) -> DMatrix<f64> {
        DMatrix::from_element(1,1,*self as f64)
    }
    fn to_ci(&self) -> Complex<i64> {
        Complex::from(self)
    }
    fn to_cf(&self) -> Complex64 {
        Complex::from(*self as f64)
    }
    fn to_cb(&self) -> Complex<BigInt> {
        Complex::from(self.to_bigint().unwrap())
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,Complex::from(*self as f64))
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.clone())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        *self != 0
    }
}

impl Calc for f64 {
    fn type_of(&self) -> ValType {
        ValType{
            list: false,
            string: false,
            complex: false,
            matrix: (false,0),
            precision: Precision::Float,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        *self as i64
    }
    fn to_rf(&self) -> f64 {
        *self
    }
    fn to_rb(&self) -> BigInt {
        (*self as i64).to_bigint().unwrap()
    }
    fn to_rm(&self) -> DMatrix<f64> {
        DMatrix::from_element(1,1,*self)
    }
    fn to_ci(&self) -> Complex<i64> {
        Complex::from(*self as i64)
    }
    fn to_cf(&self) -> Complex64 {
        Complex::from(*self)
    }
    fn to_cb(&self) -> Complex<BigInt> {
        Complex::from((*self as i64).to_bigint().unwrap())
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,Complex::from(*self))
    }
    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }

    fn to_urf(&self) -> UV<f64> {
        UV::from(self.clone())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        *self != 0.
    }
}

impl Calc for BigInt {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (false, 0),
            precision: Precision::Big,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        self.to_i64().unwrap()
    }
    fn to_rf(&self) -> f64 {
        self.to_f64().unwrap()
    }
    fn to_rb(&self) -> BigInt {
        self.clone()
    }
    fn to_rm(&self) -> DMatrix<f64> {
        DMatrix::from_element(1,1,self.to_f64().unwrap())
    }
    fn to_ci(&self) -> Complex<i64> {
        Complex::from(self.to_i64().unwrap())
    }
    fn to_cf(&self) -> Complex64 {
        Complex::from(self.to_f64().unwrap())
    }
    fn to_cb(&self) -> Complex<BigInt> {
        Complex::from(self.clone())
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,Complex::from(self.to_f64().unwrap()))
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.clone())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
         !self.is_zero()
    }
}

impl Calc for DMatrix<f64> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (true,self.len()),
            precision: Precision::Float,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.len() == 1 {
            *self.data.get(0).unwrap() as i64
        } else {
            panic!("cannot convert to ri")
        }
    }
    fn to_rf(&self) -> f64 {
        if self.len() == 1 {
            *self.data.get(0).unwrap()
        } else {
            panic!("cannot convert to rf")
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.len() == 1 {
            self.data.get(0).unwrap().to_bigint().unwrap()
        } else {
            panic!("cannot convert to rb")
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        self.clone()
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.len() == 1 {
            Complex::from(*self.data.get(0).unwrap() as i64)
        } else {
            panic!("cannot convert to ci")
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.len() == 1 {
            Complex::from(self.data.get(0).unwrap())
        } else {
            panic!("cannot convert to cf")
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.len() == 1 {
            Complex::from(self.data.get(0).unwrap().to_bigint().unwrap())
        } else {
            panic!("cannot convert to cb")
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        self.map(|n| Complex::from(n))
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.clone())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
         !self.data.contains(&0.)
    }
}

impl Calc for Complex<i64> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false,0),
            precision: Precision::Int,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.im == 0 {
            self.re
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.im == 0 {
            self.re as f64
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.im == 0 {
            self.re.to_bigint().unwrap()
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.im == 0 {
            DMatrix::from_element(1,1,self.re as f64)
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        *self
    }
    fn to_cf(&self) -> Complex64 {
        Complex::new(self.re as f64, self.im as f64)
    }
    fn to_cb(&self) -> Complex<BigInt> {
        Complex::new(self.re.to_bigint().unwrap(), self.im.to_bigint().unwrap())
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,self.to_cf())
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.clone())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        self.re != 0 || self.im != 0
    }
}

impl Calc for Complex64 {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false,0),
            precision: Precision::Float,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.im == 0. {
            self.re as i64
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.im == 0. {
            self.re
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.im == 0. {
            self.re.to_bigint().unwrap()
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.im == 0. {
            DMatrix::from_element(1,1,self.re)
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        Complex::new(self.re as i64, self.im as i64)
    }
    fn to_cf(&self) -> Complex64 {
        *self
    }
    fn to_cb(&self) -> Complex<BigInt> {
        Complex::new(self.re.to_bigint().unwrap(), self.im.to_bigint().unwrap())
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,*self)
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.clone())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        self.re != 0. || self.im != 0.
    }
}

impl Calc for Complex<BigInt> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false, 0),
            precision: Precision::Big,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.im.is_zero() {
            self.re.to_i64().unwrap()
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.im.is_zero() {
            self.re.to_f64().unwrap()
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.im.is_zero() {
            self.re.clone()
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.im.is_zero() {
            DMatrix::from_element(1,1,self.re.to_f64().unwrap())
        } else {
            panic!("cannot truncate non-zero imaginary component.");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        Complex::new(self.re.to_i64().unwrap(),self.im.to_i64().unwrap())
    }
    fn to_cf(&self) -> Complex64 {
        Complex::new(self.re.to_f64().unwrap(),self.im.to_f64().unwrap())
    }
    fn to_cb(&self) -> Complex<BigInt> {
        self.clone()
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,self.to_cf())
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.clone())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.to_cm())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
         !self.is_zero()
    }
}

impl Calc for DMatrix<Complex64> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (true,self.len()),
            precision: Precision::Float,
            boolean: false,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.len() == 1 {
            let d = self.data.get(0).unwrap();
            if d.im == 0. {
                d.re as i64
            } else {
                panic!("cannot truncate non-zero imaginary component.");
            }
        } else {
            panic!("cannot convert to ri")
        }
    }
    fn to_rf(&self) -> f64 {
        if self.len() == 1 {
            let d = self.data.get(0).unwrap();
            if d.im == 0. {
                d.re
            } else {
                panic!("cannot truncate non-zero imaginary component.");
            }
        } else {
            panic!("cannot convert to rf")
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.len() == 1 {
            let d = self.data.get(0).unwrap();
            if d.im == 0. {
                d.re.to_bigint().unwrap()
            } else {
                panic!("cannot truncate non-zero imaginary component.");
            }
        } else {
            panic!("cannot convert to rb")
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        self.map(|c| {
            if c.im == 0. {
                c.re
            } else {
                panic!("cannot truncate non-zero imaginary component.");
            }
        })
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.len() == 1 {
            self.data.get(0).unwrap().to_ci()
        } else {
            panic!("cannot convert to ci")
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.len() == 1 {
            *self.data.get(0).unwrap()
        } else {
            panic!("cannot convert to cf")
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.len() == 1 {
            self.data.get(0).unwrap().to_cb()
        } else {
            panic!("cannot convert to cb")
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        self.clone()
    }

    fn to_uri(&self) -> UV<i64> {
        UV::from(self.to_ri())
    }
    fn to_urf(&self) -> UV<f64> {
        UV::from(self.to_rf())
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV::from(self.to_rb())
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV::from(self.to_rm())
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV::from(self.to_ci())
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV::from(self.to_cf())
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV::from(self.to_cb())
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV::from(self.clone())
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        !self.data.contains(&Complex64::zero())
    }
}

impl Calc for String {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: true,
            complex: false,
            matrix: (false,0),
            precision: Precision::None,
            boolean: false,
            unitless: true,
            null: false,
        }
    }
    
    fn to_ri(&self) -> i64 {
        self.parse::<i64>().unwrap()
    }
    fn to_rf(&self) -> f64 {
        self.parse::<f64>().unwrap()
    }
    fn to_rb(&self) -> BigInt {
        BigInt::parse_bytes(self.as_bytes(), 10).unwrap()
    }
    fn to_rm(&self) -> DMatrix<f64> {
        panic!("no can do")
    }
    fn to_ci(&self) -> Complex<i64> {
        panic!("not till we got an interpreter")
    }
    fn to_cf(&self) -> Complex64 {
        panic!("not till we got an interpreter")
    }
    fn to_cb(&self) -> Complex<BigInt> {
        panic!("not till we got an interpreter")
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        panic!("not till we got an interpreter")
    }

    fn to_uri(&self) -> UV<i64> {
        panic!("not till we got an interpreter")
    }
    fn to_urf(&self) -> UV<f64> {
        panic!("not till we got an interpreter")
    }
    fn to_urb(&self) -> UV<BigInt> {
        panic!("not till we got an interpreter")
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        panic!("not till we got an interpreter")
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        panic!("not till we got an interpreter")
    }
    fn to_ucf(&self) -> UV<Complex64> {
        panic!("not till we got an interpreter")
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        panic!("not till we got an interpreter")
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        panic!("not till we got an interpreter")
    }

    fn to_str(&self) -> String {
        self.clone()
    }
    fn to_bool(&self) -> bool {
        self.len() != 0
    }
}

impl Calc for bool {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (false,0),
            precision: Precision::None,
            boolean: true,
            unitless: true,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if *self {
            1
        } else {
            0
        }
    }
    fn to_rf(&self) -> f64 {
        if *self {
            1.
        } else {
            0.
        }
    }
    fn to_rb(&self) -> BigInt {
        if *self {
            1.to_bigint().unwrap()
        } else {
            0.to_bigint().unwrap()
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        DMatrix::from_element(1,1,self.to_rf())
    }
    fn to_ci(&self) -> Complex<i64> {
        if *self {
            Complex::from(1)
        } else {
            Complex::zero()
        }
    }
    fn to_cf(&self) -> Complex64 {
        if *self {
            Complex64::from(1.)
        } else {
            Complex64::zero()
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if *self {
            Complex::from(1.to_bigint().unwrap())
        } else {
            Complex::from(0.to_bigint().unwrap())
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        DMatrix::from_element(1,1,self.to_cf())
    }

    fn to_uri(&self) -> UV<i64> {
        panic!("not till we got an interpreter")
    }
    fn to_urf(&self) -> UV<f64> {
        panic!("not till we got an interpreter")
    }
    fn to_urb(&self) -> UV<BigInt> {
        panic!("not till we got an interpreter")
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        panic!("not till we got an interpreter")
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        panic!("not till we got an interpreter")
    }
    fn to_ucf(&self) -> UV<Complex64> {
        panic!("not till we got an interpreter")
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        panic!("not till we got an interpreter")
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        panic!("not till we got an interpreter")
    }

    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        *self
    }
}

impl Calc for UV<i64> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (false,0),
            precision: Precision::Int,
            boolean: false,
            unitless: false,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        self.clone()
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<f64> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (false,0),
            precision: Precision::Float,
            boolean: false,
            unitless: false,
            null: false,
        }

    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        self.clone()
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<BigInt> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (false,0),
            precision: Precision::Big,
            boolean: false,
            unitless: false,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.clone()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        self.clone()
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<DMatrix<f64>> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: false,
            matrix: (true,self.v.len()),
            precision: Precision::Float,
            boolean: false,
            unitless: false,
            null: false,
        }

    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.clone()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        self.clone()
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<Complex<i64>> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false,0),
            precision: Precision::Int,
            boolean: false,
            unitless: false,
            null: false,
        }

    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.clone()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        self.clone()
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<Complex64> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false,0),
            precision: Precision::Float,
            boolean: false,
            unitless: false,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.clone()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        self.clone()
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<Complex<BigInt>> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false,0),
            precision: Precision::Big,
            boolean: false,
            unitless: false,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.clone()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.to_cm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        self.clone()
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        UV {
            v: self.v.to_cm(),
            u: self.u
        }
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for UV<DMatrix<Complex64>> {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (true,self.v.len()),
            precision: Precision::Float,
            boolean: false,
            unitless: false,
            null: false,
        }
    }

    fn to_ri(&self) -> i64 {
        if self.u.is_unitless() {
            self.v.to_ri()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rf(&self) -> f64 {
        if self.u.is_unitless() {
            self.v.to_rf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rb(&self) -> BigInt {
        if self.u.is_unitless() {
            self.v.to_rb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_rm(&self) -> DMatrix<f64> {
        if self.u.is_unitless() {
            self.v.to_rm()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_ci(&self) -> Complex<i64> {
        if self.u.is_unitless() {
            self.v.to_ci()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cf(&self) -> Complex64 {
        if self.u.is_unitless() {
            self.v.to_cf()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cb(&self) -> Complex<BigInt> {
        if self.u.is_unitless() {
            self.v.to_cb()
        } else {
            panic!("cannot implicitly strip units");
        }
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        if self.u.is_unitless() {
            self.v.clone()
        } else {
            panic!("cannot implicitly strip units");
        }
    }

    fn to_uri(&self) -> UV<i64> {
        UV {
            v: self.v.to_ri(),
            u: self.u
        }
    }
    fn to_urf(&self) -> UV<f64> {
        UV {
            v: self.v.to_rf(),
            u: self.u
        }
    }
    fn to_urb(&self) -> UV<BigInt> {
        UV {
            v: self.v.to_rb(),
            u: self.u
        }
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        UV {
            v: self.v.to_rm(),
            u: self.u
        }
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        UV {
            v: self.v.to_ci(),
            u: self.u
        }
    }
    fn to_ucf(&self) -> UV<Complex64> {
        UV {
            v: self.v.to_cf(),
            u: self.u
        }
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        UV {
            v: self.v.to_cb(),
            u: self.u
        }
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        self.clone()
    }
    
    fn to_str(&self) -> String {
        format!("{}{}",self.v.to_string(),self.u.to_str())
    }
    fn to_bool(&self) -> bool {
        if self.u.is_unitless() {
            self.v.to_bool()
        } else {
            panic!("units must be stripped to convert to boolean");
        }
    }
}

impl Calc for Null {
    fn type_of(&self) -> ValType {
        ValType {
            list: false,
            string: false,
            complex: true,
            matrix: (false, 0),
            precision: Precision::None,
            boolean: false,
            unitless: true,
            null: true,
        }

    }

    fn to_ri(&self) -> i64 {
        panic!("operations not allowed on null");
    }
    fn to_rf(&self) -> f64 {
        panic!("operations not allowed on null");
    }
    fn to_rb(&self) -> BigInt {
        panic!("operations not allowed on null");
    }
    fn to_rm(&self) -> DMatrix<f64> {
        panic!("operations not allowed on null");
    }
    fn to_ci(&self) -> Complex<i64> {
        panic!("operations not allowed on null");
    }
    fn to_cf(&self) -> Complex64 {
        panic!("operations not allowed on null");
    }
    fn to_cb(&self) -> Complex<BigInt> {
        panic!("operations not allowed on null");
    }
    fn to_cm(&self) -> DMatrix<Complex64> {
        panic!("operations not allowed on null");
    }

    fn to_uri(&self) -> UV<i64> {
        panic!("operations not allowed on null");
    }
    fn to_urf(&self) -> UV<f64> {
        panic!("operations not allowed on null");
    }
    fn to_urb(&self) -> UV<BigInt> {
        panic!("operations not allowed on null");
    }
    fn to_urm(&self) -> UV<DMatrix<f64>> {
        panic!("operations not allowed on null");
    }
    fn to_uci(&self) -> UV<Complex<i64>> {
        panic!("operations not allowed on null");
    }
    fn to_ucf(&self) -> UV<Complex64> {
        panic!("operations not allowed on null");
    }
    fn to_ucb(&self) -> UV<Complex<BigInt>> {
        panic!("operations not allowed on null");
    }
    fn to_ucm(&self) -> UV<DMatrix<Complex64>> {
        panic!("operations not allowed on null");
    }

    fn to_str(&self) -> String {
        panic!("operations not allowed on null");
    }
    fn to_bool(&self) -> bool {
        panic!("operations not allowed on null");
    }
}
