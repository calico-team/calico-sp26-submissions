for i in range(int(input())):
  a = int(input())
  c = list(map(int, input().split()))
  d = [c[0]]
  for j in range(1,len(c)):
    if(abs(d[-1]-c[j])<=1):
      d.append(c[j])
    else:
      d.append(d[j-1])
  print(*d)