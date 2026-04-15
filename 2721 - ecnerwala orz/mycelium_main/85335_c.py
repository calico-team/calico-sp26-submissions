from collections import deque
import heapq
import sys

input = lambda: sys.stdin.readline().strip()
print = lambda *args, end='\n': sys.stdout.write(" ".join([str(arg) for arg in args]) + end)

def soln_brute():
    size = 100
    x_g, y_g, x_m, y_m = map(lambda x: int(x) + size, input().split())
    grid = [[""] * 2 * size for _ in range(2 * size)]
    q = []
    heapq.heappush(q, (0, x_g, y_g, 'g'))
    heapq.heappush(q, (0, x_m, y_m, 'm'))
    ungrown = 1
    grown = 0
    while ungrown > 0:
        t, x, y, dirt_type = heapq.heappop(q)
        if dirt_type == 'm':
            ungrown -= 1
        if grid[x][y]:
            continue
        grid[x][y] = dirt_type
        if dirt_type == 'm':
            grown += 1
        for x_new, y_new in ((x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1)):
            heapq.heappush(q, (t + 7 if dirt_type == 'm' else t + 2, x_new, y_new, dirt_type))
            ungrown += 1 if dirt_type == 'm' else 0
    print(grown)

for _ in range(int(input())):
    soln_brute()