def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out_lines = []
    for _ in range(t):
        N = int(next(it))
        P = int(next(it))
        R = int(next(it))
        K = int(next(it))
        E = [int(next(it)) for _ in range(N)]
        power = P
        win = True
        for i, e in enumerate(E, start=1):
            power -= e
            if power < 0:
                win = False
                break
            if i % K == 0:
                power += R
        out_lines.append("nah i'd win" if win else "nah i'd lose")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
