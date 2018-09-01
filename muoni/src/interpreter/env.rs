use std::collections::HashMap;
use super::value::*;

struct Scope {
    look_to: Option<usize>,
    varls: HashMap<String,(V,bool)>,
    highest_base_unit: u64,
    highest_base_quantity: u64,
    units: HashMap<String,U>,
    quantities: HashMap<String,Q>,
    unit_quantity_map: HashMap<U,Q>,
    converters: HashMap<String,C>,
}

impl Scope {
    fn declare_var(&mut self, n: &String) {
        self.varls.insert(n.clone(), (V::N,true));
    }
    fn declare_val(&mut self, n: &String) {
        self.varls.insert(n.clone(), (V::N,false));
    }
    fn declare_assign_var(&mut self, n: &String, v: V) {
        self.varls.insert(n.clone(),(v,true));
    }
    fn declare_assign_val(&mut self, n: &String, v: V) {
        self.varls.insert(n.clone(),(v,false));
    }
    fn assign_varl(&mut self, n: &String, v: V) {
        if let Some((o,m)) = self.varls.get_mut(n) {
            if *m {
                *o = v;
            } else {
                panic!("cannot assign twice to immutable value")
            }
        } else {
            panic!("assignment to undeclared variable {}",n);
        }
    }
    fn declare_quantity(&mut self, n: &String) {
        self.highest_base_quantity = next_prime(self.highest_base_quantity);
        self.quantities.insert(n.clone(), Q{n:self.highest_base_quantity,d:1});
    }
    fn declare_derived_quantity(&mut self, n: &String, q: Q) {
        if let Some(_) = self.quantities.get(n) {
            panic!("quantities cannot be shadowed or redefined");
        }
        self.quantities.insert(n.clone(),q);
    }
    fn declare_base_unit(&mut self, n: &String, q: &Option<String>) {
        if let Some(_) = self.units.get(n) {
            panic!("units cannot be shadowed or redefined");
        }
        self.highest_base_unit = next_prime(self.highest_base_unit);
        let u = U {n: self.highest_base_unit, d: 1};
        self.units.insert(n.clone(), u);
        if let Some(s) = q {
            let q = self.quantities.get(s);
            match q {
                Some(q) => {
                    self.unit_quantity_map.insert(u,q.clone());
                }
                None => panic!("quantity does not exist"),
            }
        }
    }
    fn declare_derived_unit(&mut self, n: &String, u: U, c: C) {
        if let Some(_) = self.units.get(n) {
            panic!("units cannot be shadowed or redefined");
        }
        self.units.insert(n.clone(),u);
        self.converters.insert(n.clone(),c);
    }
}

pub struct Environment {
    stack: Vec<Scope>,
}

impl Environment {
    pub fn new() -> Self {
        let mut stack = Vec::new();
        stack.push( Scope {
            look_to: None,
            varls: HashMap::new(),
            highest_base_unit: 1,
            highest_base_quantity: 1,
            units: HashMap::new(),
            quantities: HashMap::new(),
            unit_quantity_map: HashMap::new(),
            converters: HashMap::new(),
        } );
        Environment {
            stack
        }
    }
    fn get_top_scope(&self) -> &Scope {
        self.stack.last().unwrap()
    }
    fn get_top_scope_mut(&mut self) -> &mut Scope {
        self.stack.last_mut().unwrap()
    }
    fn get_scope_stack_height(&self) -> usize {
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
    pub fn declare_var(&mut self, n: &String) {
        self.get_top_scope_mut().declare_var(n);
    }
    fn declare_val(&mut self, n: &String) {
        self.get_top_scope_mut().declare_val(n);
    }
    pub fn declare_assign_var(&mut self, n: &String, v: V) {
        self.get_top_scope_mut().declare_assign_var(n,v);
    }
    pub fn declare_assign_val(&mut self, n: &String, v: V) {
        self.get_top_scope_mut().declare_assign_val(n,v);
    }
    fn assign_varl(&mut self, n: &String, v: V) {
        self.get_top_scope_mut().assign_varl(n,v);
    }
    fn declare_quantity(&mut self, n: &String) {
        self.get_top_scope_mut().declare_quantity(n);
    }
    fn declare_derived_quantity(&mut self, n: &String, q: Q) {
        self.get_top_scope_mut().declare_derived_quantity(n,q);
    }
    fn declare_base_unit(&mut self, n: &String, q: &Option<String>) {
        self.get_top_scope_mut().declare_base_unit(n,q);
    }
    fn declare_derived_unit(&mut self, n: &String, u: U, c: C) {
        self.get_top_scope_mut().declare_derived_unit(n,u,c);
    }
    pub fn drop_varl(&mut self, n: &String) {
        let mut i = self.get_scope_stack_height();
        loop {
            let cursor = self.get_scope_mut(i);
            if let Some(_) = cursor.varls.remove(n) {
                break;
            } else {
                match cursor.look_to {
                    None => panic!("variable name not found"),
                    Some(n) => i = n,
                }
            }
        }
    }
    fn new_scope(&mut self, lt: usize) {
        let (hbu, hbq);
        {
            let top = self.get_top_scope();
            hbu = top.highest_base_unit;
            hbq = top.highest_base_quantity;
        }
        self.stack.push( Scope {
            look_to: Some(lt),
            varls: HashMap::new(),
            highest_base_unit: hbu,
            highest_base_quantity: hbq,
            units: HashMap::new(),
            quantities: HashMap::new(),
            unit_quantity_map: HashMap::new(),
            converters: HashMap::new(),
        } );
    }
    pub fn get_varl(&self, n: &String) -> V {
        let mut cursor = self.get_top_scope();
        loop {
            if let Some((v,_)) = cursor.varls.get(n) {
                return v.clone();
            } else {
                match cursor.look_to {
                    None => panic!("variable name not found"),
                    Some(n) => cursor = self.get_scope(n),
                }
            }
        }
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
