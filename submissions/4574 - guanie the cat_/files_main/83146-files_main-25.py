for T in range(int(input())):
    A = input()
    B = input()
    indices = set()
    c = 0
    for i in range(len(B)):
        for j in range(c, len(A)):
            if B[i] == A[j]:
                indices.add(c)
                c += 1
                break
            c += 1
    C = list(A)
    for i in range(len(C)):
        if i not in indices:
            C[i] = "#"
    print("".join(C))