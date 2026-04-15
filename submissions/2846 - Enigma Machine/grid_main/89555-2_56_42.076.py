def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    if N == 1:
        return [A[0]]
    cost_c=0
    for i in range(N-1):
        cost_c+=abs(A[i]-A[i+1])
    b_copy = A[:]
    b_sorted=sorted(A)
    m=b_sorted[N//2]
    cost_flat = sum(abs(x-m) for x in A)
    if cost_c<=cost_flat:
        return [m] * N
    else:
        return b_copy

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
