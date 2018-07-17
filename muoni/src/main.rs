extern crate regex;

#[macro_use]
extern crate lazy_static;

use std::env;
use std::fs::File;
use std::io::prelude::*;

mod ast;
mod values;
mod lexer;
//mod parser;

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
    println!("{:?}",lexemes);

//    let asts = parser::parse(lexemes);
}
