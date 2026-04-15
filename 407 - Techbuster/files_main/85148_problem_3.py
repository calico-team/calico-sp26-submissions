def censor_this_please(A, B):
    result =list(A)
    j =0
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            j +=1
        else:
            result[i]= '#'
    return ''.join(result)


def read_your_input():
    T = int(input())
    for _ in range(T):
        L =input()
        M= input()
        print(censor_this_please(L, M))


read_your_input()