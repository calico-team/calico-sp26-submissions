import heapq
import sys

def bfs_sim(DX, DY):
    DX, DY = abs(DX), abs(DY)
    pq = [(0, 0, 0, 0), (0, 1, DX, DY)]
    occupied = {}
    S = DX + DY
    min_coord = -S - 10
    max_coord = 2 * S + 10
    count = 0
    while pq:
        time, unit_type, x, y = heapq.heappop(pq)
        if (x, y) in occupied: continue
        occupied[(x, y)] = unit_type
        if unit_type == 1:
            count += 1
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if nx < min_coord or nx > max_coord or ny < min_coord or ny > max_coord:
                continue
            if (nx, ny) not in occupied:
                if unit_type == 0:
                    heapq.heappush(pq, (time + 2, 0, nx, ny))
                else:
                    heapq.heappush(pq, (time + 7, 1, nx, ny))
    return count

def solve(X_G, Y_G, X_M, Y_M):
    DX = abs(X_M - X_G)
    DY = abs(Y_M - Y_G)
    S = DX + DY
    if S <= 250:
        return bfs_sim(DX, DY)
    s3 = 210 + (S % 14)
    s2 = s3 - 14
    s1 = s2 - 14
    def get_scaled(s_target):
        dx = round(DX * s_target / S)
        dy = s_target - dx
        return bfs_sim(dx, dy), dx + dy
    v1, a1 = get_scaled(s1)
    v2, a2 = get_scaled(s2)
    v3, a3 = get_scaled(s3)
    d1, d2 = a2 - a1, a3 - a2
    q1, q2 = a2**2 - a1**2, a3**2 - a2**2
    v1d, v2d = v2 - v1, v3 - v2
    det = (q2 * d1 - q1 * d2)
    A = (v2d * d1 - v1d * d2) / det
    B = (v1d - A * q1) / d1
    C = v1 - A * a1**2 - B * a1
    return int(round(A * S**2 + B * S + C))

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    it = iter(input_data)
    try:
        T = int(next(it))
        for _ in range(T):
            X_G = int(next(it))
            Y_G = int(next(it))
            X_M = int(next(it))
            Y_M = int(next(it))
            print(solve(X_G, Y_G, X_M, Y_M))
    except StopIteration:
        pass

if __name__ == '__main__':
    main()
