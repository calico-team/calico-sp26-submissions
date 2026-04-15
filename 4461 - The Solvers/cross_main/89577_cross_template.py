def solve(N, M):
    grid = [[0]*M for _ in range(N)]
    
    for i in range(N):
        if i % 3 == 0:
           
            for j in range(M):
                grid[i][j] = 0
                
        elif i % 3 == 1:
           
            for j in range(M):
                grid[i][j] = (j % 4) + 1
                
        else:
           
            for j in range(M):
                grid[i][j] = 4

    return grid


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = solve(N, M)
        for row in grid:
            print(*row)


if __name__ == '__main__':
    main()