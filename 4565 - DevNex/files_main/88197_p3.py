def censor_this_please(A, B):
    result = []
    j = 0
    for ch in A:
        if j < len(B) and ch == B[j]:
            result.append(ch)
            j += 1
        else:
            result.append('#')
    return ''.join(result)

def read_your_input():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(censor_this_please(A, B))

read_your_input()