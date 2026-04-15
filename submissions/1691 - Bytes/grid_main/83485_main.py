from sys import stdin
from collections import deque
input = stdin.readline

INF = float('inf')
MOD = 1_000_000_007
MOD1 = 998_244_353

def solve(I):
    n=int(input())
    a=list(map(int,input().split()))
    
    ls=list(set(a))
    mx=INF
    ans=None
    
    if n==1:
        for x in ls:
            cost=abs(a[0]-x)
            if cost<mx:
                mx=cost
                ans=[x]
    elif n==2:
        for x in ls:
            for y in ls:
                cost=0
                cost+=abs(a[0]-x)
                cost+=abs(a[1]-y)
                cost+=abs(x-y)
                if cost<mx:
                    mx=cost
                    ans=[x,y]
    elif n==3:
        for x in ls:
            for y in ls:
                for z in ls:
                    cost=0
                    cost+=abs(a[0]-x)
                    cost+=abs(a[1]-y)
                    cost+=abs(a[2]-z)
                    
                    cost+=abs(x-y)
                    cost+=abs(y-z)
                    
                    if cost<mx:
                        mx=cost
                        ans=[x,y,z]
                        
    print(*ans)
    
                    



                    

q = int(input())
for i in range(q):
    solve(i+1)