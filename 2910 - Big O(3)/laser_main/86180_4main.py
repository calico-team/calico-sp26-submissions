def solve(K, N, M, P, Q, X, Y):
    inX = X[0]
    inY = Y[0]
    ans = -1
    while ans == -1:
        inX += Q
        inY += P
        if inX > N:
            inX = inX - N
        if inY > M:
            inY = inY - M
        for j in range(K):
            if inX == X[j] and inY == Y[j]:
                ans = j
                break
    return ans

def main():
    T = int(input())
    for _ in range(T):
        line = input().split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])
        X = []
        Y = []
        for _ in range(K):
            coords = input().split()
            a_i = int(coords[0])
            b_i = int(coords[1])
            X.append(a_i)
            Y.append(b_i)
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()