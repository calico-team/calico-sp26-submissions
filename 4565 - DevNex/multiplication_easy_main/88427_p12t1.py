import sys
import math
from collections import defaultdict, deque

def find(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(parent, rank, x, y):
    px, py = find(parent, x), find(parent, y)
    if px == py:
        return False
    if rank[px] < rank[py]:
        px, py = py, px
    parent[py] = px
    if rank[px] == rank[py]:
        rank[px] += 1
    return True

def read_your_input():
    data = sys.stdin.buffer.read().split()
    pos = 0
    N = int(data[pos]); pos += 1
    M = int(data[pos]); pos += 1
    D = int(data[pos]); pos += 1

    constraints = []
    for _ in range(M):
        r = int(data[pos]); pos += 1
        c = int(data[pos]); pos += 1
        v = int(data[pos]); pos += 1
        w = int(data[pos]); pos += 1
        constraints.append((r, c, v, w))

    sorted_idx = sorted(range(M), key=lambda i: -constraints[i][3])

    parent = list(range(N + 1))
    rank = [0] * (N + 1)

    tree_adj = defaultdict(list)
    for si in sorted_idx:
        r, c, v, w = constraints[si]
        if find(parent, r) != find(parent, c):
            union(parent, rank, r, c)
            lv = math.log(v)
            tree_adj[r].append((c, lv))
            tree_adj[c].append((r, lv))

    b = [None] * (N + 1)
    for start in range(1, N + 1):
        if b[start] is not None:
            continue
        b[start] = 0.0
        queue = deque([start])
        while queue:
            node = queue.popleft()
            for nbr, lv in tree_adj[node]:
                if b[nbr] is None:
                    b[nbr] = lv - b[node]
                    queue.append(nbr)

    better_than_me = []
    for i in range(1, N + 1):
        val = round(math.exp(b[i]))
        val = max(1, min(10 ** 9, val))
        better_than_me.append(val)

    penalties = []
    for i, (r, c, v, w) in enumerate(constraints):
        prod = better_than_me[r - 1] * better_than_me[c - 1]
        pen = w * abs(prod - v) / v
        penalties.append((pen, i + 1))

    penalties.sort(reverse=True)
    discard = sorted(penalties[i][1] for i in range(D))

    out = []
    out.append(' '.join(map(str, better_than_me)))
    out.append(str(len(discard)) + (' ' + ' '.join(map(str, discard)) if discard else ''))
    sys.stdout.write('\n'.join(out) + '\n')

read_your_input()