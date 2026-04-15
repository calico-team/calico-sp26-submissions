import math
from collections import defaultdict

def lcm(a, b):
    return a // math.gcd(a, b) * b

def solve():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        
        ast = {}
        coords = []
        
        for i in range(K):
            x, y = map(int, input().split())
            coords.append((x, y))
            if (x, y) not in ast:
                ast[(x, y)] = i
            else:
                ast[(x, y)] = min(ast[(x, y)], i)

        x0, y0 = coords[0]

        
        ax = N // math.gcd(N, Q)
        ay = M // math.gcd(M, P)
        L = lcm(ax, ay)

        x, y = x0, y0
        ans = None
        best_time = float('inf')

        for t in range(1, L + 1):
            x = (x + Q) % N
            y = (y + P) % M

            if (x, y) in ast:
                idx = ast[(x, y)]
                if t < best_time or (t == best_time and idx < ans):
                    best_time = t
                    ans = idx

        print(ans)

if __name__ == "__main__":
    solve()