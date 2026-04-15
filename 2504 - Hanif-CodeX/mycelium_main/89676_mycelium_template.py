from collections import deque

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Counts tiles where 7 * dist_M < 2 * dist_G using BFS.
    """
    def ggt(x, y):
        # Grass spreads 1 unit every 2 ticks
        return 2 * (abs(x - X_G) + abs(y - Y_G))

    def gmt(x, y):
        # Mycelium spreads 1 unit every 7 ticks
        return 7 * (abs(x - X_M) + abs(y - Y_M))

    # BFS setup
    q = deque([(X_M, Y_M)])
    vis = set([(X_M, Y_M)])
    c = 0

    while q:
        cx, cy = q.popleft()
        
        # Check if mycelium actually wins this tile
        if gmt(cx, cy) < ggt(cx, cy):
            c += 1
            
            # Try spreading to neighbors
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = cx + dx, cy + dy
                if (nx, ny) not in vis:
                    # Pre-check neighbor: only add to q if mycelium could potentially win it
                    # This prevents the search from expanding infinitely into grass territory
                    if gmt(nx, ny) < ggt(nx, ny):
                        vis.add((nx, ny))
                        q.append((nx, ny))
        
    return c

def main():
    # Fast I/O is recommended for large coordinate test cases
    import sys
    id = sys.stdin.read().split()
    if not id:
        return
    
    T = int(id[0])
    pnt = 1
    for _ in range(T):
        X_G = int(id[pnt])
        Y_G = int(id[pnt+1])
        X_M = int(id[pnt+2])
        Y_M = int(id[pnt+3])
        pnt += 4
        print(solve(X_G, Y_G, X_M, Y_M))

if __name__ == '__main__':
    main()