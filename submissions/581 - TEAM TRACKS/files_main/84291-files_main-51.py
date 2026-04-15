t = int(input())
for _ in range(t):
    a = input()
    b = input()
    ans = ""
    j = 0
    for c in a:
        if j < len(b) and c == b[j]:
            ans += c
            j += 1
        else:
            ans += "#"
    print(ans)
