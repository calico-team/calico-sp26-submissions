def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    b = [A[0]]
    for i in range(N-2):
        if A[i+1] > A[i]:
            if A[i+2] >= A[i+1]:
                b.append(b[i]+1)
            if A[i+2] < A[i+1]:
                b.append(b[i])
        if A[i+1] == A[i]:
            b.append(b[i-1])
        if A[i+1] < A[i]:
            if A[i+2] <= A[i+1]:
                b.append(b[i]+1)
            if A[i+2] > A[i+1]:
                b.append(b[i])

    b.append(b[-1])

    return [num for num in b]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
