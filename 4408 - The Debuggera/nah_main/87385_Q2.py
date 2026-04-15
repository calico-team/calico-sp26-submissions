import sys


def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        N = int(next(it))
        P = int(next(it))
        R = int(next(it))
        K = int(next(it))
        E = [int(next(it)) for _ in range(N)]
        ok = True
        defeated = 0
        for e in E:
            if P < e:
                ok = False
                break
            P -= e
            defeated += 1
            if defeated % K == 0:
                P += R
        out.append("nah i'd win" if ok else "nah i'd lose")
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
