def solve_one(XG, YG, XM, YM):
    d = abs(XM - XG) + abs(YM - YG)
    return d * d + 1

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
