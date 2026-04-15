def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    B=[0]*N
    B[0]=min(A[0],A[1])
    
    for i in range(1,N-1):
        B[i]=sorted([A[i-1],A[i],A[i+1]])[1]
        
    B[N-1]=min(A[N-1],A[N-2])
    return B
    #return [0 for _ in range(N)]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
