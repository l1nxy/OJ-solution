fn main() {
    println!("{}", dont_give_me_five(4, 15));
}

fn is_even(n: i32) -> bool {
    n % 2 == 0
}

use std::collections::HashSet;

fn remove_duplicate_words(s: &str) -> String {
    let v: Vec<&str> = s.split(" ").collect();

    let mut n: Vec<&str> = Vec::new();

    for i in v {
        if !n.contains(&i) {
            n.push(i);
        }
    }

    n.join(" ")
}

//https://www.codewars.com/kata/dont-give-me-five/train/rust
fn dont_give_me_five(start: isize, end: isize) -> isize {
    (start..end + 1).filter(|&a| { !a.to_string().contains('5') }).count() as isize
}

// Rust test example:
#[test]
fn sample_test_cases() {
    assert_eq!(remove_duplicate_words("alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta"), "alpha beta gamma delta");
    assert_eq!(remove_duplicate_words("my cat is my cat fat"), "my cat is fat");
}