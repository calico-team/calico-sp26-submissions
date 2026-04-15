t = int(input())

def function():
  l, w, e, r = map(int, input().split())
  total = 0
  perimeter = l * 2 + w * 2
  while e > total:
    total += r * perimeter
  print(int((total/perimeter)/r))
  
for i in range(t):
  function()