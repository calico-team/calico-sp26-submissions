import sys
input = sys.stdin.readline

def modinv(a, m):
    return pow(a, -1, m)

def crt(a1, m1, a2, m2):
    
    g = pow(m1, -1, m2)
    t = (a2 - a1) % m2
    t = (t * g) % m2
    return a1 + m1 * t

T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    ast = [tuple(map(int, input().split())) for _ in range(K)]
    
    x0, y0 = ast[0]
    
    invQ = modinv(Q, N)
    invP = modinv(P, M)
    
    best = None
    ans = -1
    
    for i, (x, y) in enumerate(ast):
        dx = (x - x0) % N
        dy = (y - y0) % M
        
        a = dx * invQ % N
        b = dy * invP % M
        
        t = crt(a, N, b, M)
        
        if t == 0:
            t = (N * M) // __import__('math').gcd(N, M)
        
        if best is None or t < best:
            best = t
            ans = i
    
    print(ans)