import sys

def solve(N, M, D, cells):
    if M == 0:
        return [1] * N, []
    A = [1] * N
    errors = []
    for idx, (R, C, V, W) in enumerate(cells, start=1):
        prod = 1
        err = W * abs(prod - V) / V
        errors.append((err, idx))
    errors.sort(reverse=True)
    discard_cnt = min(D, len(errors))
    discards = [idx for _, idx in errors[:discard_cnt]]

    return A, discards


def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    N = int(next(it))
    M = int(next(it))
    D = int(next(it))

    cells = []
    for _ in range(M):
        R = int(next(it))
        C = int(next(it))
        V = int(next(it))
        W = int(next(it))
        cells.append((R, C, V, W))

    A, discards = solve(N, M, D, cells)

    out_lines = []
    out_lines.append(' '.join(str(x) for x in A))
    out_lines.append(str(len(discards)) + ' ' + ' '.join(str(x) for x in discards))
    sys.stdout.write('\n'.join(out_lines))


if __name__ == '__main__':
    main()