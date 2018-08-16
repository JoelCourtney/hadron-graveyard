extern crate regex;
extern crate nalgebra as na;
extern crate num_bigint as ni;
extern crate num_complex as nc;
extern crate num_traits;

#[macro_use]
extern crate lazy_static;

use std::env;
use std::fs::File;
use std::io::prelude::*;

mod ast;
mod lexer;
mod parser;
mod interpreter;

use interpreter::value::{Number::*,Value::*,Unit};
use interpreter::value;

fn main() {
    let args: Vec<String> = env::args().collect();
    let filename = args.get(1)
        .expect("Please give a filename.");
    let mut file = File::open(filename)
        .expect("File does not exist");
    let mut code = String::new();
    file.read_to_string(&mut code)
        .expect("error reading file");

    let lexemes = lexer::lex(code);

    let controls = parser::parse(lexemes);

    let mut test = ast::RValue::Number(5.);
    let asdf = value::Value::from(&test);
    test = ast::RValue::Number(6.);
    println!("{:?}",asdf);
    println!("{:?}",test);
    let test2 = N(RI(i64::max_value()));
    let test3 = N(RI(5));
    let asdf2 = value::add(&test2,&test3);
    println!("{:?}",test2);
    println!("{:?}",test3);
    println!("{:?}",asdf2);
    println!("{:?}",value::add(&(N(RF(5.))),&asdf2));
    println!("{:?}",na::DMatrix::from_element(2,3,5));
}
