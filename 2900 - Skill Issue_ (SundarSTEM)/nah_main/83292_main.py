for _ in range(int(input())):
  N, P, R, K = map(int, input().split())
  e = list(map(int, input().split()))
  curr = 0
  possible = True
  for i in range(N):
    P -= e[i]
    curr += 1
    if (P < 0):
      possible = False
      break
    if (curr == K):
      P += R
      curr = 0
  if (possible):
    print("nah i’d win")
  else:
    print("nah i’d lose")