fn main() {
    println!("Hello, world!");
}


// type Point = (f32, f32);

fn point_in_poly(poly: &[Point], point: Point) -> bool {
    let mut i = 0;
    let mut j = poly.len() - 1;
    let mut flag = false;
    while i < poly.len() {
        let p1 = poly[i];
        let p2 = poly[j];
        if (p1.1 - point.1 > 0.0) != (p2.1 - point.1 > 0.0) && (point.0 - (point.1 - p1.1) * (p1.0 - p2.0) / (p1.1 - p2.1) - p1.0) < 0.0 {
            flag = !flag;
        }
    }
    flag
}

#[test]
fn simple_square() {
    let poly = [(-5., -5.), (5., -5.),
        (5., 5.), (-5., 5.)];
    show_and_test(&poly, (-6., 0.), false);
    show_and_test(&poly, (-1., 1.), true);
}