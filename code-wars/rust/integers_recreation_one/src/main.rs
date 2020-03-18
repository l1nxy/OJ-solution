fn main() {
    list_squared(1, 250);
}

//ref:https://en.wikipedia.org/wiki/Divisor_function#cite_note-FOOTNOTEHardyWright2008310_f§16.7-4
fn list_squared(m: u64, n: u64) -> Vec<(u64, u64)> {
    let mut factor = 2;
    let mut cnt = 0;
    let mut ret = vec![];
    for i in m..n {
        if i == 1 {
            ret.push((1, 1));
            continue;
        }
        factor = 2;
        let mut sum = 1;
        let mut number = i;
        while number > 1 {
            cnt = 0;
            while number % factor == 0 {
                number /= factor;
                cnt += 1;
            }
            if cnt > 0 {
                let mut t = 0;
                t += (((factor as f64).powi(2 * (cnt + 1)) - 1.0) / ((factor as f64).powi(2) - 1.0)) as u64;
                sum *= t;
            }
            factor += 1;
        }
        if (sum as f64).sqrt() - (sum as f64).sqrt().trunc() < 0.000001 {
            println!("{}", sum);
            ret.push((i, sum));
        }
    }
    println!("{:?}", ret);
    ret
}


fn testing(m: u64, n: u64, exp: Vec<(u64, u64)>) -> () {
    assert_eq!(list_squared(m, n), exp)
}

#[test]
fn basics_list_squared() {
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(42, 250, vec![(42, 2500), (246, 84100)]);
    testing(300, 600, vec![]);
}