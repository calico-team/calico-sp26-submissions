from collections import deque
import sys

def solve():
    input = sys.stdin.readline
    t = int(input())

    dirs = [(1,0), (-1,0), (0,1), (0,-1)]

    for _ in range(t):
        n, m, k = map(int, input().split())

        grid = []
        empties = []

        for i in range(n):
            row = input().strip()
            grid.append(row)
            for j, c in enumerate(row):
                if c == '-':
                    empties.append((i, j))

        # trivial case
        if k == 1:
            x, y = empties[0]
            print(x, y)
            continue

        def bfs_count(start, D):
            sx, sy = start
            q = deque([(sx, sy)])
            seen = set([(sx, sy)])
            cnt = 1

            while q:
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in seen:
                        if grid[nx][ny] == '-' and abs(nx - sx) + abs(ny - sy) <= D:
                            seen.add((nx, ny))
                            q.append((nx, ny))
                            cnt += 1
                            if cnt >= k:
                                return cnt
            return cnt

        def feasible(D):
            for start in empties:
                if bfs_count(start, D) >= k:
                    return start
            return None

        def build_answer(start, D):
            sx, sy = start
            q = deque([(sx, sy)])
            seen = set([(sx, sy)])
            res = [(sx, sy)]

            while q and len(res) < k:
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in seen:
                        if grid[nx][ny] == '-' and abs(nx - sx) + abs(ny - sy) <= D:
                            seen.add((nx, ny))
                            q.append((nx, ny))
                            res.append((nx, ny))
                            if len(res) == k:
                                return res
            return res

        lo, hi = 0, n + m
        best_start = None
        best_D = None

        while lo <= hi:
            mid = (lo + hi) // 2
            start = feasible(mid)
            if start is not None:
                best_start = start
                best_D = mid
                hi = mid - 1
            else:
                lo = mid + 1

        # fallback safety (should not happen)
        if best_start is None:
            for i in range(k):
                print(*empties[i])
            continue

        ans = build_answer(best_start, best_D)

        for x, y in ans:
            print(x, y)

if __name__ == "__main__":
    solve()