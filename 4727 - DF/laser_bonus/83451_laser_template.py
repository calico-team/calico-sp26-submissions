import math

def solve_congruence(a, b, m):
    g = math.gcd(a, m)
    if b % g != 0: return None, None
    a //= g; b //= g; m //= g
    return (b * pow(a, -1, m)) % m, m

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]
    min_t, ans_idx = float('inf'), -1
    
    for i in range(K):
        rx, mx = solve_congruence(Q, (X[i] - x0) % N, N)
        ry, my = solve_congruence(P, (Y[i] - y0) % M, M)
        if rx is None or ry is None: continue
        
        k, mod_k = solve_congruence(mx, (ry - rx) % my, my)
        if k is None: continue
        
        t, mod = rx + k * mx, mx * mod_k
        if i == 0 and t == 0: t = mod
        
        if t < min_t:
            min_t, ans_idx = t, i
            
    return ans_idx

def main():
    T_str = input().strip()
    if not T_str: return
    T = int(T_str)
    for _ in range(T):
        line = input().split()
        if not line: continue
        K, N, M, P, Q = map(int, line)
        X, Y = [], []
        for _ in range(K):
            xi, yi = map(int, input().split())
            X.append(xi); Y.append(yi)
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()
