use interpreter::value::{V,U,VI};
use V::*;
use nc::{Complex,Complex64};
use na::DMatrix;

impl V {
    pub fn add(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                let n3 = n1 + n2;
                let u3 = u1.add(u2);
                RI(n1+n2,u3)
            }
            _ => unimplemented!(),
        }
    }
    pub fn add_ref(&self, with: &V) -> Self {
        self.clone().add(with.clone())
    }
    pub fn sub(self, with: V) -> Self {
        match (self,with) {
            _ => unimplemented!(),
        }
    }
    pub fn less_or_equal_ref(&self, with: &V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                u1.equal(u2);
                B(n1 <= n2)
            }
            _ => unimplemented!(),
        }
    }
}

impl Iterator for VI {
    type Item = V;

    fn next(&mut self) -> Option<V> {
        match self.v {
            RI(_,_) | RF(_,_) | CI(_,_) | CF(_,_) | S(_) | B(_) | F(_) => {
                match self.i {
                    0 => {
                        self.i = 1;
                        Some(self.v.clone())
                    }
                    _ => None,
                }
            }
            RM(ref m, u) => {
                match m.data.get(self.i) {
                    Some(n) => {
                        self.i += 1;
                        Some(RF(*n,u))
                    }
                    None => None,
                }
            }
            CM(ref m,u) => {
                match m.data.get(self.i) {
                    Some(n) => {
                        self.i += 1;
                        Some(CF(*n,u))
                    }
                    None => None,
                }
            }
            L(_) => unimplemented!(),
            R(ref s, ref b, ref e) => {
                let hold;
                match self.c {
                    N => {
                        self.c = *s.clone();
                        hold = self.c.clone();
                    }
                    _ => {
                        self.c = self.c.add_ref(&*b);
                        hold = self.c.clone();
                    }
                }
                if hold.less_or_equal_ref(&e).to_bool_unwrap() {
                    Some(hold)
                } else {
                    None
                }
            }
            N => None,
        }
    }
}

impl IntoIterator for V {
    type Item = V;
    type IntoIter = VI;

    fn into_iter(self) -> Self::IntoIter {
        VI {
            v: self,
            i: 0,
            c: N,
        }
    }
}
