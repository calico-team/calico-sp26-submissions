def solve(K, N, M, P, Q, X, Y):
    asteroid_map = {}
    for i in range(K):
        if (X[i], Y[i]) not in asteroid_map:
            asteroid_map[(X[i], Y[i])] = i

    x, y = X[0], Y[0]
    visited = set()

    while True:
        x = (x + Q) % N
        y = (y + P) % M

        if (x, y) in asteroid_map:
            return asteroid_map[(x, y)]

        if (x, y) in visited:
            break
        visited.add((x, y))

    return -1


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
