use std::io;

fn input() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn main() {
    let &[n]: &[i32] = &input().split_whitespace().map(|x|x.parse::<i32>().unwrap()).collect::<Vec<_>>() else { return };
    for _ in 0..n{
        problem_4();
    }
}


fn problem_4(){
    let vals: Vec<i32> = input().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let (k, n, m, p, q) = (vals[0], vals[1], vals[2], vals[3], vals[4]);
    let mut asteroids = Vec::new();
    for _ in 0..k {
        let vals: Vec<i32> = input().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
        let x = vals[0];
        let y = vals[1];
        asteroids.push((x, y));
    }
    let &(mut x, mut y) = asteroids.first().unwrap();
    loop{
        x += q;
        x %= n;
        y += p;
        y %= m;
        for i in 0..asteroids.len(){
            if asteroids.get(i).unwrap() == &(x, y){
                println!("{i}");
                return;
            }
        }
    }
}
