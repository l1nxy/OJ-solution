fn main() {
    sq_in_rect(5, 3);
    println!("Hello, world!");
}

fn sq_in_rect_base(lng: i32, wdth: i32) -> Option<Vec<i32>> {
    let lng1 = std::cmp::max(lng, wdth);
    let wdth1 = std::cmp::min(lng, wdth);
    let mut ret = Vec::new();
    if lng1 == wdth1 {
        return Some(vec![lng1]);
    } else {
        ret.push(wdth1);
        ret.append(&mut sq_in_rect(lng1 - wdth1, wdth1).unwrap());
    }
    Some(ret)
}

fn sq_in_rect(lng: i32, wdth: i32) -> Option<Vec<i32>> {
    let ret = sq_in_rect_base(lng, wdth).unwrap();
    if ret.len() == 1 {
        None
    } else {
        Some(ret)
    }
}

fn testing(lng: i32, wdth: i32, exp: Option<Vec<i32>>) -> () {
    assert_eq!(sq_in_rect(lng, wdth), exp)
}

#[test]
fn tests_sq_in_rect() {
//    testing(5, 3, Some(vec![3, 2, 1, 1]));
//    testing(3, 5, Some(vec![3, 2, 1, 1]));
    testing(5, 5, None);
}
