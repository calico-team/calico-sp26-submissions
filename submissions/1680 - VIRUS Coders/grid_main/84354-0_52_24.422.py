def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    L = [0] * N
    R = [0] * N

    L[0] = A[0]
    R[0] = A[0]

    for i in range(1, N):
        if A[i] < L[i - 1]:
            L[i] = A[i]
            R[i] = L[i - 1]
        elif A[i] > R[i - 1]:
            L[i] = R[i - 1]
            R[i] = A[i]
        else:
            L[i] = A[i]
            R[i] = A[i]

    B = [0] * N
    B[N - 1] = L[N - 1]

    for i in range(N - 2, -1, -1):
        if B[i + 1] < L[i]:
            B[i] = L[i]
        elif B[i + 1] > R[i]:
            B[i] = R[i]
        else:
            B[i] = B[i + 1]

    return B
    # return [0 for _ in range(N)]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
