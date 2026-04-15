import sys

data = sys.stdin.read().strip().split("\n")

for i in range(0, len(data), 2):
    S = data[i].strip()
    A = data[i + 1].strip()

    r = []
    g = 0

    u = len(S)
    v = len(A)

    for i in range(u):
        if g < v and S[i] == A[g]:
            r.append(S[i])
            g += 1
        else:
            r.append('-')

    print("".join(r))