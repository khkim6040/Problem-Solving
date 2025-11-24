
use std::io;

fn main() {
    // get a, b from stdin
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let mut nums = input.split_whitespace();
    let a: i32 = nums.next().unwrap().parse().expect("Please type a number!");
    let b: i32 = nums.next().unwrap().parse().expect("Please type a number!");

    let sum = a + b;

    println!("{}", sum);
}