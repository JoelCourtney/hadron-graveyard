use super::value::*;
use ast::{Control,Statement,LValue,RValue,RValue::Binary,BOP,Assign,Assign::*};
use ast::Break;
use super::eval::*;
use super::env::Environment;
use self::LValue::*;
use na::DMatrix;

pub fn exec(scope: &[Control]) {
    let mut env = Environment::new();
    exec_scope(scope, &mut env);
}

fn exec_scope(scope: &[Control], mut env: &mut Environment) -> (Option<V>,Option<Vec<Break>>) {
    use self::Control::*;
    use self::Break;
    for control in scope {
        match control {
            State {statement} => {
                let mut r = exec_statement(statement, &mut env);
                match r.1 {
                    None => {}
                    Some(mut b) => {
                        match b.last() {
                            Some(Break::Equal) => {
                                return (r.0,Some(b));
                            }
                            Some(Break::Dash) => {
                                b.pop();
                                return (r.0,Some(b));
                            }
                            Some(Break::Tilde) => {
                                return (r.0,Some(b));
                            }
                            None => {
                                panic!("thats not how breaks work");
                            }
                        }
                    }
                }
            }
            If {condition, body} => {
                if unwrap_break(eval(condition)).to_bool_unwrap() {
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    return (r.0,Some(b));
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
                if unwrap_break(eval(condition)).to_bool_unwrap() {
                    let mut r = exec_statement(if_body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    return (r.0,Some(b));
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                } else {
                    let mut r = exec_statement(else_body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    return (r.0,Some(b));
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
                    if unwrap_break(eval(condition)).to_bool_unwrap() {
                        let mut r = exec_statement(bodies.get(i).unwrap(), &mut env);
                        match r.1 {
                            None => {}
                            Some(mut b) => {
                                match b.last() {
                                    Some(Break::Equal) => {
                                        return (r.0,Some(b));
                                    }
                                    Some(Break::Dash) => {
                                        b.pop();
                                        return (r.0,Some(b));
                                    }
                                    Some(Break::Tilde) => {
                                        return (r.0,Some(b));
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
                    if unwrap_break(eval(condition)).to_bool_unwrap() {
                        let mut r = exec_statement(if_bodies.get(i).unwrap(), &mut env);
                        match r.1 {
                            None => {}
                            Some(mut b) => {
                                match b.last() {
                                    Some(Break::Equal) => {
                                        return (r.0,Some(b));
                                    }
                                    Some(Break::Dash) => {
                                        b.pop();
                                        return (r.0,Some(b));
                                    }
                                    Some(Break::Tilde) => {
                                        return (r.0,Some(b));
                                    }
                                    None => {
                                        panic!("thats not how breaks work");
                                    }
                                }
                            }
                        }
                        e = false;
                        break;
                    }
                }
                if e {
                    let mut r = exec_statement(else_body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    return (r.0,Some(b));
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
                for _ in unwrap_break(eval(range)) {
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    unimplemented!(); // have to push to ans
                                    break;
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
                for v in unwrap_break(eval(range)) {
                    match **target {
                        Name(ref s) => env.declare_assign_val(&s,v),
                        _ => unimplemented!(),
                    }
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    unimplemented!(); // have to push to ans
                                    break;
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
                match **target {
                    Name(ref s) => env.drop_varl(&s),
                    _ => unimplemented!(),
                }
            }
            ForAt {range, index, body} => {
                let range = unwrap_break(eval(range));
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
                        match **index {
                            Name(ref s) => {
                                let i = V::RM(DMatrix::from_row_slice(1,2,&[(r+1) as f64,(c+1) as f64]),U::empty());
                                env.declare_assign_val(&s,i);
                            }
                            MatrixDecomp(ref m) => {
                                unimplemented!();
                            }
                            _ => unimplemented!(),
                        }
                    } else {
                        unimplemented!();
                    }
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    unimplemented!(); // have to push to ans
                                    break;
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                    e += 1;
                }
                match **index {
                    Name(ref s) => env.drop_varl(&s),
                    _ => unimplemented!(),
                }
            }
            ForAsAt {range, target, index, body} => {
                let range = unwrap_break(eval(range));
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
                    match **target {
                        Name(ref s) => env.declare_assign_val(&s,v),
                        _ => unimplemented!(),
                    }
                    if matrix {
                        let r = e % stride;
                        let c = (e - r) / stride;
                        match **index {
                            Name(ref s) => {
                                let i = V::RM(DMatrix::from_row_slice(1,2,&[(r+1) as f64,(c+1) as f64]),U::empty());
                                env.declare_assign_val(&s,i);
                            }
                            MatrixDecomp(ref m) => {
                                unimplemented!();
                            }
                            _ => unimplemented!(),
                        }
                    } else {
                        unimplemented!();
                    }
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    unimplemented!(); // have to push to ans
                                    break;
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
                match **target {
                    Name(ref s) => env.drop_varl(&s),
                    _ => unimplemented!(),
                }
                match **index {
                    Name(ref s) => env.drop_varl(&s),
                    _ => unimplemented!(),
                }
            }
            While {condition, body} => {
                while unwrap_break(eval(condition)).to_bool_unwrap() {
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    unimplemented!(); // have to push to ans
                                    break;
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
                    let mut r = exec_statement(body, &mut env);
                    match r.1 {
                        None => {}
                        Some(mut b) => {
                            match b.last() {
                                Some(Break::Equal) => {
                                    return (r.0,Some(b));
                                }
                                Some(Break::Dash) => {
                                    b.pop();
                                    return (r.0,Some(b));
                                }
                                Some(Break::Tilde) => {
                                    b.pop();
                                    unimplemented!(); // have to push to ans
                                    break;
                                }
                                None => {
                                    panic!("thats not how breaks work");
                                }
                            }
                        }
                    }
                }
            }
            BreakEmpty {series} => {
                
            }
            _ => unimplemented!(),
        }
    }
    unimplemented!();
}

fn exec_statement(state: &Statement, mut env: &mut Environment) -> (Option<V>,Option<Vec<Break>>) {
    use self::Statement::*;
    match state {
        VarDecl {name} => {
            match **name {
                Name(ref s) => env.declare_var(&s),
                MatrixDecomp(ref v) => {
                    for r in v {
                        for c in r {
                            match c {
                                Name(ref s) => env.declare_var(&s),
                                Discard => {}
                                _ => panic!("invalid matrix decomposition lvalue"),
                            }
                        }
                    }
                }
                _ => unimplemented!(),
            }
        }
        VarAssign {name, op, e1} => {
            match **name {
                Name(ref s) => {
                    match op {
                        Equal => {
                            let v1 = unwrap_break(eval(&e1));
                            env.declare_assign_var(&s,v1);
                        }
                        OpEqual(bop) => {
                            let v1 = unwrap_break(eval(&e1));
                            let v2 = env.get_varl(&s);
                            let v3 = eval_bop(*bop,v1,v2);
                            env.declare_assign_var(&s,v3);
                        }
                    }
                }
                _ => unimplemented!(),
            }
        }
        StateValue {e1} => {
            return eval(e1);
        }
        _ => unimplemented!(),
    }
    unimplemented!()
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
