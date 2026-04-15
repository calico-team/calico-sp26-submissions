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
        
        dp = [[float('inf')] * 3 for _ in range(n)]
        choice = [[-1] * 3 for _ in range(n)]
        
        values = [A[0], A[0] - 1, A[0] + 1]
        for j in range(3):
            dp[0][j] = 0
            choice[0][j] = -1
            
        for i in range(1, n):
            prev_vals = [A[i-1], A[i-1] - 1, A[i-1] + 1]
            curr_vals = [A[i], A[i] - 1, A[i] + 1]
            for j in range(3):
                for k in range(3):
                    cost = abs(curr_vals[j] - prev_vals[k]) + abs(curr_vals[j] - A[i])
                    if i == 1:
                        cost += abs(prev_vals[k] - A[0])
                    if dp[i-1][k] + cost < dp[i][j]:
                        dp[i][j] = dp[i-1][k] + cost
                        choice[i][j] = k
        
        best = min(range(3), key=lambda j: dp[n-1][j])
        b = [0] * n
        curr = best
        for i in range(n-1, -1, -1):
            vals = [A[i], A[i] - 1, A[i] + 1]
            b[i] = vals[curr]
            curr = choice[i][curr]
        
        out.append(' '.join(map(str, b)))
    
    sys.stdout.write('\n'.join(out))

if __name__ == "__main__":
    solve()