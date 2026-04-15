def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
def grid(A):
    N = len(A)
    if N == 0:
        return []
    
    # Option 1: B ko A jaisa hi rakhna (top row ke differences)
    cost_copy = 0
    for i in range(N - 1):
        cost_copy += abs(A[i] - A[i + 1])
    
    # Option 2: saari B ek hi number (median) pe rakhna
    sorted_A = sorted(A)
    median = sorted_A[N // 2]
    cost_median = sum(abs(x - median) for x in A)
    
    # Jo better hai woh choose karo
    if cost_median < cost_copy:
        return [median] * N
    else:
        return A[:]
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
