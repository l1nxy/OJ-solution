//(see: http://mathworld.wolfram.com/PrimeGaps.html).
//https://www.codewars.com/kata/gap-in-primes/train/rust
//#Ref https://en.wikipedia.org/wiki/Prime_gap


fn generate_prime() -> Vec<u64> {
    let mut prime = vec![0u64; 100001];
    let mut not_prime = vec![0; 100001];
    let mut num_prime = 0usize;
    not_prime[0] = 1;
    not_prime[1] = 1;
    for i in 2..100000 {
        if not_prime[i] == 0 {
            prime[num_prime] = i as u64;
            num_prime += 1;
        }
        for j in 0..num_prime {
            if i * prime[j] as usize > 100000 { break; }

            not_prime[i * prime[j] as usize] = 1;
            if i % prime[j] as usize == 0 {
                break;
            }
        }
    }

    prime
}

fn generate_prime_seg(m: u64, n: u64) -> Vec<u64> {
    let mut prime = vec![true; (n - m + 1) as usize];
    let mut prime_small = vec![true; (n as f64).sqrt() as usize + 1];
    let mut p: Vec<u64> = Vec::new();
    for i in 2..(n as f64).sqrt() as usize {
        if prime_small[i] == true {
            let mut j = 2 * i;
            while j < (n as f64).sqrt() as usize {
                prime_small[j] = false;
                j += i;
            }

            let mut j =std::cmp::max(2u64, (m + i as u64 - 1) / i as u64) *i as u64;
            while j <  n {
                prime[(j-m) as usize] = false;
                j += i as u64;
            }
        }
    }
    for i in 0..(n - m) {
        if prime[i as usize] == true {
            println!("{}", i + m);
            p.push(i + m);
        }
    }
    for i in &p {
        println!("{}", i);
    }
    p
}

fn gap(g: i32, m: u64, n: u64) -> Option<(u64, u64)> {
    let prime = generate_prime_seg(m, n);
    for i in 1..prime.len() {
        if prime[i] - prime[i - 1] == g as u64 {
            return Some((prime[i - 1], prime[i]));
        }
    }
    None
}

fn main() {
//    let p = generate_prime();
//    for i in p {
//        println!("{}", i);
//    }
    //gap(2, 100, 110);
    generate_prime_seg(100, 110);
    println!("Hello, world!");
}

fn testing(g: i32, m: u64, n: u64, exp: Option<(u64, u64)>) -> () {
    assert_eq!(gap(g, m, n), exp)
}

#[test]
fn basics_gap() {
    testing(2, 100, 110, Some((101, 103)));
    testing(4, 100, 110, Some((103, 107)));
    testing(6, 100, 110, None);
    testing(8, 300, 400, Some((359, 367)));
}
