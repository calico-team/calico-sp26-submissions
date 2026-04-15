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

fn one(a: &Vec<i64>, ans: &mut Vec<i64>) {
    ans[0] = a[0];
}

fn two(a: &Vec<i64>, ans: &mut Vec<i64>) {
    ans[0] = a[0];
    ans[1] = a[1];
}

fn three(a: &Vec<i64>, ans: &mut Vec<i64>) {
    ans[0] = a[0];
    ans[2] = a[2];

    let mut asdf = a.clone();

    asdf.sort();

    ans[1] = asdf[1];
}

fn solve() {
    let n: usize = read!();

    let a: Vec<i64> = (0..n).map(|_| read!()).collect();

    let mut ans: Vec<i64> = vec![0; n];

    if n == 1 {
        one(&a, &mut ans);
    } else if n == 2 {
        two(&a, &mut ans);
    } else if n == 3 {
        three(&a, &mut ans);
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
