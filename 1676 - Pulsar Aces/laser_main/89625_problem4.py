def eee(a,b):
  c=1
  d=0
  e=0
  f=1
  while a!=0 and b!=0:
    if a<b:
      b,a,d,c,f,e=(a,b,c,d,e,f)
    n=a//b
    a-=b*n
    c-=d*n
    e-=f*n
  return (d,f) if a==0 else (c,e)
for i in range(int(input())):
    k, m, n, q, p = map(int, input().split())
    t = [[int(i) for i in input().split()] for j in range(k)]
    a, b = t[0][0] + p, t[0][1] + q
    pp=eee(p,m)[0]%m
    qq=eee(q,n)[0]%n
    mini=0
    minv=float('inf')
    for j in range(len(t)):
      i=t[j]
      cx = i[0]-a
      cy = i[1]-b
      mm = (pp*cx)%m
      nn = (qq*cy)%n
      inc = (nn-mm)%n
      rr = eee(n,m)[0]%n
      res = (mm+m*(rr*inc)%n)%(m*n)
      if res < minv:
        minv=res
        mini=j
    print(mini)