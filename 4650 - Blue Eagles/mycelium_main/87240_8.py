def solve_one(XG, YG, XM, YM):
    dx = XM - XG
    dy = YM - YG
    d = abs(dx) + abs(dy)
    
    if d == 0:
        return 1
    
    a = min(abs(dx), abs(dy))
    b = max(abs(dx), abs(dy))
    
    total = 0
    for x in range(-b-1, b+2):
        for y in range(-b-1, b+2):
            if 7 * (abs(x - dx) + abs(y - dy)) < 2 * (abs(x) + abs(y)):
                total += 1
    return total

def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    out = []
    for _ in range(t):
        XG = int(data[idx]); YG = int(data[idx+1])
        XM = int(data[idx+2]); YM = int(data[idx+3])
        idx += 4
        out.append(str(solve_one(XG, YG, XM, YM)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    read_your_input()
