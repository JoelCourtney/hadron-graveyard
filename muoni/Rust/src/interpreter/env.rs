use std::collections::HashMap;
use super::value::*;
use ast::LValue;
use interpreter::exec::lvalue;
use nc::Complex;

#[derive(Clone)]
pub enum Scope {
    Explicit {
        look_to: Option<usize>,
        varls: HashMap<String,(V,bool)>,
        next_base_key: u64,
        units: HashMap<String,C>,
        dimensions: HashMap<String,D>,
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
        let mut varls = HashMap::new();
        varls.insert(String::from("i"),(V::CI(Complex::<i64>::i()),false));
        varls.insert(String::from("e"),(V::RF(2.718281828459045235360287471352662497757247093699959574966967627724076630354),false));
        varls.insert(String::from("π"),(V::RF(3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863),false));
        varls.insert(String::from("φ"),(V::RF(1.61803398874989484820458683436563811772030917980576286213544862270526046281890),false));
        let s = Scope::Explicit {
            look_to: None,
            varls,
            next_base_key: 0,
            units: HashMap::new(),
            dimensions: HashMap::new(),
            ans: Vec::new(),
        };
        stack.push(s);
        Environment {
            stack,
        }
    }
    pub fn get_top_scope(&self) -> &Scope {
        self.stack.last().unwrap()
    }
    fn get_top_scope_mut(&mut self) -> &mut Scope {
        self.stack.last_mut().unwrap()
    }
    pub fn get_highest_scope_index(&self) -> usize {
        self.stack.len() - 1
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
        let s = self.stack.len()-1;
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
                varls.insert(n.clone(), (V::Null,true));
            }
            _ => panic!("cannot declare vars in implicit scope"),
        }
    }
    pub fn declare_val(&mut self, n: &String) {
        match self.get_highest_explicit_mut() {
            Explicit {varls,..} => {
                varls.insert(n.clone(), (V::Null,false));
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
                varls.insert(n.clone(),(V::Null,true));
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
        let mut i = self.get_highest_scope_index();
        loop {
            let cursor = self.get_scope_mut(i);
            match cursor {
                Explicit {look_to,varls,..} => {
                    if let Some((o,m)) = varls.get_mut(n) {
                        if  o.is_null() || *m {
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
                        if o.is_null() || *m {
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
    pub fn declare_base_dimension(&mut self, n: &String) -> D {
        match self.get_highest_explicit_mut() {
            Explicit {dimensions,next_base_key,..} => {
                if let Some(_) = dimensions.get(n) {
                    panic!("dimensions cannot be shadowed or redefined");
                }
                let q = D::from_base(*next_base_key);
                dimensions.insert(n.clone(), q.clone());
                *next_base_key += 1;
                return q;
            }
            _ => panic!("cannot declare dimensions in implicit scope"),
        }
    }
    pub fn declare_derived_dimension(&mut self, n: &String, q: D) {
        match self.get_highest_explicit_mut() {
            Explicit {dimensions,..} => {
                if let Some(_) = dimensions.get(n) {
                    panic!("dimensions cannot be shadowed or redefined");
                }
                dimensions.insert(n.clone(),q);
            }
            _ => panic!("cannot declare dimensions in implicit scope"),
        }
    }
    pub fn declare_base_unit(&mut self, n: &String, q: D) {
        match self.get_highest_explicit_mut() {
            Explicit {dimensions,units,next_base_key,..} => {
                if let Some(_) = units.get(n) {
                    panic!("units cannot be shadowed or redefined");
                }
                units.insert(n.clone(), C::base_unit_converter(q));
            }
            _ => panic!("cannot declare units in implicit scope"),
        }
    }
    pub fn declare_derived_unit(&mut self, n: &String, c: C) {
        match self.get_highest_explicit_mut() {
            Explicit {units,..} => {
                if let Some(_) = units.get(n) {
                    panic!("units cannot be shadowed or redefined");
                }
                units.insert(n.clone(),c);
            }
            _ => panic!("cannot declare dimensions in implicit scope"),
        }
    }
    pub fn drop_varl(&mut self, n: &String) {
        let mut i = self.get_highest_scope_index();
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
        let height = self.get_highest_scope_index();
        if exp {
            let nui;
            {
                match self.get_top_scope() {
                    Explicit {next_base_key,..} => {
                        nui = *next_base_key;
                    }
                    Implicit {look_to,..} => {
                        match self.get_scope(*look_to) {
                            Explicit {next_base_key,..} => {
                                nui = *next_base_key;
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
                next_base_key: nui,
                units: HashMap::new(),
                dimensions: HashMap::new(),
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
        let mut i = self.get_highest_scope_index();
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,varls,..} => {
                    if let Some((v,_)) = varls.get(n) {
                        return v.clone();
                    } else {
                        match look_to {
                            None => panic!("variable name not found: {}",n),
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
        let mut i = self.get_highest_scope_index();
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
    pub fn get_dimension(&self, n: &String) -> D {
        let mut i = self.get_highest_scope_index();
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,dimensions,..} => {
                    if let Some(d) = dimensions.get(n) {
                        return d.clone();
                    } else {
                        match look_to {
                            None => panic!("dimension name not found"),
                            Some(n) => i = *n,
                        }
                    }
                }
                Implicit {look_to,..} => {
                    i = *look_to;
                }
            }
        }
    }
    pub fn get_dimension_opt(&self, n: &String) -> Option<D> {
        let mut i = self.get_highest_scope_index();
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,dimensions,..} => {
                    if let Some(d) = dimensions.get(n) {
                        return Some(d.clone());
                    } else {
                        match look_to {
                            None => return None,
                            Some(n) => i = *n,
                        }
                    }
                }
                Implicit {look_to,..} => {
                    i = *look_to;
                }
            }
        }
    }
    pub fn get_unit(&self, n: &String) -> C {
        let mut i = self.get_highest_scope_index();
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,units,..} => {
                    if let Some(u) = units.get(n) {
                        return u.clone();
                    } else {
                        match look_to {
                            None => panic!("unit name not found"),
                            Some(n) => i = *n,
                        }
                    }
                }
                Implicit {look_to,..} => {
                    i = *look_to;
                }
            }
        }
    }
    pub fn get_unit_name(&self, u: u64) -> String {
        let mut i = self.get_highest_scope_index();
        let test_dim = D::from_base(u);
        let test_conv = C::base_unit_converter(test_dim);
        loop {
            let cursor = self.get_scope(i);
            match cursor {
                Explicit {look_to,units,..} => {
                    for (n,c) in units {
                        if *c == test_conv {
                            return n.clone();
                        }
                    }
                    match look_to {
                        None => panic!("unit number not found"),
                        Some(n) => i = *n,
                    }
                }
                Implicit {look_to,..} => {
                    i = *look_to;
                }
            }
        }
    }
    pub fn pop_reduce_scope(&mut self) -> Option<V> {
        match self.stack.pop() {
            None => panic!("cannot pop; stack is already empty"),
            Some(s) => {
                match s {
                    Explicit {mut ans,..} => {
                        return ans.pop();
                    }
                    Implicit {..} => panic!("attempting to pop implicit scope"),
                }
            }
        }
    }
    pub fn pop_scope(&mut self) {
        self.stack.pop();
    }
    pub fn push_ans(&mut self, v: V) {
        if let Explicit {ans,..} = self.get_highest_explicit_mut() {
            ans.push(v);
        } else {
            panic!("something has gone horribly wrong");
        }
    }
    pub fn clear_ans(&mut self) {
        if let Explicit {ans,..} = self.get_highest_explicit_mut() {
            ans.clear();
        } else {
            panic!("something has gone horribly wrong");
        }
    }
}

impl Environment {
    pub fn get_premade_implicit(&self, caps: &Vec<LValue>) -> Scope {
        let mut s = Scope::Implicit {
            look_to: self.get_highest_scope_index(),
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
