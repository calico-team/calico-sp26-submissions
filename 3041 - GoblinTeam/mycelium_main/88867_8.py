def compute_mycelium(Xg, Yg, Xm, Ym):
    dx = abs(Xg - Xm)
    dy = abs(Yg - Ym)
    d = dx + dy
    r = (2 * d) // 5
    return 2 * r * r + 2 * r + 1

def read_your_input():
    import sys
    data = list(map(int, sys.stdin.read().split()))
    T = data[0]
    idx = 1
    for _ in range(T):
        Xg = data[idx]
        Yg = data[idx+1]
        Xm = data[idx+2]
        Ym = data[idx+3]
        idx += 4
        print(compute_mycelium(Xg, Yg, Xm, Ym))