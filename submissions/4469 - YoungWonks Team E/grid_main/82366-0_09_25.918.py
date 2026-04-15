import sys

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        n = int(input[idx])
        idx += 1
        a = []
        for i in range(n):
            a.append(int(input[idx]))
            idx += 1

        vals = list(set(a))
        combos = [[]]
        for i in range(n):
            new_combos = []
            for c in combos:
                for v in vals:
                    new_combos.append(c + [v])
            combos = new_combos

        best_cost = float('inf')
        best_b = None
        for b in combos:
            cost = 0
            for i in range(n):
                cost += abs(a[i] - b[i])
            for i in range(n - 1):
                cost += abs(b[i] - b[i + 1])

            if cost < best_cost:
                best_cost = cost
                best_b = b

        parts = []
        for x in best_b:
            parts.append(str(x))
        print(' '.join(parts))

main()