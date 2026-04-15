def solve(N, M):
    grid = [[0 for _ in range(M)] for _ in range(N)]
    for r in range(N):
        for c in range(M):
            grid[r][c] = (2 * r + c) % 5
    return grid


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
