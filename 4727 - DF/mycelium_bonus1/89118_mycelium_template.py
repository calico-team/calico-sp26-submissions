import sys
import heapq

CACHE = {}

def simulate(xg, yg):
    if (xg, yg) in CACHE:
        return CACHE[(xg, yg)]
    
    pq = [(0, 0, xg, yg), (0, 1, 0, 0)]
    occupied = {}
    m_count = 0
    m_in_pq = 1
    while pq and m_in_pq > 0:
        t, typ, x, y = heapq.heappop(pq)
        if typ == 1: m_in_pq -= 1
        if (x, y) in occupied: continue
        occupied[(x, y)] = typ
        if typ == 1: m_count += 1
        step = 2 if typ == 0 else 7
        next_t = t + step
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if (nx, ny) not in occupied:
                heapq.heappush(pq, (next_t, typ, nx, ny))
                if typ == 1: m_in_pq += 1
    
    CACHE[(xg, yg)] = m_count
    return m_count

def fit_and_eval_int(v1, v2, v3, k):
    C = v1
    A14_2 = (v3 - 2 * v2 + v1) // 2
    B14 = (v2 - v1) - A14_2
    return A14_2 * k * k + B14 * k + C

def solve(xg, yg, xm, ym):
    dx, dy = abs(xg - xm), abs(yg - ym)
    a, b = max(dx, dy), min(dx, dy)
    d = a - b
    r = b % 14
    k = b // 14
    
    v1 = simulate(r + d, r)
    v2 = simulate(r + 14 + d, r + 14)
    v3 = simulate(r + 28 + d, r + 28)
    
    return fit_and_eval_int(v1, v2, v3, k)

def main():
    data = sys.stdin.read().split()
    if not data: return
    it = iter(data)
    try:
        T_cases = int(next(it))
    except StopIteration: return
    
    results = []
    for _ in range(T_cases):
        try:
            xg, yg, xm, ym = int(next(it)), int(next(it)), int(next(it)), int(next(it))
            results.append(str(solve(xg, yg, xm, ym)))
        except StopIteration: break
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()
