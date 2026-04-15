import sys
input = sys.stdin.readline

t = int(input())

def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = egcd(b, a % b)
    return g, y, x - (a // b) * y

def inv(a, m):
    g, x, _ = egcd(a, m)
    if g != 1:
        return None
    return x % m

for _ in range(t):
    k, n, m, p, q = map(int, input().split())
    
    ast = []
    for i in range(k):
        x, y = map(int, input().split())
        ast.append((x, y))
    
    sx, sy = ast[0]
    
    inv_q = inv(q, n)
    inv_p = inv(p, m)
    
    ans = -1
    best = 10**30  # big number
    
    for i in range(k):
        if i == 0:
            continue
        
        x, y = ast[i]
        
        dx = (x - sx) % n
        dy = (y - sy) % m
        
        if inv_q is None or inv_p is None:
            continue
        
        t1 = (dx * inv_q) % n
        t2 = (dy * inv_p) % m
        
        g, a, b = egcd(n, m)
        if (t2 - t1) % g != 0:
            continue
        
        lcm = n // g * m
        
        t_val = (t1 + ((t2 - t1) // g * a % (m // g)) * n) % lcm
        
        if t_val == 0:
            t_val = lcm
        
        if t_val < best:
            best = t_val
            ans = i
    
    if ans == -1:
        print(0)
    else:
        print(ans)


def read_your_input():
    pass