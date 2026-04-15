def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    sum = 0
    for i in range(N):
        sum += A[i]
    avg = int(sum // N)
    ans1 = 0
    for i in range(N):
        ans1 += abs(A[i] - avg)
    ans2 = 0
    for i in range(N-1):
        ans2 += abs(A[i+1] - A[i])
    
    copy = []
    for i in range(N):
        copy.append(A[i])
    copy.sort()
    medi = int(N//2)
    ans3 = 0
    for i in range(N):
        ans3 += abs(A[i] - copy[medi])

    if min(ans1, ans2, ans3) == ans1:
        ans = []
        for _ in range(N):
            ans.append(avg)
        return ans
    elif min(ans1, ans2, ans3) == ans2:
        return A
    else:
        ans = []
        for _ in range(N):
            ans.append(copy[medi])
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
