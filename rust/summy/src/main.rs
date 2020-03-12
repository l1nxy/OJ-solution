fn main() {
    println!("{}",summy("0    0"));
}

fn summy(strng: &str) -> i32 {
    strng.split_whitespace().map(|a| a.parse().unwrap_or(0)).sum()
}

#[test]
fn sample_tests() {
    assert_eq!(summy("1 2 3"), 6);
    assert_eq!(summy("1 2 3 4"), 10);
    assert_eq!(summy("1 2 3 4 5"), 15);
    assert_eq!(summy("10 10"), 20);
    assert_eq!(summy("0 0"), 0);
}