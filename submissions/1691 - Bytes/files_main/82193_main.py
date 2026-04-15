from sys import stdin
from collections import deque
input = stdin.readline

INF = float('inf')
MOD = 1_000_000_007
MOD1 = 998_244_353

def solve(I):
    a=input().strip()
    b=input().strip()
    n=len(a)
    res=list(a)
    j=0
    
    for i in range(n):
        if j<len(b) and a[i]==b[j]:
            j+=1
        else:
            res[i]='#'
    
    print("".join(res))
        
    
    
   


q = int(input())
for i in range(q):
    solve(i+1)