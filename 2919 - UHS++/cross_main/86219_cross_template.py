def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    pattern = [0, 3, 1, 4, 2]

    ans = []

    for col in range(N):
        ans.append([])
        starting_num = pattern[col % 5]
        for row in range(M):
            ans[col].append((starting_num + row%5) % 5)
    
    return ans

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
