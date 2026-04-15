import sys
import math
import numpy as np
from scipy import sparse
from scipy.sparse.linalg import lsqr

def solve(N, M, D, cells):
    if M == 0:
        return [1] * N, []
    
    cells_arr = np.array(cells, dtype=np.int64)
    R_arr = cells_arr[:, 0] - 1  # 0-indexed
    C_arr = cells_arr[:, 1] - 1
    V_arr = cells_arr[:, 2].astype(np.float64)
    W_arr = cells_arr[:, 3].astype(np.float64)
    log_V = np.log(V_arr)

    def compute_b(active_mask):
        act_idx = np.where(active_mask)[0]
        if len(act_idx) == 0:
            return np.zeros(N)
        
        act_R   = R_arr[act_idx]
        act_C   = C_arr[act_idx]
        act_lv  = log_V[act_idx]
        act_W   = W_arr[act_idx]
        sqrt_W  = np.sqrt(act_W)
        rhs     = sqrt_W * act_lv
        n_eq    = len(act_idx)

        rows = np.concatenate([np.arange(n_eq), np.arange(n_eq)])
        cols = np.concatenate([act_R, act_C])
        data = np.concatenate([sqrt_W, sqrt_W])

        A_mat = sparse.csr_matrix((data, (rows, cols)), shape=(n_eq, N))
        result = lsqr(A_mat, rhs, iter_lim=2000, atol=1e-12, btol=1e-12)
        return result[0]

    def get_penalties(b):
        pred = np.exp(np.clip(b[R_arr] + b[C_arr], -40, 40))
        return W_arr * np.abs(pred - V_arr) / V_arr

    # Step 1: Fit with all constraints
    active_mask = np.ones(M, dtype=bool)
    b = compute_b(active_mask)

    # Step 2: Discard D worst constraints
    if D > 0:
        pens = get_penalties(b)
        worst = np.argpartition(pens, -D)[-D:]
        active_mask[worst] = False
        b = compute_b(active_mask)

        # Step 3: Iterative swap refinement
        for _ in range(30):
            pens    = get_penalties(b)
            act_idx = np.where(active_mask)[0]
            dis_idx = np.where(~active_mask)[0]
            if len(dis_idx) == 0:
                break

            wa = act_idx[np.argmax(pens[act_idx])]   # worst active
            bd = dis_idx[np.argmin(pens[dis_idx])]   # best discarded

            # Swap only if it clearly helps
            if pens[bd] < pens[wa] * 0.95:
                active_mask[wa] = False
                active_mask[bd] = True
                b = compute_b(active_mask)
            else:
                break

    # Step 4: Convert log-space solution to integers
    A = [
        max(1, min(10**9, int(round(math.exp(float(np.clip(b[r], -20, 20)))))))
        for r in range(N)
    ]
    discards = (np.where(~active_mask)[0] + 1).tolist()  # 1-indexed
    return A, discards


def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1
    D = int(data[idx]); idx += 1
    cells = []
    for _ in range(M):
        R = int(data[idx]); idx += 1
        C = int(data[idx]); idx += 1
        V = int(data[idx]); idx += 1
        W = int(data[idx]); idx += 1
        cells.append((R, C, V, W))

    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))

if __name__ == '__main__':
    main()