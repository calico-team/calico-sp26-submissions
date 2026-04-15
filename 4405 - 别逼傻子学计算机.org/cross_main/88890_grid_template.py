def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    # YOUR CODE HERE
    Answer = [[0 for i in range (0,M)] for j in range(N) ]
    Set = [0,1,2,3,4]
    for j in range (0,N):
        for i in range (0,M):

            Answer[j][i] = Set[(i+3*j)%5]
    return Answer


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
