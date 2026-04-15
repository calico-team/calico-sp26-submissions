import sys

def solve(N, M, D, cells):
    A = [1] * N
    if M == 0:
        return A, []
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
    data = sys.stdin.buffer
    line = data.readline()
    if not line:
        return
    N, M, D = map(int, line.split())

    cells = []
    for _ in range(M):
        parts = data.readline().split()
        if not parts:
            break
        R, C, V, W = map(int, parts)
        cells.append((R, C, V, W))

    A, discards = solve(N, M, D, cells)

    out_lines = [
        ' '.join(str(x) for x in A),
        str(len(discards)) + ' ' + ' '.join(str(x) for x in discards)
    ]
    sys.stdout.write('\n'.join(out_lines))


if __name__ == '__main__':
    main()