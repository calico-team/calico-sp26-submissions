t = int(input())
for _ in range(t):
    s = input().strip()
    h = input().strip()
    pos = []
    j = 0
    for i in range(len(s)):
        if j < len(h) and s[i] == h[j]:
            pos.append(i)
            j += 1
    if j != len(h):
        print(-1)
        continue
    res = []
    res.append('#' * pos[0])
    for i in range(len(pos)):
        res.append(s[pos[i]])
        if i < len(pos) - 1:
            res.append('#' * (pos[i+1] - pos[i] - 1))
        else:
            res.append('#' * (len(s) - pos[i] - 1))
    print("".join(res))