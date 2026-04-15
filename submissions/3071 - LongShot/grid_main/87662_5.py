import sys

d = sys.stdin.buffer.read().split()
e = iter(d)
T = int(next(e))
out = []
for _ in range(T):
    N = int(next(e))
    A = [int(next(e)) for __ in range(N)]
    if N == 1:
        out.append(str(A[0]))
        continue
    b = []
    for i in range(N):
        if i == 0:
            b.append((A[0] + A[1]) // 2)
        elif i == N - 1:
            b.append((A[N-2] + A[N-1]) // 2)
        else:
            lst = sorted([A[i-1], A[i], A[i+1]])
            b.append(lst[1])
    out.append(" ".join(map(str, b)))
sys.stdout.write("\n".join(out))