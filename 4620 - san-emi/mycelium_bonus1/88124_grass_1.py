from collections import deque
direc = [(1, 0), (-1, 0), (0, 1), (0, -1)]
def solve(xg, yg, xm, ym):
    def dG(x, y):
        return abs(x - xg) + abs(y - yg)
    def dM(x, y):
        return abs(x - xm) + abs(y - ym)
    def good(x, y):
        return 7 * dM(x, y) < 2 * dG(x, y)
    q = deque()
    visited = set()
    if good(xm, ym):
        q.append((xm, ym))
        visited.add((xm, ym))
    count = 0
    while q:
        x, y = q.popleft()
        count += 1
        for dx, dy in direc:
            nx, ny = x + dx, y + dy
            if (nx, ny) not in visited and good(nx, ny):
                visited.add((nx, ny))
                q.append((nx, ny))
    return count

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))