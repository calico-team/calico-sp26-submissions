import sys
import math
from collections import defaultdict

input = sys.stdin.readline

def solve(N, M, D, cells):
    if M == 0:
        return [1] * N, []
    
    # Work in log space: x[i] = log(a[i])
    # Want x[R] + x[C] ≈ log(V) for each constraint
    # Minimize weighted least squares: Σ W_i * (x[R_i] + x[C_i] - log(V_i))^2
    # Then discard top-D by actual penalty, re-optimize
    
    log_V = [math.log(c[2]) for c in cells]
    
    def optimize_log_space(active_indices):
        """Weighted least squares in log space using iterative approach"""
        if not active_indices:
            return [0.0] * (N + 1)
        
        # Iterative coordinate descent
        x = [0.0] * (N + 1)  # 1-indexed
        
        # Build adjacency for coordinate descent
        # For each node i: x[i] = (Σ W_k*(logV_k - x[j])) / Σ W_k
        # where k are constraints involving i, j is the other node
        
        for iteration in range(200):
            x_old = x[:]
            for i in range(1, N + 1):
                num = 0.0
                den = 0.0
                for k in active_indices:
                    R, C, V, W = cells[k]
                    if R == i:
                        num += W * (log_V[k] - x[C])
                        den += W
                    elif C == i:
                        num += W * (log_V[k] - x[R])
                        den += W
                if den > 0:
                    x[i] = num / den
            
            # Check convergence
            diff = sum(abs(x[i] - x_old[i]) for i in range(1, N+1))
            if diff < 1e-9:
                break
        
        return x
    
    def compute_penalties(x, active_indices):
        penalties = []
        for k in active_indices:
            R, C, V, W = cells[k]
            pred = x[R] + x[C]
            actual_ratio = abs(math.exp(pred) - V) / V if V > 0 else 0
            # relative error in original space
            penalty = W * actual_ratio
            penalties.append((penalty, k))
        return penalties
    
    def x_to_A(x):
        A = []
        for i in range(1, N + 1):
            val = round(math.exp(x[i]))
            val = max(1, min(10**9, val))
            A.append(val)
        return A
    
    # For large M, coordinate descent over all nodes is O(M) per iteration
    # which is acceptable
    
    # Initial optimization with all constraints
    active = list(range(M))
    
    # Use sparse structure for efficiency
    def optimize_sparse(active_indices):
        # Build per-node constraint lists
        node_constraints = defaultdict(list)
        for k in active_indices:
            R, C, V, W = cells[k]
            node_constraints[R].append((k, C))
            node_constraints[C].append((k, R))
        
        x = [0.0] * (N + 1)
        
        for iteration in range(500):
            max_diff = 0.0
            for i in range(1, N + 1):
                if not node_constraints[i]:
                    continue
                num = 0.0
                den = 0.0
                for k, j in node_constraints[i]:
                    W = cells[k][3]
                    num += W * (log_V[k] - x[j])
                    den += W
                if den > 0:
                    new_val = num / den
                    max_diff = max(max_diff, abs(new_val - x[i]))
                    x[i] = new_val
            if max_diff < 1e-10:
                break
        
        return x
    
    x = optimize_sparse(active)
    
    # Discard top D by penalty
    if D > 0:
        penalties = []
        for k in active:
            R, C, V, W = cells[k]
            pred_log = x[R] + x[C]
            pred = math.exp(pred_log)
            rel_err = abs(pred - V) / V
            penalties.append((W * rel_err, k))
        
        penalties.sort(reverse=True)
        discard_set = set(k for _, k in penalties[:D])
        active = [k for k in active if k not in discard_set]
        
        # Re-optimize without discarded
        x = optimize_sparse(active)
        
        # Try to improve discards by re-evaluating
        # Compute penalties again and re-discard
        all_penalties = []
        for k in range(M):
            R, C, V, W = cells[k]
            pred_log = x[R] + x[C]
            pred = math.exp(pred_log)
            rel_err = abs(pred - V) / V
            all_penalties.append((W * rel_err, k))
        
        all_penalties.sort(reverse=True)
        discard_set = set(k for _, k in all_penalties[:D])
        active = [k for k in range(M) if k not in discard_set]
        
        # Final optimization
        x = optimize_sparse(active)
    else:
        discard_set = set()
    
    A = x_to_A(x)
    
    # Final penalty check - try to improve with integer rounding
    # Try small perturbations around rounded values
    def total_penalty(A_try, active_idx):
        total = 0.0
        for k in active_idx:
            R, C, V, W = cells[k]
            pred = A_try[R-1] * A_try[C-1]
            total += W * abs(pred - V) / V
        return total
    
    # Convert back: discards are 1-indexed
    discards = [k + 1 for k in discard_set]
    
    return A, discards


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))

if __name__ == '__main__':
    main()