fn perimeter(n: u64) -> u64 {
    let mut a: u64 = 1;
    let mut b: u64 = 1;
    let mut c: u64 = 0;
    let mut sum = 0u64;
    for i in 0..n {
        c = a + b;
        a = b;
        b = c;
        sum += a;
    }
    println!("{},{}", a, (sum + 1) * 4);
    (sum + 1) * 4
}


fn main() {
    perimeter(5);
    println!("Hello, world!");
}

fn dotest(n: u64, exp: u64) -> () {
    assert_eq!(perimeter(n), exp)
}

#[test]
fn basics_perimeter() {
    dotest(5, 80);
    dotest(7, 216);
    dotest(20, 114624);
    dotest(30, 14098308);
}
