use std::io::{self, BufRead, Write};

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let t = a % b;
        a = b;
        b = t;
    }
    a.abs()
}

fn lcm(a: i64, b: i64) -> i64 {
    a / gcd(a, b) * b
}

fn mn(x: i64, m: i64) -> i64 {
    let r = x % m;
    if r < 0 { r + m } else { r }
}

fn e(a: i64, b: i64) -> (i64, i64, i64) {
    if b == 0 {
        (a, 1, 0)
    } else {
        let (g, x1, y1) = e(b, a % b);
        (g, y1, x1 - (a / b) * y1)
    }
}

fn solve_lc(a: i64, b: i64, m: i64) -> Option<(i64, i64)> {
    let (g_raw, x, _) = e(a, m);
    let g = g_raw.abs();
    if b % g != 0 {
        return None;
    }
    let b2 = b / g;
    let m2 = m / g;
    let inv = mn(x, m2);
    let t0 = mn(inv * b2, m2);
    Some((t0, m2))
}

fn crt(a1: i64, m1: i64, a2: i64, m2: i64) -> Option<(i64, i64)> {
    let (g_raw, x, _) = e(m1, m2);
    let g = g_raw.abs();
    let diff = a2 - a1;
    if diff % g != 0 {
        return None;
    }

    let l = m1 / g * m2;
    let m2g = m2 / g;
    let k = mn((diff / g) * x, m2g);
    let res = mn(a1 + k * m1, l);
    Some((res, l))
}

fn solve(k: usize, n: i64, m: i64, p: i64, q: i64, x: &[i64], y: &[i64]) -> i32 {
    let sx = x[0];
    let sy = y[0];

    let px = n / gcd(q, n);
    let py = m / gcd(p, m);
    let fp = lcm(px, py);

    let mut best_time = i64::MAX;
    let mut best_idx = -1i32;

    for i in 0..k {
        let dx = mn(x[i] - sx, n);
        let dy = mn(y[i] - sy, m);

        let sol_x = solve_lc(q, dx, n);
        let sol_y = solve_lc(p, dy, m);

        if let (Some((tx, mx)), Some((ty, my))) = (sol_x, sol_y) {
            if let Some((mut t, _)) = crt(tx, mx, ty, my) {
                if t == 0 {
                    t = fp;
                }
                if t < best_time {
                    best_time = t;
                    best_idx = i as i32;
                }
            }
        }
    }

    best_idx
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let t: usize = match lines.next() {
        Some(Ok(line)) => line.trim().parse().unwrap(),
        _ => return,
    };

    let mut out = io::BufWriter::new(io::stdout());

    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let temp: Vec<i64> = line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        let k = temp[0] as usize;
        let n = temp[1];
        let m = temp[2];
        let p = temp[3];
        let q = temp[4];

        let mut x = vec![0_i64; k];
        let mut y = vec![0_i64; k];

        for i in 0..k {
            let point_line = lines.next().unwrap().unwrap();
            let point: Vec<i64> = point_line
                .split_whitespace()
                .map(|s| s.parse().unwrap())
                .collect();
            x[i] = point[0];
            y[i] = point[1];
        }

        writeln!(out, "{}", solve(k, n, m, p, q, &x, &y)).unwrap();
    }
}
