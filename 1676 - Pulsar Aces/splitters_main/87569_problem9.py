import numpy as np
class Fraction:
    def __init__(self,n,d):
        self.n=n
        self.d=d
    def __add__(self,other):
        a=self.n*other.d+self.d*other.n
        b=self.d*other.d
        return Fraction(a/np.gcd(a,b),b/np.gcd(a,b))
    def __mul__(self,other):
        a=self.n*other.n
        b=self.d*other.d
        return Fraction(a/np.gcd(a,b),b/np.gcd(a,b))
fact=[]
m=0
n=0
def eval(x,y):
    v=fact[x][y]
    if v == "<":
        if x>0:
            return eval(x-1,y)
        else:
            return Fraction(1,1)
    elif v == ">":
        if x<m-1:
            return eval(x+1,y)
        else:
            return Fraction(1,1)
    elif v == "^":
        if y>0:
            return eval(x,y-1)
        else:
            return Fraction(1,1)
    elif v == "v":
        if y<n-1:
            return eval(x,y+1)
        else:
            return Fraction(1,1)
    elif v == "X":
        return Fraction(0,1)
    elif v == "S":
        ps=[]
        if x>0:
            if fact[x-1][y] not in [">"," "]:
                ps.append([x-1,y])
        if x<m-1:
            if fact[x+1][y] not in ["<"," "]:
                ps.append([x+1,y])
        if y>0:
            if fact[x][y-1] not in ["v"," "]:
                ps.append([x,y-1])
        if y<n-1:
            if fact[x][y+1] not in ["^"," "]:
                ps.append([x,y+1])
        return sum([eval(i[0],i[1]) for i in ps],start=Fraction(0,1))/Fraction(1,len(ps))
output=""
for _ in range(int(input())):
    m,n=tuple(map(int, input().split()))
    fact=[[] for _ in range(n)]
    for i in range(n):
        s=input()
        for k in s:
            fact[i].append(k)
    z=eval(0,0)
    output+=str(z.n)+" "+str(z.d)+"\n"
print(output)