def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    INF = 10**18
    dp_prev = {}

    dp_prev[A[0]] = 0

    for i in range(1, N):
        dp_curr = {}

        for prev_val, cost in dp_prev.items():

            for b in range(A[i] - 1, A[i] + 2):
                if b < 0:
                    continue

                new_cost = cost + abs(A[i] - b) + abs(prev_val - b)

                if b not in dp_curr:
                    dp_curr[b] = new_cost
                else:
                    dp_curr[b] = min(dp_curr[b], new_cost)

        dp_prev = dp_curr

    return [min(dp_prev, key=dp_prev.get)] * N


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(" ".join(str(x) for x in result))


if __name__ == "__main__":
    main()
