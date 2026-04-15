t = int(input())

def function():
  dict = {}
  k, n, m, p, q = map(int, input().split())
  asteroids = []
  for i in range(k):
    a, b = map(int, input().split())
    asteroids.append((a, b))
    dict[(a, b)] = i
  x, y = asteroids[0]
  

  while 1+1==2:
    x = (x + q) % n
    y = (y + p) % m
    #use dictionary to go to O(1)
    if (x, y) in dict:
      print(dict[(x, y)])
      return
    if (x, y) == asteroids[0]:
      print(-1)
      break

for i in range(t):
    function()
