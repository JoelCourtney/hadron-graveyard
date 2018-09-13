use super::value::*;
use ast::{RValue,BOP,UOP,Break};
use interpreter::exec::unwrap_break;
use interpreter::env::Environment;
use interpreter::exec::{lvalue,exec_scope,exec_statement};
use na::DMatrix;
use self::RValue::*;
use nc::{Complex,Complex64};

pub fn eval(rv: &RValue, env: &mut Environment) -> (Option<V>,Option<Vec<Break>>) {
    match rv {
        Integer(n) => {
            (Some(V::RI(*n,U::empty())),None)
        }
        ImagInteger(n) => {
            (Some(V::CI(Complex::<i64>::new(0,*n),U::empty())),None)
        }
        Float(n) => {
            (Some(V::RF(*n,U::empty())),None)
        }
        ImagFloat(n) => {
            (Some(V::CF(Complex64::new(0.,*n),U::empty())),None)
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
                    (Some(V::R(Box::new(vs),Box::new(vb),Box::new(ve))),None)
                }
                _ => {
                    let vs = unwrap_break(eval(e1,env)).to_numeric();
                    (Some(V::R(Box::new(vs),Box::new(V::RI(1,U::empty())),Box::new(ve))),None)
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
            match v1 {
                V::F(f) => {
                    env.push_premade_scope(f.scope.clone());
                    let args = eval_arglist(e2,env);
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
                V::RM(m1,u1) => {
                    let args = eval_arglist(e2,env);
                    match args.len() {
                        1 => {
                            match args.first().unwrap() {
                                V::RI(ri,u2) => {
                                    if u2.is_empty() {
                                        return (Some(V::RF(*m1.data.get(*ri as usize).unwrap(),u1)),None);
                                    } else {
                                        panic!("can only index matrices and lists with unitless numbers");
                                    }
                                }
                                V::RM(m2,u2) => {
                                    if m1.shape() == m2.shape() {
                                        if u2.is_empty() {
                                            let mut v = Vec::new();
                                            for (i,j) in m2.iter().enumerate() {
                                                if *j != 0. {
                                                    v.push(*m1.data.get(i).unwrap());
                                                }
                                            }
                                            return (Some(V::RM(DMatrix::from_column_slice(v.len(),1,&v),u1)),None);
                                        } else {
                                            panic!("can only index matrices and lists with unitless numbers");
                                        }
                                    } else {
                                        panic!("cannot access using matrix of another size");
                                    }
                                }
                                _ => unimplemented!(),
                            }
                        }
                        2 => {
                            match (args.first().unwrap(),args.get(1).unwrap()) {
                                (i1,i2) => {
                                    match i1 {
                                        _ => unimplemented!(),
                                    }
                                }
                            }
                        }
                        _ => panic!("i can't handle this pls no"),
                    }
                }
                _ => unimplemented!(),
            }
        }
        Access(_,_) => unimplemented!(),
        List(v) => {
            return (Some(V::L(v.iter().map(|x| unwrap_break(eval(&x,env))).collect())),None);
        }
        Matrix(v) => {
            let mut m = Vec::new();
            for row in v {
                let mut r = Vec::new();
                for elem in row {
                    let mut hold = unwrap_break(eval(elem,env));
                    if let V::R(s,b,e) = hold {
                        hold = expand_range(*s,*b,*e);
                    }
                    r.push(hold);
                }
                m.push(r);
            }
            let mut u = None;
            let mut complex = false;
            for row in &m {
                for elem in row {
                    match elem {
                        V::RI(_,u2) | V::RF(_,u2) | V::RM(_,u2) => {
                            if u == None {
                                u = Some(u2.clone());
                            } else if !u.as_ref().unwrap().equal(u2) {
                                panic!("units of elements do not match");
                            }
                        }
                        V::CI(_,u2) | V::CF(_,u2) | V::CM(_,u2) => {
                            complex = true;
                            if u == None {
                                u = Some(u2.clone());
                            } else if !u.as_ref().unwrap().equal(u2) {
                                panic!("units of elements do not match");
                            }
                        }
                        V::R(..) => panic!("something has gone horribly wrong"),
                        V::S(_) => panic!("cannot insert string to matrix"),
                        V::B(_) => panic!("cannot insert bool to matrix"),
                        V::L(_) => unimplemented!(),
                        V::F(_) => panic!("cannot insert function into matrix"),
                        V::N => panic!("cannot insert null into matrix"),
                    }
                }
            }
            let mut height = 0;
            let mut width = 0;
            if !complex {
                let mut col_major = Vec::new();
                for row in &m {
                    let mut row_height = 0;
                    let mut cols = Vec::new();
                    for elem in row {
                        match elem {
                            V::RI(ri,_) => {
                                if row_height == 0 {
                                    row_height = 1;
                                } else if row_height != 1 {
                                    panic!("row heights do not match");
                                }
                                cols.push(vec![*ri as f64]);
                            }
                            V::RF(rf,_) => {
                                if row_height == 0 {
                                    row_height = 1;
                                } else if row_height != 1 {
                                    panic!("row heights do not match");
                                }
                                cols.push(vec![*rf]);
                            }
                            V::RM(rm,_) => {
                                if row_height == 0 {
                                    row_height = rm.nrows();
                                } else if row_height != rm.nrows() {
                                    panic!("row heights do not match");
                                }
                                for c in 0..rm.ncols() {
                                    cols.push(rm.column(c).iter().map(|x|*x).collect());
                                }
                            }
                            _ => panic!("should not be seeing these here"),
                        }
                    }
                    height += row_height;
                    if width == 0 {
                        width = cols.len();
                    } else if width != cols.len() {
                        panic!("row lengths do not match");
                    }
                    if col_major.len() == 0 {
                        col_major = cols;
                    } else {
                        for (i,c) in cols.into_iter().enumerate() {
                            col_major.get_mut(i).unwrap().extend(c);
                        }
                    }
                }
                let data = col_major.into_iter().flat_map(|x| x).collect::<Vec<f64>>();
                return (Some(V::RM(DMatrix::from_column_slice(height,width,&data),u.unwrap())),None);
            } else {
                let mut col_major = Vec::new();
                for row in &m {
                    let mut row_height = 0;
                    let mut cols = Vec::new();
                    for elem in row {
                        match elem {
                            V::RI(ri,_) => {
                                if row_height == 0 {
                                    row_height = 1;
                                } else if row_height != 1 {
                                    panic!("row heights do not match");
                                }
                                cols.push(vec![Complex64::from(*ri as f64)]);
                            }
                            V::RF(rf,_) => {
                                if row_height == 0 {
                                    row_height = 1;
                                } else if row_height != 1 {
                                    panic!("row heights do not match");
                                }
                                cols.push(vec![Complex64::from(rf)]);
                            }
                            V::RM(rm,_) => {
                                if row_height == 0 {
                                    row_height = rm.nrows();
                                } else if row_height != rm.nrows() {
                                    panic!("row heights do not match");
                                }
                                for c in 0..rm.ncols() {
                                    cols.push(rm.column(c).iter().map(|x| Complex64::from(*x)).collect());
                                }
                            }
                            V::CI(ci,_) => {
                                if row_height == 0 {
                                    row_height = 1;
                                } else if row_height != 1 {
                                    panic!("row heights do not match");
                                }
                                cols.push(vec![Complex64::new(ci.re as f64,ci.im as f64)]);
                            }
                            V::CF(cf,_) => {
                                if row_height == 0 {
                                    row_height = 1;
                                } else if row_height != 1 {
                                    panic!("row heights do not match");
                                }
                                cols.push(vec![*cf]);
                            }
                            _ => panic!("should not be seeing these here"),
                        }
                    }
                    height += row_height;
                    if width == 0 {
                        width = cols.len();
                    } else if width != cols.len() {
                        panic!("row lengths do not match");
                    }
                    if col_major.len() == 0 {
                        col_major = cols;
                    } else {
                        for (i,c) in cols.into_iter().enumerate() {
                            col_major.get_mut(i).unwrap().extend(c);
                        }
                    }
                }
                let data = col_major.into_iter().flat_map(|x| x).collect::<Vec<Complex64>>();
                return (Some(V::CM(DMatrix::from_column_slice(height,width,&data),u.unwrap())),None);
            }
        }
        ArgList(_) => {
            panic!("should not be attempting to eval this directly");
        }
        Unit(u) => {
            return (Some(eval_unit(u,env)),None);
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
        BOP::Is => v1.is(v2),
        BOP::Less => v1.less(v2),
        _ => unimplemented!(),
    }
}

pub fn eval_unit(u: &RValue, env: &mut Environment) -> V {
    match u {
        Name(n) => {
            let c = env.get_unit(n);
            c.convert(V::RI(1,U::empty()))
        }
        StringLiteral(_) | Bool(_) => {
            panic!("invalid unit stuffs")
        }
        Integer(n) => {
            if *n == 1 {
                V::RI(1,U::empty())
            } else {
                panic!("1 is the only number allowed in unit blocks, except in exponents")
            }
        }
        Float(n) => {
            if *n == 1. {
                V::RI(1,U::empty())
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

fn expand_range(s: V, b: V, e: V) -> V {
    unimplemented!();
}
