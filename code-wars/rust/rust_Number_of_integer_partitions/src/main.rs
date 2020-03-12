fn main() {
    println!("{}", partitions(5));

    println!("Hello, world!");
}

fn partitions(n: isize) -> isize { //Solution 1
    let len = n as usize;
    let mut v = vec![0isize; len+1];
    v[0] = 1;
    for i in 1usize..len+1 {
        for j in i..len+1 {i
            v[j] += v[j - i];
        }
    }
    for i in &v{
        print!("{} ",i);
    }
    v[len]
}

//fn partitions(n: isize) -> isize {//DP Solution 2
//    let len = n as usize;
//    let mut v = vec![vec![0isize; len + 1]; len + 1];
//    for n in 0..len+1 {
//        for k in 0..len+1{
//            if n == 0 || k == 0 { v[n][k] = 0; }
//            else if n == 1 || k == 1 { v[n][k] = 1; }
//            else if n < k { v[n][k] = v[n][n]; }
//            else if n == k { v[n][k] = v[n][k - 1] + 1; }
//            else { v[n][k] = v[n][k - 1] + v[n - k][k]; }
//        }
//    }
//    v[len][len]
//}

#[test]
fn basic_test_01() {
    assert_eq!(partitions(1), 1);
}

#[test]
fn basic_test_05() {
    assert_eq!(partitions(5), 7);
}

#[test]
fn basic_test_10() {
    assert_eq!(partitions(10), 42);
}

#[test]
fn basic_test_25() {
    assert_eq!(partitions(25), 1958);
}
