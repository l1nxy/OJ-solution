fn longest_consec(strarr: Vec<&str>, k: usize) -> String {
    let mut v = strarr.clone();
    let mut ret = String::new();
    let len = strarr.len();
    if k <= 0 || k > len || len == 0 {
        return String::from("");
    }

    if k == 1{
         v.sort_by(|a,b| b.len().cmp(&a.len()));
        return v[0].to_string();
    }
    let mut sum = 0;
    for i in 0..strarr.len()-k+1{
        let t = strarr[i..i+k].to_vec();
        let a : usize= t.iter().map(|s| s.len()).sum();
        if sum < a{
            sum = a;
            ret.clear();
            for  i in t {
                ret.push_str(i);
            }
        }
    }
    //println!("{:#?}",ret);
    ret
    // your code
}

fn testing(strarr: Vec<&str>, k: usize, exp: &str) -> () {
    assert_eq!(&longest_consec(strarr, k), exp)
}

#[test]
fn basics_longest_consec() {
    testing(vec!["zone", "abigail", "theta", "form", "libe", "zas"], 2, "abigailtheta");
    testing(vec!["ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"], 1,
            "oocccffuucccjjjkkkjyyyeehh");
    testing(vec![], 3, "");
    testing(vec!["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 3, "ixoyx3452zzzzzzzzzzzz");
    testing(vec!["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 15, "");
    testing(vec!["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 0, "");
}

fn main() {
    longest_consec(vec!["zone", "abigail", "theta", "form", "libe", "zas"],2);
    println!("Hello, world!");
}
