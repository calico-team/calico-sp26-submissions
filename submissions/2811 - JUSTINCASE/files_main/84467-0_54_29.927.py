__ = int(input())
L = []
for _ in range(__):
    A = input()
    B = input()
    s = ""
    for c in B:
        found=False
        for r in range(len(A)):
            if c == A[r]:
                s += A[r]   
                found=True
                break
        if not found:
            s+="#"

    L.append(s)


for ans in L:
    print(ans)
