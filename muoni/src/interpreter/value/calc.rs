use interpreter::value::{D,VI,V};
use V::*;
use nc::{Complex,Complex64};
use na::DMatrix;
use super::numeric::*;

impl V {
    pub fn add(self, with: V) -> Self {
        match (self,with) {
            (N(n1),N(n2)) => {
                match (n1.type_of(),n2.type_of()) {
                    (NT::RI,NT::RI) => {
                        N(Box::new(n1.to_ri()+n2.to_ri()))
                    }
                    _ => unimplemented!(),
                }
            }
            _ => unimplemented!(),
        }
    }
    pub fn add_ref(&self, with: &V) -> Self {
        unimplemented!()
    }
    pub fn sub(self, with: V) -> Self {
        unimplemented!()
    }
    pub fn times(self, with: V) -> Self {
        unimplemented!()
    }
    pub fn divide(self, with: V) -> Self {
        unimplemented!()
    }
    pub fn less_or_equal_ref(&self, with: &V) -> Self {
        unimplemented!()
    }
    pub fn is(self, with: V) -> Self {
        match (self,with) {
            (N(n1),N(n2)) => {
                match (n1.type_of(),n2.type_of()) {
                    (NT::RI,NT::RI) => {
                        B(n1.to_ri() == n2.to_ri())
                    }
                    _ => unimplemented!(),
                }
            }
            _ => unimplemented!(),
        }
    }
    pub fn less(self, with: V) -> Self {
        match (self,with) {
            (N(n1),N(n2)) => {
                match (n1.type_of(),n2.type_of()) {
                    (NT::RI,NT::RI) => {
                        B(n1.to_ri() < n2.to_ri())
                    }
                    _ => unimplemented!(),
                }
            }
            _ => unimplemented!(),
        }
    }
}

impl Iterator for VI {
    type Item = V;

    fn next(&mut self) -> Option<V> {
        match self {
            VI::RI(ref ri, mut b) => {
                if b {
                    b = false;
                    Some(V::N(Box::new(*ri)))
                } else {
                    None
                }
            }
            VI::R(ref mut r) => {
                if r.b.greater_ref(V::RI(0)).to_bool_unwrap() {
                    if r.s.less_or_equal_ref(r.e) {
                        let hold = r.s.box_clone();
                        r.s = r.s.add_ref(r.b);
                        Some(V::N(hold))
                    } else {
                        None
                    }
                } else {
                    if r.s.greater_or_equal_ref(r.e) {
                        let hold = r.s.box_clone();
                        r.s = r.s.add_ref(r.b);
                        Some(V::N(hold))
                    } else {
                        None
                    }
                }
            }
            _ => unimplemented!()
        }
    }
}

impl IntoIterator for V {
    type Item = V;
    type IntoIter = VI;

    fn into_iter(self) -> Self::IntoIter {
        match self {
            N(n) => {
                match n.type_of() {
                    NT::RI => VI::RI(n.to_ri(),true),
                    _ => unimplemented!(),
                }
            }
            R(r) => VI::R(r),
            _ => unimplemented!(),
        }
    }
}
