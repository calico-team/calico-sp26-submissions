def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

def exgcd(a, b, arr):
    if b == 0:
        arr[0] = 1
        arr[1] = 0
        return a
    g = exgcd(b, a % b, arr)
    tmp = arr[0]
    arr[0] = arr[1]
    arr[1] = tmp - (a // b) * arr[1]
    return g

def modInv(a, m):
    arr = [0, 0]
    g = exgcd(a, m, arr)
    if g != 1:
        return -1
    return (arr[0] % m + m) % m

def solveMod(step, target, mod):
    target = (target % mod + mod) % mod
    g = gcd(step, mod)
    if target % g != 0:
        return -1

    new_step = step // g
    new_target = target // g
    new_mod = mod // g

    inv = modInv(new_step, new_mod)
    if inv == -1:
        return -1
    return (new_target * inv) % new_mod

def crt(a1, m1, a2, m2):
    arr = [0, 0]
    g = exgcd(m1, m2, arr)
    diff = a2 - a1
    if diff % g != 0:
        return -1

    lcm_val = m1 // g * m2
    m1g = m1 // g
    m2g = m2 // g

    k = (diff // g) % m2g
    if k < 0:
        k += m2g

    inv = modInv(m1g, m2g)
    if inv == -1:
        return -1

    k = (k * inv) % m2g
    if k < 0:
        k += m2g

    t = a1 + k * m1
    t = (t % lcm_val + lcm_val) % lcm_val
    return t

def solve(K, N, M, P, Q, X, Y):
    x0 = X[0]
    y0 = Y[0]
    minT = float('inf')
    ans = 0

    lcm_nm = lcm(N, M)

    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        tx = solveMod(Q, dx, N)
        if tx == -1:
            continue

        ty = solveMod(P, dy, M)
        if ty == -1:
            continue

        gx = gcd(Q, N)
        period_x = N // gx

        gy = gcd(P, M)
        period_y = M // gy

        t = crt(tx, period_x, ty, period_y)
        if t == -1:
            continue

        lcm_p = lcm(period_x, period_y)
        if t == 0:
            t = lcm_p

        if t > 0 and t < minT:
            minT = t
            ans = i

    return ans

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = int(data[idx])
    idx += 1
    for _ in range(T):
        K = int(data[idx])
        N = int(data[idx+1])
        M = int(data[idx+2])
        P = int(data[idx+3])
        Q = int(data[idx+4])
        idx +=5

        X = []
        Y = []
        for __ in range(K):
            x = int(data[idx])
            y = int(data[idx+1])
            X.append(x)
            Y.append(y)
            idx +=2

        print(solve(K, N, M, P, Q, X, Y))

if __name__ == "__main__":
    main()