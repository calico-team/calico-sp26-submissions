import heapq

def bfs_sim(DX, DY):
    DX, DY = abs(DX), abs(DY)
    pq = [(0, 0, 0, 0), (0, 1, DX, DY)]
    occupied = {}
    
    S = DX + DY
    limit = S + 50 
    
    count = 0
    while pq:
        t, ttype, x, y = heapq.heappop(pq)
        if (x, y) in occupied:
            continue
        occupied[(x, y)] = ttype
        if ttype == 1:
            count += 1
            
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if abs(nx) > limit * 2 or abs(ny) > limit * 2:
                continue
            if (nx, ny) not in occupied:
                if ttype == 0:
                    heapq.heappush(pq, (t + 2, 0, nx, ny))
                else:
                    heapq.heappush(pq, (t + 7, 1, nx, ny))
    return count

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    DX = abs(X_M - X_G)
    DY = abs(Y_M - Y_G)
    S = DX + DY
    
    if S < 400:
        return bfs_sim(DX, DY)
    
    def get_scaled_area(s_target):
        dx = round(DX * s_target / S)
        dy = round(DY * s_target / S)
        return bfs_sim(dx, dy), dx + dy
    
    s1_val, s1_actual = get_scaled_area(200)
    s2_val, s2_actual = get_scaled_area(300)
    s3_val, s3_actual = get_scaled_area(400)
    
    d1 = s2_actual - s1_actual
    d2 = s3_actual - s2_actual
    q1 = s2_actual**2 - s1_actual**2
    q2 = s3_actual**2 - s2_actual**2
    v1_diff = s2_val - s1_val
    v2_diff = s3_val - s2_val
    
    A = (v2_diff - v1_diff * d2 / d1) / (q2 - q1 * d2 / d1)
    B = (v1_diff - A * q1) / d1
    C = s1_val - A * s1_actual**2 - B * s1_actual
    
    ans = A * S**2 + B * S + C
    return round(ans)

def main():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    it = iter(input_data)
    T = int(next(it))
    for _ in range(T):
        X_G = int(next(it))
        Y_G = int(next(it))
        X_M = int(next(it))
        Y_M = int(next(it))
        print(solve(X_G, Y_G, X_M, Y_M))

if __name__ == '__main__':
    main()
