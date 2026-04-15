def solve():
    import sys
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    pos = 1
    out = []
    for _ in range(t):
        n = data[pos]; pos += 1
        A = data[pos:pos+n]; pos += n
        if n == 1:
            out.append(str(A[0]))
            continue
        b = [0]*n
        b[0] = A[0]
        b[-1] = A[-1]
        for i in range(1, n-1):
            b[i] = sorted([A[i-1], A[i], A[i+1]])[1]
        out.append(' '.join(map(str, b)))
    print('\n'.join(out))

if __name__ == '__main__':
    solve()
