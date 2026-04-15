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
    n,m = map(int,input().split())

    for j in range(n):
        for k in range(m):
            print((j + 2*k) % 5,end=' ')
        print()