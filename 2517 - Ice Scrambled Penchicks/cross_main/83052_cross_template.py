def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    # YOUR CODE HERE
    carr=[0,1,2,3,4]
    oa=[]
    ta=[]
    tha=[]
    fa=[]
    fia=[]
    for i in range(M):
        oa.append(carr[i%5])
        ta.append(carr[(i+1)%5])
        tha.append(carr[(i+2)%5])
        fa.append(carr[(i+3)%5])
        fia.append(carr[(i+4)%5])
    ansarr=[]
    for i in range(N):
        if i%5==0:
            ansarr.append(fia)
        elif i%5==1:
            ansarr.append(ta)
        elif i%5==2:
            ansarr.append(fa)
        elif i%5==3:
            ansarr.append(oa)
        else:
            ansarr.append(tha)
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
