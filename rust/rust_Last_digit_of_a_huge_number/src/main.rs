fn main() {
    println!("Hello, world!");
}

fn cal_n(n: u64) -> i32 {
    if n < 4 {
        n as i32
    } else {
        (n % 4 + 4) as i32
    }
}

fn last_digit(lst: &[u64]) -> u64 {
    let mut n = 1u64;
    for i in lst.iter().rev() {
        let x = if *i >= 1000 { *i % 100 } else { *i };
        n = (x as f64).powi(if n < 4 {
            n as i32
        } else {
            (n % 4 + 4) as i32
        }) as u64;
    }
    n % 10
}

#[test]
fn basic_tests() {
    let tests = vec![
        (vec![], 1),
        (vec![0, 0], 1),
        (vec![0, 0, 0], 0),
        (vec![1, 2], 1),
        (vec![3, 4, 5], 1),
        (vec![4, 3, 6], 4),
        (vec![7, 6, 21], 1),
        (vec![12, 30, 21], 6),
        (vec![2, 2, 2, 0], 4),
        (vec![937640, 767456, 981242], 0),
        (vec![123232, 694022, 140249], 6),
        (vec![499942, 898102, 846073], 6)
    ];

    for test in tests {
        assert_eq!(last_digit(&test.0), test.1);
    }
}