import sys
T = int(sys.stdin.readline())
for _ in range(T):
    A = list(sys.stdin.readline().rstrip())
    B = sys.stdin.readline().rstrip()
    s = 0
    indices = []
    for i in range(len(B)):
        c = B[i]
        a = A.index(c, s)
        indices.append(a)
        s = a+1
    for i in range(len(A)):
        if i not in indices:
            A[i] = "#"
    print("".join(A))