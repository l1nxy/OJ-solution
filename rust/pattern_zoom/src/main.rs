fn main() {
    println!("Hello, world!");
    zoom(13);
}

fn zoom(n: i32) -> String {
    let mut ret = String::new();
    let mut ch = vec![vec!['■'; (n) as usize]; n as usize];
    let size = n/2;
    println!("{}",size);
    for k in (0..(size + 1)).rev() {
        for i in (0 - k)..(k + 1) {
            for j in (0 - k)..(k + 1) {
                if  i.abs() + j.abs() <= k * 2   {
                    if i.abs() + j.abs() == k && i.abs()==j.abs() &&k!=0{
                        continue;
                    }
                    if k % 2 == 0 {
                        ch[(size - i) as usize][(size + j) as usize] = '■';
                    } else {
                        ch[(size - i) as usize][(size + j) as usize] = '□';
                    }
                }
            }
        }
    }

    for i in ch{
        for j in i{
            ret.push(j);
        }
        ret.push('\n');
    }
    ret.pop();
    ret
}


#[test]
fn basic_test_1() {
    assert_eq!(zoom(1), "■");
}

#[test]
fn basic_test_2() {
    assert_eq!(zoom(3), "\
□□□
□■□
□□□"
    );
}

#[test]
fn basic_test_3() {
    assert_eq!(zoom(5), "\
■■■■■
■□□□■
■□■□■
■□□□■
■■■■■"
    );
}

#[test]
fn basic_test_4() {
    assert_eq!(zoom(7), "\
□□□□□□□
□■■■■■□
□■□□□■□
□■□■□■□
□■□□□■□
□■■■■■□
□□□□□□□"
    );
}

#[test]
fn basic_test_5() {
    assert_eq!(zoom(9), "\
■■■■■■■■■
■□□□□□□□■
■□■■■■■□■
■□■□□□■□■
■□■□■□■□■
■□■□□□■□■
■□■■■■■□■
■□□□□□□□■
■■■■■■■■■"
    );
}