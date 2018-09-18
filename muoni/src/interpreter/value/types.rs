use super::D;

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
