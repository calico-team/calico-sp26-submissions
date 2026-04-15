import collections
import sys

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Returns the total number of tiles mycelium will ever occupy.
    """
    # Manhattan distance helper
    def get_dist(x1, y1, x2, y2):
        return abs(x1 - x2) + abs(y1 - y2)
    
    def is_mycelium(x, y):
        t_g = 2 * get_dist(x, y, X_G, Y_G)
        t_m = 7 * get_dist(x, y, X_M, Y_M)
        # If both convert on the same tick, it becomes grass 
        return t_m < t_g

    
    if not is_mycelium(X_M, Y_M):
        return 0


    queue = collections.deque([(X_M, Y_M)])
    visited = {(X_M, Y_M)}
    total_count = 0

    while queue:
        cx, cy = queue.popleft()
        total_count += 1

        # Check adjacent tiles
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = cx + dx, cy + dy
            if (nx, ny) not in visited:
                visited.add((nx, ny)) # Mark visited regardless of type
                if is_mycelium(nx, ny):
                    queue.append((nx, ny))
                    
    return total_count

def main():
    # Use fast I/O for large test sets [cite: 128]
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    pointer = 1
    for _ in range(T):
        if pointer + 3 < len(input_data):
            X_G = int(input_data[pointer])
            Y_G = int(input_data[pointer+1])
            X_M = int(input_data[pointer+2])
            Y_M = int(input_data[pointer+3])
            pointer += 4
            print(solve(X_G, Y_G, X_M, Y_M))

if __name__ == '__main__':
    main()