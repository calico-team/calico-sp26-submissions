def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    A_sorted = sorted(A)
    median_val = A_sorted[N // 2]
    the_two_tower_heights = [median_val] * N
    return the_two_tower_heights
    return [0 for _ in range(N)]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()

def read_your_input():
    import sys
    return sys.stdin.read().split()