from fractions import Fraction
from collections import deque

t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    c=[input().strip() for _ in range(a)]
    
    d=[[Fraction(0,1) for _ in range(b)]for _ in range(a)]
    d[0][0]=Fraction(1,1)
    e=Fraction(0,1)
    
    f=deque()
    f.append((0,0))
    g=[[False]*b for _ in range(a)]
    g[0][0]=True
    
    while f:
        h,i=f.popleft()
        if d[h][i]==0:
            continue
        j=c[h][i]
        
        if j=='X':
            continue
        
        elif j in '^v<>':
            k,l=h,i
            if j=='^':k-=1
            elif j=='v':k+=1
            elif j=='<':l-=1
            else:l+=1
            
            if k<0 or k>=a or l<0 or l>=b:
                e+=d[h][i]
            else:
                d[k][l]+=d[h][i]
                if not g[k][l]:
                    g[k][l]=True
                    f.append((k,l))
        
        elif j=='S':
            m=[]
            for n,o in [(-1,0),(1,0),(0,-1),(0,1)]:
                p,q=h+n,i+o
                if 0<=p<a and 0<=q<b and c[p][q]!='.':
                    r=False
                    if c[p][q]=='^' and p+1==h:r=True
                    if c[p][q]=='v' and p-1==h:r=True
                    if c[p][q]=='<' and q+1==i:r=True
                    if c[p][q]=='>' and q-1==i:r=True
                    if not r:
                        m.append((p,q))
            if m:
                s=d[h][i]/len(m)
                for t,u in m:
                    d[t][u]+=s
                    if not g[t][u]:
                        g[t][u]=True
                        f.append((t,u))
    
    print(e.numerator,e.denominator)
