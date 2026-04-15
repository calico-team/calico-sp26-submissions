T = int(input())

for _ in range(T):
    A = input().strip()
    B = input().strip()
    datawithHash = []
    indx = 0
    indxB=0
    while indx < len(B):
        if A[indxB] != B[indx]:
            datawithHash.append('#')
        else:
            datawithHash.append(A[indxB])
            indx+= 1
        indxB+= 1
    print(''.join(datawithHash))