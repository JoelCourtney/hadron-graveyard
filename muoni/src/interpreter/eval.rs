use super::value::*;
use super::super::ast::{RValue,BOP};

pub fn eval(rv: &RValue) -> V {
    use self::RValue::*;
    match rv {
        Number(_) | StringLiteral(_) | Bool(_) => V::from(&rv),
        Binary(bop, r1, r2) => {
            let e1 = eval(r1);
            let e2 = eval(r2);
            match bop {
                BOP::Plus => e1 + e2,
                BOP::Minus => e1 - e2,
                _ => unimplemented!(),
            }
        }
        _ => unimplemented!(),
    }
}
