from math import gcd

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]
    pts = {(X[i], Y[i]): i for i in range(1, K)}
    
    cx, cy = x0, y0
    period = (N * M) // gcd(N, M)
    
    for t in range(1, period + 1):
        cx = (cx + Q) % N
        cy = (cy + P) % M
        if (cx, cy) in pts:
            return pts[(cx, cy)]
        if cx == x0 and cy == y0:
            return 0
    
    return 0

def main():
    T = int(input())
    for _ in range(T):
        line = input().split()
        K, N, M, P, Q = int(line[0]), int(line[1]), int(line[2]), int(line[3]), int(line[4])
        X, Y = [], []
        for _ in range(K):
            coords = input().split()
            X.append(int(coords[0]))
            Y.append(int(coords[1]))
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()