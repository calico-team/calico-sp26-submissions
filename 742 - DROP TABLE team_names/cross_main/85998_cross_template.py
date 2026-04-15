import math


def loop_amap(lis, length):
    # TO FUTUREU me AMAPIs as mUCH AS POSSSILBE

    newlis = lis * (math.ceil(length / len(lis)))
    return newlis[:length]

def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    pattern1 = [3, 0, 4, 1, 2]
    pattern2 = [1, 2, 3, 0, 4]
    pattern3 = [0, 4, 1, 2, 3]
    pattern4 = [2, 3, 0, 4, 1]
    pattern5 = [4, 1, 2, 3, 0]
    patterns = [pattern1, pattern2, pattern3, pattern4, pattern5]

    toReturn = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        toReturn[i] = loop_amap(patterns[i % 5], M)



    # YOUR CODE HERE
    return toReturn


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
