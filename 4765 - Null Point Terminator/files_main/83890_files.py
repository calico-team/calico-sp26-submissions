t = int(input())
for i in range(t):
    a = input()
    b = input()
    j = 0
    ans = ""
    for x in a:
        if j < len(b) and x == b[j]:
            ans = ans + x
            j = j + 1
        else:
            ans = ans + "#"
    print(ans)
