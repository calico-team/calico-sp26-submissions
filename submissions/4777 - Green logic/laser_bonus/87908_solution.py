import sys
import math

def extgcd(a, b):
    if b == 0:
        return 1, 0, a
    x, y, g = extgcd(b, a % b)
    return y, x - y * (a // b), g

def get_mod_base(A, B, M):
    g = math.gcd(A, M)
    if B % g != 0:
        return None
    A_p = A // g
    B_p = B // g
    M_p = M // g
    
    if M_p == 1:
        return 0, 1
        
    inv = pow(A_p, -1, M_p)
    return (B_p * inv) % M_p, M_p

def merge_eqs(t1, m1, t2, m2):
    _, _, g = extgcd(m1, m2)
    
    if (t1 - t2) % g != 0:
        return None
        
    lcm = (m1 // g) * m2
    diff = (t2 - t1) // g
    m2_p = m2 // g
    
    if m2_p == 1:
        k = 0
    else:
        inv = pow(m1 // g, -1, m2_p)
        k = (diff * inv) % m2_p
        
    t = (t1 + k * m1) % lcm
    
    # The laser must take at least 1 step (handles the 'wrapped around once' rule)
    if t <= 0:
        t += lcm 
        
    return t, lcm

def main():
    # Read all input from standard input at once
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    for _ in range(T):
        K = int(input_data[idx])
        N = int(input_data[idx+1])
        M = int(input_data[idx+2])
        P = int(input_data[idx+3])
        Q = int(input_data[idx+4])
        idx += 5
        
        asteroids = []
        for _ in range(K):
            asteroids.append((int(input_data[idx]), int(input_data[idx+1])))
            idx += 2
            
        start_x, start_y = asteroids[0]
        ans_time = float('inf')
        ans_index = -1
        
        for i in range(K):
            target_x, target_y = asteroids[i]
            dx = (target_x - start_x) % N
            dy = (target_y - start_y) % M
            
            eq_x = get_mod_base(Q, dx, N)
            eq_y = get_mod_base(P, dy, M)
            
            if eq_x is None or eq_y is None:
                continue
                
            combined = merge_eqs(eq_x[0], eq_x[1], eq_y[0], eq_y[1])
            if combined:
                t, _ = combined
                # Find the asteroid hit with the smallest time 't'
                if t < ans_time:
                    ans_time = t
                    ans_index = i
                    
        # Print directly to standard output
        print(ans_index)

if __name__ == '__main__':
    main()