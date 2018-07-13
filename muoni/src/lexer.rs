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
    NewLine,
    Dot,
    Number(f64),
    Handle(String),
    StringLiteral(String),
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
    OUnit,
    OList,
    CParen,
    CBraket,
    CBrace,
    Print,
    None,
} 

#[derive(Debug)]
#[derive(PartialEq)]
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
    NotEquals,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
}

#[derive(Debug)]
#[derive(PartialEq)]
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
        let mut choice = Lexeme::None;
        let c = chars.get(i).unwrap();
        if c.is_whitespace() {
            if c == &'\n' {
                choice = Lexeme::NewLine;
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
                            Lexeme::BinaryOp(Binary::IsEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::Is)
                    }
                }
                "isnt" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::IsntEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::Isnt)
                    }
                }
                "and" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::AndEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::And)
                    }
                }
                "nand" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::NAndEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::NAnd)
                    }
                }
                "or" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::OrEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::Or)
                    }
                }
                "nor" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::NOrEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::NOr)
                    }
                }
                "xor" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::XOrEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::XOr)
                    }
                }
                "not" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::NotEquals)
                        }
                        _ => Lexeme::UnaryOp(Unary::Not)
                    }
                }
                "mod" => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            i += 1;
                            Lexeme::BinaryOp(Binary::ModEquals)
                        }
                        _ => Lexeme::BinaryOp(Binary::Mod)
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
                            choice = Lexeme::BinaryOp(Binary::PlusEquals);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(Binary::Plus);
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
                                    choice = Lexeme::BinaryOp(Binary::MinusEquals);
                                    i += 2;
                                }
                                _ => {
                                    choice = Lexeme::BinaryOp(Binary::Minus);
                                    i += 1;
                                }
                            }
                        }
                        Some(Lexeme::Number(_)) | Some(Lexeme::CBrace) 
                            | Some(Lexeme::CBraket) => {
                                choice = Lexeme::BinaryOp(Binary::Minus);
                                i += 1;
                            }
                        _ => {
                            choice = Lexeme::UnaryOp(Unary::Negate);
                            i += 1;
                        }
                    }
                }
                '*' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::BinaryOp(Binary::TimesEquals);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(Binary::Times);
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
                            choice = Lexeme::BinaryOp(Binary::DivideEquals);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(Binary::Divide);
                            i += 1;
                        }
                    }
                }
                '^' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::BinaryOp(Binary::PowerEquals);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(Binary::Power);
                            i += 1;
                        }
                    }
                }
                '.' => {
                    let n1 = chars.get(i+1);
                    let n2 = chars.get(i+2);
                    match (n1, n2) {
                        (Some('*'),Some('=')) => {
                            choice = Lexeme::BinaryOp(Binary::DotTimesEquals);
                            i += 3;
                        }
                        (Some('*'),_) => {
                            choice = Lexeme::BinaryOp(Binary::DotTimes);
                            i += 2;
                        }
                        (Some('/'),Some('=')) => {
                            choice = Lexeme::BinaryOp(Binary::DotDivideEquals);
                            i += 3;
                        }
                        (Some('/'),_) => {
                            choice = Lexeme::BinaryOp(Binary::DotDivide);
                            i += 2;
                        }
                        (Some('^'),Some('=')) => {
                            choice = Lexeme::BinaryOp(Binary::DotPowerEquals);
                            i += 3;
                        }
                        (Some('^'),_) => {
                            choice = Lexeme::BinaryOp(Binary::DotPower);
                            i += 2;
                        }
                        (_,_) => {
                            choice = Lexeme::Dot;
                            i += 1;
                        }
                    }
                }
                '#' => {
                    choice = Lexeme::UnaryOp(Unary::Cardinality);
                    i += 1;
                }
                '!' => {
                    choice = Lexeme::UnaryOp(Unary::Factorial);
                    i += 1;
                }
                '=' => {
                    choice = Lexeme::Assign;
                    i += 1;
                }
                '(' => {
                    let prev = lexemes.last();
                    match prev {
                        Some(Lexeme::Handle(_)) => {
                            choice = Lexeme::OArgList;
                            i += 1;
                        }
                        _ => {
                            if is_range(&chars, i) {
                                choice = Lexeme::ORangeEx;
                            } else {
                                choice = Lexeme::OMatrix;
                            }
                            i += 1;
                        }
                    }
                }
                '[' => {
                    if is_range(&chars, i) {
                        choice = Lexeme::ORangeIn;
                    } else {
                        choice = Lexeme::OUnit;
                    }
                    i += 1;
                }
                '{' => {
                    if is_list(&chars, i) {
                        choice = Lexeme::OList;
                    } else {
                        choice = Lexeme::OScope;
                    }
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
                            choice = Lexeme::BinaryOp(Binary::LessOrEqual);
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
                                    choice = Lexeme::BinaryOp(Binary::Less);
                                    i += 1;
                                }
                            }
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(Binary::Less);
                            i += 1;
                        }
                    }
                }
                '>' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::BinaryOp(Binary::GreaterOrEqual);
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::BinaryOp(Binary::Greater);
                            i += 1;
                        }
                    }
                }
                ':' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('=') => {
                            choice = Lexeme::Let;
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::Colon;
                            i += 1;
                        }
                    }
                }
                ',' => {
                    choice = Lexeme::Comma;
                    i += 1;
                }
                ';' => {
                    choice = Lexeme::Semicolon;
                    i += 1;
                }
                '|' => {
                    let next = chars.get(i+1);
                    match next {
                        Some('|') => {
                            let mut cursor = lexemes.len()-1;
                            let mut open = true;
                            while cursor >= 0 {
                                let prev = lexemes.get(cursor).unwrap();
                                match prev {
                                    Lexeme::UnaryOp(Unary::ONorm) => {
                                        open = false;
                                        break;
                                    }
                                    Lexeme::UnaryOp(Unary::CNorm) => {
                                        break;
                                    }
                                    _ => {
                                        cursor -= 1;
                                    }
                                }
                            }
                            if open {
                                choice = Lexeme::UnaryOp(Unary::ONorm);
                            } else {
                                choice = Lexeme::UnaryOp(Unary::CNorm);
                            }
                            i += 2;
                        }
                        _ => {
                            let prev = lexemes.last();
                            match prev {
                                Some(Lexeme::UnaryOp(Unary::CNorm)) | Some(Lexeme::UnaryOp(Unary::CDeterminant)) => {
                                    choice = Lexeme::UnaryOp(Unary::CDeterminant);
                                    i += 1;
                                }
                                Some(Lexeme::UnaryOp(_)) | Some(Lexeme::BinaryOp(_))
                                    | Some(Lexeme::Assign) | Some(Lexeme::Let) => {
                                        choice = Lexeme::UnaryOp(Unary::ODeterminant);
                                        i += 1;
                                    }
                                _ => {
                                    choice = Lexeme::UnaryOp(Unary::CDeterminant);
                                    i += 1;
                                }
                            }
                        }
                    }
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

fn is_range(chars: &(Vec<char>), i: usize) -> bool {
    let mut level = 1;
    let mut cursor: usize = i;
    let mut range = false;
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
            Some(':') => {
                if level == 1 {
                    range = true;
                }
            }
            _ => {}
        }
    }
    range
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
            Some(',') => {
                if level == 1 {
                    list = true;
                }
            }
            _ => {}
        }
    }
    list
}
