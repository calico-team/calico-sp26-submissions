def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    if N == 0:
        return []
    if N == 1:
        the_two_tower_heights = [A[0]]
        return the_two_tower_heights

    the_two_tower_heights = [0] * N


    the_two_tower_heights[0] = sorted([A[0], A[0], A[1]])[1]

    for i in range(1, N - 1):
        vals = [A[i - 1], A[i], A[i + 1]]
        vals.sort()
        the_two_tower_heights[i] = vals[1]

    the_two_tower_heights[N - 1] = sorted([A[N - 2], A[N - 1], A[N - 1]])[1]

    return the_two_tower_heights


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
