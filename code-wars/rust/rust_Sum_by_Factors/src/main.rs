fn main() {
    sum_of_divided(vec![-29804, -4209, -28265, -72769, -31744]);
    println!("Hello, world!");
}

fn generate_prime() -> Vec<i64> {
    let mut is_prime: Vec<bool> = vec![true; 100000];
    let mut ret: Vec<i64> = Vec::new();
    for i in 2..100000f64.sqrt() as usize {
        if is_prime[i] == true {
            let mut j = 2 * i;
            while j < 100000 {
                is_prime[j as usize] = false;
                j += i;
            }
        }
    }

    for i in 2usize..100000 {
        if is_prime[i] == true  {
            ret.push(i as i64);
        }
    }
    ret
}

fn sum_of_divided(l: Vec<i64>) -> Vec<(i64, i64)> {
    let v = generate_prime();
    println!("{:#?}",v);
    let mut ret: Vec<(i64, i64)> = Vec::new();
    let mut is_sum = vec![false; 100000];
    let mut sum = vec![0; 100000];

    for i in l {
        for x in 0..v.len() {
            if v[x] > i.abs() as i64 { break; } else {
                if i % v[x] == 0 {

                    println!("{}'s factor:{}",i,v[x]);
                    sum[v[x] as usize] += i;
                    is_sum[v[x] as usize] = true;
                }
            }
        }
    }

    for i in 0..is_sum.len() {
        if is_sum[i] == true {
            ret.push((i as i64, sum[i]));
        }
    }
    println!("{:#?}", ret);
    ret
    // your code
}

fn testing(l: Vec<i64>, exp: Vec<(i64, i64)>) -> () {
    assert_eq!(sum_of_divided(l), exp)
}

#[test]
fn basics_sum_of_divided() {
    testing(vec![12, 15], vec![(2, 12), (3, 27), (5, 15)]);
    testing(vec![15, 21, 24, 30, 45], vec![(2, 54), (3, 135), (5, 90), (7, 21)]);
}