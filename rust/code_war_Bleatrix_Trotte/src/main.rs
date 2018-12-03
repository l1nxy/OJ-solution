
use std::collections::HashSet;
fn trotter(n: i32)-> i32{
    let mut num_set = HashSet::new();
    for i in 1u64..{
        let num = n as u64 * i;
        for c in num.to_string().chars(){
            num_set.insert(c);
        }
        if num_set.len() == 10 { return num as i32;}
    }
    -1
}

#[test]
fn returns_expected() {
  assert_eq!(trotter(1692), 5076);
  assert_eq!(trotter(2), 90);
  assert_eq!(trotter(7), 70);
}

fn main() {
    trotter(2);
    println!("Hello, world!");
}
