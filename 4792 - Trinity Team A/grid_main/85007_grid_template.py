def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    row2 = [0 for _ in range(N)]
    row2[0] = A[0]
    row2[-1] = A[-1]
    for i in range(1, N//2):
        row2[i] = abs(row2[i-1] - A[i])
    for i in range(N-2, N//2+1, -1):
        row2[i] = abs(row2(i+1) - A[i])
    
    row2[N//2] = minimizeCost(row2[N//2 - 2], row2[N//2], A[N//2 - 1])
    
    return row2


def minimizeCost(A, B, C):
    ans = A + B + C
    for i in range(1, 2 * C + 1):
        j = 0
        while (i * j <= 2 * C):

            ans = min(ans, abs(A - i) + abs(B - j) + abs(i * j - C))
            j += 1

    return ans


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
