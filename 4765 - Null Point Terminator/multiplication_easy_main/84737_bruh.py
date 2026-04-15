import sys
import numpy as np

def main():
    inp = sys.stdin.read().split()
    p = 0
    n = int(inp[p]); p += 1
    m = int(inp[p]); p += 1
    d = int(inp[p]); p += 1

    dat = np.array(inp[p:p+4*m], dtype=float).reshape(m, 4)
    r = dat[:, 0].astype(int) - 1
    c = dat[:, 1].astype(int) - 1
    v = dat[:, 2]
    w = dat[:, 3]

    sv = np.sqrt(v)
    a = np.ones(n, dtype=int)
    for j in range(n):
        mask = (r == j) | (c == j)
        if np.any(mask):
            vals = sv[mask]
            a[j] = max(1, int(round(np.median(vals))))

    #2 rounds
    for it in range(2):
        for j in range(n):
            mask_r = r == j
            mask_c = c == j
            targets = []
            if np.any(mask_r):
                ov = a[c[mask_r]].astype(float)
                good = ov > 0
                if np.any(good):
                    targets.append(v[mask_r][good] / ov[good])
            if np.any(mask_c):
                ov = a[r[mask_c]].astype(float)
                good = ov > 0
                if np.any(good):
                    targets.append(v[mask_c][good] / ov[good])
            if targets:
                all_t = np.concatenate(targets)
                a[j] = max(1, min(10**9, int(round(np.median(all_t)))))

    ################
    prods = a[r].astype(float) * a[c].astype(float)
    pens = w * np.abs(prods - v) / v
    if d > 0:
        k = min(d, m)
        idx = np.argsort(pens)[::-1][:k]
        idx = idx[pens[idx] > 0]
        idx = np.sort(idx)
    else:
        idx = np.array([], dtype=int)

    print(' '.join(map(str, a)))
    d1 = idx + 1
    if len(d1) > 0:
        print(str(len(d1)) + ' ' + ' '.join(map(str, d1)))
    else:
        print('0')

main()
