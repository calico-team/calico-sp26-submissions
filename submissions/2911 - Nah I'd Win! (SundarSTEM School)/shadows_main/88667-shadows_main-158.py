for _ in range(int(input())):
  n=int(input())
  l=[0]*n
  c=[0]*n
  
  for i in range(n):
    s=input()
    l[i]=s.count("#")
    c[i]=l[i]
  
  for i in range(n):
    s=input()
    sc=s.count("#")
    l[i]*=sc
    c[i]=max(c[i],sc)
  print(sum(l),sum(c))