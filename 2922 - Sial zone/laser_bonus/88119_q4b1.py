import sys
input = sys.stdin.readline
from math import gcd

def crt(a1, m1, a2, m2):
    g = gcd(m1, m2)
    
    if (a2 - a1) % g != 0:
        return None
    
    lcm = m1 // g * m2
    
    m1_ = m1 // g
    m2_ = m2 // g
    
    inv = pow(m1_, -1, m2_)
    
    t = ((a2 - a1) // g * inv) % m2_
    
    return (a1 + m1 * t) % lcm

T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    ast = [tuple(map(int, input().split())) for _ in range(K)]
    
    x0, y0 = ast[0]
    
    invQ = pow(Q, -1, N)
    invP = pow(P, -1, M)
    
    best = None
    ans = -1
    
    for i, (x, y) in enumerate(ast):
        dx = (x - x0) % N
        dy = (y - y0) % M
        
        a = dx * invQ % N
        b = dy * invP % M
        
        t = crt(a, N, b, M)
        if t is None:
            continue
        
        if t == 0:
            t = (N * M) // gcd(N, M)
        
        if best is None or t < best:
            best = t
            ans = i
    
    print(ans)