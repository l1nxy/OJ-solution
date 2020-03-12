// Preloaded:
//

use std::collections::HashMap;

struct MorseDecoder {
    morse_code: HashMap<String, String>,
}
//
// MorseDecoder::new() populates the morse_code map, e.g. ".-" -> "A".


impl MorseDecoder {
    fn decode_morse(&self, encoded: &str) -> String {
        let mut new_str = encoded.to_string();
        new_str.trim();

        let v1:Vec<Vec<&str>> = new_str.split("   ").collect::<Vec<&str>>()
            .iter().map(|a| a.split(" ").collect::<Vec<&str>>().iter().map(|a| self.morse_code.get(a)).collect::<Vec<&str>>()).collect();

        let mut ret = String::new();
        for i in v1{
            ret.push_str(i.join("").as_str());
            ret.push(' ');
        }

        ret.trim_end();
        ret
    }

//    fn new(&self)
//    {
//        let v = HashMap::from();
//        self.morse_code = HashMap::
//    }
}

fn decode_morse(encoded: &str) -> String {
//    if encoded.is_empty() {
//        return "".to_string();
//    }
//    let mut start = 0usize;
//    let mut ret = String::new();
//    while encoded.chars().nth(start) == Some(' ') {
//        start += 1;
//    }
//    let mut end = encoded.len();
//    while encoded.chars().nth(end) == Some(' ') {
//        end -= 1;
//    }
//
//
//    let new_str = encoded[start..end].to_string();
//
//
//    let v :Vec<&str>= new_str.split("   ").collect();
//    let v1 = v.iter().map(|&a| a.split(" ").collect::<Vec<&str>>()).collect::<Vec<Vec<&str>>>();
//    for i in v1{
//        for j in i{
//            if self. { }
//        }
//    }
//    let mut ret = String::new();
//    for i in v1 {
//        ret.push_str(i.join("").as_str());
//        ret.push(' ');
//    }
//
//    println!("{}",ret);
//
//
//    ret
}

fn main() {
    decode_morse("  .... . -.--   .--- ..- -.. .   ");
    println!("Hello, world!");
}


#[test]
fn test_hey_jude() {
    let decoder = MorseDecoder::new();
    assert_eq!(decoder.decode_morse(".... . -.--   .--- ..- -.. ."), "HEY JUDE");
}