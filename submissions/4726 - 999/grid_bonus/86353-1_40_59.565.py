from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    height = list(map(int, input().split()))

    val = []
    length = []
    start = []

    i = 0
    while i < n:
        j = i
        while j < n and height[j] == height[i]:
            j += 1
        val.append(height[i])
        length.append(j - i)
        start.append(i)
        i = j

    m = len(val)

    if m == 1:
        print(*([val[0]] * n))
        continue

    left = [-1] * m
    right = [-1] * m
    alive = [True] * m

    for i in range(m):
        if i > 0:
            left[i] = i - 1
        if i + 1 < m:
            right[i] = i + 1

    q = deque()
    for i in range(m):
        if length[i] == 1:
            l = left[i]
            r = right[i]
            if l != -1 and r != -1:
                if (val[l] < val[i] > val[r]) or (val[l] > val[i] < val[r]):
                    q.append(i)

    while q:
        i = q.popleft()

        if not alive[i] or length[i] != 1:
            continue

        l = left[i]
        r = right[i]

        if l == -1 or r == -1 or not alive[l] or not alive[r]:
            continue

        if not ((val[l] < val[i] > val[r]) or (val[l] > val[i] < val[r])):
            continue

        if val[i] > val[l] and val[i] > val[r]:
            val[i] = max(val[l], val[r])
        else:
            val[i] = min(val[l], val[r])

        cur = i

        if l != -1 and alive[l] and val[l] == val[cur]:
            length[l] += length[cur]
            right[l] = right[cur]
            if right[cur] != -1:
                left[right[cur]] = l
            alive[cur] = False
            cur = l

        rr = right[cur]
        if rr != -1 and alive[rr] and val[rr] == val[cur]:
            length[cur] += length[rr]
            right[cur] = right[rr]
            if right[rr] != -1:
                left[right[rr]] = cur
            alive[rr] = False

        check = [cur]
        if left[cur] != -1:
            check.append(left[cur])
            if left[left[cur]] != -1:
                check.append(left[left[cur]])
        if right[cur] != -1:
            check.append(right[cur])
            if right[right[cur]] != -1:
                check.append(right[right[cur]])

        for x in check:
            if x == -1 or not alive[x] or length[x] != 1:
                continue
            l = left[x]
            r = right[x]
            if l != -1 and r != -1 and alive[l] and alive[r]:
                if (val[l] < val[x] > val[r]) or (val[l] > val[x] < val[r]):
                    q.append(x)

    ans = [0] * n
    i = 0
    while i != -1 and not alive[i]:
        i = right[i]

    while i != -1:
        st = start[i]
        ln = length[i]
        v = val[i]
        for k in range(st, st + ln):
            ans[k] = v
        i = right[i]

    print(*ans)
