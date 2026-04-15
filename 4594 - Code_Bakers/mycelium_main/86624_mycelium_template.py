import collections

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    
    def dist(x1, y1, x2, y2):
        return abs(x1 - x2) + abs(y1 - y2)
   
    def is_mycelium_tile(x, y):
        time_mycelium = 7 * dist(x, y, X_M, Y_M)
        time_grass = 2 * dist(x, y, X_G, Y_G)
        return time_mycelium < time_grass

    if not is_mycelium_tile(X_M, Y_M):
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
                if is_mycelium_tile(nx, ny):
                    visited.add((nx, ny))
                    queue.append((nx, ny))
                else:
                   
                    visited.add((nx, ny))

    return count

def main():
    import sys

    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    pointer = 1
    for _ in range(T):
        xg, yg, xm, ym = map(int, input_data[pointer:pointer+4])
        print(solve(xg, yg, xm, ym))
        pointer += 4

if __name__ == '__main__':
    main()