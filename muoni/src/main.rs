extern crate regex;

#[macro_use]
extern crate lazy_static;

use std::env;
use std::fs::File;
use std::io::prelude::*;

mod ast;
mod lexer;
mod parser;
mod interpreter;

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
    let asdf = interpreter::value::Value::from(&test);
    test = ast::RValue::Number(6.);
    println!("{:?}",asdf);
    println!("{:?}",test);
}
