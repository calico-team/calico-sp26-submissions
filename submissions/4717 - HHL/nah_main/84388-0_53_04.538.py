import sys

def solve():
    tokens = (int(x) for line in sys.stdin for x in line.split())
    try:
        T = next(tokens)
        for _ in range(T):
            N = next(tokens)
            P = next(tokens)
            R = next(tokens)
            K = next(tokens)

            charges = 0
            possible = True

            for i in range(1, N + 1):
                E = next(tokens)

                if not possible:
                    continue

                P -= E

                if P < 0 < R and charges > 0:
                    use = min((-P + R - 1) // R, charges)
                    P += use * R
                    charges -= use

                if P < 0:
                    possible = False
                elif i % K == 0:
                    charges += 1

            print("nah i'd win" if possible else "nah i'd lose", flush=True)

    except StopIteration:
        pass

if __name__ == '__main__':
    solve()