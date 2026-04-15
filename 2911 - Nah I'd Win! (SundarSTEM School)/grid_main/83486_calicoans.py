for _ in range(int(input())):
  n=int(input())
  l=list(map(int,input().split()))
  if n==1:
    print(l[0])
  elif n==3:
    minn=float('inf')
    for i in l:
      for j in l:
        for k in l:
          if abs(l[0]-i)+abs(l[1]-j)+abs(l[2]-k)+abs(k-j)+abs(j-i)<minn:
            minn=abs(l[0]-i)+abs(l[1]-j)+abs(l[2]-k)+abs(k-j)+abs(j-i)
            ans=[i,j,k]
    print(*ans)
  else:
    minn=float('inf')
    for i in l:
      for j in l:
          if abs(l[0]-i)+abs(l[1]-j)+abs(j-i)<minn:
            minn=abs(l[0]-i)+abs(l[1]-j)+abs(j-i)
            ans=[i,j]
    print(*ans)