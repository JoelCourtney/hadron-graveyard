use std::collections::HashMap;
use super::value::*;
use ast::LValue;
use interpreter::exec::lvalue;

#[derive(Clone,PartialEq,Debug)]
pub enum Scope {
    Explicit {
        look_to: Option<usize>,
        varls: HashMap<String,(V,bool)>,
        highest_base_unit: u64,
        highest_base_quantity: u64,
        units: HashMap<String,U>,
        quantities: HashMap<String,Q>,
        unit_quantity_map: HashMap<U,Q>,
        converters: HashMap<String,C>,
        ans: Vec<V>,
    },
    Implicit {
        look_to: usize,
        varls: HashMap<String,(V,bool)>,
    },
}
use self::Scope::*;

pub struct Environment {
    stack: Vec<Scope>,
}

impl Environment {
    pub fn new() -> Self {
        let mut stack = Vec::new();
        stack.push( Scope::Explicit {
            look_to: None,
            varls: HashMap::new(),
            highest_base_unit: 1,
            highest_base_quantity: 1,
            units: HashMap::new(),
            quantities: HashMap::new(),
            unit_quantity_map: HashMap::new(),
            converters: HashMap::new(),
            ans: Vec::new(),
        } );
        Environment {
            stack
        }
    }
    pub fn get_top_scope(&self) -> &Scope {
        self.stack.last().unwrap()
    }
    fn get_top_scope_mut(&mut self) -> &mut Scope {
        self.stack.last_mut().unwrap()
    }
    pub fn get_scope_stack_height(&self) -> usize {
        self.stack.len()
    }
    fn get_scope(&self, i: usize) -> &Scope {
        match self.stack.get(i) {
            Some(s) => s,
            None => panic!("invalid scope requested"),
        }
    }
    fn get_scope_mut(&mut self, i: usize) -> &mut Scope {
        match self.stack.get_mut(i) {
            Some(s) => s,
            None => panic!("invalid scope requested"),
        }
    }
    fn get_highest_explicit(&self) -> &Scope {
        let s = self.stack.last().unwrap();
        match s {
            Explicit {..} => return s,
            Implicit {look_to,..} => {
                let s = self.stack.get(*look_to).unwrap();
                match s {
                    Explicit {..} => return s,
                    Implicit {..} => panic!("something has gone horribly wrong"),
                }
            }
        }
    }
    fn get_highest_explicit_mut(&mut self) -> &mut Scope {
        let s = self.stack.len();
        let i;
        match self.stack.get(s).unwrap() {
            Explicit {..} => i = s,
            Implicit {look_to,..} => {
                match self.stack.get(*look_to).unwrap() {
                    Explicit {..} => i = *look_to,
                    Implicit {..} => panic!("something has gone horribly wrong"),
                }
            }
        }
        return self.stack.get_mut(i).unwrap();
    }
    pub fn declare_var(&mut self, n: &String) {
        match self.get_highest_explicit_mut() {
            Explicit {varls,..} => {
                varls.insert(n.clone(), (V::N,true));
            }
            _ => panic!("cannot declare vars in implicit scope"),
        }
    }
    pub fn declare_val(&mut self, n: &String) {
        match self.get_highest_explicit_mut() {
            Explicit {varls,..} => {
                varls.insert(n.clone(), (V::N,false));
            }
            _ => panic!("cannot declare vals in implicit scope"),
        }
    }
    pub fn declare_param(&mut self, n: &String) {
        match self.get_top_scope_mut() {
            Explicit {..} => {
                panic!("cannot declare parameters on explicit scope");
            }
            Implicit {varls,..} => {
                varls.insert(n.clone(),(V::N,true));
            }
        }
    }
    pub fn declare_assign_param(&mut self, n: &String, v: V) {
        match self.get_top_scope_mut() {
            Explicit {..} => {
                panic!("cannot declare parameters on explicit scope");
            }
            Implicit {varls,..} => {
                varls.insert(n.clone(),(v,true));
            }
        }
    }
    pub fn declare_assign_var(&mut self, n: &String, v: V) {
        match self.get_highest_explicit_mut() {
            Explicit {varls,..} => {
                varls.insert(n.clone(), (v,true));
            }
            _ => panic!("cannot declare vars in implicit scope"),
        }
    }
    pub fn declare_assign_val(&mut self, n: &String, v: V) {
        match self.get_highest_explicit_mut() {
            Explicit {varls,..} => {
                varls.insert(n.clone(), (v,false));
            }
            _ => panic!("cannot declare vals in implicit scope"),
        }
    }
    pub fn assign_varl(&mut self, n: &String, mut v: V) {
        let mut i = self.get_scope_stack_height();
        loop {
            let cursor = self.get_scope_mut(i);
            match cursor {
                Explicit {look_to,varls,..} => {
                    if let Some((o,m)) = varls.get_mut(n) {
                        if  *o == V::N || *m {
                            *o = v;
                            return;
                        } else {
                            panic!("cannot assign twice to immutable value");
                        }
                    } else {
                        match look_to {
                            Some(n) => i = *n,
                            None => panic!("name not found"),
                        }
                    }
                }
                Implicit {look_to,varls} => {
                    if let Some((o,m)) = varls.get_mut(n) {
                        if *o == V::N || *m {
                            *o = v;
                            return;
                        } else {
                            panic!("cannot assign twice to immutable value");
                        }
                    } else {
                        i = *look_to;
                    }
                }
            }
        }
    }
    fn declare_quantity(&mut self, n: &String) {
        match self.get_highest_explicit_mut() {
            Explicit {quantities,highest_base_quantity,..} => {
                *highest_base_quantity = next_prime(*highest_base_quantity);
                quantities.insert(n.clone(), Q{n:*highest_base_quantity,d:1});
            }
            _ => panic!("cannot declare quantities in implicit scope"),
        }
    }
    fn declare_derived_quantity(&mut self, n: &String, q: Q) {
        match self.get_highest_explicit_mut() {
            Explicit {quantities,..} => {
                if let Some(_) = quantities.get(n) {
                    panic!("quantities cannot be shadowed or redefined");
                }
                quantities.insert(n.clone(),q);
            }
            _ => panic!("cannot declare quantities in implicit scope"),
        }
    }
    fn declare_base_unit(&mut self, n: &String, q: &Option<String>) {
        match self.get_highest_explicit_mut() {
            Explicit {quantities,units,unit_quantity_map,highest_base_unit,..} => {
                if let Some(_) = units.get(n) {
                    panic!("units cannot be shadowed or redefined");
                }
                *highest_base_unit = next_prime(*highest_base_unit);
                let u = U {n: *highest_base_unit, d: 1};
                units.insert(n.clone(), u);
                if let Some(s) = q {
                    let q = quantities.get(s);
                    match q {
                        Some(q) => {
                            unit_quantity_map.insert(u,q.clone());
                        }
                        None => panic!("quantity does not exist"),
                    }
                }
            }
            _ => panic!("cannot declare quantities in implicit scope"),
        }
    }
    fn declare_derived_unit(&mut self, n: &String, u: U, c: C) {
        match self.get_highest_explicit_mut() {
            Explicit {units,converters,..} => {
                if let Some(_) = units.get(n) {
                    panic!("units cannot be shadowed or redefined");
                }
                units.insert(n.clone(),u);
                converters.insert(n.clone(),c);
            }
            _ => panic!("cannot declare quantities in implicit scope"),
        }
    }
    pub fn drop_varl(&mut self, n: &String) {
        let mut i = self.get_scope_stack_height();
        loop {
            let cursor = self.get_scope_mut(i);
            match cursor {
                Explicit {look_to,varls,..} => {
                    if let Some(_) = varls.remove(n) {
                        return;
                    } else {
                        match look_to {
                            None => panic!("variable name not found"),
                            Some(n) => i = *n,
                        }
                    }
                }
                Implicit {look_to,varls} => {
                    if let Some(_) = varls.remove(n) {
                        return;
                    } else {
                        i = *look_to;
                    }
                }
            }
        }
    }
    pub fn push_scope(&mut self, exp: bool) {
        let height = self.get_scope_stack_height();
        if exp {
            let (hbu, hbq);
            {
                match self.get_top_scope() {
                    Explicit {highest_base_unit,highest_base_quantity,..} => {
                        hbu = *highest_base_unit;
                        hbq = *highest_base_quantity;
                    }
                    Implicit {look_to,..} => {
                        match self.get_scope(*look_to) {
                            Explicit {highest_base_unit,highest_base_quantity,..} => {
                                hbu = *highest_base_unit;
                                hbq = *highest_base_quantity;
                            }
                            Implicit {..} => {
                                panic!("thats not supposed to happen")
                            }
                        }
                    }
                }
            }
            self.stack.push( Scope::Explicit {
                look_to: Some(height),
                varls: HashMap::new(),
                highest_base_unit: hbu,
                highest_base_quantity: hbq,
                units: HashMap::new(),
                quantities: HashMap::new(),
                unit_quantity_map: HashMap::new(),
                converters: HashMap::new(),
                ans: Vec::new(),
            } );
        } else {
            self.stack.push( Scope::Implicit {
                look_to: height,
                varls: HashMap::new(),
            });
        }
    }
    pub fn push_premade_scope(&mut self, s: Scope) {
        self.stack.push(s);
    }
    pub fn get_varl(&self, n: &String) -> V {
        let mut i = self.get_scope_stack_height();
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,varls,..} => {
                    if let Some((v,_)) = varls.get(n) {
                        return v.clone();
                    } else {
                        match look_to {
                            None => panic!("variable name not found"),
                            Some(n) => i = *n,
                        }
                    }
                }
                Implicit {look_to,varls} => {
                    if let Some((v,_)) = varls.get(n) {
                        return v.clone();
                    } else {
                        i = *look_to;
                    }
                }
            }
        }
    }
    pub fn get_varl_mutability(&self, n: &String) -> (V,bool) {
        let mut i = self.get_scope_stack_height();
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,varls,..} => {
                    if let Some((v,m)) = varls.get(n) {
                        return (v.clone(),*m);
                    } else {
                        match look_to {
                            None => panic!("variable name not found"),
                            Some(n) => i = *n,
                        }
                    }
                }
                Implicit {look_to,varls} => {
                    if let Some((v,m)) = varls.get(n) {
                        return (v.clone(),*m);
                    } else {
                        i = *look_to;
                    }
                }
            }
        }
    }
    pub fn pop_reduce_scope(&mut self) -> Option<V> {
        // let ans = self.get_top_scope_mut().ans.pop();
        self.stack.pop();
        return None;
    }
    pub fn pop_scope(&mut self) {
        self.stack.pop();
    }
}

impl Environment {
    pub fn get_premade_implicit(&self, caps: &Vec<LValue>) -> Scope {
        let mut s = Scope::Implicit {
            look_to: self.get_scope_stack_height(),
            varls: HashMap::new(),
        };
        for c in caps {
            lvalue::redeclare(c,&self,&mut s);
        }
        return s;
    }
}

fn next_prime(n: u64) -> u64 {
    let mut n = n;
    let mut not_prime;
    loop {
        not_prime = false;
        n += 1;
        for i in 2..=(n as f64).sqrt() as u64 {
            if n % i == 0 {
                not_prime = true;
                break;
            }
        }
        if !not_prime {
            return n;
        }
    }
}
