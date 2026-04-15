def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    vals = set(A)
    rows = []
    for i in vals:
        rows.append([i for _ in range(N)])
    rows.sort(key=lambda row: rowDiff(row, A, N))
    if sum(abs(a - b) for a, b in zip(A, A[1:])) < rowDiff(rows[0], A, N):
        return A
    return rows[0]


def rowDiff(A, B, N):
    diff = 0 
    for i in range(N):
        diff += abs(A[i]-B[i])
    return diff


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
