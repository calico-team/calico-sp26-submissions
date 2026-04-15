def epfiles():
    A = list(input())
    B = list(input())
    B.append("⠀")
    counter = -1
    i = 0
    for j in range(counter + 1, len(A)):
        if A[j] == B[i]:
            counter = j
            i += 1
        else:
            A[j] = "#"
    return ''.join(A)


cases = int(input())
for i in range(cases):
    print(epfiles())
