for _ in range(int(input())):
  n,power,r,k=map(int,input().split())
  l=list(map(int,input().split()))
  res="nah i'd win"
  for i in range(n):
    if l[i]>power:
      res="nah i'd lose";break
    power-=l[i]
    
    if (i+1)%k==0:
      power+=r
  if r<0:
    res="nah i'd lose"
  print(res)