def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    if N == 1:
        return A
    if N == 2:
        return A
    if N == 3:
        x = 10**18
        out = [A[0], x, A[2]]
        for i in range(1, A[1]+1):
            x = min(x, abs(A[0] - i) + abs(A[1] - i) + abs(A[2] - i))
        return out

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
