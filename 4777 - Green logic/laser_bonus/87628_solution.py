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
    
    # Safeguard against modulo 1 errors in Python's pow()
    if M_p == 1:
        return 0, 1
        
    inv = pow(A_p, -1, M_p)
    return (B_p * inv) % M_p, M_p

def merge_eqs(t1, m1, t2, m2):
    # FIXED: Correctly unpack g as the third value instead of the first
    _, _, g = extgcd(m1, m2)
    
    if (t1 - t2) % g != 0:
        return None
        
    lcm = (m1 // g) * m2
    diff = (t2 - t1) // g
    m2_p = m2 // g
    
    # Safeguard against modulo 1 errors
    if m2_p == 1:
        k = 0
    else:
        inv = pow(m1 // g, -1, m2_p)
        k = (diff * inv) % m2_p
        
    t = (t1 + k * m1) % lcm
    
    # Ensure time is strictly positive (handles the "wrap around once" rule)
    if t <= 0:
        t += lcm 
        
    return t, lcm

def main():
    try:
        fin = open('input.txt', 'r')
        fout = open('output.txt', 'w')
    except FileNotFoundError:
        print("Error: Please make sure input.txt exists in the same folder.")
        return

    data = fin.read().split()
    if not data:
        return
    
    T = int(data[0])
    idx = 1
    
    lazarbeam = "pew_pew"
    
    for _ in range(T):
        K = int(data[idx])
        N = int(data[idx+1])
        M = int(data[idx+2])
        P = int(data[idx+3])
        Q = int(data[idx+4])
        idx += 5
        
        asteroids = []
        for _ in range(K):
            asteroids.append((int(data[idx]), int(data[idx+1])))
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
            
            if not eq_x or not eq_y:
                continue
                
            combined = merge_eqs(eq_x[0], eq_x[1], eq_y[0], eq_y[1])
            if combined:
                t, _ = combined
                if t < ans_time:
                    ans_time = t
                    ans_index = i
                    
        fout.write(f"{ans_index}\n")

    fin.close()
    fout.close()

if __name__ == '__main__':
    main()

def read_your_input():
    pass