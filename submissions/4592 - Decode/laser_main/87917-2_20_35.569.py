t = int(input())

def function():
  k, n, m, p, q = map(int, input().split())
  asteroids = []
  for i in range(k):
    a, b = map(int, input().split())
    asteroids.append((a, b))
  x, y = asteroids[0]


  while 1+1==2:
    x = (x + q) % n
    y = (y + p) % m
    #check to find
    for i in range(k):
      if asteroids[i][0] == x and asteroids[i][1] == y:
        print(i)
        return
    if (x, y) == asteroids[0]:
      print(-1)
      break

for i in range(t):
    function()
