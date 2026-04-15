
def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    B = A 
    
    for i in range(0,3):
        B[0] = B[1]
        B[len(A)-1] = B[len(A)-2]
        for j in range(1,len(A)-1):
            '''if j != 0 and j != len(A)-1:'''
            if 0 > (B[j-1]-B[j])*(B[j+1]-B[j]):
                if 0 > (B[j-1]-B[j]):
                    B[j] = B[j] - 1 
                else:
                    B[j] = B[j] + 1 
            elif 0 < (B[j-1]-B[j])*(B[j+1]-B[j]):
                B[j] = B[j]
            elif 0 == (B[j-1]-B[j])*(B[j+1]-B[j]):
                B[j] = B[j]


    return [B[_] for _ in range(N)]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
