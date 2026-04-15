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
        B[i] = int((A[i] + 2*B[i-1])/3)
    for i in range(1, N-1):
        if B[i-1] == B[i+1]:
            B[i] = B[i-1]
    return B


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
