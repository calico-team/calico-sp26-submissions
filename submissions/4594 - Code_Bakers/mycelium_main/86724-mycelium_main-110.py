import collections

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
   
    
    def can_be_mycelium(x, y):
        dist_g = abs(x - X_G) + abs(y - Y_G)
        dist_m = abs(x - X_M) + abs(y - Y_M)
       
        return (7 * dist_m) < (2 * dist_g)

    # Starting tile check
    if not can_be_mycelium(X_M, Y_M):
        return 0

    queue = collections.deque([(X_M, Y_M)])
    visited = {(X_M, Y_M)}
    count = 0

    while queue:
        cx, cy = queue.popleft()
        count += 1

        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = cx + dx, cy + dy
            if (nx, ny) not in visited:
                visited.add((nx, ny))
                if can_be_mycelium(nx, ny):
                    queue.append((nx, ny))
    
    return count