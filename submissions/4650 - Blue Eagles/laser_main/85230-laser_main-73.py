t = int(input())
for _ in range(t):
    a = input().strip()
    b = input().strip()

    result = list(a)
    j = 0

    for i in range(len(a)):
        if j < len(b) and a[i] == b[j]:
            j += 1
        else:
            result[i] = '#'

    print(''.join(result))