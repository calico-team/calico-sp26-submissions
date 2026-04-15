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

out = []

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    vals = sorted(set(a))
    m = len(vals)

    dp = [0] * m
    for j in range(m):
        dp[j] = abs(a[0] - vals[j])

    par = []
    for j in range(n):
        row = [-1] * m
        par.append(row)

    for j in range(1, n):
        pmin = [0] * m
        parg = [0] * m

        pmin[0] = dp[0] - vals[0]
        parg[0] = 0

        for k in range(1, m):
            v = dp[k] - vals[k]
            if v < pmin[k - 1]:
                pmin[k] = v
                parg[k] = k
            else:
                pmin[k] = pmin[k - 1]
                parg[k] = parg[k - 1]

        smin = [0] * m
        sarg = [0] * m

        smin[m - 1] = dp[m - 1] + vals[m - 1]
        sarg[m - 1] = m - 1

        for k in range(m - 2,-1,-1):
            v = dp[k] + vals[k]
            if v < smin[k + 1]:
                smin[k] = v
                sarg[k] = k
            else:
                smin[k] = smin[k + 1]
                sarg[k] = sarg[k + 1]

        ndp = [0] * m

        for k in range(m):
            opt1 = pmin[k] + vals[k]
            opt2 = smin[k] - vals[k]
            if opt1 <= opt2:
                ndp[k] = abs(a[j] - vals[k]) + opt1
                par[j][k] = parg[k]
            else:
                ndp[k] = abs(a[j] - vals[k]) + opt2
                par[j][k] = sarg[k]

        dp = ndp

    cur = 0
    for j in range(1, m):
        if dp[j] < dp[cur]:
            cur = j

    bst = [0] * n
    bst[n - 1] = vals[cur]

    for j in range(n - 2,-1,-1):
        cur = par[j + 1][cur]
        bst[j] = vals[cur]

    print(*bst)