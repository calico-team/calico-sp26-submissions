import sys
import math
from math import gcd

def main():
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        K = int(input[ptr])
        N = int(input[ptr+1])
        M = int(input[ptr+2])
        P = int(input[ptr+3])
        Q = int(input[ptr+4])
        ptr += 5
        asteroids = []
        for __ in range(K):
            x = int(input[ptr])
            y = int(input[ptr+1])
            asteroids.append((x, y))
            ptr += 2
        
        X0, Y0 = asteroids[0]
        min_t = float('inf')
        ans_idx = -1
        
        for idx in range(K):
            Xi, Yi = asteroids[idx]
            b1 = (Xi - X0) % N
            b2 = (Yi - Y0) % M
            
            g1 = gcd(Q, N)
            if b1 % g1 != 0:
                continue
            q1 = Q // g1
            n1 = N // g1
            b1_prime = b1 // g1
            inv1 = pow(q1, -1, n1)
            c1 = (b1_prime * inv1) % n1
            m1_prime = n1
            
            g2 = gcd(P, M)
            if b2 % g2 != 0:
                continue
            p2 = P // g2
            m2 = M // g2
            b2_prime = b2 // g2
            inv2 = pow(p2, -1, m2)
            c2 = (b2_prime * inv2) % m2
            m2_prime = m2
            
            g = gcd(m1_prime, m2_prime)
            if (c1 - c2) % g != 0:
                continue
            lcm = (m1_prime * m2_prime) // g
            a = m1_prime // g
            b = (c2 - c1) // g
            mod = m2_prime // g
            inv_a = pow(a, -1, mod)
            k0 = (b * inv_a) % mod
            c = c1 + k0 * m1_prime
            c = c % lcm
            
            # Get minimal t ≥ 1
            if c == 0:
                t_i = lcm
            else:
                t_i = c
            
            if t_i < min_t or (t_i == min_t and idx < ans_idx):
                min_t = t_i
                ans_idx = idx
        
        print(ans_idx)

if __name__ == "__main__":
    main()
