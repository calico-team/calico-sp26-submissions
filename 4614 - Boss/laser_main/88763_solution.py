def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def solve():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        astrds = []
        pos_indx = {}
        for i in range(K):
            x, y = map(int, input().split())
            astrds.append((x, y))
            pos_indx[(x, y)] = i
        prd = lcm(N // gcd(Q, N), M // gcd(P, M))
        x, y = astrds[0]
        for _ in range(1, prd + 1):
            x = (x + Q) % N
            y = (y + P) % M
            if (x, y) in pos_indx:
                print(pos_indx[(x, y)])
                break

if __name__ == "__main__":
    solve()