for _ in range(int(input())):
  n=int(input())
  l=list(map(int,input().split()))
  if n==1:
    print(l[0])
  else:
    ans=[sorted(l)[(n+1)//2-1]]*n
    c=0
    for i in range(n):
      c+=abs(l[i]-ans[i])
      
    just=0
    for i in range(1,n):
      just+=abs(l[i-1]-l[i])
    
    if c<just:
      print(*ans)
    else:
      print(*l)