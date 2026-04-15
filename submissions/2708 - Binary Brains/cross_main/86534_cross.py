def solve(N, M):
    g = []
    for r in range(N):
        row = []
        for c in range(M):
            row.append((2 * r + c) % 5)
        g.append(row)
    return g


def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        N = int(temp[0])
        M = int(temp[1])
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()
