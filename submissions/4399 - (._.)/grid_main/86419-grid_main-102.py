def calc(A, B):
    T = abs(A[len(A) - 1] - A[len(B) - 1])
    for i in range(len(A) - 1):
        T += abs(A[i] - A[i + 1])
        T += abs(B[i] - B[i + 1])
        T += abs(A[i] - B[i])
    return T


def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    B = A.copy()
    B[1] = round(B[0], B[2])    
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
