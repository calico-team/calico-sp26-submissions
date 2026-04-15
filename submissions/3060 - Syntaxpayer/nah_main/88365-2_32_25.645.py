import sys

def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    t = data[0]
    idx = 1
    out = []

    for _ in range(t):
        N = data[idx]
        P = data[idx + 1]
        R = data[idx + 2]
        K = data[idx + 3]
        idx += 4

        saif = P
        win = True

        for i in range(N):
            saif -= data[idx + i]
            if saif < 0:
                win = False
                idx += N - i
                break
            if (i + 1) % K == 0 and i + 1 < N:
                saif += R

        if win:
            idx += N

        out.append("nah i’d win" if win else "nah i’d lose")

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()