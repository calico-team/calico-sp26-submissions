import sys

def solve():
    _data = iter(sys.stdin.buffer.read().split())
    t = int(next(_data))
    out_pt = []

    for _ in range(t):
        N = int(next(_data))
        P = int(next(_data))
        R = int(next(_data))
        K = int(next(_data))

        a_live = True
        for i in range(1, N + 1):
            P -= int(next(_data))
            if P < 0:
                a_live = False
                break
            if i % K == 0 and i != N:
                P += R
        if a_live:
            out_pt.append("nah i’d win")
        else:
            out_pt.append("nah i’d lose")
        if not a_live:
            for _ in range(i + 1, N + 1):
                next(_data)
    sys.stdout.write("\n".join(out_pt))

def read_your_input():
    return sys.stdin.buffer.read().split()
if __name__ == "__main__":
    solve()