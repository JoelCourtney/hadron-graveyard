use super::D;
use super::numeric::NT;

pub enum Types {
    Numeric(Set,Precision,Dimension,Cardinality),
    String,
    Bool,
    List(Option<Vec<Types>>,Cardinality),
    Function(Vec<Types>,Box<Types>),
    Wild,
}

pub type T = Types;

pub enum Set {
    Real,
    Complex,
    Quaternion,
    Octonion,
    Wild,
}

pub enum Dimension {
    Quantity(D),
    Wild,
}

pub enum Precision {
    Integer,
    Float,
    Big,
    Wild,
}

pub enum Cardinality {
    Shape(usize,usize),
    Size(usize),
    Wild,
}

fn range_type(t1: NT, t2: NT) -> NT {
    match t1 {
        NT::RI => {
            match t2 {
                NT::RI | NT::RF | NT::RB | NT::CI | NT::CF | NT::CB => t2,
                _ => panic!("range bounds incompatible.")
            }
        }
        NT
    }
}
