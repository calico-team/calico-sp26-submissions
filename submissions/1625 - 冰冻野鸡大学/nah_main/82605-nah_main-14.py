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
    n,p,r,k = map(int,input().split())
    e = list(map(int,input().split()))
    cc = p
    uses = 0
    defe = True
    for j in range(n):
        need = e[j]
        while cc < need and uses > 0:
            cc += r
            uses -= 1
        if cc < need:
            defe = False
            break
        cc -= need
        if (j+1) % k == 0:
            uses += 1
    if defe == True:
        print("nah i'd win")
    else:
        print("nah i'd lose")