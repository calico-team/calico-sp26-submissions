from sys import stdin
from collections import deque
input = stdin.readline

INF = float('inf')
MOD = 1_000_000_007
MOD1 = 998_244_353

def solve(I):
    n,p,r,k=list(map(int,input().split()))
    ls=list(map(int,input().split()))
    cur=p
    
    count=0
    for x in ls:
        cur-=x
        if cur<0:
            print("nah i'd lose")
            return
        count+=1
        if count==k:
            cur+=r
            count=0
            
    print("nah i'd win")

    
    
    
    
                    



                    

q = int(input())
for i in range(q):
    solve(i+1)