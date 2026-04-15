t = int(input())



def function():
  n, m = map(int, input().split())
  lst = [0, 1, 2, 3, 4]
  offset = 0
  #construct matrix
  matrix = [[0 for _ in range(n)] for _ in range(m)]
  for col in range(n):
    for row in range(m):
      matrix[row][col] = lst[(row + offset) % 5]
    offset += 2  
  for row in matrix:
    print(*row)

 
    
for i in range(t):
  function()