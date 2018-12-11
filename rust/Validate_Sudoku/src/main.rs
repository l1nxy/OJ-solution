fn main() {
    let bad_sudoku_2 = Sudoku {
        data: vec![
            vec![1, 2, 3, 4, 5],
            vec![1, 2, 3, 4],
            vec![1, 2, 3, 4],
            vec![1],
        ]
    };
    println!("{}", bad_sudoku_2.is_valid());
    println!("Hello, world!");
}


struct Sudoku {
    data: Vec<Vec<u32>>,
}


impl Sudoku {
    fn is_valid(&self) -> bool {
        let len = (self.data.len() as f64) as usize;
        let n_of_sudoku = self.data.len();
        for i in &self.data {
            if i.len() != n_of_sudoku { return false; }
            let mut mask = vec![false; len + 1];

            for j in i {
                if *j <= 0 || *j > len as u32 { return false; }
                mask[*j as usize] = true;
            }
            if mask.iter().filter(|&&a| a != true).count() > 1 { return false; }
        }


        for i in 0..len {
            let mut mask = vec![false; len + 1];
            for j in 0..len {
                if self.data[j][i] <= 0 || self.data[j][i] > len as u32 {
                    return false;
                }
                mask[self.data[j][i] as usize] = true;
            }
            if mask.iter().filter(|&&a| a != true).count() > 1 { return false; }
        }

        let sqrt_len = (len as f64).sqrt() as usize;
        for i in 0..sqrt_len {
            for j in 0..sqrt_len {
                let mut mask = vec![false; len + 1];
                for k in 0..sqrt_len {
                    for m in 0..sqrt_len {
                        let index_x = k + sqrt_len * i;
                        let index_y = m + sqrt_len * j;
                        if self.data[index_x][index_y] <= 0 || self.data[index_x][index_y] > len as u32 { return false; }
                        mask[self.data[index_x][index_y] as usize] = true;
                    }
                }
                if mask.iter().filter(|&&a| a != true).count() > 1 { return false; }
            }
        }
        true
    }
}


#[test]
fn good_sudoku() {
    let good_sudoku_1 = Sudoku {
        data: vec![
            vec![7, 8, 4, 1, 5, 9, 3, 2, 6],
            vec![5, 3, 9, 6, 7, 2, 8, 4, 1],
            vec![6, 1, 2, 4, 3, 8, 7, 5, 9],
            vec![9, 2, 8, 7, 1, 5, 4, 6, 3],
            vec![3, 5, 7, 8, 4, 6, 1, 9, 2],
            vec![4, 6, 1, 9, 2, 3, 5, 8, 7],
            vec![8, 7, 6, 3, 9, 4, 2, 1, 5],
            vec![2, 4, 3, 5, 6, 1, 9, 7, 8],
            vec![1, 9, 5, 2, 8, 7, 6, 3, 4]
        ]
    };

    let good_sudoku_2 = Sudoku {
        data: vec![
            vec![1, 4, 2, 3],
            vec![3, 2, 4, 1],
            vec![4, 1, 3, 2],
            vec![2, 3, 1, 4],
        ]
    };
    assert!(good_sudoku_1.is_valid());
    assert!(good_sudoku_2.is_valid());
}

#[test]
fn bad_sudoku() {
    let bad_sudoku_1 = Sudoku {
        data: vec![
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9],
        ]
    };

    let bad_sudoku_2 = Sudoku {
        data: vec![
            vec![1, 2, 3, 4, 5],
            vec![1, 2, 3, 4],
            vec![1, 2, 3, 4],
            vec![1],
        ]
    };
    assert!(!bad_sudoku_1.is_valid());
    assert!(!bad_sudoku_2.is_valid());
}
