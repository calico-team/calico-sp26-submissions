def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    ans = []
    for i in range(N):
        if i == 0:
            ans.append(A[i])
        elif i == N-1:
            ans.append(A[i])
        else:
            ans.append(A[i]+ans[i-1]+A[i+1]-max(A[i],ans[i-1],A[i+1])-min(A[i],ans[i-1],A[i+1]))
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
