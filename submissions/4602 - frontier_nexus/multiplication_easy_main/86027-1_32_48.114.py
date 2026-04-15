import sys
import numpy as np

def solve():
    raw = sys.stdin.buffer.read()
    nl  = raw.index(b'\n')
    hdr = raw[:nl].split()
    N   = int(hdr[0]); M = int(hdr[1]); D = int(hdr[2])

    # Fast parse: replace newlines with spaces then fromstring
    flat = np.fromstring(raw[nl+1:].replace(b'\n', b' '), dtype=np.int64, sep=' ')
    flat = flat[:4*M].reshape(M, 4)
    R = flat[:, 0]; C = flat[:, 1]; V = flat[:, 2]; W = flat[:, 3]

    Wf    = W.astype(np.float64)
    Vf    = V.astype(np.float64)
    WlogV = Wf * np.log(Vf)

    # Precompute sum_w once — constant across CD iterations
    sum_w  = np.bincount(R, weights=Wf, minlength=N+1) + \
             np.bincount(C, weights=Wf, minlength=N+1)
    inv_sw = np.where(sum_w > 0, 1.0 / np.where(sum_w > 0, sum_w, 1.0), 0.0)

    # Coordinate descent in log space (only 2 bincounts per iteration)
    x       = np.zeros(N + 1, dtype=np.float64)
    damping = 0.35

    for _ in range(80):
        xC      = x[C]; xR = x[R]
        sum_rhs = np.bincount(R, weights=WlogV - Wf*xC, minlength=N+1) + \
                  np.bincount(C, weights=WlogV - Wf*xR, minlength=N+1)
        new_x   = (1 - damping) * (sum_rhs * inv_sw) + damping * x
        if np.max(np.abs(new_x - x)) < 1e-9:
            x = new_x; break
        x = new_x

    # Round float solution to integers
    a    = np.clip(np.round(np.exp(x)), 1, 10**9).astype(np.int64)
    a[0] = 1

    # CSR adjacency for fast per-node constraint lookup
    order_R = np.argsort(R, kind='stable')
    order_C = np.argsort(C, kind='stable')
    R_bnd   = np.searchsorted(R[order_R], np.arange(N + 2))
    C_bnd   = np.searchsorted(C[order_C], np.arange(N + 2))

    # Initial discard selection
    pen = Wf * np.abs(a[R].astype(np.float64) * a[C].astype(np.float64) - Vf) / Vf
    if 0 < D < M:
        disc_mask            = np.zeros(M, dtype=bool)
        disc_mask[np.argpartition(pen, M - D)[-D:]] = True
    elif D >= M:
        disc_mask = np.ones(M, dtype=bool)
    else:
        disc_mask = np.zeros(M, dtype=bool)

    # One pass of integer local search: weighted median per node
    for node in range(1, N + 1):
        all_idxs = np.concatenate([order_R[R_bnd[node]:R_bnd[node+1]],
                                   order_C[C_bnd[node]:C_bnd[node+1]]])
        if len(all_idxs) == 0:
            continue
        kidxs = all_idxs[~disc_mask[all_idxs]]
        if len(kidxs) == 0:
            continue

        others = np.where(R[kidxs] == node, a[C[kidxs]], a[R[kidxs]])
        nz     = others != 0
        if not np.any(nz):
            continue

        ki_nz   = kidxs[nz]
        oth_nz  = others[nz].astype(np.float64)
        targets = V[ki_nz].astype(np.float64) / oth_nz
        Wi_nz   = W[ki_nz].astype(np.float64)
        Vi_nz   = V[ki_nz].astype(np.float64)

        # Weighted median
        ord2 = np.argsort(targets)
        ts   = targets[ord2]; ws = Wi_nz[ord2]
        cumw = np.cumsum(ws)
        mi   = np.searchsorted(cumw, cumw[-1] / 2)
        med  = max(1, min(10**9, int(round(ts[min(mi, len(ts)-1)]))))

        orig     = int(a[node])
        best_val = orig
        best_c   = float(np.sum(Wi_nz * np.abs(orig * oth_nz - Vi_nz) / Vi_nz))

        for d in (-1, 0, 1):
            cand = max(1, min(10**9, med + d))
            nc   = float(np.sum(Wi_nz * np.abs(cand * oth_nz - Vi_nz) / Vi_nz))
            if nc < best_c:
                best_c = nc; best_val = cand

        a[node] = best_val

    # Final penalty and discard selection
    pen = Wf * np.abs(a[R].astype(np.float64) * a[C].astype(np.float64) - Vf) / Vf
    if 0 < D <= M:
        d_actual    = min(D, M)
        disc_sorted = sorted(int(i)+1 for i in np.argpartition(pen, M - d_actual)[-d_actual:])
    else:
        disc_sorted = []

    out_a = ' '.join(str(int(a[i])) for i in range(1, N+1))
    out_d = (str(len(disc_sorted)) + ' ' + ' '.join(str(s) for s in disc_sorted)) if disc_sorted else '0'
    better_than_me = out_a + '\n' + out_d
    sys.stdout.write(better_than_me + '\n')


def read_your_input():
    return sys.stdin.buffer.read().decode()


solve()