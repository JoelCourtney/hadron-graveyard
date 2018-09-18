use interpreter::value::{D,VI,V};
use V::*;
use nc::{Complex,Complex64};
use na::DMatrix;

impl V {
    pub fn add(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                let n3 = n1 + n2;
                let u3 = u1.add(u2);
                RI(n3,u3)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                let n3 = n1 + n2;
                let u3 = u1.add(u2);
                RF(n3,u3)
            }
            (CI(n1,u1),CI(n2,u2)) => {
                let n3 = n1 + n2;
                let u3 = u1.add(u2);
                CI(n3,u3)
            }
            (RI(n1,u1),RF(n2,u2)) | (RF(n2,u2),RI(n1,u1)) => {
                let n3 = (n1 as f64) + n2;
                let u3 = u1.add(u2);
                RF(n3,u3)
            }
            (RI(n1,u1),CI(n2,u2)) | (CI(n2,u2),RI(n1,u1)) => {
                let n3 = Complex::<i64>::from(n1) + n2;
                let u3 = u1.add(u2);
                CI(n3,u3)
            }
            _ => unimplemented!(),
        }
    }
    pub fn add_ref(&self, with: &V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                let n3 = n1 + n2;
                if !u1.equal(u2) {
                    panic!("units in addition are not equal");
                }
                RI(n3,u1.clone())
            }
            (RF(n1,u1),RF(n2,u2)) => {
                let n3 = n1 + n2;
                if !u1.equal(u2) {
                    panic!("units in addition are not equal");
                }
                RF(n3,u1.clone())
            }
            _ => {
                panic!("failed to {:?} + {:?}",self,with);
            }
        }
    }
    pub fn sub(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                let n3 = n1 - n2;
                let u3 = u1.add(u2);
                RI(n3,u3)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                let n3 = n1 - n2;
                let u3 = u1.add(u2);
                RF(n3,u3)
            }
            _ => unimplemented!(),
        }
    }
    pub fn times(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                let n3 = n1 * n2;
                let u3 = u1.multiply(u2);
                RI(n3,u3)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                let n3 = n1 * n2;
                let u3 = u1.multiply(u2);
                RF(n3,u3)
            }
            (RI(n1,u1),RF(n2,u2)) | (RF(n2,u2),RI(n1,u1)) => {
                let n3 = (n1 as f64) * n2;
                let u3 = u1.multiply(u2);
                RF(n3,u3)
            }
            _ => unimplemented!(),
        }
    }
    pub fn divide(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                let n3 = n1 / n2;
                let u3 = u1.divide(u2);
                RI(n3,u3)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                let n3 = n1 / n2;
                let u3 = u1.divide(u2);
                RF(n3,u3)
            }
            (RI(n1,u1),RF(n2,u2)) | (RF(n2,u2),RI(n1,u1)) => {
                let n3 = (n1 as f64) / n2;
                let u3 = u1.divide(u2);
                RF(n3,u3)
            }
            _ => unimplemented!(),
        }
    }
    pub fn less_or_equal_ref(&self, with: &V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                if !u1.equal(u2) {
                    panic!("cannot compare different units");
                }
                B(n1 <= n2)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                if !u1.equal(u2) {
                    panic!("cannot compare different units");
                }
                B(n1 <= n2)
            }
            _ => {
                panic!("failed to {:?} &<= {:?}",self,with);
            }
        }
    }
    pub fn is(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                if !u1.equal(&u2) {
                    panic!("cannot compare different units");
                }
                B(n1 == n2)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                if !u1.equal(&u2) {
                    panic!("cannot compare different units");
                }
                B(n1 == n2)
            }
            _ => unimplemented!(),
        }
    }
    pub fn less(self, with: V) -> Self {
        match (self,with) {
            (RI(n1,u1),RI(n2,u2)) => {
                if !u1.equal(&u2) {
                    panic!("cannot compare different units");
                }
                B(n1 < n2)
            }
            (RF(n1,u1),RF(n2,u2)) => {
                if !u1.equal(&u2) {
                    panic!("cannot compare different units");
                }
                B(n1 < n2)
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
            RM(ref m, ref u) => {
                match m.data.get(self.i) {
                    Some(n) => {
                        self.i += 1;
                        Some(RF(*n,u.clone()))
                    }
                    None => None,
                }
            }
            CM(ref m, ref u) => {
                match m.data.get(self.i) {
                    Some(n) => {
                        self.i += 1;
                        Some(CF(*n,u.clone()))
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
