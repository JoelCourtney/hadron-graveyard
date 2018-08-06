use regex::Regex;
use super::ast::{Lexeme,BOP,UOP};

pub fn lex(code: String) -> Vec<Lexeme> {
    let mut lexemes = Vec::new();
    let l = code.len();
    let chars = code.chars().collect::<Vec<_>>();
    let mut i = 0;
    while i < l {
        let mut choice = Lexeme::None;
        let c = chars.get(i).unwrap();
        if c.is_whitespace() {
            if c == &'\n' {
                let prev = lexemes.last();
                if prev != Some(&Lexeme::NewLine) {
                    choice = Lexeme::NewLine;
                }
            }
            i += 1;
        } else if c.is_alphabetic() || c == &'_' {
            let string = get_handle_string(&code[i..]);
            i += string.len();
            choice = match string {
                "is" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::Is)
                        }
                        _ => Lexeme::BinaryOp(BOP::Is)
                    }
                }
                "isnt" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::Isnt)
                        }
                        _ => Lexeme::BinaryOp(BOP::Isnt)
                    }
                }
                "and" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::And)
                        }
                        _ => Lexeme::BinaryOp(BOP::And)
                    }
                }
                "nand" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::NAnd)
                        }
                        _ => Lexeme::BinaryOp(BOP::NAnd)
                    }
                }
                "or" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::Or)
                        }
                        _ => Lexeme::BinaryOp(BOP::Or)
                    }
                }
                "nor" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::NOr)
                        }
                        _ => Lexeme::BinaryOp(BOP::NOr)
                    }
                }
                "xor" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::XOr)
                        }
                        _ => Lexeme::BinaryOp(BOP::XOr)
                    }
                }
                "not" => {
                    Lexeme::UnaryOp(UOP::Not)
                }
                "mod" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::AssignOp(BOP::Modulus)
                        }
                        _ => Lexeme::BinaryOp(BOP::Modulus)
                    }
                }
                "if" => Lexeme::If,
                "elseif" => Lexeme::ElseIf,
                "else" => Lexeme::Else,
                "for" => Lexeme::For,
                "as" => Lexeme::As,
                "at" => Lexeme::At,
                "while" => Lexeme::While,
                "print" => Lexeme::Print,
                "var" => Lexeme::Var,
                "val" => Lexeme::Val,
                "sym" => Lexeme::Sym,
                "fn" => Lexeme::Func,
                _ => Lexeme::Handle(String::from(string))
            }
        } else if c.is_numeric() {
            let (num,len) = get_number_token(&code[i..]);
            i += len;
            choice = num;
        } else if c == &'\'' {
            let string = get_string_squote(&code[i+1..]);
            i += string.len() + 2;
            choice = Lexeme::StringLiteral(String::from(string));
        } else if c == &'"' {
            let string = get_string_dquote(&code[i+1..]);
            i += string.len() + 2;
            choice = Lexeme::StringLiteral(String::from(string));
        } else {
            match c {
                '+' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::AssignOp(BOP::Plus);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(BOP::Plus);
                            i += 1;
                        }
                    }
                }
                '-' => {
                    let prev = lexemes.last();
                    match prev {
                        Some(Lexeme::Handle(_)) | Some(Lexeme::CParen) => {
                            let next = chars.get(i+1);
                            match next {
                                Some('>') => {
                                    choice = Lexeme::RightArrow;
                                    i += 2;
                                }
                                Some('=') => {
                                    choice = Lexeme::AssignOp(BOP::Minus);
                                    i += 2;
                                }
                                _ => {
                                    choice = Lexeme::BinaryOp(BOP::Minus);
                                    i += 1;
                                }
                            }
                        }
                        Some(Lexeme::Number(_)) | Some(Lexeme::CBrace) 
                            | Some(Lexeme::CBraket) => {
                                choice = Lexeme::BinaryOp(BOP::Minus);
                                i += 1;
                            }
                        _ => {
                            choice = Lexeme::UnaryOp(UOP::Negate);
                            i += 1;
                        }
                    }
                }
                '*' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::AssignOp(BOP::Times);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(BOP::Times);
                            i += 1;
                        }
                    }
                }
                '/' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('/') => {
                            i += 2;
                            while chars.get(i) != Some(&'\n') && i < l {
                                i += 1;
                            }
                        }
                        Some('=') => {
                            choice = Lexeme::AssignOp(BOP::Divide);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(BOP::Divide);
                            i += 1;
                        }
                    }
                }
                '^' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::AssignOp(BOP::Power);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(BOP::Power);
                            i += 1;
                        }
                    }
                }
                '.' => {
                    let n1 = chars.get(i+1);
                    let n2 = chars.get(i+2);
                    match (n1, n2) {
                        (Some('*'),Some('=')) => {
                            choice = Lexeme::AssignOp(BOP::ElemTimes);
                            i += 3;
                        }
                        (Some('*'),_) => {
                            choice = Lexeme::BinaryOp(BOP::ElemTimes);
                            i += 2;
                        }
                        (Some('/'),Some('=')) => {
                            choice = Lexeme::AssignOp(BOP::ElemDivide);
                            i += 3;
                        }
                        (Some('/'),_) => {
                            choice = Lexeme::BinaryOp(BOP::ElemDivide);
                            i += 2;
                        }
                        (Some('^'),Some('=')) => {
                            choice = Lexeme::AssignOp(BOP::ElemPower);
                            i += 3;
                        }
                        (Some('^'),_) => {
                            choice = Lexeme::BinaryOp(BOP::ElemPower);
                            i += 2;
                        }
                        (_,_) => {
                            choice = Lexeme::Dot;
                            i += 1;
                        }
                    }
                }
                '#' => {
                    choice = Lexeme::UnaryOp(UOP::Size);
                    i += 1;
                }
                '$' => {
                    choice = Lexeme::UnaryOp(UOP::Shape);
                    i += 1;
                }
                '=' => {
                    choice = Lexeme::Assign;
                    i += 1;
                }
                '(' => {
                    let prev = lexemes.last();
                    match prev {
                        Some(Lexeme::Func)
                            | Some(Lexeme::Handle(_))
                            | Some(Lexeme::CParen)
                            | Some(Lexeme::CBrace) => {
                                choice = Lexeme::OArgList;
                            }
                        _ => {
                            if is_list(&chars, i) {
                                choice = Lexeme::OMatrix;
                            } else {
                                choice = Lexeme::OParen;
                            }
                        }
                    }
                    i += 1;
                }
                '[' => {
                    let prev = lexemes.last();
                    match prev {
                        Some(Lexeme::Number(_))
                            | Some(Lexeme::CParen)
                            | Some(Lexeme::BinaryOp(BOP::StripUnit))
                            | Some(Lexeme::BinaryOp(BOP::ConcatUnit))
                            | Some(Lexeme::BinaryOp(BOP::Convert)) => {
                                choice = Lexeme::OUnit;
                            }
                        _ => {
                            choice = Lexeme::OList;
                        }
                    }
                    i += 1;
                }
                '{' => {
                    choice = Lexeme::OScope;
                    i += 1;
                }
                ')' => {
                    choice = Lexeme::CParen;
                    i += 1;
                }
                ']' => {
                    choice = Lexeme::CBraket;
                    i += 1;
                }
                '}' => {
                    choice = Lexeme::CBrace;
                    i += 1;
                }
                '<' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::BinaryOp(BOP::LessOrEqual);
                            i += 2;
                        }
                        Some('-') => {
                            let prev = lexemes.last();
                            match prev {
                                Some(Lexeme::NewLine) | Some(Lexeme::Semicolon) => {
                                    choice = Lexeme::LeftArrow;
                                    i += 2;
                                }
                                _ => {
                                    choice = Lexeme::BinaryOp(BOP::Less);
                                    i += 1;
                                }
                            }
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(BOP::Less);
                            i += 1;
                        }
                    }
                }
                '>' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::BinaryOp(BOP::GreaterOrEqual);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(BOP::Greater);
                            i += 1;
                        }
                    }
                }
                ':' => {
                    choice = Lexeme::BinaryOp(BOP::Range);
                    i += 1;
                }
                ',' => {
                    choice = Lexeme::Comma;
                    i += 1;
                }
                ';' => {
                    choice = Lexeme::Semicolon;
                    i += 1;
                }
                '&' => {
                    choice = Lexeme::BinaryOp(BOP::ConcatUnit);
                    i += 1;
                }
                '@' => {
                    choice = Lexeme::BinaryOp(BOP::StripUnit);
                    i += 1;
                }
                '~' => {
                    choice = Lexeme::BinaryOp(BOP::Convert);
                    i += 1;
                }
                '|' => {
                    choice = Lexeme::Pipe;
                    i += 1;
                }
                '?' => {
                    choice = Lexeme::Question;
                    i += 1;
                }
                _ => {
                    panic!("Unexpected character in code: {}", c);
                }
            }
        }
        if choice != Lexeme::None {
            lexemes.push(choice);
        }
    }
    lexemes
}

lazy_static! {
    static ref INTEGER_FORM: Regex =
        Regex::new(r"[[:digit:]]+").unwrap();
    static ref FLOAT_FORM: Regex =
        Regex::new(r"([[:digit:]]+\.[[:digit:]]*)|([[:digit:]]*\.[[:digit:]]+)").unwrap();
    static ref SCIENTIFIC_FORM: Regex =
        Regex::new(r"[[:digit:]]+(\.[[:digit:]]*)?e[[:digit:]]+").unwrap();
    static ref HANDLE_FORM: Regex =
        Regex::new(r"[[:alpha:]_][[:word:]]*").unwrap();
}

fn get_handle_string(state: &str) -> &str {
    let loc = HANDLE_FORM.find(state).unwrap();
    if loc.start() != 0 {
        panic!("Failed to parse token!\n{}",state);
    }
    &state[..loc.end()]
}

fn get_number_token(state: &str) -> (Lexeme, usize) {
    let scientific = SCIENTIFIC_FORM.find(&state);
    match scientific {
        Some(inst) => {
            if inst.start() == 0 {
                let len = inst.end();
                let mut s = String::from(&state[..inst.end()]);
                return (Lexeme::Number(s.parse::<f64>().unwrap()),len);
            }
        }
        None => {}
    }
    let float = FLOAT_FORM.find(&state);
    match float {
        Some(inst) => {
            if inst.start() == 0 {
                let len = inst.end();
                let mut s = String::from(&state[..inst.end()]);
                return (Lexeme::Number(s.parse::<f64>().unwrap()),len);
            }
        }
        None => {}
    }
    let int = INTEGER_FORM.find(&state);
    match int {
        Some(inst) => {
            if inst.start() == 0 {
                let len = inst.end();
                let mut s = String::from(&state[..inst.end()]);
                return (Lexeme::Number(s.parse::<f64>().unwrap()),len);
            }
        }
        None => {}
    }
    panic!(format!("Number parsing failed!\n{}",state));
}

fn get_string_dquote(state: &str) -> &str {
    let loc = state.find('"').unwrap();
    &state[..loc]
}

fn get_string_squote(state: &str) -> &str {
    let loc = state.find('\'').unwrap();
    &state[..loc]
}

fn is_list(chars: &(Vec<char>), i: usize) -> bool {
    let mut level = 1;
    let mut cursor: usize = i;
    let mut list = false;
    while level > 0 {
        cursor += 1;
        let c = chars.get(cursor);
        match c {
            Some('(') | Some('[') | Some('{') => {
                level += 1;
            }
            Some(')') | Some(']') | Some('}') => {
                level -= 1;
            }
            Some(',') | Some(';') => {
                if level == 1 {
                    list = true;
                }
            }
            _ => {}
        }
    }
    list
}
