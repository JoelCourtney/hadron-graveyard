use interpreter::value::{D,VI,V};
use V::*;
use nc::{Complex,Complex64};
use na::DMatrix;
use super::numeric::*;
use super::IterEnum;

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
        unimplemented!()
    }
}

impl IntoIterator for V {
    type Item = V;
    type IntoIter = VI;

    fn into_iter(self) -> Self::IntoIter {
        match self {
            N(n) => {
                match n.type_of() {
                    NT::RI => VI {
                        iter: IterEnum::RI(n.to_ri(),false),
                        unit: None,
                    },
                    _ => unimplemented!(),
                }
            }

            _ => unimplemented!(),
        }
    }
}
