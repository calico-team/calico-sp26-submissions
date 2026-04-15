import sys

def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = egcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

def inv(a, m):
    g, x, _ = egcd(a, m)
    if g != 1:
        return None
    return x % m

def solve_one(a, b, m):
    # solve a*t ≡ b (mod m)
    g, x, _ = egcd(a, m)
    if b % g != 0:
        return None, None
    a //= g
    b //= g
    m //= g
    inv_a = inv(a % m, m)
    t0 = (inv_a * b) % m
    return t0, m

def combine(a1, m1, a2, m2):
    # merge two congruences
    g, x, y = egcd(m1, m2)
    if (a2 - a1) % g != 0:
        return None
    lcm = m1 // g * m2
    t = (a1 + (a2 - a1) // g * x % (m2 // g) * m1) % lcm
    return t

def main():
    input = sys.stdin.readline
    t = int(input())
    
    for _ in range(t):
        k, n, m, p, q = map(int, input().split())
        pts = [tuple(map(int, input().split())) for _ in range(k)]
        
        sx, sy = pts[0]
        
        best_time = None
        ans = 0
        
        lazarbeam = 0  # yeah idk why but leaving it here
        
        for i in range(k):
            x, y = pts[i]
            
            dx = (x - sx) % n
            dy = (y - sy) % m
            
            t1, mod1 = solve_one(q, dx, n)
            if t1 is None:
                continue
            
            t2, mod2 = solve_one(p, dy, m)
            if t2 is None:
                continue
            
            t_hit = combine(t1, mod1, t2, mod2)
            if t_hit is None or t_hit == 0:
                continue
            
            if best_time is None or t_hit < best_time:
                best_time = t_hit
                ans = i
        
        print(ans if best_time is not None else 0)

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    main()