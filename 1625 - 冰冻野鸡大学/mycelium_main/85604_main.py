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
    xg,yg,xm,ym = map(int,input().split())

    grid = {}
    grid[(xg, yg)] = "G"
    grid[(xm, ym)] = "M"

    gf = {(xg, yg)}
    mf = {(xm, ym)}

    tm = 1

    tick = 1
    while tick < 300:
        gt = False
        gm = False

        if tick % 2 == 0:
            gt = True
        if tick % 7 == 0:
            gm = True

        if gt or gm:
            gc = set()
            mc = set()

            if gt == True:
                for x, y in gf:
                    q = (x, y + 1)
                    if q not in grid:
                        gc.add(q)
                    q = (x, y - 1)
                    if q not in grid:
                        gc.add(q)
                    q = (x + 1, y)
                    if q not in grid:
                        gc.add(q)
                    q = (x - 1, y)
                    if q not in grid:
                        gc.add(q)

            if gm == True:
                for x, y in mf:
                    q = (x, y + 1)
                    if q not in grid:
                        mc.add(q)
                    q = (x, y - 1)
                    if q not in grid:
                        mc.add(q)
                    q = (x + 1, y)
                    if q not in grid:
                        mc.add(q)
                    q = (x - 1, y)
                    if q not in grid:
                        mc.add(q)

            for p in gc:
                grid[p] = "G"

            nmf = set()
            for p in mc:
                if p not in gc:
                    grid[p] = "M"
                    nmf.add(p)
                    tm += 1

            if gt == True:
                gf = gc

            if gm == True:
                mf = nmf
                if len(mf) == 0:
                    break

        tick += 1

    print(tm)