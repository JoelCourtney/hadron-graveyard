use ast::{RValue,LValue,Statement};
use na::*;
use nc::{Complex,Complex64};
use ni::{BigInt,ToBigInt};
use num_traits::{ToPrimitive,Zero};

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
}

impl ValType {
    pub fn add_priority(&self, o: ValType) {
        unimplemented!();
    }
}

pub trait Calc {
    fn type_of(&self) -> ValType;

    fn add_mat_real(&self, f64) -> DMatrix<f64>;
    fn add_mat_comp(&self, Complex64) -> DMatrix<Complex64>;

    fn to_ri(&self) -> i64;
    fn to_rf(&self) -> f64;
    fn to_rb(&self) -> BigInt;
    fn to_rm(&self) -> DMatrix<f64>;
    fn to_ci(&self) -> Complex<i64>;
    fn to_cf(&self) -> Complex64;
    fn to_cb(&self) -> Complex<BigInt>;
    fn to_cm(&self) -> DMatrix<Complex64>;
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("unable to do matrix add on ri");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("unable to do matrix add on ri");
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("unable to do matrix add on rf");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("unable to do matrix add on rf");
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("unable to do matrix add on rb");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("unable to do matrix add on rb");
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        self.add_scalar(o)
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        self.to_cm().add_scalar(o)
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("unable to do matrix add on ci");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("unable to do matrix add on ci");
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("unable to do matrix add on cf");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("unable to do matrix add on cf");
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("unable to do matrix add on cb");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("unable to do matrix add on cb");
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        self.to_rm().add_scalar(o)
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        self.add_scalar(o)
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
        }
    }
    
    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("realy");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("nah man")
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
        }
    }

    fn add_mat_real(&self, o: f64) -> DMatrix<f64> {
        panic!("nop");
    }
    fn add_mat_comp(&self, o: Complex64) -> DMatrix<Complex64> {
        panic!("howd you even manage to call this")
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
    fn to_str(&self) -> String {
        self.to_string()
    }
    fn to_bool(&self) -> bool {
        *self
    }
}
