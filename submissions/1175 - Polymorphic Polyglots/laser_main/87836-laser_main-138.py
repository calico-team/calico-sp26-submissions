import sys
# sys.stdin = open("4.in")
input = sys.stdin.readline
import math
from collections import defaultdict

def solve():
    k, n, m, p, q = map(int, input().split())
    coords = [tuple(map(int, input().split())) for _ in range(k)]
    reduceFactor = math.gcd(p, q)
    p //= reduceFactor
    q //= reduceFactor
    if p / q == 0:
        print(-1)
        return

    xInterceptToAsteroids = defaultdict(list)
    for i in range(k):
        xIntercept = round(coords[i][0] - coords[i][1] / (p / q), 8)
        xInterceptToAsteroids[xIntercept].append(i)
    # print(xInterceptToAsteroids)
    
    # start at (0, 0)
    curX, curY = coords[0][0], coords[0][1]
    xIntercept = round(curX - curY / (p / q), 8)
    # fast forward
    for i in range(10000000):
        # print(xIntercept)
        if xInterceptToAsteroids[xIntercept]:            
            lowestX = float('inf')
            firstHit = -1
            for idx in xInterceptToAsteroids[xIntercept]:
                # ignore the starting point
                if not (i == 0 and idx == 0):
                    if coords[idx][0] < lowestX:
                        lowestX = coords[idx][0]
                        firstHit = idx
            if firstHit != -1:
                print(firstHit)                
                return
        # go out of range, check the new x-intercept
        '''
        does x reach n first or does y reach m first?
             right q            up p
        integer number of "right p, up q" steps needed to get to a real next integer point:
        tN = math.ceil((n - curX) / q)
        tM = math.ceil((m - curY) / p)
        fast-forward min(tN, tM), then take the mod
        '''
        tN = math.ceil((n - curX) / q)
        tM = math.ceil((m - curY) / p)
        fastForward = min(tN, tM)
        curX += fastForward * q
        curY += fastForward * p
        curX %= n
        curY %= m
        xIntercept = round(curX - curY / (p / q), 8)
    # we should never get here, something's wrong
    # assert False

tcs = int(input())

for tc in range(tcs):
    solve()

'''
gcd so we don't miss anything, then iterate through
note: direct simulation is probably too slow, let's try to fast forward instead
'''
