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