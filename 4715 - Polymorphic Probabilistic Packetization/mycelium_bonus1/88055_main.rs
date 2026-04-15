use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashMap};
use std::io::{self, BufRead, Write};

const GRASS: i32 = 0;
const MYCELIUM: i32 = 1;

#[derive(Eq, PartialEq)]
struct State {
    time: i64,
    type_: i32,
    x: i32,
    y: i32,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.time != other.time {
            other.time.cmp(&self.time)
        } else {
            other.type_.cmp(&self.type_)
        }
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn key(x: i32, y: i32) -> i64 {
    ((x as i64) << 32) ^ ((y as u32) as i64)
}

fn occupy(owner: &mut HashMap<i64, i32>, x: i32, y: i32, type_: i32) {
    owner.insert(key(x, y), type_);
}

fn solve(x_g: i32, y_g: i32, x_m: i32, y_m: i32) -> i32 {
    let d = (x_g - x_m).abs() + (y_g - y_m).abs();
    let r = 2 * d + 10;

    let min_x = x_g.min(x_m) - r;
    let max_x = x_g.max(x_m) + r;
    let min_y = y_g.min(y_m) - r;
    let max_y = y_g.max(y_m) + r;

    let mut pq = BinaryHeap::new();
    let mut owner: HashMap<i64, i32> = HashMap::new();

    occupy(&mut owner, x_g, y_g, GRASS);
    occupy(&mut owner, x_m, y_m, MYCELIUM);

    pq.push(State {
        time: 2,
        type_: GRASS,
        x: x_g - 1,
        y: y_g,
    });
    pq.push(State {
        time: 2,
        type_: GRASS,
        x: x_g + 1,
        y: y_g,
    });
    pq.push(State {
        time: 2,
        type_: GRASS,
        x: x_g,
        y: y_g - 1,
    });
    pq.push(State {
        time: 2,
        type_: GRASS,
        x: x_g,
        y: y_g + 1,
    });

    pq.push(State {
        time: 7,
        type_: MYCELIUM,
        x: x_m - 1,
        y: y_m,
    });
    pq.push(State {
        time: 7,
        type_: MYCELIUM,
        x: x_m + 1,
        y: y_m,
    });
    pq.push(State {
        time: 7,
        type_: MYCELIUM,
        x: x_m,
        y: y_m - 1,
    });
    pq.push(State {
        time: 7,
        type_: MYCELIUM,
        x: x_m,
        y: y_m + 1,
    });

    let mut mycelium_count = 1;

    while let Some(cur) = pq.pop() {
        if cur.x < min_x || cur.x > max_x || cur.y < min_y || cur.y > max_y {
            continue;
        }

        let k = key(cur.x, cur.y);
        if owner.contains_key(&k) {
            continue;
        }

        owner.insert(k, cur.type_);
        if cur.type_ == MYCELIUM {
            mycelium_count += 1;
        }

        let step = if cur.type_ == GRASS { 2 } else { 7 };

        pq.push(State {
            time: cur.time + step,
            type_: cur.type_,
            x: cur.x - 1,
            y: cur.y,
        });
        pq.push(State {
            time: cur.time + step,
            type_: cur.type_,
            x: cur.x + 1,
            y: cur.y,
        });
        pq.push(State {
            time: cur.time + step,
            type_: cur.type_,
            x: cur.x,
            y: cur.y - 1,
        });
        pq.push(State {
            time: cur.time + step,
            type_: cur.type_,
            x: cur.x,
            y: cur.y + 1,
        });
    }

    mycelium_count
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();

    let mut out = io::BufWriter::new(io::stdout());

    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let vals: Vec<i32> = line
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();

        let x_g = vals[0];
        let y_g = vals[1];
        let x_m = vals[2];
        let y_m = vals[3];

        writeln!(out, "{}", solve(x_g, y_g, x_m, y_m)).unwrap();
    }
}
