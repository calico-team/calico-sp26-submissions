def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    # YOUR CODE HERE
        
    LABEL = []
    
    for i in range(N):
        STORE = []
        
        for j in range(M):
            STORE.append((2 * i + j) % 5)
            
        LABEL.append(STORE)
            
    return LABEL
    
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
