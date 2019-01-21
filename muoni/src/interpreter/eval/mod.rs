use super::value::*;
use ast::{RValue,BOP,UOP,Break};
use interpreter::exec::unwrap_break;
use interpreter::env::Environment;
use interpreter::exec::{lvalue,exec_scope,exec_statement};
use na::DMatrix;
use self::RValue::*;
use nc::{Complex,Complex64};
use interpreter::value::numeric::*;

mod matrix;

pub fn eval(rv: &RValue, env: &mut Environment) -> (Option<V>,Option<Vec<Break>>) {
    match rv {
        Integer(n) => {
            (Some(V::RI(*n)),None)
        }
        ImagInteger(n) => {
            (Some(V::CI(Complex::<i64>::new(0,*n))),None)
        }
        Float(n) => {
            (Some(V::RF(*n)),None)
        }
        ImagFloat(n) => {
            (Some(V::CF(Complex64::new(0.,*n))),None)
        }
        StringLiteral(s) => {
            (Some(V::S(s.clone())),None)
        }
        Bool(b) => {
            (Some(V::B(*b)),None)
        }
        Name(n) => {
            (Some(env.get_varl(n)),None)
        }
        Unary(uop, e1) => {
            let v1 = unwrap_break(eval(e1,env));
            (Some(eval_uop(*uop,v1)),None)
        }
        Binary(BOP::Range, e1, ee) => {
            let mut ve = unwrap_break(eval(ee,env)).to_numeric();
            match **e1 {
                Binary(BOP::Range, ref es, ref eb) => {
                    let vs = unwrap_break(eval(&es,env)).to_numeric();
                    let vb = unwrap_break(eval(&eb,env)).to_numeric();
                    (Some(V::R(R::new(vs,vb,ve))),None)
                }
                _ => {
                    let vs = unwrap_break(eval(e1,env)).to_numeric();
                    (Some(V::R(R::new(vs,V::RI(1),ve))),None)
                }
            }
        }
        Binary(bop, e1, e2) => {
            let v1 = unwrap_break(eval(e1,env));
            let v2 = unwrap_break(eval(e2,env));
            (Some(eval_bop(*bop,v1,v2)),None)
        }
        Call(e1, e2) => {
            let v1 = unwrap_break(eval(e1,env));
            let args = eval_arglist(e2,env);
            match v1 {
                V::F(f) => {
                    env.push_premade_scope(f.scope.clone());
                    if f.args.len() != args.len() {
                        panic!("arglist sizes do not match");
                    }
                    for (l,r) in f.args.iter().zip(args.into_iter()) {
                        lvalue::declare_assign_param(l,r,env);
                    }
                    let mut r = eval(&f.body, env);
                    env.pop_scope();
                    match r.1 {
                        None => {
                            return (r.0,None);
                        }
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        panic!("functions do not have authority to break underlying scopes.");
                                    }
                                    return (r.0,None);
                                }
                                Some(Break::Dash) => {
                                    panic!("functions do not have authority to break underlying scopes.");
                                }
                                Some(Break::Tilde) => {
                                    panic!("functions do not have authority to break underlying scopes.");
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
                V::N(n) => {
                    match n.type_of() {
                        NT::RIM => {
                            unimplemented!()
                        }
                        _ => unimplemented!(),
                    }
                }
                // V::RM(m1,u1) => {
                //     match args.len() {
                //         1 => {
                //             match args.first().unwrap() {
                //                 V::RI(ri,u2) => {
                //                     if u2.is_empty() {
                //                         return (Some(V::RF(*m1.data.get(*ri as usize).unwrap(),u1)),None);
                //                     } else {
                //                         panic!("can only index matrices and lists with unitless numbers");
                //                     }
                //                 }
                //                 V::RM(m2,u2) => {
                //                     if m1.shape() == m2.shape() {
                //                         if u2.is_empty() {
                //                             let mut v = Vec::new();
                //                             for (i,j) in m2.iter().enumerate() {
                //                                 if *j != 0. {
                //                                     v.push(*m1.data.get(i).unwrap());
                //                                 }
                //                             }
                //                             return (Some(V::RM(DMatrix::from_column_slice(v.len(),1,&v),u1)),None);
                //                         } else {
                //                             panic!("can only index matrices and lists with unitless numbers");
                //                         }
                //                     } else {
                //                         panic!("cannot access using matrix of another size");
                //                     }
                //                 }
                //                 _ => unimplemented!(),
                //             }
                //         }
                //         2 => {
                //             match (args.first().unwrap(),args.get(1).unwrap()) {
                //                 (i1,i2) => {
                //                     match i1 {
                //                         _ => unimplemented!(),
                //                     }
                //                 }
                //             }
                //         }
                //         _ => panic!("i can't handle this pls no"),
                //     }
                // }
                _ => unimplemented!(),
            }
        }
        Access(_,_) => unimplemented!(),
        List(v) => {
            return (Some(V::L(v.iter().map(|x| unwrap_break(eval(&x,env))).collect())),None);
        }
        Matrix(v) => {
            return matrix::eval(v,env);
        }
        ArgList(_) => {
            panic!("should not be attempting to eval this directly");
        }
        Unit(u) => {
            return (Some(eval_unit(u,env)),None);
        }
        UnitTag(e1,u) => {
            let u = eval_unit(u,env);
            let v1 = unwrap_break(eval(e1,env));
            return (Some(v1.times(u)),None);
        }
        Scope(s) => {
            env.push_scope(true);
            let breaks = exec_scope(s,env);
            let result = env.pop_reduce_scope();
            return (result,breaks);
        }
        Function(name, args, caps, body) => {
            let scope = env.get_premade_implicit(caps);
            let f = F {
                args: args.clone(),
                scope,
                body: body.clone(),
            };
            return (Some(V::F(Box::new(f))),None);
        }
        _ => {
            println!("{:?}",rv);
            unimplemented!();
        }
    }
}

pub fn eval_arglist(rv: &RValue, env: &mut Environment) -> Vec<V> {
    use self::RValue::*;
    match rv {
        ArgList(v) => {
            return v.iter().map(|x| unwrap_break(eval(&x,env))).collect();
        }
        _ => panic!("expected argument list for function call"),
    }
}

pub fn eval_uop(uop: UOP, v1: V) -> V {
    unimplemented!();
}

pub fn eval_bop(bop: BOP, v1: V, v2: V) -> V {
    match bop {
        BOP::Plus => v1.add(v2),
        BOP::Minus => v1.sub(v2),
        BOP::Times => v1.times(v2),
        BOP::Divide => v1.divide(v2),
        BOP::Is => v1.is(v2),
        BOP::Less => v1.less(v2),
        _ => unimplemented!(),
    }
}

pub fn eval_unit(u: &RValue, env: &mut Environment) -> V {
    match u {
        Name(n) => {
            let c = env.get_unit(n);
            V::URF(c.mult,c.dim)
        }
        StringLiteral(_) | Bool(_) => {
            panic!("invalid unit stuffs")
        }
        Integer(n) => {
            if *n == 1 {
                V::RI(1)
            } else {
                panic!("1 is the only number allowed in unit blocks, except in exponents")
            }
        }
        Float(n) => {
            if *n == 1. {
                V::RF(1.)
            } else {
                panic!("1 is the only number allowed in unit blocks, except in exponents")
            }
        }
        Unary(..) => {
            panic!("*, /, and ^ are the only operators allowed in units")
        }
        Binary(bop, e1, e2) => {
            match bop {
                BOP::Times => {
                    let v1 = eval_unit(e1,env);
                    let v2 = eval_unit(e2,env);
                    v1.times(v2)
                }
                BOP::Divide => {
                    let v1 = eval_unit(e1,env);
                    let v2 = eval_unit(e2,env);
                    v1.divide(v2)
                }
                BOP::Power => {
                    let v1 = eval_unit(e1,env);
                    let v2 = unwrap_break(eval(e2,env)).to_numeric();
                    match v2 {
                        _ => unimplemented!(),
                    }
                }
                _ => unimplemented!(),
            }
        }
        _ => unimplemented!(),
    }
}

pub fn eval_converter(rv: &RValue, env: &mut Environment) -> C {
    use ast::RValue::*;
    match rv {
        Name(n) => {
            env.get_unit(&n)
        }
        Binary(bop, e1, e2) => {
            match bop {
                BOP::Plus => {
                    let c1 = eval_converter(e1,env);
                    let c2 = eval_converter(e2,env);
                    if c1.dim == c2.dim {
                        C {
                            dim: c1.dim,
                            mult: c1.mult + c2.mult,
                        }
                    } else {
                        panic!("cannot add units of different dimensions. Affine transformations are not allowed")
                    }
                }
                BOP::Minus => {
                    let c1 = eval_converter(e1,env);
                    let c2 = eval_converter(e2,env);
                    if c1.dim == c2.dim {
                        C {
                            dim: c1.dim,
                            mult: c1.mult - c2.mult,
                        }
                    } else {
                        panic!("cannot subtract units of different dimensions. Affine transformations are not allowed")
                    }
                }
                BOP::Times => {
                    let c1 = eval_converter(e1,env);
                    let c2 = eval_converter(e2,env);
                    C {
                        dim: c1.dim.multiply(c2.dim),
                        mult: c1.mult * c2.mult,
                    }
                }
                BOP::Divide => {
                    let c1 = eval_converter(e1,env);
                    let c2 = eval_converter(e2,env);
                    C {
                        dim: c1.dim.divide(c2.dim),
                        mult: c1.mult / c2.mult,
                    }
                }
                BOP::Power => {
                    let c1 = eval_converter(e1,env);
                    let c2 = eval_converter(e2,env);
                    if !c2.dim.is_empty() {
                        panic!("unit exponents must be dimensionless quantities");
                    }
                    C {
                        dim: c1.dim.raise(c2.mult),
                        mult: c1.mult.powf(c2.mult),
                    }
                }
                _ => panic!("operation is not permitted in unit conversions"),
            }
        }
        Integer(n) => {
            C {
                dim: D::empty(),
                mult: *n as f64,
            }
        }
        Float(n) => {
            C {
                dim: D::empty(),
                mult: *n,
            }
        }
        ImagInteger(_) | Float(_) => unimplemented!(),
        Scope(s) => {
            env.push_scope(true);
            let breaks = exec_scope(s,env);
            let result = env.pop_reduce_scope();
            let m = unwrap_break((result,breaks)).to_rf_unwrap();
            C {
                dim: D::empty(),
                mult: m,
            }
        }
        _ => panic!("invalid operations in unit definition"),
    }
}

fn expand_range(r: R) -> V {
    unimplemented!();
}
