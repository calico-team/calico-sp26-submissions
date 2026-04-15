# ﷽
from math import ceil
for _ in range(int(input())):
    n,p,r,k=list(map(int,input().split()))
    curses=list(map(int,input().split()))
    ans=1
    cur=0
    for i in curses:
        p-=i
        if(p<0):
            ans=0
        cur+=1
        if(cur==k):
            cur=0 
            p+=r  
    print("nah i'd win" if ans else "nah i'd lose")        