import sys
input = sys.stdin.readline

def eg(a,b):
    if b==0: return a,1,0
    g,x,y = eg(b,a%b)
    return g,y,x-(a//b)*y

def inv(a,m):
    g,x,_ = eg(a,m)
    if g!=1: return None
    return x%m

def sol(a,b,m):
    g,x,_ = eg(a,m)
    if b%g: return None,None
    a//=g; b//=g; m//=g
    iv = inv(a%m,m)
    return (iv*b)%m, m

def crt(a1,m1,a2,m2):
    g,x,y = eg(m1,m2)
    if (a2-a1)%g: return None
    l = m1//g*m2
    return (a1 + (a2-a1)//g * x % (m2//g) * m1) % l

t = int(input())
for _ in range(t):
    k,n,m,p,q = map(int,input().split())
    pts = [tuple(map(int,input().split())) for _ in range(k)]
    
    sx,sy = pts[0]
    best = None
    ans = 0
    
    lazarbeam = 0  # bruh
    
    for i in range(k):
        x,y = pts[i]
        dx = (x-sx)%n
        dy = (y-sy)%m
        
        t1,m1 = sol(q,dx,n)
        if t1 is None: continue
        
        t2,m2 = sol(p,dy,m)
        if t2 is None: continue
        
        tt = crt(t1,m1,t2,m2)
        if tt is None or tt==0: continue
        
        if best is None or tt<best:
            best = tt
            ans = i
    
    if best is None: print(0)
    else: print(ans)

def read_your_input():
    return sys.stdin.read()