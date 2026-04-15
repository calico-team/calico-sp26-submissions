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

        lo = [0] * n
        hi = [0] * n
        lv = a[0]
        rv = a[0]
        lo[0] = lv
        hi[0] = rv

        for i in range(1, n):
            pts = sorted([lv, rv, a[i], a[i]])
            lv = pts[1]
            rv = pts[2]
            lo[i] = lv
            hi[i] = rv
        best_b = [0] * n
        best_b[n - 1] = lo[n - 1]
        for i in range(n - 2, -1, -1):
            if best_b[i + 1] < lo[i]:
                best_b[i] = lo[i]
            elif best_b[i + 1] > hi[i]:
                best_b[i] = hi[i]
            else:
                best_b[i] = best_b[i + 1]

        parts = []
        for x in best_b:
            parts.append(str(x))
        print(' '.join(parts))

main()