use interpreter::value::*;
use interpreter::env::{Environment,Scope};
use ast::{LValue,LValue::*};

pub fn assign_varl(l: &LValue, v: V, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.assign_varl(&s,v);
        }
        MatrixDecomp(ref lm) => {
            let r1 = lm.len();
            let c1 = {
                if r1 > 0 {
                    lm.last().unwrap().len()
                } else {
                    0
                }
            };
            match v {
                V::RM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::RF(*x,u)));
                        for (l,r) in pairs {
                            assign_varl(l,r,env);
                        }
                    }
                }
                V::CM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::CF(*x,u)));
                        for (l,r) in pairs {
                            assign_varl(l,r,env);
                        }
                    }
                }
                V::L(_) | V::S(_) | V::B(_) => {
                    panic!("cannot assign non-numeric types to matrix decomposition")
                }
                V::N => {
                    for r in lm {
                        for c in r {
                            assign_varl(c,V::N,env);
                        }
                    }
                }
                _ => {
                    if r1 != 1 || c1 != 1 {
                        panic!("matrix dimensions of assignment do not agree")
                    } else {
                        assign_varl(lm.get(0).unwrap().get(0).unwrap(),v,env);
                    }
                }
            }
        }
        ListDecomp(ref l) => {
            match v {
                V::L(r) => {
                    if l.len() != r.len() {
                        panic!("sizes of assigned list and value do not match")
                    } else {
                        let pairs = l.iter().zip(r.iter().map(|x| x.clone()));
                        for (l,r) in pairs {
                            assign_varl(l,r,env);
                        }
                    }
                }
                V::N => {
                    for s in l {
                        assign_varl(s,V::N,env);
                    }
                }
                _ => panic!("cannot decompose value into list"),
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn declare_val(l: &LValue, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.declare_val(&s);
        }
        MatrixDecomp(ref lm) => {
            for r in lm {
                for c in r {
                    declare_val(c,env);
                }
            }
        }
        ListDecomp(ref l) => {
            for n in l {
                declare_val(n,env);
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn declare_var(l: &LValue, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.declare_var(&s);
        }
        MatrixDecomp(ref lm) => {
            for r in lm {
                for c in r {
                    declare_var(c,env);
                }
            }
        }
        ListDecomp(ref l) => {
            for n in l {
                declare_var(n,env);
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn declare_param(l: &LValue, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.declare_param(&s);
        }
        MatrixDecomp(ref lm) => {
            for r in lm {
                for c in r {
                    declare_param(c,env);
                }
            }
        }
        ListDecomp(ref l) => {
            for n in l {
                declare_param(n,env);
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn declare_assign_param(l: &LValue, v: V, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.declare_assign_param(&s,v);
        }
        MatrixDecomp(ref lm) => {
            let r1 = lm.len();
            let c1 = {
                if r1 > 0 {
                    lm.last().unwrap().len()
                } else {
                    0
                }
            };
            match v {
                V::RM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::RF(*x,u)));
                        for (l,r) in pairs {
                            declare_assign_param(l,r,env);
                        }
                    }
                }
                V::CM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::CF(*x,u)));
                        for (l,r) in pairs {
                            declare_assign_param(l,r,env);
                        }
                    }
                }
                V::L(_) | V::S(_) | V::B(_) => {
                    panic!("cannot assign non-numeric types to matrix decomposition")
                }
                V::N => {
                    for r in lm {
                        for c in r {
                            declare_assign_param(c,V::N,env);
                        }
                    }
                }
                _ => {
                    if r1 != 1 || c1 != 1 {
                        panic!("matrix dimensions of assignment do not agree")
                    } else {
                        declare_assign_param(lm.get(0).unwrap().get(0).unwrap(),v,env);
                    }
                }
            }
        }
        ListDecomp(ref l) => {
            match v {
                V::L(r) => {
                    if l.len() != r.len() {
                        panic!("sizes of assigned list and value do not match")
                    } else {
                        let pairs = l.iter().zip(r.iter().map(|x| x.clone()));
                        for (l,r) in pairs {
                            declare_assign_param(l,r,env);
                        }
                    }
                }
                V::N => {
                    for s in l {
                        declare_assign_param(s,V::N,env);
                    }
                }
                _ => panic!("cannot decompose value into list"),
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn declare_assign_var(l: &LValue, v: V, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.declare_assign_var(&s,v);
        }
        MatrixDecomp(ref lm) => {
            let r1 = lm.len();
            let c1 = {
                if r1 > 0 {
                    lm.last().unwrap().len()
                } else {
                    0
                }
            };
            match v {
                V::RM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::RF(*x,u)));
                        for (l,r) in pairs {
                            declare_assign_var(l,r,env);
                        }
                    }
                }
                V::CM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::CF(*x,u)));
                        for (l,r) in pairs {
                            declare_assign_var(l,r,env);
                        }
                    }
                }
                V::L(_) | V::S(_) | V::B(_) => {
                    panic!("cannot assign non-numeric types to matrix decomposition")
                }
                V::N => {
                    for r in lm {
                        for c in r {
                            declare_assign_var(c,V::N,env);
                        }
                    }
                }
                _ => {
                    if r1 != 1 || c1 != 1 {
                        panic!("matrix dimensions of assignment do not agree")
                    } else {
                        declare_assign_var(lm.get(0).unwrap().get(0).unwrap(),v,env);
                    }
                }
            }
        }
        ListDecomp(ref l) => {
            match v {
                V::L(r) => {
                    if l.len() != r.len() {
                        panic!("sizes of assigned list and value do not match")
                    } else {
                        let pairs = l.iter().zip(r.iter().map(|x| x.clone()));
                        for (l,r) in pairs {
                            declare_assign_var(l,r,env);
                        }
                    }
                }
                V::N => {
                    for s in l {
                        declare_assign_var(s,V::N,env);
                    }
                }
                _ => panic!("cannot decompose value into list"),
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn declare_assign_val(l: &LValue, v: V, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.declare_assign_val(&s,v);
        }
        MatrixDecomp(ref lm) => {
            let r1 = lm.len();
            let c1 = {
                if r1 > 0 {
                    lm.last().unwrap().len()
                } else {
                    0
                }
            };
            match v {
                V::RM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::RF(*x,u)));
                        for (l,r) in pairs {
                            declare_assign_val(l,r,env);
                        }
                    }
                }
                V::CM(rm,u) => {
                    let (r2,c2) = (rm.nrows(),rm.ncols());
                    if r2 != r1 || c2 != c1 {
                        panic!("matrix dimensions of assignment do not match")
                    } else {
                        let pairs = lm.iter().flat_map(|x| x).zip(rm.iter().map(|x| V::CF(*x,u)));
                        for (l,r) in pairs {
                            declare_assign_val(l,r,env);
                        }
                    }
                }
                V::L(_) | V::S(_) | V::B(_) => {
                    panic!("cannot assign non-numeric types to matrix decomposition")
                }
                V::N => {
                    for r in lm {
                        for c in r {
                            declare_assign_val(c,V::N,env);
                        }
                    }
                }
                _ => {
                    if r1 != 1 || c1 != 1 {
                        panic!("matrix dimensions of assignment do not agree")
                    } else {
                        declare_assign_val(lm.get(0).unwrap().get(0).unwrap(),v,env);
                    }
                }
            }
        }
        ListDecomp(ref l) => {
            match v {
                V::L(r) => {
                    if l.len() != r.len() {
                        panic!("sizes of assigned list and value do not match")
                    } else {
                        let pairs = l.iter().zip(r.iter().map(|x| x.clone()));
                        for (l,r) in pairs {
                            declare_assign_val(l,r,env);
                        }
                    }
                }
                V::N => {
                    for s in l {
                        declare_assign_val(s,V::N,env);
                    }
                }
                _ => panic!("cannot decompose value into list"),
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn drop_varl(l: &LValue, env: &mut Environment) {
    match l {
        Name(ref s) => {
            env.drop_varl(&s);
        }
        MatrixDecomp(ref lm) => {
            for r in lm {
                for c in r {
                    drop_varl(c,env);
                }
            }
        }
        ListDecomp(ref l) => {
            for n in l {
                drop_varl(n,env);
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}

pub fn redeclare(l: &LValue, env: &Environment, scope: &mut Scope) {
    match l {
        Name(ref s) => {
            match scope {
                Scope::Explicit {varls,..} | Scope::Implicit {varls,..} => {
                    let (v,m) = env.get_varl_mutability(s);
                    if m {
                        varls.insert(s.clone(),(v,m));
                    } else {
                        varls.insert(s.clone(),(v,m));
                    }
                }
            }
        }
        MatrixDecomp(ref lm) => {
            for r in lm {
                for c in r {
                    redeclare(c,env,scope);
                }
            }
        }
        ListDecomp(ref l) => {
            for n in l {
                redeclare(n,env,scope);
            }
        }
        Discard => {}
        _ => unimplemented!(),
    }
}
