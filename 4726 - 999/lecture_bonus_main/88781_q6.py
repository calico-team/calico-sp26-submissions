a = int(input())
ans = []

for i in range(a):
    n, m, k = map(int, input().split())
    g = []
    for i in range(n):
        g.append(input().strip())

    u = n + m - 1
    sh = m - 1

    col = []
    for i in range(u):
        col.append([])

    for i in range(n):
        s = g[i]
        for j in range(m):
            if s[j] == '-':
                col[i + j].append(i - j + sh)

    l = -1
    r = u - 1

    while r - l > 1:
        mid = (l + r) // 2

        cnt = [0] * u
        ok = False
        rr = -1

        limu = u - mid
        limv = u - mid

        for left in range(limu):
            while rr + 1 <= left + mid:
                rr += 1
                for x in col[rr]:
                    cnt[x] += 1

            s = 0
            for x in range(mid + 1):
                s += cnt[x]
            if s >= k:
                ok = True
                break

            for down in range(1, limv):
                s += cnt[down + mid]
                s -= cnt[down - 1]
                if s >= k:
                    ok = True
                    break

            if ok:
                break

            for x in col[left]:
                cnt[x] -= 1

        if ok:
            r = mid
        else:
            l = mid

    d = r

    cnt = [0] * u
    rr = -1
    lu = 0
    lv = 0
    found = False

    limu = u - d
    limv = u - d

    for left in range(limu):
        while rr + 1 <= left + d:
            rr += 1
            for x in col[rr]:
                cnt[x] += 1

        s = 0
        for x in range(d + 1):
            s += cnt[x]
        if s >= k:
            lu = left
            lv = 0
            found = True
            break

        for down in range(1, limv):
            s += cnt[down + d]
            s -= cnt[down - 1]
            if s >= k:
                lu = left
                lv = down
                found = True
                break

        if found:
            break

        for x in col[left]:
            cnt[x] -= 1

    got = 0
    for i in range(n):
        if got == k:
            break
        s = g[i]
        for j in range(m):
            if s[j] == '-':
                uu = i + j
                vv = i - j + sh
                if lu <= uu <= lu + d and lv <= vv <= lv + d:
                    ans.append(str(i) + " " + str(j))
                    got += 1
                    if got == k:
                        break

print("\n".join(ans))
