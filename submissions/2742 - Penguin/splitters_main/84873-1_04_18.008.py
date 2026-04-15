import math as m

def g(a,b):
    while b:
        a,b=b,a%b
    return a

def s(p,q):
    c=g(p,q)
    return p//c,q//c

def add(f1,f2):
    p1,q1=f1
    p2,q2=f2
    np=p1*q2+p2*q1
    nq=q1*q2
    return s(np,nq)

def sol():
    import sys as sss
    d=sss.stdin.read().split()
    if not d:return
    i=0
    T=int(d[i]); i+=1

    for _ in range(T):
        n=int(d[i]); i+=1
        m=int(d[i]); i+=1

        g=[]
        for r in range(n):
            g.append(d[i]); i+=1

        prob=[[(0,1) for _ in range(m)] for _ in range(n)]
        prob[0][0]=(1,1)

        indeg=[[0]*m for _ in range(n)]

        def nxt(r,c):
            t=g[r][c].lower()
            if t=='.' or t=='x': return []

            if t=='s':
                out=[]
                for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                    nr,nc=r+dr,c+dc
                    if 0<=nr<n and 0<=nc<m:
                        nt=g[nr][nc].lower()
                        if nt=='x': out.append((nr,nc))
                        elif nt in '<>^v':
                            if not ((nt=='>' and dc==-1) or
                                    (nt=='<' and dc==1) or
                                    (nt=='v' and dr==-1) or
                                    (nt=='^' and dr==1)):
                                out.append((nr,nc))
                return out

            dr,dc={'^':(-1,0),'v':(1,0),'<':(0,-1),'>':(0,1)}[t]
            nr,nc=r+dr,c+dc
            return [(nr,nc)] if 0<=nr<n and 0<=nc<m else [(-1,-1)]

        for r in range(n):
            for c in range(m):
                for nr,nc in nxt(r,c):
                    if nr!=-1:
                        indeg[nr][nc]+=1

        q=[(r,c) for r in range(n) for c in range(m) if indeg[r][c]==0]
        fin=(0,1)

        while q:
            r,c=q.pop(0)
            p,qv=prob[r][c]

            if p==0 and not (r==0 and c==0): continue

            nb=nxt(r,c)
            if not nb: continue

            for nr,nc in nb:
                sp,sv=s(p,qv*len(nb))

                if nr==-1:
                    fin=add(fin,(sp,sv))
                else:
                    prob[nr][nc]=add(prob[nr][nc],(sp,sv))
                    indeg[nr][nc]-=1
                    if indeg[nr][nc]==0:
                        q.append((nr,nc))

        print(fin[0],fin[1])

sol()