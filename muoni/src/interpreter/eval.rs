use super::value::*;
use ast::{RValue,BOP,UOP,Break};
use interpreter::exec::unwrap_break;
use interpreter::env::Environment;
use interpreter::exec::{lvalue,exec_scope,exec_statement};
use na::DMatrix;

pub fn eval(rv: &RValue, env: &mut Environment) -> (Option<V>,Option<Vec<Break>>) {
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
        Unary(uop, e1) => {
            let v1 = unwrap_break(eval(e1,env));
            (Some(eval_uop(*uop,v1)),None)
        }
        Binary(BOP::Range, e1, e2) => {
            let mut v1 = unwrap_break(eval(e1,env)).to_numeric();
            match **e2 {
                Binary(BOP::Range, ref e3, ref e4) => {
                    let v3 = unwrap_break(eval(&e3,env)).to_numeric();
                    let v4 = unwrap_break(eval(&e4,env)).to_numeric();
                    (Some(V::R(Box::new(v1),Box::new(v3),Box::new(v4))),None)
                }
                _ => {
                    let v2 = unwrap_break(eval(e2,env)).to_numeric();
                    (Some(V::R(Box::new(v1),Box::new(V::N),Box::new(v2))),None)
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
                    let mut r = exec_statement(&f.body, env);
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
                    env.pop_scope();
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
                                u = Some(u2);
                            } else if u.unwrap() != u2 {
                                panic!("units of elements do not match");
                            }
                        }
                        V::CI(_,u2) | V::CF(_,u2) | V::CM(_,u2) => {
                            complex = true;
                            if u == None {
                                u = Some(u2);
                            } else if u.unwrap() != u2 {
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
                return (Some(V::RM(DMatrix::from_column_slice(height,width,&data),*u.unwrap())),None);
            } else {
                unimplemented!();
            }
        }
        _ => unimplemented!(),
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
        _ => unimplemented!(),
    }
}

fn expand_range(s: V, b: V, e: V) -> V {
    unimplemented!();
}
