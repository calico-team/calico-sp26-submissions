def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    # YOUR CODE HERE
    zarr=[0]*M
    carr=[1,2,3,4]
    oa=[]
    ta=[]
    for i in range(M):
        oa.append(carr[i%4])
        ta.append(carr[(i+2)%4])
    ansarr=[]
    for i in range(N):
        if i%3==0:
            ansarr.append(zarr)
        elif i%3==1:
            ansarr.append(oa)
        else:
            ansarr.append(ta)
    return ansarr



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
