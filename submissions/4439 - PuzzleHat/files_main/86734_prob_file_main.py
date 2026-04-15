def censor_this_please(a, b):
    result = list(a)
    j = 0
    for i in range(len(a)):
        if j < len(b) and a[i] == b[j]:
            j += 1
        else:
            result[i] = '#'
    return ''.join(result)

def read_your_input():
    t = int(input())
    for _ in range(t):
        a = input().strip()
        b = input().strip()
        print(censor_this_please(a, b))

read_your_input()
