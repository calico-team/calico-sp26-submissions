from collections import deque
import sys

def solve():
    input = sys.stdin.readline
    for _ in range(t):
    `    n, m, k = map(int, input().split())
        
        grid = []
        empties = []

        for i in range(n):
            row = input().strip()
            grid.append(row)
            for j, c in enumerate(row):
                if c == '-':
                    empties.append((i, j))

        if k == 1:
            x, y = empties[0]
            print(x, y)
            return

        dirs = [(1,0), (-1,0), (0,1), (0,-1)]

        def bfs_limit(start, D):
            sx, sy = start
            q = deque([(sx, sy)])
            seen = set([(sx, sy)])
            res = [(sx, sy)]

            while q and len(res) < k:
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in seen:
                        if grid[nx][ny] == '-':
                            # Manhattan distance constraint via BFS depth not exact;
                            # we enforce by explicit check
                            if abs(nx - sx) + abs(ny - sy) <= D:
                                seen.add((nx, ny))
                                q.append((nx, ny))
                                res.append((nx, ny))
                                if len(res) == k:
                                    return res
            return res if len(res) >= k else None

        def feasible(D):
            # Try a subset of starting points (all empties is safe for constraints up to 1e6 total)
            for start in empties:
                res = bfs_limit(start, D)
                if res is not None:
                    return res
            return None

        lo, hi = 0, n + m
        answer = None

        while lo <= hi:
            mid = (lo + hi) // 2
            res = feasible(mid)
            if res is not None:
                answer = res
                hi = mid - 1
            else:
                lo = mid + 1

        # output best found
        for x, y in answer:
            print(x, y)

if __name__ == "__main__":
    solve()
