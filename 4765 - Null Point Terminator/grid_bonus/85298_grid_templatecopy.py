def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    l = [0] * N
    r = [0] * N

    low = high = A[0]
    l[0] = r[0] = A[0]

    for i in range(1, N):
        x = A[i]
        if x < low:
            high = low
            low = x
        elif x > high:
            low = high
            high = x
        else:
            low = high = x
        l[i] = low
        r[i] = high

    res = [0] * N
    res[N - 1] = l[N - 1]  

    for i in range(N - 2, -1, -1):
        x = res[i + 1]
        if x < l[i]:
            res[i] = l[i]
        elif x > r[i]:
            res[i] = r[i]
        else:
            res[i] = x

    return res


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
