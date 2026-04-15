def solve(N, M):
    grid = []
    
    for i in range(N):
        row = []
        for j in range(M):
            row.append((i + j) % 5)
        grid.append(row)
    
    return grid


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = solve(N, M)
        for row in grid:
            print(' '.join(map(str, row)))


if __name__ == '__main__':
    main()