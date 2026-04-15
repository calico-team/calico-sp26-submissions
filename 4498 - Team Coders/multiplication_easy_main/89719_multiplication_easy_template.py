import sys
import math
from collections import defaultdict

def solve(N, M, D, cells):
    # Take log of everything: log(a[r]) + log(a[c]) = log(V)
    # This becomes a least-squares problem in log space.
    # We optimize x[i] = log(a[i]) to minimize weighted relative error.
    
    # Strategy:
    # 1. Use log-space: let x[i] = log(a[i]). Then log(a[r]*a[c]) = x[r]+x[c] ~ log(V)
    # 2. Relative error |a[r]*a[c] - V|/V is minimized when x[r]+x[c] ~ log(V)
    # 3. Solve weighted least squares in log space via iterative approach
    # 4. Discard D constraints with highest individual penalty contribution
    
    if M == 0:
        return [1] * N, []
    
    # Build log targets
    log_V = [math.log(c[2]) for c in cells]
    
    # Weighted least squares: minimize sum W_i * (x[R_i] + x[C_i] - log(V_i))^2
    # Use coordinate descent / message passing
    
    # Initialize x with median estimates
    x = [0.0] * (N + 1)  # 1-indexed
    
    # For each node, collect constraints involving it
    node_constraints = defaultdict(list)  # node -> list of (other_node, log_v, weight, idx)
    for i, (R, C, V, W) in enumerate(cells):
        lv = log_V[i]
        node_constraints[R].append((C, lv, W, i))
        node_constraints[C].append((R, lv, W, i))
    
    # Initialize x[i] using weighted median of (log_V - x[other]) estimates
    # Start with x = 0, then do coordinate descent
    
    # Coordinate descent iterations
    for iteration in range(20):
        for node in range(1, N + 1):
            if not node_constraints[node]:
                continue
            # x[node] = weighted mean of (lv - x[other]) over constraints
            total_w = 0.0
            total_wx = 0.0
            for (other, lv, w, idx) in node_constraints[node]:
                residual = lv - x[other]
                total_w += w
                total_wx += w * residual
            if total_w > 0:
                x[node] = total_wx / total_w
    
    # Convert x to integer a values
    A = []
    for i in range(1, N + 1):
        val = round(math.exp(x[i]))
        val = max(1, min(10**9, val))
        A.append(val)
    
    # Now select D constraints to discard: pick those with highest penalty
    penalties = []
    for i, (R, C, V, W) in enumerate(cells):
        prod = A[R - 1] * A[C - 1]
        pen = W * abs(prod - V) / V
        penalties.append((pen, i + 1))  # 1-indexed
    
    penalties.sort(reverse=True)
    discards = [penalties[j][1] for j in range(min(D, M))]
    
    return A, discards


def main():
    input_data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(input_data[idx]); idx += 1
    M = int(input_data[idx]); idx += 1
    D = int(input_data[idx]); idx += 1
    cells = []
    for _ in range(M):
        R = int(input_data[idx]); idx += 1
        C = int(input_data[idx]); idx += 1
        V = int(input_data[idx]); idx += 1
        W = int(input_data[idx]); idx += 1
        cells.append((R, C, V, W))
    
    A, discards = solve(N, M, D, cells)
    
    better_than_me = (A, discards)
    
    sys.stdout.write(' '.join(str(x) for x in A) + '\n')
    sys.stdout.write(' '.join(str(x) for x in [len(discards)] + list(discards)) + '\n')


def read_your_input():
    input_data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(input_data[idx]); idx += 1
    M = int(input_data[idx]); idx += 1
    D = int(input_data[idx]); idx += 1
    cells = []
    for _ in range(M):
        R = int(input_data[idx]); idx += 1
        C = int(input_data[idx]); idx += 1
        V = int(input_data[idx]); idx += 1
        W = int(input_data[idx]); idx += 1
        cells.append((R, C, V, W))
    return N, M, D, cells


if __name__ == '__main__':
    main()