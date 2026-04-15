import sys
import heapq

def simulate(xg, yg, xm, ym):
    dx, dy = abs(xg - xm), abs(yg - ym)
    xg, yg = dx, dy
    xm, ym = 0, 0
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
    return m_count

def fit_and_eval(s1, v1, s2, v2, s3, v3, S):
    q1, q2, q3 = s1*s1, s2*s2, s3*s3
    denom = (s1 - s2) * (s1 - s3) * (s2 - s3)
    A = (s3 * (v2 - v1) + s2 * (v1 - v3) + s1 * (v3 - v2)) / denom
    B = (q3 * (v1 - v2) + q2 * (v3 - v1) + q1 * (v2 - v3)) / denom
    C = (s2 * s3 * (s2 - s3) * v1 + s3 * s1 * (s3 - s1) * v2 + s1 * s2 * (s1 - s2) * v3) / denom
    return A * S*S + B * S + C

def solve(xg, yg, xm, ym):
    dx, dy = abs(xg - xm), abs(yg - ym)
    a, b = max(dx, dy), min(dx, dy)
    if a + b <= 140:
        return simulate(a, b, 0, 0)

    k = (min(a, b) // 14) - 2
    if k < 0: k = 0
    
    a_base, b_base = a - 14 * k, b - 14 * k
    if a_base + b_base > 140:
        k2 = (a_base // 14) - 4
        if k2 < 0: k2 = 0
        a_base2 = a_base - 14 * k2
        s1, s2, s3 = 0, 14, 28
        v1 = simulate(a_base2 + s1, b_base, 0, 0)
        v2 = simulate(a_base2 + s2, b_base, 0, 0)
        v3 = simulate(a_base2 + s3, b_base, 0, 0)
        res_base = int(round(fit_and_eval(s1, v1, s2, v2, s3, v3, 14 * k2)))
    else:
        res_base = simulate(a_base, b_base, 0, 0)
        
    if k == 0: return res_base
    
    s1, s2, s3 = 0, 14, 28
    v1 = res_base
    v2 = simulate(a_base + s2, b_base + s2, 0, 0)
    v3 = simulate(a_base + s3, b_base + s3, 0, 0)
    return int(round(fit_and_eval(s1, v1, s2, v2, s3, v3, 14 * k)))

def main():
    it = iter(sys.stdin.read().split())
    try:
        T_cases = int(next(it))
    except StopIteration:
        return
    for _ in range(T_cases):
        try:
            xg, yg, xm, ym = int(next(it)), int(next(it)), int(next(it)), int(next(it))
            print(solve(xg, yg, xm, ym))
        except StopIteration:
            break

if __name__ == "__main__":
    main()
