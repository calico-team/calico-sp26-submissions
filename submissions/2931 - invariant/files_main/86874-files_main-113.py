T = int(input())

for _ in range(T):
    A = input().strip()
    B = input().strip()
    datawithHash = []
    indx = 0
    indxB=0
    while indxB < len(A):
        if indx < len(B) and A[indxB] == B[indx]:
            datawithHash.append(A[indxB])
            indx+= 1
        else:
            datawithHash.append('#')

        indxB+= 1
    print(''.join(datawithHash))