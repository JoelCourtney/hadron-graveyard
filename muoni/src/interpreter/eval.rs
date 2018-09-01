use super::value::*;
use ast::{RValue,BOP,Break};
use interpreter::exec::unwrap_break;

pub fn eval(rv: &RValue) -> (Option<V>,Option<Vec<Break>>) {
    use self::RValue::*;
    match rv {
        Number(n) => {
            (Some(V::RF(*n,U::empty())),None)
        }
        StringLiteral(s) => {
            (Some(V::S(s.clone())),None)
        }
        Bool(b) => {
            (Some(V::B(*b)),None)
        }
        Binary(BOP::Range, e1, e2) => {
            let mut v1 = unwrap_break(eval(e1)).to_numeric();
            match **e2 {
                Binary(BOP::Range, ref e3, ref e4) => {
                    let v3 = unwrap_break(eval(&e3)).to_numeric();
                    let v4 = unwrap_break(eval(&e4)).to_numeric();
                    (Some(V::R(Box::new(v1),Box::new(v3),Box::new(v4))),None)
                }
                _ => {
                    let v2 = unwrap_break(eval(&e2)).to_numeric();
                    (Some(V::R(Box::new(v1),Box::new(V::N),Box::new(v2))),None)
                }
            }
        }
        Binary(bop, e1, e2) => {
            let v1 = unwrap_break(eval(e1));
            let v2 = unwrap_break(eval(e2));
            (Some(eval_bop(*bop,v1,v2)),None)
        }
        _ => unimplemented!(),
    }
}

pub fn eval_bop(bop: BOP, v1: V, v2: V) -> V {
    match bop {
        BOP::Plus => v1.add(v2),
        BOP::Minus => v1.sub(v2),
        _ => unimplemented!(),
    }
}
