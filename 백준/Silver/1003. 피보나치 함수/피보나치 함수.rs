use std::io;


fn fibonacci_count(n: usize) -> (usize, usize) {
    // Create a table to store the counts of fib[0] and fib[1]
    let mut counts = vec![(0, 0); n + 1];
    counts[0] = (1, 0); // fib(0) calls fib[0] once
    if n >= 1 {
        counts[1] = (0, 1); // fib(1) calls fib[1] once
    }

    for i in 2..=n {
        counts[i].0 = counts[i - 1].0 + counts[i - 2].0; // count of fib[0]
        counts[i].1 = counts[i - 1].1 + counts[i - 2].1; // count of fib[1]
    }

    counts[n]
}

fn main() {
    // print the count of fib[0], fib[1] are called
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    // test cases
    let T: usize = input.trim().parse().expect("Please type a number!");

    for _ in 0..T {
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let n: usize = input.trim().parse().expect("Please type a number!");
        let (count_0, count_1) = fibonacci_count(n);
        println!("{} {}", count_0, count_1);
    }

}