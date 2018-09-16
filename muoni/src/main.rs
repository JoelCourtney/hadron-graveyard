extern crate regex;
extern crate nalgebra as na;
extern crate num_bigint as nb;
extern crate num_integer as ni;
extern crate num_complex as nc;
extern crate num_traits;
extern crate cpuprofiler;
extern crate time;

#[macro_use]
extern crate lazy_static;

use std::env;
use std::fs::File;
use std::io::prelude::*;
use cpuprofiler::PROFILER;
use time::{PreciseTime,Duration};


mod ast;
mod lexer;
mod parser;
mod interpreter;

use interpreter::value::*;

fn main() {
    let args: Vec<String> = env::args().collect();
    let filename = args.get(1)
        .expect("Please give a filename.");
    let mut file = File::open(filename)
        .expect("File does not exist");
    let mut code = String::new();
    file.read_to_string(&mut code)
        .expect("error reading file");
    let start = PreciseTime::now();
    PROFILER.lock().unwrap().start("./my-prof.profile").unwrap();
    let lexemes = lexer::lex(code);

    let controls = parser::parse(lexemes);

    interpreter::exec::exec(&controls);

    PROFILER.lock().unwrap().stop().unwrap();
    // println!("{:}",start.to(PreciseTime::now()));
}
