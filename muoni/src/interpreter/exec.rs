use super::value::*;
use ast::{Control,Statement,RValue,BOP,Break};
use super::eval::eval;

struct BreakVal {
    series: Vec<Break>,
    value: Option<V>,
}

pub fn exec(scope: &[Control]) {
    use self::Control::*;
    for control in scope {
        match control {
            State {statement} => {
                exec_statement(statement);
            }
            If {condition, body} => {
                if eval(condition).unwrap().to_bool() {
                    exec_statement(body);
                }
            }
            IfElse {condition, if_body, else_body} => {
                if eval(condition).unwrap().to_bool() {
                    exec_statement(if_body);
                } else {
                    exec_statement(else_body);
                }
            }
            IfSeries {conditions, bodies} => {
                for (i,condition) in conditions.iter().enumerate() {
                    if eval(condition).unwrap().to_bool() {
                        exec_statement(bodies.get(i).unwrap());
                        break;
                    }
                }
            }
            IfSeriesElse {conditions, if_bodies, else_body} => {
                let mut e = true;
                for (i,condition) in conditions.iter().enumerate() {
                    if eval(condition).unwrap().to_bool() {
                        exec_statement(if_bodies.get(i).unwrap());
                        e = false;
                        break;
                    }
                }
                if e {
                    exec_statement(else_body);
                }
            }
            _ => unimplemented!(),
        }
    }
}

fn exec_scope(scope: &[Control]) -> Option<BreakVal> {
    unimplemented!()
}

fn exec_statement(state: &Statement) -> Option<BreakVal> {
    unimplemented!();
}
