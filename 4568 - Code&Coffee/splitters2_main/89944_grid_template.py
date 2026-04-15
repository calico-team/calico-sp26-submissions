def solve(n, a):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    nums = sorted(set(a))
    m = len(nums)
    dp = [abs(a[0]- nums [i]) for i in range(m)]
    prev = [[-1]*m for _ in range(n)]
    for i in range(1, n):
        left_val = [0]*m
        left_id = [0]*m
        best = dp[0]-nums[0]
        best_i = 0
        left_val[0] = best
        left_id[0] = best_i
        for j in range(1,m):
            cur = dp[j] - nums[j]
            if cur < best:
                best = cur
                best_i = j
            left_val[j] = best
            left_id[j] = best_i
        right_val = [0]*m
        right_id = [0]*m
        best = dp[m-1]+nums[m-1]
        best_i = m-1
        right_val[m-1] = best
        right_id[m-1] = best_i
        for j in range(m-2,-1,-1):
            cur = dp[j]+nums[j]
            if cur<best:
                best = cur
                best_i = j
            right_val[j] = best
            right_id[j] = best_i
        new_dp = [0]*m
        for j in range(m):
            v = nums[j]
            left_cost = left_val[j]+v
            right_cost = right_val[j]-v
            if left_cost<=right_cost:
                new_dp[j] = abs(a[i]-v)+left_cost
                prev[i][j] = left_id[j]
            else:
                new_dp[j] = abs(a[i]-v)+right_cost
                prev[i][j] = right_id[j]
        dp = new_dp
    pos = 0
    for i in range(1,m):
        if dp[i]<dp[pos]:
            pos = i
    b = [0]*n
    for i in range(n-1,-1,-1):
        b[i] = nums[pos]
        if(i>0):
            pos = prev[i][pos]
    return b




def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
