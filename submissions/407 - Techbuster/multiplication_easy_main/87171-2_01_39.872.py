import sys
import numpy as np

def solve():
    data= sys.stdin.buffer.read().split()
    idx = 0
    P =int(data[idx]); idx+=1
    M = int(data[idx]); idx+=1
    D= int(data[idx]); idx+=1

    arr = np.array(data[idx:idx+M*4], dtype=np.int64).reshape(M, 4)

    R= (arr[:,0]-1).astype(np.int32)
    C= (arr[:,1]-1).astype(np.int32)
    V= arr[:,2].astype(np.float64)
    W = arr[:,3].astype(np.float64)
    logV =np.log(V)

    x = np.zeros(P, dtype=np.float64)
    MAX_LOG= np.log(10**9)

    if M<= 100000:
        init_iter, outer, inner = 80, 6, 40
    elif M <= 500000:
        init_iter, outer, inner = 50, 5, 30
    else:
        init_iter, outer, inner = 30,4, 20

    def damped_cd(Ra, Ca, lVa, Wa, n_iter, alpha=0.5):
        if len(Ra) == 0:
            return
        tw = np.bincount(Ra, weights=Wa, minlength=P) + np.bincount(Ca, weights=Wa, minlength=P)
        tw = np.where(tw == 0, 1.0, tw)
        for _ in range(n_iter):
            xC = np.clip(x[Ca], -MAX_LOG, MAX_LOG)
            xR = np.clip(x[Ra], -MAX_LOG, MAX_LOG)
            cr= np.bincount(Ra, weights=Wa*(lVa - xC), minlength=P)
            cc = np.bincount(Ca, weights=Wa*(lVa - xR), minlength=P)
            x_new = (cr + cc) / tw
            x[:] = (1 - alpha)*x + alpha*np.clip(x_new, -MAX_LOG, MAX_LOG)

    damped_cd(R, C, logV, np.ones(M, dtype=np.float64), init_iter)

    mask =np.ones(M, dtype=bool)
    D_actual = min(D, M)

    for _ in range(outer):
        xR = np.clip(x[R], -MAX_LOG, MAX_LOG)
        xC= np.clip(x[C], -MAX_LOG, MAX_LOG)
        prod = np.exp(xR + xC)
        penalties = W * np.abs(prod - V) / V
        mask[:] = True
        if D_actual > 0:
            mask[np.argpartition(penalties, -D_actual)[-D_actual:]] = False
        damped_cd(R[mask], C[mask], logV[mask], W[mask], inner)

    a =np.round(np.exp(np.clip(x, 0, MAX_LOG))).astype(np.int64)
    a = np.clip(a, 1, 10**9)

    prod_final = a[R].astype(np.float64) * a[C].astype(np.float64)
    penalties_final = W * np.abs(prod_final - V) / V

    if D_actual >0:
        discard_set = (np.argpartition(penalties_final, -D_actual)[-D_actual:] + 1).tolist()
    else:
        discard_set = []

    out =[' '.join(map(str, a.tolist()))]
    out.append(str(len(discard_set)) + (' ' + ' '.join(map(str, discard_set)) if discard_set else ''))
    sys.stdout.write('\n'.join(out) + '\n')

def read_input():
    return sys.stdin.buffer.read()

solve()