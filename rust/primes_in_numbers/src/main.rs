extern crate rand;


fn main() {
    prime_factors(17 * 17 * 93 * 677);
    println!("Hello, world!");
}

use rand::prelude::*;
use std::collections::HashMap;

//fn prime_factors(n: i64) -> String {
//    let mut number = n;
//    let mut prime_numbers = vec![];
//    let mut factor = 2;
//    let mut cnt;
//    while number > 1 {
//        cnt = 0;
//        while number % factor == 0 {
//            number /= factor;
//            cnt += 1;
//        }
//        if cnt > 0 {
//            if cnt > 1
//                {prime_numbers.push(format!("({}**{})", factor, cnt));}
//                else
//                {prime_numbers.push(format!("({})", factor));}
//        }
//        factor += 1;
//    }
//    prime_numbers.join("")
//}
fn gcd(a: i64, b: i64) -> i64 {
    let mut t = 0i64;
    let mut a = a;
    let mut b = b;
    while b != 0 {
        t = a;
        a = b;
        b = t % b;
    }
    if a >= 0 { return a; }
    return 0 - a;
}


fn mul_mod(a: i64, b: i64, c: i64) -> i64 {
    let mut a = a % c;
    let mut b = b % c;
    let mut ret = 0i64;
    while b != 0 {
        if b & 1 == 1 {
            ret += a;
            ret %= c;
        }
        a <<= 1;
        if a >= c {
            a %= c;
        }
        b >>= 1;
    }
    ret
}

fn speed_mod(a: u64, b: u64, c: u64) -> u64 {
    let mut ans = 1u64;
    let mut a = a;
    let mut b = b;
    a %= c;
    while b != 0 {
        if b & 1 == 1 {
            ans = (ans * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    ans
}


fn is_prime(n: u64) -> bool {
    if n == 2 { return true; }
    if n < 2 || n % 2 == 0 {
        return false;
    }
    if n == 3 {
        return true;
    }

    let mut t = 0u64;
    let mut b = n - 1;
    while b & 1 == 0 {
        t += 1;
        b >>= 1;
    }

    for i in 0..20 {
        let mut rng = thread_rng();
        let a = rng.gen_range(2, n - 1);
        let mut x = speed_mod(a, b, n);
        for i in 0..t {
            let mut y = speed_mod(x, 2, n);
            if y == 1 && x != 1 && x != n - 1 {
                return false;
            } else {
                x = y;
            }
        }
        if x != 1 { return false; } else {
            return true;
        }
    }
    true
}


fn poll_rho(x: i64, c: i64) -> i64 {
    let mut i = 1;
    let mut k = 2u64;
    let mut rng = thread_rng();
    let mut x0: i64 = rng.gen_range(1i64, x);
    let mut y: i64 = x0;
    loop {
        i += 1;
        x0 = (mul_mod(x0, x0, x) + c) % x;
        let d = gcd(((y - x0) as i64).abs(), x);
        if d != 1 && d != x { return d; }
        if y == x0 { return x; }
        if i == k {
            y = x0;
            k += k;
        }
    }
}


fn find(n: i64, k: i64, v: &mut Vec<i64>) {
    if n == 1 { return; }

    if is_prime(n as u64) {
        println!("{}", n);
        v.push(n);
        return;
    } else {
        let mut p = n;
        let mut c = k;
        while p >= n {
            p = poll_rho(p, c);
            c -= 1;
        }
        find(p, k, v);
        find(n / p, k, v);
    }
}


fn prime_factors(n: i64) -> String {
    let mut v: Vec<i64> = Vec::new();
    let mut m: HashMap<i64, i64> = HashMap::new();
    find(n, 11, &mut v);
    v.sort();
    for i in v {
        if !m.contains_key(&i) {
            m.insert(i, 1);
        } else {
            let mut num = 0i64;
            { num = *m.get(&i).unwrap(); };
            m.insert(i, num + 1);
        }
    }
    println!("{:#?}", m);
    let mut v1: Vec<(i64, i64)> = m.iter().map(|(a, b)| (*a, *b)).collect();

    v1.sort_by(|&a, &b| a.0.cmp(&b.0));
    println!("{:?}", v1);
    let mut ret = String::new();
    for i in v1 {
        if i.1 == 1 {
            ret.push_str(format!("({})", i.0).as_str());
        } else {
            ret.push_str(format!("({}**{})", i.0, i.1).as_str());
        }
    }
    ret
}

fn testing(n: i64, exp: &str) -> () {
    assert_eq!(&prime_factors(n), exp)
}

#[test]
fn basics_prime_factors() {
    testing(7775460, "(2**2)(3**3)(5)(7)(11**2)(17)");
    testing(17 * 17 * 93 * 677, "(3)(17**2)(31)(677)");
}
