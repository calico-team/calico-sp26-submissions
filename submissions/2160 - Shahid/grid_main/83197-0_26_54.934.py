import sys
from functools import lru_cache

def solve():
    N = int(input())
    A = list(map(int, input().split()))
    
    if N == 1:
        print(A[0])
        return
    
    # For small N (<=3), we can use DP with median-based candidates
    # For large N, optimal b[i] = A[i] (copy top row) works well
    # but we need to minimize: sum|A[i]-A[i+1]| + sum|b[i]-b[i+1]| + sum|A[i]-b[i]|
    
    # Key insight: each b[i] contributes to:
    #   |A[i] - b[i]| (vertical)
    #   |b[i] - b[i-1]| (horizontal left, if i>0)
    #   |b[i] - b[i+1]| (horizontal right, if i<N-1)
    #
    # For the bonus (large N), the optimal b[i] is the median of its neighbors:
    # A[i], b[i-1], b[i+1]. But since b values depend on each other, we use DP.
    #
    # For N<=3, brute-force over candidate values.
    # Candidate values for each b[i] are from the set of A values (and neighbors).
    
    # The optimal b[i] must be one of the "interesting" values.
    # For general solution: DP where candidates for b[i] are from sorted A values.
    # Actually for minimizing sum of absolute differences, optimal b[i] values
    # come from the set of A values.
    
    # Collect candidate values
    candidates = sorted(set(A))
    
    if len(candidates) > 300:
        # For large N with many distinct values, b[i] = A[i] is optimal
        # because vertical cost = 0, and horizontal costs are same for both rows
        the_two_tower_heights = A[:]
        print(*the_two_tower_heights)
        return
    
    M = len(candidates)
    val_to_idx = {v: i for i, v in enumerate(candidates)}
    
    # DP: dp[j] = min total cost when b[i] = candidates[j]
    # We process left to right
    
    INF = float('inf')
    
    # dp[j] = min cost considering columns 0..i, with b[i] = candidates[j]
    # cost for column i with b[i]=candidates[j]:
    #   vertical: |A[i] - candidates[j]|
    #   horizontal from prev: |candidates[j] - candidates[prev_j]|
    
    dp = [0] * M
    parent = [[0]*M for _ in range(N)]
    
    # Column 0
    for j in range(M):
        dp[j] = abs(A[0] - candidates[j])
    
    for i in range(1, N):
        new_dp = [INF] * M
        best_from = [0] * M
        
        # For each j, we want min over k of: dp[k] + |candidates[j] - candidates[k]|
        # Since candidates are sorted, we can do this in O(M) using two passes
        
        # Left pass: min(dp[k] - candidates[k]) + candidates[j] for k <= j
        # Right pass: min(dp[k] + candidates[k]) - candidates[j] for k >= j
        
        left_min = INF
        left_idx = 0
        for j in range(M):
            val = dp[j] - candidates[j]
            if val < left_min:
                left_min = val
                left_idx = j
            cost = left_min + candidates[j] + abs(A[i] - candidates[j])
            if cost < new_dp[j]:
                new_dp[j] = cost
                best_from[j] = left_idx
        
        right_min = INF
        right_idx = M - 1
        for j in range(M - 1, -1, -1):
            val = dp[j] + candidates[j]
            if val < right_min:
                right_min = val
                right_idx = j
            cost = right_min - candidates[j] + abs(A[i] - candidates[j])
            if cost < new_dp[j]:
                new_dp[j] = cost
                best_from[j] = right_idx
        
        dp = new_dp
        parent[i] = best_from[:]
    
    # Find best final state
    best_j = 0
    for j in range(M):
        if dp[j] < dp[best_j]:
            best_j = j
    
    # Backtrack
    the_two_tower_heights = [0] * N
    j = best_j
    for i in range(N - 1, -1, -1):
        the_two_tower_heights[i] = candidates[j]
        if i > 0:
            j = parent[i][j]
    
    print(*the_two_tower_heights)


def read_your_input():
    T = int(input())
    for _ in range(T):
        solve()

if __name__ == '__main__':
    read_your_input()
