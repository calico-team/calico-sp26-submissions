def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    L = [0] * N
    R = [0] * N
    L[0] = R[0] = A[0]
    for i in range(1, N):
        a = A[i]
        if a < L[i - 1]:
            L[i] = a
            R[i] = L[i - 1]
        elif a > R[i - 1]:
            L[i] = R[i - 1]
            R[i] = a
        else:
            L[i] = a
            R[i] = a
    B = [0] * N
    B[-1] = L[-1]
    for i in range(N - 2, -1, -1):
        B[i] = max(L[i], min(R[i], B[i + 1]))
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
