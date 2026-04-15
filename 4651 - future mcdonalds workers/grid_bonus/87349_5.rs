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

fn med(a: i64, b: i64, c: i64) -> i64 {
    let mut v = vec![a, b, c];
    v.sort();
    v[1]
}

fn solve() {
    let n: usize = read!();

    let a: Vec<i64> = (0..n).map(|_| read!()).collect();

    let mut ans: Vec<i64> = a.clone();

    for i in 1..(n - 1) {
        ans[i] = med(ans[i - 1], a[i], ans[i + 1]);
    }
    for i in 1..(n - 1) {
        ans[i] = med(ans[i - 1], a[i], ans[i + 1]);
    }
    for i in 1..(n - 1) {
        ans[i] = med(ans[i - 1], a[i], ans[i + 1]);
    }
    for i in ans {
        print!("{i} ");
    }

    println!();
}

fn main() {
    let t: usize = read!();
    for _ in 0..t {
        solve();
    }
}
