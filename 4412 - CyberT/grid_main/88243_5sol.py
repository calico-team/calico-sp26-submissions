import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    t = int(input_data[0])
    idx = 1
    out = []
    for _ in range(t):
        n = int(input_data[idx])
        idx += 1
        A = list(map(int, input_data[idx:idx+n]))
        idx += n
        
        unique_vals = sorted(set(A))
        m = len(unique_vals)
        
        dp = [[float('inf')] * m for _ in range(n)]
        backtrack = [[-1] * m for _ in range(n)]
        
        for j in range(m):
            dp[0][j] = abs(A[0] - unique_vals[j])
        
        for i in range(1, n):
            min_prev = float('inf')
            min_idx = -1
            for j in range(m):
                if dp[i-1][j] < min_prev:
                    min_prev = dp[i-1][j]
                    min_idx = j
                dp[i][j] = min_prev + abs(A[i] - unique_vals[j])
                backtrack[i][j] = min_idx
            
            min_prev = float('inf')
            min_idx = -1
            for j in range(m-1, -1, -1):
                if dp[i-1][j] < min_prev:
                    min_prev = dp[i-1][j]
                    min_idx = j
                cost = min_prev + abs(A[i] - unique_vals[j])
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    backtrack[i][j] = min_idx
        
        best_j = min(range(m), key=lambda j: dp[n-1][j])
        b = [0] * n
        curr_j = best_j
        for i in range(n-1, -1, -1):
            b[i] = unique_vals[curr_j]
            curr_j = backtrack[i][curr_j]
        
        out.append(' '.join(map(str, b)))
    
    sys.stdout.write('\n'.join(out))

if __name__ == "__main__":
    solve()