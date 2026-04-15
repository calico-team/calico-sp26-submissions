def solve():
    import sys
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    pos = 1
    out_lines = []
    for _ in range(t):
        n = data[pos]
        pos += 1
        A = data[pos:pos + n]
        pos += n
        b = []
        for i in range(n):
            left = A[i - 1] if i > 0 else A[i]
            right = A[i + 1] if i + 1 < n else A[i]
            b.append(sorted([left, A[i], right])[1])
        out_lines.append(' '.join(map(str, b)))
    sys.stdout.write('\n'.join(out_lines))

if __name__ == "__main__":
    solve()
