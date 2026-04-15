def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """

    tempL = [0] * N
    
    l = [0] * N
    r = [0] * N

    l[0] = A[0]
    r[0] = A[0]

    for i in range(1, N):
        x = A[i]

        if x < l[i - 1]:
            l[i] = x
            r[i] = l[i - 1]

        elif x > r[i - 1]:
            l[i] = r[i - 1]
            r[i] = x

        else:
            l[i] = x
            r[i] = x

    b = [0] * N
    b[N - 1] = l[N - 1]

    for i in range(N - 2, -1, -1):
        x = b[i + 1]

        if x < l[i]:
            b[i] = l[i]
        elif x > r[i]:
            b[i] = r[i]
        else:
            b[i] = x

    return b


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()