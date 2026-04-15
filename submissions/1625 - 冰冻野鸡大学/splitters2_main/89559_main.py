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

t = int(input())
for i in range(t):
    p,a,b = map(int,input().split())

    den = 2**a * 3**b

    if p == 0:
        print("1 1")
        print('X')
        continue

    if p == den:
        print("1 1")
        print('^')
        continue

    bases = []
    for j in range(a):
        bases.append(2)

    for j in range(b):
        bases.append(3)

    k = len(bases)
    digits = [0] * k

    rn = p
    for j in range(k - 1,-1,-1):
        base = bases[j]
        digits[j] = rn % base
        rn //= base

    n = 3
    m = 2*k + 2

    g = []
    for j in range(n):
        row = []
        for l in range(m):
            row.append('.')
        g.append(row)

    g[0][0] = 'v'
    g[1][0] = '>'
    g[1][1] = '>'

    for j in range(k):
        c = 2 + 2*j
        base = bases[j]
        d = digits[j]

        g[1][c] = 'S'
        if j + 1 == k:
            g[1][c + 1] = 'X'
        else:
            g[1][c + 1] = '>'

        if base == 2:
            if d == 1:
                g[0][c] = '^'
            else:
                g[0][c] = 'X'
        else:
            if d >= 1:
                g[0][c] = '^'
            else:
                g[0][c] = 'X'

            if d == 2:
                g[2][c] = 'v'
            else:
                g[2][c] = 'X'

    print(f"{n} {m}")
    for j in range(n):
        print(*g[j],sep='')
