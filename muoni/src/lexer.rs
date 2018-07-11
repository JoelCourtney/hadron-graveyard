use regex::Regex;

#[derive(Debug)]
#[derive(PartialEq)]
#[allow(dead_code)]
pub enum Lexeme {
    Plus,
    Dash,
    Star,
    Slash,
    Carrot,
    Equals,
    Mod,
    Pipe,
    Hash,
    Bang,
    And,
    Nand,
    Or,
    Nor,
    Xor,
    NXor,
    Not,
    Is,
    Isnt,
    If,
    For,
    As,
    At,
    In,
    While,
    Print,
    OParen,
    CParen,
    OBraket,
    CBraket,
    OBrace,
    CBrace,
    OHairpin,
    CHairpin,
    Colon,
    Separator,
    Comma,
    SQuote,
    DQuote,
    Backtick,
    Number(f64),
    Handle(String),
    StringLiteral(String),
    Indent(i32),
} 

enum IndentTypes {
    Tab,
    Space,
    Unknown,
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
                    "is" => Lexeme::Is,
                    "isnt" => Lexeme::Isnt,
                    "and" => Lexeme::And,
                    "nand" => Lexeme::Nand,
                    "or" => Lexeme::Or,
                    "nor" => Lexeme::Nor,
                    "xor" => Lexeme::Xor,
                    "nxor" => Lexeme::NXor,
                    "not" => Lexeme::Not,
                    "mod" => Lexeme::Mod,
                    "if" => Lexeme::If,
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
            let token = match c {
                '+' => Lexeme::Plus,
                '-' => Lexeme::Dash,
                '*' => Lexeme::Star,
                '/' => Lexeme::Slash,
                '^' => Lexeme::Carrot,
                '#' => Lexeme::Hash,
                '!' => Lexeme::Bang,
                '=' => Lexeme::Equals,
                '(' => Lexeme::OParen,
                ')' => Lexeme::CParen,
                '[' => Lexeme::OBraket,
                ']' => Lexeme::CBraket,
                '{' => Lexeme::OBrace,
                '}' => Lexeme::CBrace,
                '<' => Lexeme::OHairpin,
                '>' => Lexeme::CHairpin,
                ':' => Lexeme::Colon,
                ';' => Lexeme::Separator,
                ',' => Lexeme::Comma,
                '|' => Lexeme::Pipe,
                _ => panic!("Unexpected character in code: {}", c),
            };
            lexemes.push(token);
            i += 1;
        }
    }
    lexemes
}

lazy_static! {
    static ref INTEGER_FORM: Regex =
        Regex::new(r"[[:digit:]]+").unwrap();
    static ref FLOAT_FORM: Regex =
        Regex::new(r"[[:digit:]]+\.[[:digit:]]*").unwrap();
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
