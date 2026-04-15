import sys

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    out = []
    for _ in range(t):
        xg = int(data[idx]); yg = int(data[idx+1])
        xm = int(data[idx+2]); ym = int(data[idx+3])
        idx += 4
        
        dx = abs(xg - xm)
        dy = abs(yg - ym)
        d = dx + dy
        
        r = (2 * d + 4) // 9
        cnt = 2 + 4 * r * (r + 1)
        
        out.append(str(cnt))
    
    sys.stdout.write("\n".join(out))

def read_your_input():
    pass

if __name__ == "__main__":
    solve()
