import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    ptr = 0
    t = int(data[ptr])
    ptr += 1
    out = []
    for _ in range(t):
        N = int(data[ptr])
        P = int(data[ptr+1])
        R = int(data[ptr+2])
        K = int(data[ptr+3])
        ptr +=4
        E = list(map(int, data[ptr:ptr+N]))
        ptr +=N
        power = P
        ok = True
        for idx, e in enumerate(E, 1):
            power -= e
            if power < 0:
                ok = False
                break
            if idx % K == 0:
                power += R
        out.append("nah i'd win" if ok else "nah i'd lose")
    print('\n'.join(out))

if __name__ == "__main__":
    solve()
