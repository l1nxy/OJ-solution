struct Solution;

fn main() {
    let v = vec![-1, 0, 1, 2, -1, -4];
    let ret = Solution::three_sum(v);
    println!("{:?}", ret);
    println!("Hello, world!");
}
impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.is_empty() || nums.len() < 2 {
            return vec![];
        };
        let mut nums_mut = nums.clone();
        let mut ret: Vec<Vec<i32>> = Vec::new();
        nums_mut.sort();
        let length = nums_mut.len();
        for i in 0..length - 2 {
            if i > 0 && nums_mut[i-1] == nums_mut[i]{
                continue;
            }
            let target = nums_mut[i];
            let mut left = i + 1;
            let mut right = length - 1;
            while left < right {
                if target + nums_mut[left] + nums_mut[right] > 0 {
                    right -= 1;
                } else if target + nums_mut[left] + nums_mut[right] == 0 {
                    let ans = vec![target, nums_mut[left], nums_mut[right]];
                    ret.push(ans);
                    while left < right && nums_mut[left] == nums_mut[left+1] {
                        left +=1;
                    }
                    while left < right && nums_mut[right] == nums_mut[right-1]{
                        right -=1;
                    }
                    left +=1;
                    right -=1;
                } else {
                    left += 1;
                }
            }
        }
        ret
    }
}

#[cfg(test)]
#[test]
fn test_three_nums() {
    let v = vec![-1, 0, 1, 2, -1, -4];
    let ret = Solution::three_sum(v);
    println!("{:?}", ret);
    assert_eq!(ret, vec![vec![-1, -1, 2],vec![-1, 0, 1]]);
}
#[test]
fn test_empty_nums(){
    let v = vec![];
    let ret = Solution::three_sum(v);
    let ret1: Vec<Vec<i32>> = Vec::new();
    assert_eq!(ret,ret1);
}

#[test]
fn test_less_three() {
    let v = vec![0];
    let ret = Solution::three_sum(v);
    let ret1: Vec<Vec<i32>> = Vec::new();
    assert_eq!(ret,ret1);
}

#[test]
fn test_four_zero() {
    let v = vec![0,0,0,0];
    let ret = Solution::three_sum(v);
    assert_eq!(ret,vec![vec![0,0,0]]);
}

#[test]
fn test_de() {
    let v = vec![-2,0,1,1,2];
    let ret = Solution::three_sum(v);
    assert_eq!(ret,vec![vec![-2,0,2],vec![-2,1,1]]);
}