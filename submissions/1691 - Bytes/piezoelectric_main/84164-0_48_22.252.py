from sys import stdin
from collections import deque
input = stdin.readline

INF = float('inf')
MOD = 1_000_000_007
MOD1 = 998_244_353

def solve(I):
    l,w,e,r=list(map(int,input().split()))
    
    cur=0
    count=0
    mx=2*(l+w)*r
    while cur<e:
        cur+=mx
        count+=1
    print(count)
    
    
    
                    



                    

q = int(input())
for i in range(q):
    solve(i+1)