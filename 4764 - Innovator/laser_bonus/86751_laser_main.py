import sys
def read_your_input():
    return sys.stdin.read().split()
def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y
def solve():
    input_data = read_your_input()
    if not input_data:
        return
    
    idx = 0
    T_cases = int(input_data[idx])
    idx += 1
    
    for _ in range(T_cases):
        K = int(input_data[idx])
        N = int(input_data[idx+1])
        M = int(input_data[idx+2])
        P = int(input_data[idx+3])
        Q = int(input_data[idx+4])
        idx += 5
        
        asteroids = []
        for i in range(K):
            x = int(input_data[idx])
            y = int(input_data[idx+1])
            asteroids.append((x, y))
            idx += 2
            
        start_x, start_y = asteroids[0]
        min_t = float('inf')
        lazarbeam = -1
        
        for i in range(K):
            dx = (asteroids[i][0] - start_x) % N
            dy = (asteroids[i][1] - start_y) % M
            
            try:
                t_n = (dx * pow(Q, -1, N)) % N
                t_m = (dy * pow(P, -1, M)) % M
                
                target = (t_m - t_n) % M
                g, x_inv, _ = extended_gcd(N, M)
                
                if target % g == 0:
                    mod_m = M // g
                    a = (x_inv * (target // g)) % mod_m
                    t = t_n + a * N
                    
                    if t == 0:
                        t = (N * M) // g
                    
                    if t < min_t:
                        min_t = t
                        lazarbeam = i
            except ValueError:
                continue
                
        print(lazarbeam)

if __name__ == "__main__":
    solve()