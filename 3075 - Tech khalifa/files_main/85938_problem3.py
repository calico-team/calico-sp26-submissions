import sys

data = sys.stdin.read().strip().split("\n")

u = len(data)

for i in range(0, u - 1, 2): 
    S = data[i].strip()
    A = data[i + 1].strip()

    r = []
    g = 0

    v = len(A)

    for j in range(len(S)):
        if g < v and S[j] == A[g]:
            r.append(S[j])
            g += 1
        else:
            r.append('-')

    print("".join(r))