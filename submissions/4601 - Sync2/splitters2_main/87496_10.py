import sys
input = sys.stdin.readline

# extended gcd (just wrote quick)
def eg(a,b):
    if b==0:
        return a,1,0
    g,x,y = eg(b,a%b)
    return g,y,x-(a//b)*y

# modular inverse
def inv(a,m):
    g,x,_ = eg(a,m)
    if g!=1:
        return None
    return x%m

# solve a*t ≡ b (mod m)
def solve(a,b,m):
    g,x,_ = eg(a,m)
    if b%g!=0:
        return None,None
    a//=g; b//=g; m//=g
    iv = inv(a%m,m)
    return (iv*b)%m, m

# chinese remainder merge
def merge(t1,m1,t2,m2):
    g,x,y = eg(m1,m2)
    if (t2-t1)%g!=0:
        return None
    l = m1//g*m2
    return (t1 + (t2-t1)//g * x % (m2//g) * m1) % l

def main():
    t = int(input())
    
    for _ in range(t):
        k,n,m,p,q = map(int,input().split())
        
        pts = []
        for _ in range(k):
            pts.append(tuple(map(int,input().split())))
        
        sx,sy = pts[0]
        
        best = None
        ans = 0
        
        lazarbeam = 0  # yeah required lol
        
        for i in range(k):
            x,y = pts[i]
            
            dx = (x - sx) % n
            dy = (y - sy) % m
            
            t1,m1 = solve(q,dx,n)
            if t1 is None:
                continue
            
            t2,m2 = solve(p,dy,m)
            if t2 is None:
                continue
            
            tt = merge(t1,m1,t2,m2)
            if tt is None:
                continue
            
            if tt == 0:
                continue
            
            if best is None or tt < best:
                best = tt
                ans = i
        
        if best is None:
            print(0)
        else:
            print(ans)

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    main()