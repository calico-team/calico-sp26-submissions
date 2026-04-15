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
    a = list(map(int,input().split()))

    best = -1
    bst = -1
    for b in product(a,repeat=n):
        s = 0
        for j in range(n):
            s += abs(a[j] - b[j])
            if j + 1 < n:
                s += abs(a[j] - a[j+1])
                s += abs(b[j] - b[j+1])
        if best == -1 or s < best:
            best = s
            bst = b
    print(*bst)