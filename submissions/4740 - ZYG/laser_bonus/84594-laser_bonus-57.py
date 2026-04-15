import sys

input_data = sys.stdin.read().strip().split()
it = iter(input_data)
T = int(next(it))

out_lines = []

for _ in range(T):
    K = int(next(it))
    N = int(next(it))
    M = int(next(it))
    P = int(next(it))
    Q = int(next(it))
    
    coords = []
    for i in range(K):
        x = int(next(it))
        y = int(next(it))
        coords.append((x, y))
    
    x0, y0 = coords[0]
    
    # 计算 gx = gcd(Q, N)
    a = Q
    b = N
    while b:
        a, b = b, a % b
    gx = a
    
    # 计算 gy = gcd(P, M)
    a = P
    b = M
    while b:
        a, b = b, a % b
    gy = a
    
    mx = N // gx
    my = M // gy
    
    # 计算 Q//gx 在模 mx 下的逆元
    a = Q // gx
    mod = mx
    inv_q = 1
    base = a
    exp = mod - 2
    while exp > 0:
        if exp & 1:
            inv_q = (inv_q * base) % mod
        base = (base * base) % mod
        exp >>= 1
    
    # 计算 P//gy 在模 my 下的逆元
    a = P // gy
    mod = my
    inv_p = 1
    base = a
    exp = mod - 2
    while exp > 0:
        if exp & 1:
            inv_p = (inv_p * base) % mod
        base = (base * base) % mod
        exp >>= 1
    
    best_t = 10**30
    best_idx = -1
    
    for i in range(1, K):
        xi, yi = coords[i]
        
        dx = (xi - x0) % N
        if dx % gx != 0:
            continue
        tx = (inv_q * (dx // gx)) % mx
        
        dy = (yi - y0) % M
        if dy % gy != 0:
            continue
        ty = (inv_p * (dy // gy)) % my
        
        # 中国剩余定理合并 tx (mod mx) 和 ty (mod my)
        m1 = mx
        m2 = my
        r1 = tx
        r2 = ty
        
        # 扩展欧几里得
        a = m1
        b = m2
        x0_egcd = 1
        y0_egcd = 0
        x1 = 0
        y1 = 1
        while b:
            q = a // b
            a, b = b, a - q * b
            x0_egcd, x1 = x1, x0_egcd - q * x1
            y0_egcd, y1 = y1, y0_egcd - q * y1
        g = a
        x = x0_egcd
        y = y0_egcd
        
        if (r2 - r1) % g != 0:
            continue
        
        lcm = m1 // g * m2
        t = r1 + m1 * (((r2 - r1) // g * x) % (m2 // g))
        t = t % lcm
        if t == 0:
            t = lcm
        
        if t < best_t:
            best_t = t
            best_idx = i
    
    out_lines.append(str(best_idx))

print("\n".join(out_lines))








