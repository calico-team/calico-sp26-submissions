import sys
import math

def ext_gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    g, x1, y1 = ext_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return (g, x, y)

def inv(a, m):
    g, x, y = ext_gcd(a, m)
    return x % m

def crt2(a1, m1, a2, m2):
    d, x, y = ext_gcd(m1, m2)
    c = a2 - a1
    if c % d != 0:
        return None
    lcm = m1 // d * m2
    tmp = (c // d) * x % (m2 //d)
    t = (a1 + tmp * m1) % lcm
    if t <= 0:
        t += lcm
    return t

def main():
    data = list(map(int, sys,stdin.read().split()))
    ptr = 0
    T = data[ptr]
    ptr += 1
    for _ in range(T):
        K = data[ptr]
        N = data[ptr+1]
        M = data[ptr+2]
        P = data[ptr+3]
        Q = data[ptr+4]
        ptr += 5

        ast = []
        for i in range(K):
            x = data[ptr]
            y = data[ptr+1]
            ast.append( (x, y, i) )
            ptr +=2

        x0, y0, _ = ast[0]
        best_t = 10**18
        best_idx = -1

        for xi, yi, idx in ast:
            if idx == 0:
                continue

            dx = (xi - x0) % N
            dy = (yi - y0) % M

            gq = math.gcd(Q, N)
            if dx % gq != 0:
                continue
            m1 = N // gq
            a1 = (dx // gq) * inv(Q // gq, m1) % m1

            gp = math.gcd(P, M)
            if dy % gp != 0:
                continue
            m2 = M // gp
            a2 = (dy // gp) * inv(p // gp, m2) % m2

            t = crt2(a1, m1, a2, m2)
            if t is None:
                continue
            if t > 0 and t < best_t:
                best_t = t
                best_idx = idx

        print(best_idx)

if __name__ == "__main__":
    main()


















            

            
