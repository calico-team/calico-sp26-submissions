# import collections
import math
def solve():
   n, m = map(int, input().split())
   grid = [[0]*m for i in range(n)]
   for r in range(n):
       for c in range(m):
           # rohan’s and keshav’s algorithm
           grid[r][c] = (2*c+2*r-c) % 5
  
   for i in range(n):
       print(*grid[i])
      


for i in range(int(input())):
   solve()
