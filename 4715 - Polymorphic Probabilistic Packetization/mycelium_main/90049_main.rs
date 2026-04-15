use std::io::{self, BufRead, Write};

const EMPTY: u8 = 0;
const GRASS: u8 = 1;
const MYCELIUM: u8 = 2;

const DIRS: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

fn expand(frontier: &[(usize, usize)], owner: &mut [Vec<u8>], kind: u8) -> Vec<(usize, usize)> {
    let h = owner.len();
    let w = owner[0].len();
    let mut next = Vec::new();

    for &(r, c) in frontier {
        for &(dr, dc) in &DIRS {
            let nr = r as i32 + dr;
            let nc = c as i32 + dc;
            if nr < 0 || nr >= h as i32 || nc < 0 || nc >= w as i32 {
                continue;
            }
            let nr = nr as usize;
            let nc = nc as usize;
            if owner[nr][nc] == EMPTY {
                owner[nr][nc] = kind;
                next.push((nr, nc));
            }
        }
    }

    next
}

fn solve(x_g: i32, y_g: i32, x_m: i32, y_m: i32) -> i32 {
    let d = (x_g - x_m).abs() + (y_g - y_m).abs();

    let margin = d + 3;
    let min_x = x_g.min(x_m) - margin;
    let max_x = x_g.max(x_m) + margin;
    let min_y = y_g.min(y_m) - margin;
    let max_y = y_g.max(y_m) + margin;

    let h = (max_x - min_x + 1) as usize;
    let w = (max_y - min_y + 1) as usize;

    let gx = (x_g - min_x) as usize;
    let gy = (y_g - min_y) as usize;
    let mx = (x_m - min_x) as usize;
    let my = (y_m - min_y) as usize;

    let mut owner = vec![vec![EMPTY; w]; h];
    owner[gx][gy] = GRASS;
    owner[mx][my] = MYCELIUM;

    let mut grass_frontier = vec![(gx, gy)];
    let mut mycelium_frontier = vec![(mx, my)];

    let mut next_grass_time = 2i32;
    let mut next_mycelium_time = 7i32;

    let mut mycelium_count = 1i32;

    loop {
        if next_grass_time < next_mycelium_time {
            grass_frontier = expand(&grass_frontier, &mut owner, GRASS);
            next_grass_time += 2;
        } else if next_mycelium_time < next_grass_time {
            let next = expand(&mycelium_frontier, &mut owner, MYCELIUM);
            mycelium_count += next.len() as i32;
            mycelium_frontier = next;
            next_mycelium_time += 7;

            if mycelium_frontier.is_empty() {
                break;
            }
        } else {
            grass_frontier = expand(&grass_frontier, &mut owner, GRASS);
            next_grass_time += 2;

            let next = expand(&mycelium_frontier, &mut owner, MYCELIUM);
            mycelium_count += next.len() as i32;
            mycelium_frontier = next;
            next_mycelium_time += 7;

            if mycelium_frontier.is_empty() {
                break;
            }
        }
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
