def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE

    B = [0]*N
    for i in range(N):
        l = A[i-1]  if i > 0  else A[i]
        r = A[i+1] if i < (N-1) else A[i]
        mid = A[i]
        B[i] = sorted([l,mid,r])[1]
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
