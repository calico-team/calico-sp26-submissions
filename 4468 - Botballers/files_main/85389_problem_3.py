def censor_this_please():
    A = input()
    B = input()
    result = list(A)
    j = 0
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            j += 1
        else:
            result[i] = '#'
    print(''.join(result))

censor_this_please()
