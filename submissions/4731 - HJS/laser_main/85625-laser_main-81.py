import sys

def solve(K, N, M, P, Q, X, Y):

    lazarbeam = -1
    min_s = float('inf')
    ans_idx = -1
    
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        d, x1, y1 = extended_gcd(b % a, a)
        x = y1 - (b // a) * x1
        y = x1
        return d, x, y

    def mod_inverse(a, m):
        d, x, y = extended_gcd(a, m)
        if d != 1:
            return None
        return (x % m + m) % m

    for i in range(K):
        dx = (X[i] - X[0]) % N
        dy = (Y[i] - Y[0]) % M
        
        g_q, x_q, _ = extended_gcd(Q, N)
        if dx % g_q != 0: continue
        s_mod_n = ((dx // g_q) * x_q) % (N // g_q)
        mod_n = N // g_q
        
        g_p, x_p, _ = extended_gcd(P, M)
        if dy % g_p != 0: continue
        s_mod_m = ((dy // g_p) * x_p) % (M // g_p)
        mod_m = M // g_p
        
        rhs = (s_mod_m - s_mod_n) % mod_m
        g_comb, x_comb, _ = extended_gcd(mod_n, mod_m)
        
        if rhs % g_comb != 0: continue
        
        k = ((rhs // g_comb) * x_comb) % (mod_m // g_comb)
        s_val = s_mod_n + k * mod_n
        lcm = (mod_n * mod_m) // g_comb
        
        if s_val == 0:
            s_val = lcm
            
        if s_val < min_s:
            min_s = s_val
            ans_idx = i
            
    return ans_idx

def read_your_input():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    T = int(input_data[ptr])
    ptr += 1
    
    for _ in range(T):
        K = int(input_data[ptr])
        N = int(input_data[ptr+1])
        M = int(input_data[ptr+2])
        P = int(input_data[ptr+3])
        Q = int(input_data[ptr+4])
        ptr += 5
        
        X = []
        Y = []
        for i in range(K):
            X.append(int(input_data[ptr]))
            Y.append(int(input_data[ptr+1]))
            ptr += 2
            
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    read_your_input()