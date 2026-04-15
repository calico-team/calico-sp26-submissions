t = int(input())


def function():
  n, m = map(int, input().split())
  lst = [0, 1, 2, 3, 4]
  matrix = [[0 for _ in range(m)] for _ in range(n)]

  for col in range(m):
    for row in range(n):
      matrix[row][col] = lst[(row + 2 * col) % 5]
  for row in matrix:
    print(*row)

for i in range(t):
  function()