import sys

def solve(N, M, D, cells):
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
    data = sys.stdin.read().strip().split()
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
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + discards))

if __name__ == '__main__':
    main()