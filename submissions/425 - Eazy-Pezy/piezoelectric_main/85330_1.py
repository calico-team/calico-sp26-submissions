import math
tc=int(input())
for i in range(tc):
  l,w,e,r=map(int,input().split())
  if l==w:
    p1=4*l*r
    print(math.floor(e/p1))
  else:
    pe=2*(l+w)*r
    print(math.floor(e/pe))