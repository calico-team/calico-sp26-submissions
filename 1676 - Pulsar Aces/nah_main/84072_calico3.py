m = int(input())
for i in range(m):
  n, p, r, k = map(int, input().split())
  t = [int(i) for i in input().split()]
  #print("nah, i'd win" if p - sum(t) + (r * ((n-1) // k)) >= 0 else "nah, i'd lose")
  flag = True
  for i in range(n):
    p -= t[i]
    print(p)
    if p < 0:
      flag = False
    if (i + 1) % k == 0:
      p += r

  if flag:
    print("nah, i'd win")
  else:
    print("nah, i'd lose")