def solve():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    out_lines = []
    idx = 1
    for _ in range(t):
        XG = int(data[idx]); YG = int(data[idx+1]); XM = int(data[idx+2]); YM = int(data[idx+3])
        idx += 4
        dx = abs(XG - XM)
        dy = abs(YG - YM)
        dist = dx + dy
        if dist == 1:
            out_lines.append("2")
        elif dist == 0:
            out_lines.append("1")
        else:
            if dist % 2 == 0:
                out_lines.append(str(dist + 1))
            else:
                out_lines.append(str(dist))
    sys.stdout.write("\n".join(out_lines))

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()