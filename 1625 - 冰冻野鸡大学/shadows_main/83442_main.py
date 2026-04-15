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
    n = int(input())

    c1 = [0] * n
    for j in range(n):
        s = input()
        c1[j] = s.count('#')

    c2 = [0] * n
    for j in range(n):
        s = input()
        c2[j] = s.count('#')

    mmax = 0
    mmin = 0
    for j in range(n):
        a = c1[j]
        b = c2[j]
        mmax += (a * b)
        if a > b:
            mmin += a
        else:
            mmin += b

    print(f"{mmax} {mmin}")