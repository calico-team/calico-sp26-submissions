from collections import defaultdict
from math import floor
import time
t = int(input())

def nextB():
    global currx
    global b
    y = slope*n+b #actually yq
    if y < m*q:
        currx = 0
        b = y - slope*currx #actually bq
    elif y == m*q:
        currx = 0
        y = 0
        b = 0
    else:
        y = 0
        currx = (m-b)/(slope)
        b = y-(m*q-b) #hopefully bq?

def check(b,f):
    for i in d[b]:
        if currx <= i[0] and (not (i[1] == 0 and f)):
            return i[1]
    return -1

for _ in range(t):
    k,n,m,p,q = map(int,input().split())
    points = [list(map(int,input().split())) for i in range(k)]
    start = points[0]
    slope = p #(should be p/q, but to avoid floats we mutliply everthing by q)

    d = defaultdict(list)
    for i in range(k):
        b = points[i][1]*q - p*points[i][0] #actually bq
        d[b].append([points[i][0],i])
    for i in d:
        d[i].sort()
    

    currx = start[0]
    b = start[1]*q - slope*start[0]
    f = True
    ans = check(b,f)
    while ans == -1:
        f = False
        nextB()
        ans = check(b,f)
    
    print(ans)


    
    