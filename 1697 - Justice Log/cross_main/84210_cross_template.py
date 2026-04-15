def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    grid = []
    x = [0,1,2,3,4]
    y = [0,2,4,1,3]
    i = 0
    adjust = 0
    for rowindex in range(N):
        i =0
        adjust = y[rowindex % 5]
        grid.append([])
        while i < M:
            what_to_append = x[(i+adjust)%5]
            grid[-1].append(what_to_append)
            i += 1
    

        
        
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
