#
#    Author: mikelou
#

import sys
import math
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right, insort_left, insort_right
from functools import lru_cache, reduce
from itertools import accumulate, permutations, combinations, product

INF = 10**18 + 5
MOD = 10**9 + 7

things = ['^', '<', '>', 'v']

def helper(nb,nr,nc,bad,n,m,g):
    if 0 <= nr < n and 0 <= nc < m:
        nch = g[nr][nc]
        if nch == 'X':
            nb.append((nr,nc))
        elif nch in things:
            if nch != bad:
                nb.append((nr,nc))

t = int(input())

for i in range(t):
    n, m = map(int,input().split())

    g = [''] * n
    for j in range(n):
        g[j] = input()

    ind = {}
    adj = {}

    for j in range(n):
        for k in range(m):
            ch = g[j][k]
            if ch != '.':
                ind[(j,k)] = 0
                adj[(j,k)] = []

    for j in range(n):
        for k in range(m):
            ch = g[j][k]

            if ch == '.' or ch == 'X':
                continue

            if ch in things:
                nr = j
                nc = k
                if ch == '^':
                    nr = j - 1
                elif ch == 'v':
                    nr = j + 1
                elif ch == '<':
                    nc = k - 1
                else:
                    nc = k + 1

                if 0 <= nr < n and 0 <= nc < m:
                    if g[nr][nc] != '.':
                        adj[(j,k)].append((nr,nc,1,1))
                        ind[(nr,nc)] += 1
                else:
                    adj[(j, k)].append(('C',0,1,1))

            elif ch == 'S':
                nb = []

                helper(nb,j - 1,k,'v',n,m,g)
                helper(nb,j + 1,k,'^',n,m,g)
                helper(nb,j,k - 1,'>',n,m,g)
                helper(nb,j,k + 1,'<',n,m,g)

                cnt = len(nb)
                for l in range(cnt):
                    nr, nc = nb[l]
                    adj[(j, k)].append((nr,nc,1,cnt))
                    ind[(nr, nc)] += 1

    q = []
    for node in ind:
        if ind[node] == 0:
            q.append(node)

    fr = {(0,0): (1,1)}
    cp = 0
    cq = 1

    while len(q) > 0:
        nd = q.pop()
        fp,fq = fr.get(nd, (0,1))

        for e in adj.get(nd,[]):
            if e[0] == 'C':
                np2 = fp * e[2]
                nq2 = fq * e[3]

                x = cp*nq2 + np2*cq
                y = cq*nq2
                gg = math.gcd(x,y)
                cp = x // gg
                cq = y // gg
            else:
                nr = e[0]
                nc = e[1]
                ep = e[2]
                eq = e[3]

                np2 = fp * ep
                nq2 = fq * eq

                a, b = fr.get((nr,nc), (0, 1))
                x = a * nq2 + np2 * b
                y = b * nq2
                gg = math.gcd(x,y)
                fr[(nr,nc)] = (x // gg, y // gg)

                ind[(nr,nc)] -= 1
                if ind[(nr,nc)] == 0:
                    q.append((nr,nc))

    print(f"{cp} {cq}")
