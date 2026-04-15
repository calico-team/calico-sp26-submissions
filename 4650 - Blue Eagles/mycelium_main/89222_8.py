def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        XG = int(next(it)); YG = int(next(it))
        XM = int(next(it)); YM = int(next(it))
        D = abs(XG - XM) + abs(YG - YM)
        if D == 1:
            out.append('2')
        else:
            R = (2 * D - 2) // 9
            out.append(str(2 * R * (R + 1) + 1))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    read_your_input()
