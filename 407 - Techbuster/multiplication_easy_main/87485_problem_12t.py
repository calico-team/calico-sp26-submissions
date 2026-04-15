import sys
import numpy as np

def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    P = int(data[idx]); idx+=1
    M= int(data[idx]); idx+=1
    D = int(data[idx]); idx+=1

    if M == 0:
        a = [1] * P
        sys.stdout.write(' '.join(map(str, a)) + '\n0\n')
        return

    arr = np.array(data[idx:idx+M*4], dtype=np.float64).reshape(M, 4)

    R = arr[:,0].astype(np.int32) - 1
    C =arr[:,1].astype(np.int32) - 1
    V = arr[:,2]
    W = arr[:,3]
    logV = np.log(V)

    x = np.zeros(P, dtype=np.float64)
    MAX_LOG = 20.7232658  # log(10^9)

    if M <= 100000:
        init_iter, outer, inner = 80, 6, 40
    elif M <= 500000:
        init_iter, outer, inner = 50, 5, 30
    else:
        init_iter, outer, inner = 30, 4, 20

    def damped_cd(Ra, Ca, lVa, Wa, n_iter, alpha=0.5):
        if len(Ra) == 0:
            return
        tw = np.bincount(Ra, weights=Wa, minlength=P) + np.bincount(Ca, weights=Wa, minlength=P)
        tw = np.where(tw == 0, 1.0, tw)
        for _ in range(n_iter):
            cr = np.bincount(Ra, weights=Wa*(lVa - np.clip(x[Ca], -MAX_LOG, MAX_LOG)), minlength=P)
            cc = np.bincount(Ca, weights=Wa*(lVa - np.clip(x[Ra], -MAX_LOG, MAX_LOG)), minlength=P)
            x[:] = (1-alpha)*x + alpha*np.clip((cr+cc)/tw, -MAX_LOG, MAX_LOG)

    damped_cd(R,C, logV, np.ones(M), init_iter)

    D_actual = min(D, M)
    mask = np.ones(M, dtype=bool)

    for _ in range(outer):
        xsum= np.clip(x[R], -MAX_LOG, MAX_LOG) + np.clip(x[C], -MAX_LOG, MAX_LOG)
        prod = np.exp(xsum)
        pen =W * np.abs(prod - V) / V
        pen =np.nan_to_num(pen, nan=1e18, posinf=1e18, neginf=0.0)
        mask[:] = True
        if D_actual >0:
            mask[np.argpartition(pen, -D_actual)[-D_actual:]] = False
        damped_cd(R[mask], C[mask], logV[mask], W[mask], inner)

    a = np.clip(np.round(np.exp(np.clip(x, 0, MAX_LOG))), 1, 10**9).astype(np.int64)

    prod_f= a[R].astype(np.float64) * a[C].astype(np.float64)
    pen_f =W * np.abs(prod_f - V) / V
    pen_f = np.nan_to_num(pen_f, nan=1e18, posinf=1e18, neginf=0.0)

    if D_actual >0:
        disc = (np.argpartition(pen_f, -D_actual)[-D_actual:] + 1).tolist()
    else:
        disc = []

    out = [' '.join(map(str, a.tolist()))]
    out.append(str(len(disc)) + (' ' + ' '.join(map(str, disc)) if disc else ''))
    sys.stdout.write('\n'.join(out) + '\n')

def read_input():
    return sys.stdin.buffer.read()

solve()