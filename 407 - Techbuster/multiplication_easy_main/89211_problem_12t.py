import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    N = int(input_data[ptr]); ptr += 1
    M = int(input_data[ptr]); ptr += 1
    D = int(input_data[ptr]); ptr += 1
    
    adj = [[] for _ in range(N + 1)]
    constraints = []
    
    for i in range(M):
        r = int(input_data[ptr]); ptr += 1
        c = int(input_data[ptr]); ptr += 1
        v = int(input_data[ptr]); ptr += 1
        w = int(input_data[ptr]); ptr += 1
        constraints.append((r, c, v, w, i + 1))
        adj[r].append((c, v, w))
        adj[c].append((r, v, w))

    a = [1000.0] * (N + 1)
    
    for _ in range(40):
        for i in range(1, N + 1):
            if not adj[i]:
                continue
            num = 0.0
            den = 0.0
            for neighbor, v, w in adj[i]:
                target = v / a[neighbor]
                weight = w / v
                num += weight * target
                den += weight
            if den > 0:
                a[i] = num / den

    penalties = []
    for r, c, v, w, idx in constraints:
        error = w * (abs(a[r] * a[c] - v) / v)
        penalties.append((error, idx))
    
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded = sorted([penalties[i][1] for i in range(min(D, M))])
    
    a_out = [max(1, min(10**9, int(round(x)))) for x in a[1:]]
    print(*(a_out))
    print(len(discarded), *(discarded))

if __name__ == "__main__":
    solve()