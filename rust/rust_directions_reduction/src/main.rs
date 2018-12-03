#![feature(uniform_paths)]

#[derive(Debug, PartialEq,Clone,Copy)]
enum Direction { NORTH, SOUTH, EAST, WEST }


fn dir_reduc(arr: &[Direction]) -> Vec<Direction> {
    use Direction::*;
    let mut ret: Vec<Direction> = Vec::new();
    for i in 0..arr.len(){
        if ret.is_empty() { ret.push(arr[i]);}
        else{
           match (arr[i],*ret.last().unwrap()) {
               (NORTH,SOUTH)|(SOUTH,NORTH)|(WEST,EAST)|(EAST,WEST) =>{ ret.pop();}
               _ => { ret.push(arr[i]);}
           }
        }
    }
    println!("{:#?}",ret);
    ret
}

fn main() {
    use Direction::*;
    let a = [NORTH, SOUTH, SOUTH, EAST, WEST, NORTH, WEST];
    dir_reduc(&a);
    println!("Hello, world!");
}

#[test]
fn returns_expected() {
    use Direction::*;
    let a = [NORTH, SOUTH, SOUTH, EAST, WEST, NORTH, WEST];
    assert_eq!(dir_reduc(&a), [WEST]);
    let a = [NORTH, WEST, SOUTH, EAST];
    assert_eq!(dir_reduc(&a), [NORTH, WEST, SOUTH, EAST]);
}