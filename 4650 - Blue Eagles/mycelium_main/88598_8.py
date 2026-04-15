import sys

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    out_lines = []
    for _ in range(t):
        xg = int(data[idx]); yg = int(data[idx+1])
        xm = int(data[idx+2]); ym = int(data[idx+3])
        idx += 4
        
        dist = abs(xg-xm) + abs(yg-ym)
        max_dm = (2 * dist) // 5 + 10
        
        min_x = xm - max_dm
        max_x = xm + max_dm
        min_y = ym - max_dm
        max_y = ym + max_dm
        
        count = 0
        for x in range(min_x, max_x+1):
            for y in range(min_y, max_y+1):
                dm = abs(x-xm) + abs(y-ym)
                dg = abs(x-xg) + abs(y-yg)
                if 7*dm < 2*dg:
                    count += 1
        out_lines.append(str(count))
    
    sys.stdout.write("\n".join(out_lines))

def read_your_input():
    pass

if __name__ == "__main__":
    solve()
