fn solve(m: f64) -> f64 {
    let sum1: f64 = ((2f64 * m + 1f64) + (((2f64 * m + 1f64).powi(2) - 4f64 * (m.powi(2))) as f64).sqrt()) / (2f64 * m);
    let sum2: f64 = ((2f64 * m + 1f64) - (((2f64 * m + 1f64).powi(2) - 4f64 * (m.powi(2))) as f64).sqrt()) / (2f64 * m);

    if sum1.is_normal() && sum1 < 1f64 && sum1 > 0f64 {
        return sum1;
    } else {
        return sum2;
    }
}

fn main() {
    println!("Hello, world!");
}


#[cfg(test)]
mod tests {
    use super::*;

    fn assert_fuzzy(m: f64, expect: f64) -> () {
        let merr = 1e-12;
        println!("{:?}", m);
        let actual = solve(m);
        println!("Actual {:e}", actual);
        println!("Expect {:e}", expect);
        let inrange = (actual - expect).abs() <= merr;
        if inrange == false {
            println!("Expected value near: {:e} but got: {:e}", actual, expect);
        }
        assert_eq!(inrange, true);
    }


    #[test]
    fn basic_tests() {
        assert_fuzzy(2.00, 5.000000000000e-01);
        assert_fuzzy(4.00, 6.096117967978e-01);
        assert_fuzzy(5.00, 6.417424305044e-01);
    }
}
