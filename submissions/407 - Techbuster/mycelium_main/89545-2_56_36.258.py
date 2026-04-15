import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    try:
        line = next(it)
        T = int(line)
    except StopIteration:
        return
import sys

def floor_sum(n, m, a, b):
    ans = 0
    while True:
        if a >= m:
            ans += n * (n - 1) // 2 * (a // m)
            a %= m
        if b >= m:
            ans += n * (b // m)
            b %= m
        y_max = (a * n + b) // m
        if y_max == 0:
            break
        b_new = a * n + b - m * y_max
        ans += (n - 1) * y_max
        n, m, a, b = y_max, a, m, b_new
    return ans

def get_pts(x1, x2, A, B, C):
    if x1 > x2:
        return 0
    max_x = min(x2, C // A) if A > 0 else x2
    if max_x < x1:
        return 0
    n = max_x - x1 + 1
    b = C - A * max_x
    return floor_sum(n, B, A, b) + n

def get_u_count(y1, y2, A_u, B_y, C):
    return get_pts(y1, y2, B_y, A_u, C - A_u)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    ptr = 1
    
    out = []
    for _ in range(T):
        xg, yg, xm, ym = map(int, input_data[ptr:ptr+4])
        ptr += 4
        
        X = abs(xg - xm)
        Y = abs(yg - ym)
        D = X + Y
        
        if D == 0:
            out.append(0)
            continue
            
        x_block = (2 * D - 1) // 9
        y_block = (2 * D - 1) // 9
        x_left = (2 * D - 1) // 5
        y_bot = (2 * D - 1) // 5
        
        Py = 2 * max(0, y_block + 1 - Y)
        Px = 2 * max(0, x_block + 1 - X)
        
        total = 0
        
        for x in range(0, X + 1):
            C1 = 2 * X + 2 * Y - 1
            max_y1 = min(Y, (C1 - 9 * x) // 9) if 9 * x <= C1 else -1
            if max_y1 >= 0:
                total += max_y1 + 1
                
            C2 = 2 * X - 2 * Y - 1
            max_y2 = (C2 - 9 * x) // 5 if 9 * x <= C2 else -1
            if max_y2 > Y:
                total += max_y2 - Y

        for x in range(X + 1, (2 * D - 1) // 5 + 2):
            C3 = 2 * Y - 2 * X - 1
            max_y3 = min(Y, (C3 - 5 * x) // 9) if 5 * x <= C3 else -1
            if max_y3 >= 0:
                total += max_y3 + 1
                
            C4 = -2 * D - 1
            max_y4 = (C4 - 5 * x) // 5 if 5 * x <= C4 else -1
            if max_y4 > Y:
                total += max_y4 - Y

        y_intervals_q2 = [
            (0, min(Y, y_block), 5, 9, 2 * D + 2 * Py - 1),
            (y_block + 1, Y, 5, 9, 2 * D - 1),
            (Y + 1, y_block, 5, 9, 2 * X - 2 * Y + 4 * y_block + 3),
            (max(Y, y_block) + 1, 2 * D + 5, 5, 5, 2 * X - 2 * Y - 1)
        ]
        for y1, y2, Au, By, C in y_intervals_q2:
            if y1 <= y2:
                total += get_u_count(y1, y2, Au, By, C)

        x_intervals_q4 = [
            (0, min(X, x_block), 5, 9, 2 * D + 2 * Px - 1),
            (x_block + 1, X, 5, 9, 2 * D - 1),
            (X + 1, x_block, 5, 9, 2 * Y - 2 * X + 4 * x_block + 3),
            (max(X, x_block) + 1, 2 * D + 5, 5, 5, 2 * Y - 2 * X - 1)
        ]
        for x1, x2, Av, Bx, C in x_intervals_q4:
            if x1 <= x2:
                total += get_u_count(x1, x2, Av, Bx, C)

        def K1(u): return Py + 2 * max(0, x_left + 1 - u)
        def K2(v): return Px + 2 * max(0, y_bot + 1 - v)
        
        limit_u = (2 * D - 1) // 5 + 5
        limit_v = (2 * D - 1) // 5 + 5
        
        for u in range(1, limit_u + 1):
            k1u = K1(u)
            C_base = 2 * D - 1 - 5 * u
            if C_base + 2 * k1u < 0:
                continue
            
            v_max = -1
            low = 1
            high = limit_v
            while low <= high:
                v = (low + high) // 2
                if 5 * v <= C_base + 2 * min(k1u, K2(v)):
                    v_max = v
                    low = v + 1
                else:
                    high = v - 1
            if v_max >= 1:
                total += v_max

        out.append(str(total))
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()
    for _ in range(T):
        try:
            xg= int(next(it))
            yg = int(next(it))
            xm =int(next(it))
            ym = int(next(it))
        except StopIteration:
            break
        
        dx = xg - xm
        dy = yg - ym
        dist_gm = abs(dx) + abs(dy)
        
        limit = (2 * dist_gm - 1) // 5
        ans = 0
        
        for d in range(limit + 1):
            if d == 0:
                ans += 1
                continue
            
            valid_on_diamond = 0
            for sx, sy in [(1, 1), (1, -1), (-1, -1), (-1, 1)]:
                for i in range(d):
                    cx = i * sx
                    cy = (d - i) * sy
                    if 7 * d < 2 * (abs(cx - dx) + abs(cy - dy)):
                        valid_on_diamond += 1
            ans += valid_on_diamond
            
        sys.stdout.write(str(ans) + '\n')

if __name__ == '__main__':
    solve()