for i in range(int(input())):
  n, p, r, k = map(int, input().split())
  t = [int(i) for i in input().split()]
  print("nah, i'd win" if p - sum(t) + (r * (n // k)) >= 0 else "nah, i'd lose")