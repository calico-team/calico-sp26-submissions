# ﷽
from math import ceil
for _ in range(int(input())):
    l,w,e,r=list(map(int,input().split()))
    ans=ceil(e/(r*(2*w+2*l)))
    print(ans)