use std::collections::HashMap;
use super::value::*;
use super::value::unit::*;

struct Scope {
    look_to: usize,
    vars: HashMap<String,V>,
    vals: HashMap<String,V>,
    highest_base_unit: u64,
    highest_base_quantity: u64,
    units: HashMap<String,U>,
    quantities: HashMap<String,Q>,
    unit_quantity_map: HashMap<U,Q>,
    converters: HashMap<String,C>,
}

impl Scope {
    fn declare_var(&mut self, n: &String) {
        self.vars.insert(n.clone(), V::new(Null));
    }
    fn declare_val(&mut self, n: &String) {
        self.vals.insert(n.clone(), V::new(Null));
    }
    fn declare_assign_var(&mut self, n: &String, v: V) {
        self.vars.insert(n.clone(),v);
    }
    fn declare_assign_val(&mut self, n: &String, v: V) {
        self.vars.insert(n.clone(),v);
    }
    fn assign_varl(&mut self, n: &String, v: V) {
        if let Some(o) = self.vars.get_mut(n) {
            *o = v;
        } else if let Some(o) = self.vals.get_mut(n) {
            if o.eq(&V::new(Null)) {
                *o = v;
            } else {
                panic!("multple assignment to value {}",n);
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

fn next_prime(n: u64) -> u64 {
    let mut n = n;
    let mut not_prime;
    loop {
        not_prime = false;
        n += 1;
        for i in (2..=(n as f64).sqrt() as u64) {
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
