use regex::Regex;

#[derive(Debug)]
#[derive(PartialEq)]
pub enum Lexeme {
    BinaryOp(Binary),
    UnaryOp(Unary),
    Assign,
    Let,
    RightArrow,
    LeftArrow,
    Colon,
    Comma,
    Semicolon,
    Number(f64),
    Handle(String),
    Unit(String),
    StringLiteral(String),
    Range(bool, bool, f64, f64, f64),
    If,
    ElseIf,
    Else,
    While,
    For,
    As,
    At,
    OArgList,
    OScope,
    OMatrix,
    ORangeIn,
    ORangeEx,
    OList,
    CParen,
    CBraket,
    CBrace,
    Print,
} 

pub enum Binary {
    Plus,
    PlusEquals,
    Minus,
    MinusEquals,
    Times,
    TimesEquals,
    DotTimes,
    DotTimesEquals,
    Divide,
    DivideEquals,
    DotDivide,
    DotDivideEquals,
    Power,
    PowerEquals,
    DotPower,
    DotPowerEquals,
    Mod,
    ModEquals,
    And,
    AndEquals,
    NAnd,
    NAndEquals,
    Or,
    OrEquals,
    NOr,
    NOrEquals,
    XOr,
    XOrEquals,
    Is,
    IsEquals,
    Isnt,
    IsntEquals,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
}

pub enum Unary {
    Negate,
    Factorial,
    ONorm,
    CNorm,
    ODeterminant,
    CDeterminant,
    Cardinality,
    Not,
}

pub fn lex(code: String) -> Vec<Lexeme> {
    let mut lexemes = Vec::new();
    let l = code.len();
    let chars = code.chars().collect::<Vec<_>>();
    let mut i = 0;
    while i < l {
        let c = chars.get(i).unwrap();
        if c.is_whitespace() {
            if c == &'\n' {
                lexemes.push(Lexeme::Separator);
            }
            i += 1;
        } else if c.is_alphabetic() || c == &'_' {
            let string = get_handle_string(&code[i..]);
            i += string.len();
            lexemes.push(
                match string {
                    "is" => Lexeme::BinaryOp(Binary::Is),
                    "isnt" => Lexeme::BinaryOp(Binary::Isnt),
                    "and" => Lexeme::BinaryOp(Binary::And),
                    "nand" => Lexeme::BinaryOp(Binary::NAnd),
                    "or" => Lexeme::BinaryOp(Binary::Or),
                    "nor" => Lexeme::BinaryOp(Binary::NOr),
                    "xor" => Lexeme::BinaryOp(Binary::Xor),
                    "nxor" => Lexeme::BinaryOp(Binary::NXor),
                    "not" => Lexeme::UnaryOp(Unary::Not),
                    "mod" => Lexeme::BinaryOp(Binary::Mod),
                    "if" => Lexeme::If,
                    "elseif" => Lexeme::ElseIf,
                    "else" => Lexeme::Else,
                    "for" => Lexeme::For,
                    "as" => Lexeme::As,
                    "at" => Lexeme::At,
                    "in" => Lexeme::In,
                    "while" => Lexeme::While,
                    "print" => Lexeme::Print,
                    _ => Lexeme::Handle(String::from(string))
                }
            );
        } else if c.is_numeric() {
            let (num,len) = get_number_token(&code[i..]);
            i += len;
            lexemes.push(num);
        } else if c == &'\'' {
            let string = get_string_squote(&code[i+1..]);
            i += string.len() + 2;
            lexemes.push(Lexeme::StringLiteral(String::from(string)))
        } else if c == &'"' {
            let string = get_string_dquote(&code[i+1..]);
            i += string.len() + 2;
            lexemes.push(Lexeme::StringLiteral(String::from(string)))
        } else {
            match c {
                '+' => {
                    let next = chars.get(i+1);
                    match next {
                        '=' => {
                            lexemes.push(Lexeme::BinaryOp(Binary::PlusEquals));
                            i += 2;
                        }
                        _ => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Plus));
                            i += 1;
                        }
                }
                '-' => {
                    let prev = lexemes.last();
                    match prev {
                        Lexeme::Handle(_) | Lexeme::CArgList => {
                            let next = chars.get(i+1);
                            match next {
                                '>' => {
                                    lexemes.push(Lexeme::RightArrow);
                                    i += 2;
                                }
                                '=' => {
                                    lexemes.push(Lexeme::BinaryOp(Binary::MinusEquals));
                                    i += 2;
                                _ => {
                                    lexemes.push(Lexeme::BinaryOp(Binary::Minus));
                                    i += 1;
                                }
                            }
                        }
                        Lexeme::Number(_) | Lexeme::CMatrix | Lexeme::CScope | Lexeme::CRangeIn
                            | Lexeme::CRangeEx | Lexeme::CList => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Minus));
                            i += 1;
                        }
                        _ => {
                            lexemes.push(Lexeme::UnaryOp(Unary::Negate));
                            i += 1;
                        }
                    }
                }
                '*' => {
                    let next = chars.get(i+1);
                    match next {
                        '=' => {
                            lexemes.push(Lexeme::BinaryOp(Binary::TimesEquals));
                            i += 2;
                        }
                        _ => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Times));
                            i += 1;
                        }
                    }
                }
                '/' => {
                    let next = chars.get(i+1);
                    match next {
                        '/' => {
                            i += 2;
                            while chars.get(i) != &'\n' {
                                i += 1;
                            }
                        }
                        '=' => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DivideEquals));
                            i += 2;
                        _ => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Divide));
                            i += 1;
                        }
                    }
                }
                '^' => {
                    let next = chars.get(i+1);
                    match next {
                        '=' => {
                            lexemes.push(Lexeme::BinaryOp(Binary::PowerEquals));
                            i += 2;
                        }
                        _ => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Power));
                            i += 1;
                        }
                    }
                }
                '.' => {
                    let n1 = chars.get(i+1);
                    let n2 = chars.get(i+2);
                    match (n1, n2) {
                        ('*','=') => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DotTimesEquals));
                            i += 3;
                        }
                        ('*',_) => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DotTimes));
                            i += 2;
                        }
                        ('/','=') => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DotDivideEquals));
                            i += 3;
                        }
                        ('/',_) => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DotDivide));
                            i += 2;
                        }
                        ('^','=') => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DotPowerEquals));
                            i += 3;
                        }
                        ('^',_) => {
                            lexemes.push(Lexeme::BinaryOp(Binary::DotPower));
                            i += 2;
                        }
                    }
                }
                '#' => {
                    lexemes.push(Lexeme::UnaryOp(Unary::Cardinality));
                    i += 1;
                }
                '!' => {
                    lexemes.push(Lexeme::UnaryOp(Unary::Factorial));
                    i += 1;
                }
                '=' => {
                    lexemes.push(Lexeme::Assign);
                    i += 1;
                }
                '(' => {
                    let prev = lexemes.last();
                    match prev {
                        Lexeme::Handle(_) => {
                            lexemes.push(Lexeme::OArgList);
                            i += 1;
                        }
                        _ => {
                            let mut level = 1;
                            let mut cursor = i;
                            let mut range = false;
                            while level > 0 {
                                cursor += 1;
                                let c = chars.get(cursor);
                                match c {
                                    '(' | '[' | '{' => {
                                        level += 1;
                                    }
                                    ')' | ']' | '}' => {
                                        level -= 1;
                                    }
                                    ':' => {
                                        if level == 1 {
                                            range = true;
                                        }
                                    }
                                }
                            }
                            if range {
                                lexemes.push(Lexemes::ORangeEx);
                                i += 1;
                            } else {
                                let close = chars.get(cursor);
                                match close {
                                    ')' => {
                                        lexemes.push(Lexemes::CMatrix);
                                        i += 1;
                                    }
                                    _ => {
                                        panic!("Expected close parenthesis!");
                                    }
                                }
                            }
                        }
                    }
                }
                ')' => {
                    lexemes.push(Lexeme::CParen);
                    i += 1;
                }
                ']' => {
                    lexemes.push(Lexeme::CBraket);
                    i += 1;
                }
                '}' => {
                    lexemes.push(Lexeme::CBrace);
                    i += 1;
                }
                '<' => {
                    let next = chars.get(i+1);
                    match next {
                        '=' => {
                            lexemes.push(Lexeme::BinaryOp(Binary::LessOrEqual));
                            i += 2;
                        }
                        _ => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Less));
                            i += 1;
                        }
                    }
                }
                '>' => {
                    let next = chars.get(i+1);
                    match next {
                        '=' => {
                            lexemes.push(Lexeme::BinaryOp(Binary::GreaterOrEqual));
                            i += 2;
                        }
                        _ => {
                            lexemes.push(Lexeme::BinaryOp(Binary::Greater));
                            i += 1;
                        }
                    }
                }
                ':' => {
                    lexemes.push(Lexeme::Colon);
                    i += 1;
                }
                ',' => {
                    lexemes.push(Lexeme::Comma);
                    i += 1;
                }
                ';' => Lexeme::Separator,
                '|' => Lexeme::Pipe,
                _ => panic!("Unexpected character in code: {}", c),
            };
        }
    }
    lexemes
}

lazy_static! {
    static ref INTEGER_FORM: Regex =
        Regex::new(r"[[:digit:]]+").unwrap();
    static ref FLOAT_FORM: Regex =
        Regex::new(r"([[:digit:]]*\.[[:digit:]]+ | [[:digit:]]+\.[[:digit:]]*)").unwrap();
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
