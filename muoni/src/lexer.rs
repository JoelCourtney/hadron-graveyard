use regex::Regex;
use super::ast::{Lexeme,BOP,UOP,Break};
use std::collections::HashMap;
use std::str;

pub fn lex(code: String) -> Vec<Lexeme> {
    let mut lexemes = Vec::new();
    let chars = code.chars().collect::<Vec<_>>();
    let l = chars.len();
    let mut i = 0;
    let mut diff = 0;
    while i < l {
        let mut choice = Lexeme::None;
        let c = chars.get(i).expect(&format!("{}",i));
        if c.is_whitespace() {
            if c == &'\n' {
                let prev = lexemes.last();
                if prev != Some(&Lexeme::NewLine) {
                    choice = Lexeme::NewLine;
                }
            }
            i += 1;
        } else if c.is_alphabetic() || c == &'_' || c == &'`' {
            let (old,string) = get_handle_string(&code[i+diff..]);
            let hold = old.chars().count();
            i += hold;
            diff += old.len() - hold;
            choice = match &string[..] {
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
                "loop" => Lexeme::Loop,
                "print" => Lexeme::Print,
                "var" => Lexeme::Var,
                "val" => Lexeme::Val,
                "sym" => Lexeme::Sym,
                "drop" => Lexeme::Drop,
                "dimension" => Lexeme::Dimension,
                "fn" => Lexeme::Func,
                "collapse" => Lexeme::Collapse,
                "true" => Lexeme::Bool(true),
                "false" => Lexeme::Bool(false),
                "struct" => Lexeme::Struct,
                "class" => Lexeme::Class,
                "enum" => Lexeme::Enum,
                _ => Lexeme::Handle(String::from(string))
            };
        } else if c.is_numeric() {
            let (num,len) = get_number_token(&code[i+diff..]);
            i += len;
            choice = num;
        } else if c == &'\'' {
            let string = get_string_squote(&code[i+1+diff..]);
            i += string.len() + 2;
            choice = Lexeme::StringLiteral(String::from(string));
        } else if c == &'"' {
            let string = get_string_dquote(&code[i+1+diff..]);
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
                        Some(Lexeme::Handle(_))
                            | Some(Lexeme::CParen)
                            | Some(Lexeme::Integer(_))
                            | Some(Lexeme::Float(_))
                            | Some(Lexeme::CBrace)
                            | Some(Lexeme::CBraket) => {
                            let next = chars.get(i+1);
                            match next {
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
                        (Some(c),_) if c.is_numeric() => {
                            let (num,len) = get_number_token(&code[i+diff..]);
                            choice = num;
                            i += len;
                        }
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
                    match chars.get(i+1) {
                        Some('>') => {
                            choice = Lexeme::RightArrow;
                            i += 2;
                        }
                        _ => {
                            choice = Lexeme::Assign;
                            i += 1;
                        }
                    }
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
                            if is_list(&chars[i..]) {
                                choice = Lexeme::OMatrix;
                            } else {
                                let mut cursor = i + 1;
                                loop {
                                    match chars.get(cursor) {
                                        Some(c) if c.is_whitespace() => {
                                            cursor += 1;
                                        }
                                        Some(')') => {
                                            choice = Lexeme::OMatrix;
                                            break;
                                        }
                                        _ => {
                                            choice = Lexeme::OParen;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    i += 1;
                }
                '[' => {
                    let prev = lexemes.last();
                    match prev {
                        Some(Lexeme::Integer(_))
                            | Some(Lexeme::Float(_))
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
                            match lexemes.last() {
                                Some(Lexeme::NewLine) | Some(Lexeme::Semicolon) => {
                                    i += 1;
                                    let series = get_break_series(&chars[i..]);
                                    i += series.len();
                                    choice = Lexeme::BreakSeries(series);
                                }
                                _ => {
                                    choice = Lexeme::BinaryOp(BOP::LessOrEqual);
                                    i += 2;
                                }
                            }
                        }
                        Some('-') | Some('~') => {
                            let prev = lexemes.last();
                            match prev {
                                Some(Lexeme::NewLine) | Some(Lexeme::Semicolon) => {
                                    i += 1;
                                    let series = get_break_series(&chars[i..]);
                                    i += series.len();
                                    choice = Lexeme::BreakSeries(series);
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
        Regex::new(r"(([[:digit:]]+)|([[:digit:]]+\.[[:digit:]]*)|([[:digit:]]*\.[[:digit:]]+))e[[:digit:]]+").unwrap();
    static ref SCIENTIFIC_SUFFIX_FORM: Regex =
        Regex::new(r"e[[:digit:]]+").unwrap();
    static ref HANDLE_FORM: Regex =
        Regex::new(r"[[:alpha:]_`\p{Greek}][[:word:]`\p{Greek}]*").unwrap();
    static ref GREEK_HASHMAP: HashMap<&'static str,&'static str> = {
        let mut m = HashMap::new();
        m.insert("`alpha`","α");
        m.insert("`Alpha`","Α");
        m.insert("`beta`","β");
        m.insert("`Beta`","Β");
        m.insert("`gamma`","γ");
        m.insert("`Gamma`","Γ");
        m.insert("`delta`","δ");
        m.insert("`Delta`","Δ");
        m.insert("`epsilon`","ε");
        m.insert("`Epsilon`","Ε");
        m.insert("`zeta`","ζ");
        m.insert("`Zeta`","Ζ");
        m.insert("`eta`","η");
        m.insert("`Eta`","Η");
        m.insert("`theta`","θ");
        m.insert("`Theta`","Θ");
        m.insert("`iota`","ι");
        m.insert("`Iota`","Ι");
        m.insert("`kappa`","κ");
        m.insert("`Kappa`","Κ");
        m.insert("`lambda`","λ");
        m.insert("`Lambda`","Λ");
        m.insert("`mu`","μ");
        m.insert("`Mu`","Μ");
        m.insert("`nu`","ν");
        m.insert("`Nu`","Ν");
        m.insert("`xi`","ξ");
        m.insert("`Xi`","Ξ");
        m.insert("`omicron`","ο");
        m.insert("`Omicron`","Ο");
        m.insert("`pi`","π");
        m.insert("`Pi`","Π");
        m.insert("`rho`","ρ");
        m.insert("`Rho`","Ρ");
        m.insert("`sigma`","σ");
        m.insert("`Sigma`","Σ");
        m.insert("`tau`","τ");
        m.insert("`Tau`","Τ");
        m.insert("`upsilon`","υ");
        m.insert("`upsilon`","Υ");
        m.insert("`phi`","φ");
        m.insert("`Phi`","Φ");
        m.insert("`chi`","χ");
        m.insert("`Chi`","Χ");
        m.insert("`psi`","ψ");
        m.insert("`Psi`","Ψ");
        m.insert("`omega`","ω");
        m.insert("`Omega`","Ω");
        m
    };
}

fn get_handle_string(state: &str) -> (&str,String) {
    let loc = HANDLE_FORM.find(state).unwrap();
    if loc.start() != 0 {
        panic!("Failed to parse token!\n{}",&state[0..5]);
    }
    let end = loc.end();
    let mut s = String::from(&state[..end]);
    for (escape,chr) in GREEK_HASHMAP.iter() {
        s = s.replace(escape,chr);
    }
    (&state[..loc.end()],s)
}

fn get_number_token(state: &str) -> (Lexeme, usize) {
    let scientific = SCIENTIFIC_FORM.find(&state);
    match scientific {
        Some(inst) if inst.start() == 0 => {
            let len = inst.end();
            let mut s = String::from(&state[..inst.end()]);
            return (Lexeme::Float(s.parse::<f64>().unwrap()),len);
        }
        _ => {}
    }
    let float = FLOAT_FORM.find(&state);
    match float {
        Some(inst) if inst.start() == 0 => {
            let len = inst.end();
            let mut s = String::from(&state[..inst.end()]);
            match (&state[len..len+1],&state[len+1..len+2]) {
                ("i","e") => {
                    let scientific_suffix = SCIENTIFIC_SUFFIX_FORM.find(&state[len+1..]);
                    match scientific_suffix {
                        Some(suffix) if suffix.start() == len+1 => {
                            s.push_str(&state[len+1..suffix.end()]);
                            return (Lexeme::ImagFloat(s.parse::<f64>().unwrap()),suffix.end())
                        }
                        _ => panic!("unable to parse number"),
                    }
                }
                ("i",_) => {
                    return (Lexeme::ImagFloat(s.parse::<f64>().unwrap()),len+1);
                }
                _ => {
                    return (Lexeme::Float(s.parse::<f64>().unwrap()),len);
                }
            }
        }
        _ => {}
    }
    let int = INTEGER_FORM.find(&state);
    match int {
        Some(inst) if inst.start() == 0 => {
            let len = inst.end();
            let mut s = String::from(&state[..inst.end()]);
            match (&state[len..len+1],&state[len+1..len+2]) {
                ("i","e") => {
                    let scientific_suffix = SCIENTIFIC_SUFFIX_FORM.find(&state[len+1..]);
                    match scientific_suffix {
                        Some(suffix) if suffix.start() == len+1 => {
                            s.push_str(&state[len+1..suffix.end()]);
                            return (Lexeme::ImagFloat(s.parse::<f64>().unwrap()),suffix.end())
                        }
                        _ => panic!("unable to parse number"),
                    }
                }
                ("i",_) => {
                    return (Lexeme::ImagInteger(s.parse::<i64>().unwrap()),len+1);
                }
                _ => {
                    return (Lexeme::Integer(s.parse::<i64>().unwrap()),len);
                }
            }
        }
        _ => {}
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

fn is_list(chars: &[char]) -> bool {
    let mut level = 1;
    let mut cursor: usize = 0;
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
            Some(_) => {}
            None => panic!("expected close paren"),
        }
    }
    list
}

fn get_break_series(chars: &[char]) -> Vec<Break> {
    let mut series = Vec::new();
    let mut i = 0;
    loop {
        match chars.get(i) {
            Some('-') => {
                series.push(Break::Dash);
            }
            Some('~') => {
                series.push(Break::Tilde);
            }
            Some('=') => {
                series.push(Break::Equal);
            }
            _ => {
                return series;
            }
        }
        i += 1;
    }
}
