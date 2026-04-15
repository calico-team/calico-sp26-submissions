def solve(N, M):
    grid = []
    
    for i in range(N):
        row = []
        for j in range(M):
            value = (i + j) % 5
            row.append(value)
        grid.append(row)
    
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
