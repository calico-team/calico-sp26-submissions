import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    
    for _ in range(T):
        K = int(next(it))
        N = int(next(it))
        M = int(next(it))
        P = int(next(it))
        Q = int(next(it))
        
        asteroid = []
        for _ in range(K):
            x = int(next(it))
            y = int(next(it))
            asteroid.append((x, y))
        
        x0, y0 = asteroid[0]
        best_t = float('inf')
        best_index = -1
        
        x, y = x0, y0
        visited = set()
        
        t = 0
        while (x, y) not in visited:
            visited.add((x, y))
            
            for i, (xi, yi) in enumerate(asteroid):
                if x == xi and y == yi:
                    if t > 0 and t < best_t:
                        best_t = t
                        best_index = i
            
            x = (x + Q) % N
            y = (y + P) % M
            t += 1
        
        if best_index == -1:
            best_index = 0
            
        print(best_index)

if __name__ == "__main__":
    solve()