/**
Let be n an integer prime with 10 e.g. 7.

1/7 = 0.142857 142857 142857 ....

We see that the decimal part has a cycle: 142857. The length of this cycle is 6. In the same way:

1/11 = 0.09 09 09 .... Cycle length is 2.

Task
Given an integer n (n > 1), the function cycle(n) returns the length of the cycle if n and 10 are coprimes, otherwise returns -1.
*/
fn gcd(n: i64, m: i64) -> bool {
    let mut n = n;
    let mut m = m;
    while m != 0 {
        let r = n % m;
        n = m;
        m = r;
    }

    match n {
        1 => true,
        _ => false
    }
}

//fn cycle(n: i64) -> i64 {
//    let org_n = n;
//    let mut n = n;
//    let mut remainder: i64;
//    let divisor = 1;
//    let mut nums: Vec<i64> = Vec::new();
//    let mut loop_count = 0i64;
//    if gcd(std::cmp::max(10, n), std::cmp::min(10, n)) == false {
//        return -1;
//    }
//
//    while n % 2 == 0 {
//        n /= 2;
//    }
//    while n % 5 == 0 {
//        n /= 5;
//    }
//    remainder = divisor % n;
//    while remainder != 0 {
//        if nums.contains(&remainder) {//进入循环节
//            return nums.len() as i64;
//        } else {
//            nums.push(remainder);
//        }
//        loop_count += 1;
//        remainder *= 10;
//        remainder %= n;
//
//        if loop_count == org_n
//            {
//                return -1;
//            }
//    }
//    -1
//}


fn cycle(n: i64) -> i64 {
    if gcd(std::cmp::max(n, 10), std::cmp::min(10, n)) == false {
        return -1;
    }
    let mut n = n;

    while n % 2 == 0 {
        n /= 2;
    }

    while n % 5 == 0 {
        n /= 5;
    }


    //let mut b = e;

//    for e in 1.. {
//        let mut ret = 1i64;
//        let mut a = 10;
//        let mut b = e;
//        while b > 0 {
//            if b & 1 == 1 {
//                ret = ret * a % n;
//            }
//            a = a * a % n;
//            b >>= 1;
//        }
//        if ret == 1 {
//            return e;
//        }
//    }

    let mut var = 1i64;
    for i in 1.. {
        var = var * 10 % n;
        if var == 1 { return i; }
    }
    -1
}

fn dotest(n: i64, exp: i64) -> () {
    let ans = cycle(n);
    assert_eq!(ans, exp)
}

#[test]
fn basic_tests() {
    dotest(33, 2);
    dotest(18118, -1);
    dotest(69, 22);
    dotest(197, 98);
    dotest(65, -1);
}

fn main() {
    println!("m % n ：{}", (1 % 3));
    dotest(33, 2);
    dotest(18118, -1);
    dotest(69, 22);
    dotest(197, 98);
    dotest(65, -1);
    println!("Hello, world!");
}
