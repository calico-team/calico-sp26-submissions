def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    
    def tcost(B):
        c = 0
        for i in range(N):
            c += abs(A[i] - B[i])
        for i in range(N - 1):
            c += abs(B[i] - B[i + 1])
        return c

    
    sa = sorted(A)
    med = sa[N // 2]
    Bmed = [med] * N

    
    bc = list(A)

    if tcost(Bmed) <= tcost(bc):
        return Bmed
    else:
        return bc


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()

