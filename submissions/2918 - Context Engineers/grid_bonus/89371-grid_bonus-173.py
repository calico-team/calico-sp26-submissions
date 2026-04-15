def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """   
    cost1 = sum(abs(A[i] - A[i+1]) for i in range(N-1)) if N > 1 else 0

    arr_sort_A = sorted(A)
    med = arr_sort_A[N // 2]
    cost2 = sum(abs(x - med) for x in A)

    if cost1 <= cost2:
        return A
    else:
        return [med] * N


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
