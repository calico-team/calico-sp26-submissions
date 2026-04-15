import sys

def solve():
    try:
        line = sys.stdin.readline()
        if not line: return
        t_str = line.strip()
        if not t_str: return
        t = int(t_str)
    except EOFError:
        return

    for _ in range(t):
        xg, yg, xm, ym = map(int, sys.stdin.readline().split())

        dist_mg = abs(xg - xm) + abs(yg - ym)
        
        limit = (2 * dist_mg) // 5 + 5
        
        count = 0

        for x in range(xm - limit, xm + limit + 1):
            rhs = 2 * abs(x - xg) - 7 * abs(x - xm)
            
            
            y_start = min(ym, yg) - limit - 2
            y_end = max(ym, yg) + limit + 2
                   for y in range(ym - limit, ym + limit + 1):
                if 7 * (abs(x - xm) + abs(y - ym)) < 2 * (abs(x - xg) + abs(y - yg)):
                    count += 1
        
        print(count)

if __name__ == "__main__":
    solve()
