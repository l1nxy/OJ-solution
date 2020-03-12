#[derive(Debug, Copy, Clone)]
struct Vector {
    i: f64,
    j: f64,
    k: f64,
}


impl Vector {
    pub fn new(_i: f64, _j: f64, _k: f64) -> Vector {
        Vector {
            i: _i,
            j: _j,
            k: _k,
        }
    }

    pub fn get_magnitude(&self) -> f64 {
        (self.i.powi(2) + self.j.powi(2) + self.k.powi(2)).sqrt()
    }

    pub fn get_i() -> Vector {
        Vector {
            i: 1.0,
            j: 0.0,
            k: 0.0,
        }
    }

    pub fn get_j() -> Vector {
        Vector {
            i: 0.0,
            j: 1.0,
            k: 0.0,
        }
    }

    pub fn get_k() -> Vector {
        Vector {
            i: 0.0,
            j: 0.0,
            k: 1.0,
        }
    }

    pub fn add(&self, _other: Vector) -> Vector {
        Vector {
            i: self.i + _other.i,
            j: self.j + _other.j,
            k: self.k + _other.k,
        }
    }

    pub fn multiply_by_scalar(&self, s: f64) -> Vector {
        Vector {
            i: self.i * s,
            j: self.j * s,
            k: self.k * s,
        }
    }

    pub fn dot(&self, _other: Vector) -> f64 {
        self.i * _other.i + self.j * _other.j + self.k * _other.k
    }

    pub fn cross(&self, _other: Vector) -> Vector {
        Vector {
            i: self.j * _other.k - _other.j * self.k,
            j: -(self.i * _other.k - _other.i * self.k),
            k: self.i * _other.j - _other.i * self.j,
        }
    }

    pub fn is_parallel_to(&self, _other: Vector) -> bool {
        if self.get_magnitude() - 0.0 < 0.000001 || _other.get_magnitude() - 0.0 < 0.000001 { return false; }
        self.normalize().cross(_other.normalize()).get_magnitude() - 0.0 < 0.00001
    }

    pub fn normalize(&self) -> Vector {
        Vector {
            i: self.i / self.get_magnitude(),
            j: self.j / self.get_magnitude(),
            k: self.k / self.get_magnitude(),
        }
    }

    pub fn is_normalized(&self) -> bool {
        self.get_magnitude() - 1.0 < 0.000001
    }

    pub fn is_perpendicular_to(&self, _other: Vector) -> bool {
        if self.get_magnitude() - 0.0 < 0.000001 || _other.get_magnitude() - 0.0 < 0.000001 { return false; }
        println!("{}", self.normalize().cross(_other.normalize()).get_magnitude());
        (self.normalize().cross(_other.normalize()).get_magnitude() - 1.0).abs() < 0.0001
    }
}


fn main() {
    println!("Hello, world!");
}


fn are_equals(a: f64, b: f64) -> bool {
    (a - b).abs() < 0.000001
}


#[test]
fn constructor_test() {
    let v = Vector::new(1.0, 2.0, 3.0);
    assert_eq!(1.0, v.i, "Value of first argument passed into struct constructor should be assigned to \"i\"");
    assert_eq!(2.0, v.j, "Value of second argument passed into struct constructor should be assigned to \"j\"");
    assert_eq!(3.0, v.k, "Value of third argument passed into struct constructor should be assigned to \"k\"");

    let v = Vector::new(-4.0 / 3.0, 40.0 / 27.0, 68.0 / 69.0);
    assert!(are_equals(v.i, -4.0 / 3.0), "\"i\" of Vector should equal -4 / 3");
    assert!(are_equals(v.j, 40.0 / 27.0), "\"j\" of Vector should equal 40 / 27");
    assert!(are_equals(v.k, 68.0 / 69.0), "\"k\" of Vector should equal 68 / 69");
}

#[test]
fn get_magnitude_test() {
    let v = Vector::new(6.0, 10.0, -3.0);
    assert!(are_equals(v.get_magnitude(), (145 as f64).sqrt()));
}

#[test]
fn struct_methods_test() {
    let i = Vector::get_i();
    let j = Vector::get_j();
    let k = Vector::get_k();
    assert_eq!(1.0, i.i);
    assert_eq!(0.0, i.j);
    assert_eq!(0.0, i.k);
    assert_eq!(0.0, j.i);
    assert_eq!(1.0, j.j);
    assert_eq!(0.0, j.k);
    assert_eq!(0.0, k.i);
    assert_eq!(0.0, k.j);
    assert_eq!(1.0, k.k);
}

#[test]
fn add_test() {
    let v = Vector::new(3.0, 7.0 / 2.0, -3.0 / 2.0);
    let s: Vector = v.add(Vector::new(-27.0, 3.0, 4.0));
    assert!(are_equals(s.i, -24.0));
    assert!(are_equals(s.j, 13.0 / 2.0));
    assert!(are_equals(s.k, 5.0 / 2.0));
}

#[test]
fn multiply_test() {
    let v = Vector::new(1.0 / 3.0, 177.0 / 27.0, -99.0);
    let e = v.multiply_by_scalar(-3.0 / 7.0);
    assert!(are_equals(e.i, -1.0 / 7.0));
    assert!(are_equals(e.j, -59.0 / 21.0));
    assert!(are_equals(e.k, 297.0 / 7.0));
}

#[test]
fn dot_test() {
    let v = Vector::new(-99.0 / 71.0, 22.0 / 23.0, 45.0);
    let r = v.dot(Vector::new(-5.0, 4.0, 7.0));
    println!("{}", r);
    assert!(are_equals(r, 325.7979179));
}

#[test]
fn cross_test() {
    let a = Vector::new(2.0, 1.0, 3.0);
    let b = Vector::new(4.0, 6.0, 5.0);
    let a_cross_b = a.cross(b);
    let b_cross_a = b.cross(a);
    println!("{:#?}", a_cross_b);
    println!("{:#?}", b_cross_a);
    assert!(are_equals(a_cross_b.i, -13.0));
    assert!(are_equals(a_cross_b.j, 2.0));
    assert!(are_equals(a_cross_b.k, 8.0));
    assert!(are_equals(b_cross_a.i, 13.0));
    assert!(are_equals(b_cross_a.j, -2.0));
    assert!(are_equals(b_cross_a.k, -8.0));
}

#[test]
fn parallel_test() {
    let a = Vector::new(1045.0 / 23.0, -666.0 / 37.0, 15.0);
    let b = Vector::new(161.3385037, -59124.0 / 925.0, 9854.0 / 185.0);
    assert!(a.is_parallel_to(b));
    assert!(b.is_parallel_to(a));
    let c = Vector::new(-3.0, 0.0, 5.0);
    let d = Vector::new(-12.0, 1.0, 20.0);
    assert!(!c.is_parallel_to(d));
    assert!(!d.is_parallel_to(c));
}

#[test]
fn perpendicular_test() {
    let a = Vector::new(3.0, 4.0, 7.0);
    let b = Vector::new(1.0 / 3.0, 2.0, -9.0 / 7.0);
    assert!(a.is_perpendicular_to(b));
    assert!(b.is_perpendicular_to(a));
    let c = Vector::new(1.0, 3.0, 5.0);
    let d = Vector::new(-2.0, -7.0, 4.4);
    assert!(!c.is_perpendicular_to(d));
    assert!(!d.is_perpendicular_to(c));
}

#[test]
fn normalize_test() {
    let v = Vector::new(-1.0, -1.0, 1.0);
    let u = v.normalize();
    assert!(are_equals(u.get_magnitude(), 1.0));
    assert!(are_equals(u.i, -1.0 / (3.0 as f64).sqrt()));
    assert!(are_equals(u.j, -1.0 / (3.0 as f64).sqrt()));
    assert!(are_equals(u.k, 1.0 / (3.0 as f64).sqrt()));
}

#[test]
fn is_normalized_test() {
    let a = Vector::new(-1.0 / (2.0 as f64).sqrt(), 0.0, 1.0 / (2.0 as f64).sqrt());
    let b = Vector::new(1.0, 1.0, 1.0);
    assert!(a.is_normalized());
    assert!(!b.is_normalized());
}
