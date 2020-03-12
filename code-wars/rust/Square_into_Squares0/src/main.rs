fn main() {
    decompose(50);
}

fn decompose(n: i64) -> Option<Vec<i64>> {
    let r = _decompose(n, n * n);
    if r == None {
        return None;
    } else {
        let mut v = r.unwrap();
        v.pop();
        return Some(v);
    }
}

fn _decompose(n: i64, remain: i64) -> Option<Vec<i64>> {
    if remain == 0 {
        return Some(vec![n]);
    }

    for i in (0..n).rev() {
        if remain - i * i >= 0 {
            let r = _decompose(i, remain - i * i).clone();

            if r != None {
                let mut v = r.unwrap();
                v.push(n);
                return Some(v);
            }
        }
    }
    None
}

fn testing(n: i64, exp: Option<Vec<i64>>) -> () {
    assert_eq!(decompose(n), exp)
}

#[test]
fn tests_decompose() {
    testing(50, Some(vec![1, 3, 5, 8, 49]));
    testing(44, Some(vec![2, 3, 5, 7, 43]));
    testing(625, Some(vec![2, 5, 8, 34, 624]));
    testing(5, Some(vec![3, 4]));
}
