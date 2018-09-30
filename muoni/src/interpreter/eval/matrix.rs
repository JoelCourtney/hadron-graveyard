use interpreter::value::*;
use ast::{RValue,BOP,UOP,Break};
use interpreter::exec::unwrap_break;
use interpreter::env::Environment;
use interpreter::exec::{lvalue,exec_scope,exec_statement};
use na::DMatrix;
use nc::{Complex,Complex64};
use interpreter::value::numeric::*;
use interpreter::eval::expand_range;

pub fn eval(v: &Vec<Vec<RValue>>, env: &mut Environment) -> (Option<V>,Option<Vec<Break>>) {
    let mut m = Vec::new();
    for row in v {
        let mut r = Vec::new();
        for elem in row {
            let mut hold = unwrap_break(super::eval(elem,env));
            if let V::R(s,b,e) = hold {
                hold = expand_range(*s,*b,*e);
            }
            r.push(hold);
        }
        m.push(r);
    }
    let mut u = None;
    let mut complex = false;
    let mut float = false;
    for row in &m {
        for elem in row {
            match elem {
                V::N(n) => {
                    match n.type_of() {
                        NT::RI | NT::RB | NT::RIM => {
                            if let Some(_) = u {
                                panic!("units of elements do not match")
                            }
                        }
                        NT::RF | NT::RFM => {
                            if let Some(_) = u {
                                panic!("units of elements do not match")
                            }
                            float = true;
                        }
                        NT::CI | NT::CB | NT::CIM => {
                            if let Some(_) = u {
                                panic!("units of elements do not match")
                            }
                            complex = true;
                        }
                        NT::CF | NT::CFM => {
                            if let Some(_) = u {
                                panic!("units of elements do not match")
                            }
                            complex = true;
                            float = true;
                        }
                        NT::URI | NT::URB | NT::URIM => {
                            if u == None {
                                u = Some(n.get_unit());
                            } else if !u.as_ref().unwrap().equal(n.get_unit_ref()) {
                                panic!("units of elements do not match");
                            }
                        }
                        NT::URF | NT::URFM => {
                            if u == None {
                                u = Some(n.get_unit());
                            } else if !u.as_ref().unwrap().equal(n.get_unit_ref()) {
                                panic!("units of elements do not match");
                            }
                            float = true;
                        }
                        NT::UCI | NT::UCB | NT::UCIM => {
                            if u == None {
                                u = Some(n.get_unit());
                            } else if !u.as_ref().unwrap().equal(n.get_unit_ref()) {
                                panic!("units of elements do not match");
                            }
                            complex = true;
                        }
                        NT::UCF | NT::UCFM => {
                            if u == None {
                                u = Some(n.get_unit());
                            } else if !u.as_ref().unwrap().equal(n.get_unit_ref()) {
                                panic!("units of elements do not match");
                            }
                            complex = true;
                            float = true;
                        }
                    }
                }
                V::R(..) => panic!("something has gone horribly wrong"),
                V::S(_) => panic!("cannot insert string to matrix"),
                V::B(_) => panic!("cannot insert bool to matrix"),
                V::L(_) => unimplemented!(),
                V::F(_) => panic!("cannot insert function into matrix"),
                V::Null => panic!("cannot insert null into matrix"),
            }
        }
    }
    let mut height = 0;
    let mut width = 0;
    if !float {
        if !complex {
            if u == None {
                let mut col_major = Vec::new();
                for row in m.into_iter() {
                    let mut row_height = 0;
                    let mut cols: Vec<Vec<RI>> = Vec::new();
                    for elem in row {
                        match elem {
                            V::N(n) => {
                                match n.type_of() {
                                    NT::RI | NT::RB => {
                                        if row_height == 0 {
                                            row_height = 1;
                                        } else if row_height != 1 {
                                            panic!("row heights do not match");
                                        }
                                        cols.push(vec![n.to_ri() as RI]);
                                    }
                                    NT::RIM => {
                                        let rim: DMatrix<i64> = n.to_rim();
                                        if row_height == 0 {
                                            row_height = rim.nrows();
                                        } else if row_height != rim.nrows() {
                                            panic!("row heights do not match");
                                        }
                                        for c in 0..rim.ncols() {
                                            cols.push(rim.column(c).iter().map(|x|*x).collect());
                                        }
                                    }
                                    _ => panic!("something has gone horribly wrong")
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
                let data = col_major.into_iter().flat_map(|x| x).collect::<Vec<RI>>();
                return (Some(V::RIM(DMatrix::from_column_slice(height,width,&data))),None);
            } else {
                unimplemented!() // URIM
            }
        } else {
            if u == None {
                unimplemented!() // CIM
            } else {
                unimplemented!() // UCIM
            }
        }
    } else {
        if !complex {
            if let Some(u) = u {
                unimplemented!() // RFM
            } else {
                unimplemented!() // URFM
            }
        } else {
            if let Some(u) = u {
                unimplemented!() // CFM
            } else {
                unimplemented!() // UCFM
            }
        }
    }
}
