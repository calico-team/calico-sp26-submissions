use std::cell::RefCell;
use std::io::{self, Read};

thread_local! {
    static INPUT: RefCell<std::str::SplitWhitespace<'static>> = {
        let mut s = String::new();
        io::stdin().read_to_string(&mut s).unwrap();
        let s: &'static str = Box::leak(s.into_boxed_str());
        RefCell::new(s.split_whitespace())
    };
}

macro_rules! read {
    () => {
        INPUT.with(|it| it.borrow_mut().next().unwrap().parse().unwrap())
    };
    ($T:ty) => {
        INPUT.with(|it| it.borrow_mut().next().unwrap().parse::<$T>().unwrap())
    };
}

fn solve() {
    let n: usize = read!();
    let m: usize = read!();

    let mut ans: Vec<Vec<i64>> = vec![vec![0; m]; n];
    let start: Vec<i64> = vec![0, 2, 4, 1, 3];

    for i in 0..n {
        for j in 1..m {
            ans[i][j] = (start[i % 5] + j as i64 - 1 + 5) % 5;
        }

        ans[i][0] = (start[i % 5] - 1 + 5) % 5;
    }

    for i in 0..n {
        for j in 0..m {
            print!("{} ", ans[i][j]);
        }

        println!();
    }
}

fn main() {
    let t: usize = read!();
    for _ in 0..t {
        solve();
    }
}
