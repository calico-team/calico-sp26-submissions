def solve(N, M):
    """
    N rows aur M columns ka grid banao
    """
    grid = [[0 for _ in range(M)] for _ in range(N)]
    
    for i in range(N):
        for j in range(M):
            grid[i][j] = (2 * i + j) % 5   # yeh magic formula hai jo har cross ko unique banati hai
    
    return grid


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()