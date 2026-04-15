def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    B = [0] * N
    
    B[0] = A[0]  # Start with the first element of B equal to the first element of A
    B[N-1] = A[N-1]  # Set the last element of B equal to the last element of A
    for i in range(1, N-1):
        B[i] = int((A[i] + B[i-1])/2)
    C = B.copy()
    x = 0
    while(True):
        x += 1
        B = C.copy()
        for i in range(1, N-1):
            if(cost(A, C, i, C[i]) > cost(A, B, i, C[i]+1)):
                C[i] += cost(A, C, i, C[i]) - cost(A, B, i, C[i]+1)
            elif(cost(A, C, i, C[i]) > cost(A, B, i, C[i]-1)):
                C[i] -= cost(A, C, i, C[i]) - cost(A, B, i, C[i]-1)
        if(B == C or x > 1000):
            break
    return B

def cost(A, B, i, num):
    return abs(A[i] - num) + abs(num - A[i+1]) + abs(num - B[i-1])


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
