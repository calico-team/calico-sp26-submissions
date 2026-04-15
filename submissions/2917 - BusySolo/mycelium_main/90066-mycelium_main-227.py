from collections import deque

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    # BFS limits (safe bound based on constraints)
    LIMIT = 400  # enough for all test sets

    def bfs(x, y, cost):
        dist = {}
        q = deque()
        q.append((x, y))
        dist[(x, y)] = 0

        while q:
            cx, cy = q.popleft()
            for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                nx, ny = cx + dx, cy + dy
                if abs(nx - X_G) > LIMIT and abs(nx - X_M) > LIMIT:
                    continue
                if (nx, ny) not in dist:
                    dist[(nx, ny)] = dist[(cx, cy)] + cost
                    q.append((nx, ny))
        return dist

    # grass and mycelium spread times per step unit
    grass = bfs(X_G, Y_G, 2)
    myco = bfs(X_M, Y_M, 7)

    ans = 0
    for cell in myco:
        if cell in grass and myco[cell] < grass[cell]:
            ans += 1

    return ans

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
