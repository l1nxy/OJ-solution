#[feature()]


#[derive(Debug, Copy, Clone)]
struct Matrix4 {
    x1: u128,
    x2: u128,
    y1: u128,
    y2: u128,
}

impl Matrix4 {
    pub fn new() -> Matrix4 {
        Matrix4 { x1: 1, x2: 0, y1: 0, y2: 1 }
    }
}

impl std::ops::Mul for Matrix4 {
    type Output = Matrix4;
    fn mul(self, b: Matrix4) -> Matrix4 {
        Matrix4 {
            x1: self.x1 * b.x1 + self.x2 * b.y1,
            x2: self.x1 * b.x2 + self.x2 * b.y2,
            y1: self.y1 * b.x1 + self.y2 * b.y1,
            y2: self.y1 * b.x2 + self.y2 * b.y2,
        }
    }
}

fn pow_for_matrix(m: Matrix4, n: u64) -> Matrix4 {
    let mut count = n;
    let mut ans = Matrix4::new();
    let mut base = m;
    while count != 0 {
        if count & 1 == 1 {
            ans = ans * base;
        }
        base = base * base;
        count >>= 1;
    }
    ans
}


fn perimeter(n: u64) -> u64 {
    let base = Matrix4 { x1: 1, x2: 1, y1: 1, y2: 0 };
    let ans = pow_for_matrix(base, n + 1);
    let an = ans.y1;
    let an_1 = ans.y2;
    println!("{:#?}", ans);
    (an * 2 + an_1 - 1) as u64 * 4
}


fn main() {
    perimeter(70);
    println!("Hello, world!");
}

fn dotest(n: u64, exp: u64) -> () {
    assert_eq!(perimeter(n), exp)
}

#[test]
fn basics_perimeter() {
    dotest(5, 80);
    dotest(7, 216);
    dotest(20, 114624);
    dotest(30, 14098308);
}