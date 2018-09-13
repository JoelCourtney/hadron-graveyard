use super::value::*;
use ast::{Control,Statement,LValue,RValue,RValue::Binary,BOP,Assign,Assign::*};
use ast::Break;
use super::eval::*;
use super::env::{Environment,Scope};
use self::LValue::*;
use na::DMatrix;
use std::collections::HashMap;

pub mod lvalue;

pub fn exec(scope: &[Control]) {
    let mut env = Environment::new();
    exec_scope(scope, &mut env);
}

pub fn exec_scope(scope: &[Control], mut env: &mut Environment) -> Option<Vec<Break>> {
    use self::Control::*;
    for control in scope {
        match control {
            State {statement} => {
                let mut r = exec_statement(statement, env);
                match r {
                    None => {}
                    Some(mut b) => {
                        match b.last() {
                            Some(Break::Equal) => {
                                return Some(b);
                            }
                            Some(Break::Dash) => {
                                b.pop();
                                if b.len() > 0 {
                                    return Some(b);
                                } else {
                                    return None;
                                }
                            }
                            Some(Break::Tilde) => {
                                return Some(b);
                            }
                            None => {
                                panic!("thats not how breaks work");
                            }
                        }
                    }
                }
            }
            If {condition, body} => {
                if unwrap_break(eval(condition,env)).to_bool_unwrap() {
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    return Some(b);
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            IfElse {condition, if_body, else_body} => {
                if unwrap_break(eval(condition,env)).to_bool_unwrap() {
                    let mut r = exec_statement(if_body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    return Some(b);
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                } else {
                    let mut r = exec_statement(else_body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    return Some(b);
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            IfSeries {conditions, bodies} => {
                for (i,condition) in conditions.iter().enumerate() {
                    if unwrap_break(eval(condition,env)).to_bool_unwrap() {
                        let mut r = exec_statement(bodies.get(i).unwrap(), env);
                        match r {
                            None => {}
                            Some(mut b) => {
                                match b.last() {
                                    Some(Break::Equal) => {
                                        return Some(b);
                                    }
                                    Some(Break::Dash) => {
                                        b.pop();
                                        if b.len() > 0 {
                                            return Some(b);
                                        } else {
                                            return None;
                                        }
                                    }
                                    Some(Break::Tilde) => {
                                        return Some(b);
                                    }
                                    None => {
                                        panic!("thats not how breaks work");
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
            IfSeriesElse {conditions, if_bodies, else_body} => {
                let mut e = true;
                for (i,condition) in conditions.iter().enumerate() {
                    if unwrap_break(eval(condition,env)).to_bool_unwrap() {
                        let mut r = exec_statement(if_bodies.get(i).unwrap(), env);
                        match r {
                            None => {}
                            Some(mut b) => {
                                match b.last() {
                                    Some(Break::Equal) => {
                                        return Some(b);
                                    }
                                    Some(Break::Dash) => {
                                        b.pop();
                                        if b.len() > 0 {
                                            return Some(b);
                                        } else {
                                            return None;
                                        }
                                    }
                                    Some(Break::Tilde) => {
                                        return Some(b);
                                    }
                                    None => {
                                        panic!("thats not how breaks work");
                                    }
                                }
                            }
                        }
                    }
                }
                if e {
                    let mut r = exec_statement(else_body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    return Some(b);
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            For {range, body} => {
                for _ in unwrap_break(eval(range,env)) {
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        break;
                                    }
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            ForAs {range, target, body} => {
                env.push_scope(false);
                lvalue::declare_param(target,env);
                for v in unwrap_break(eval(range,env)) {
                    lvalue::assign_varl(target,v,env);
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        break;
                                    }
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
                env.pop_scope();
            }
            ForAt {range, index, body} => {
                env.push_scope(false);
                lvalue::declare_param(index,env);
                let range = unwrap_break(eval(range,env));
                let stride;
                let matrix;
                match range {
                    V::RM(ref m,_) => {
                        matrix = true;
                        stride = m.nrows();
                    }
                    V::CM(ref m,_) => {
                        matrix = true;
                        stride = m.nrows();
                    }
                    _ => {
                        matrix = false;
                        stride = 0;
                    }
                }
                let mut e = 0;
                for _ in range {
                    if matrix {
                        let r = e % stride;
                        let c = (e - r) / stride;
                        lvalue::assign_varl(
                            index,
                            V::RM(
                                DMatrix::from_row_slice(1,2,
                                    &[r as f64, c as f64]
                                ),
                                U::empty()
                            ),
                            env
                        );
                    } else {
                        unimplemented!();
                    }
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        break;
                                    }
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                    e += 1;
                }
                env.pop_scope();
            }
            ForAsAt {range, target, index, body} => {
                env.push_scope(false);
                lvalue::declare_param(target,env);
                lvalue::declare_param(index,env);
                let range = unwrap_break(eval(range,env));
                let stride;
                let matrix;
                match range {
                    V::RM(ref m,_) => {
                        matrix = true;
                        stride = m.nrows();
                    }
                    V::CM(ref m,_) => {
                        matrix = true;
                        stride = m.nrows();
                    }
                    _ => {
                        matrix = false;
                        stride = 0;
                    }
                }
                let mut e = 0;
                for v in range {
                    lvalue::assign_varl(target,v,env);
                    if matrix {
                        let r = e % stride;
                        let c = (e - r) / stride;
                        lvalue::assign_varl(
                            index,
                            V::RM(
                                DMatrix::from_row_slice(1,2,
                                    &[r as f64, c as f64]
                                ),
                                U::empty()
                            ),
                            env
                        );
                    } else {
                        lvalue::assign_varl(index,V::RI(e as i64,U::empty()),env);
                    }
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        break;
                                    }
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                    e += 1;
                }
                env.pop_scope();
            }
            While {condition, body} => {
                while unwrap_break(eval(condition,env)).to_bool_unwrap() {
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        break;
                                    }
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            Loop {body} => {
                loop {
                    let mut r = exec_statement(body, env);
                    match r {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return Some(b);
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        return None;
                                    }
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    if b.len() > 0 {
                                        return Some(b);
                                    } else {
                                        break;
                                    }
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            _ => unimplemented!(),
        }
    }
    return None;
}

pub fn exec_statement(state: &Statement, mut env: &mut Environment) -> Option<Vec<Break>> {
    use self::Statement::*;
    use self::Break;
    match state {
        VarDecl {name} => {
            lvalue::declare_var(name, env);
        }
        ValDecl {name} => {
            lvalue::declare_val(name, env);
        }
        VarAssign {name, op, e1} => {
            match op {
                Equal => {
                    let v1 = unwrap_break(eval(e1,env));
                    lvalue::declare_assign_var(name,v1,env);
                }
                OpEqual(bop) => {
                    match **name {
                        Name(ref s) => {
                            let v1 = unwrap_break(eval(e1,env));
                            let v2 = env.get_varl(s);
                            let v3 = eval_bop(*bop,v1,v2);
                            env.declare_assign_var(s,v3);
                        }
                        _ => unimplemented!(),
                    }
                }
            }
        }
        ValAssign {name, op, e1} => {
            match op {
                Equal => {
                    let v1 = unwrap_break(eval(e1,env));
                    lvalue::declare_assign_val(name,v1,env);
                }
                OpEqual(bop) => {
                    match **name {
                        Name(ref s) => {
                            let v1 = unwrap_break(eval(e1,env));
                            let v2 = env.get_varl(s);
                            let v3 = eval_bop(*bop,v1,v2);
                            env.declare_assign_val(s,v3);
                        }
                        _ => unimplemented!(),
                    }
                }
            }
        }
        Assign {name, op, e1} => {
            match op {
                Equal => {
                    let v1 = unwrap_break(eval(e1,env));
                    lvalue::assign_varl(name,v1,env);
                }
                OpEqual(bop) => {
                    match **name {
                        Name(ref s) => {
                            let v1 = unwrap_break(eval(e1,env));
                            let v2 = env.get_varl(s);
                            let v3 = eval_bop(*bop,v1,v2);
                            env.assign_varl(s,v3);
                        }
                        _ => unimplemented!(),
                    }
                }
            }
        }
        StateValue {e1} => {
            let r = eval(e1,env);
            match r.0 {
                Some(v) => env.push_ans(v),
                None => {}
            }
            return r.1;
        }
        Print {e1} => {
            let v1 = unwrap_break(eval(e1,env));
            println!("{}",v1.to_string_unwrap());
        }
        Drop {name} => {
            lvalue::drop_varl(name,env);
        }
        AssignFunction {name, args, caps, body} => {
            let scope = env.get_premade_implicit(caps);
            let f = F {
                //name: name.clone(),
                args: args.clone(),
                scope,
                body: body.clone(),
            };
            env.declare_assign_val(name,V::F(Box::new(f)));
        }
        Statement::Break {series, e1} => {
            let v1 = eval(e1,env);
            if v1.1 != None {
                panic!("cannot break out of break statement")
            } else {
                match v1.0 {
                    Some(v) => {
                        env.push_ans(v);
                    }
                    None => {
                        env.clear_ans();
                    }
                }
            }
            match series.last() {
                Some(_) => {
                    return Some(series.clone());
                }
                None => {
                    panic!("thats not how breaks work");
                }
            }
        }
        BreakEmpty {series} => {
            match series.last() {
                Some(_) => {
                    return Some(series.clone());
                }
                None => {
                    panic!("thats not how breaks work");
                }
            }
        }
        _ => unimplemented!(),
    }
    return None;
}

pub fn unwrap_break((v,s): (Option<V>,Option<Vec<Break>>)) -> V {
    match s {
        None => {}
        Some(_) => panic!("cannot break out of the middle of a statement"),
    }
    match v {
        None => panic!("a value is required for this operation"),
        Some(v) => v,
    }
}
