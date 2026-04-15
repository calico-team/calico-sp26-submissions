import collections

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.
    """
    
    def can_mycelium_win(x, y):
        dist_g = abs(x - X_G) + abs(y - Y_G)
        dist_m = abs(x - X_M) + abs(y - Y_M)
        return (7 * dist_m) < (2 * dist_g)


    if not can_mycelium_win(X_M, Y_M):
        return 0

    # BFS to explore all tiles mycelium can reach before grass surrounds it
    queue = collections.deque([(X_M, Y_M)])
    visited = {(X_M, Y_M)}
    count = 0

    while queue:
        curr_x, curr_y = queue.popleft()
        count += 1

        # Check neighbors (Up, Down, Left, Right) 
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = curr_x + dx, curr_y + dy
            if (nx, ny) not in visited:
                visited.add((nx, ny))
                if can_mycelium_win(nx, ny):
                    queue.append((nx, ny))
                    
    return count

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    if not data:
        return
    T = int(data[0])
    idx = 1
    for _ in range(T):
        X_G = int(data[idx])
        Y_G = int(data[idx+1])
        X_M = int(data[idx+2])
        Y_M = int(data[idx+3])
        idx += 4
        print(solve(X_G, Y_G, X_M, Y_M))

if __name__ == '__main__':
    main()