def auratables():
    A = input().split(" ")
    N = int(A[0])
    M = int(A[1])
    K = int(A[2])
    B = []
    holder = []
    for i in range(N):
        C = list(input())
        B.append(C)
    for i in range(N - 1):
        for j in range(M - 1):
            if B[i][j] == "-":
                holder.append([i, j])
    lo, hi = 0, 2000
    while lo < hi:
        mid = (lo + hi) // 2
        if can_fit(mid, holder, K) != -1:
            hi = mid
        else:
            lo = mid + 1
    best_dist = lo
    best_aura = float('inf')
    best_window = None
    left = 0
    for right in range(len(holder)):
        while (abs(holder[right][0] - holder[left][0]) +
               abs(holder[right][1] - holder[left][1])) > best_dist:
            left += 1
        if right - left + 1 >= K:
            window = holder[right - K + 1: right + 1]
            max_d = max(
                abs(window[-1][0] - window[0][0]) + abs(window[-1][1] - window[0][1])
                for i in range(len(window)) for j in range(i+1, len(window))
            ) if K > 1 else 0
            if max_d <= best_dist:
                total_aura = sum(min(auralosscalc(B[r], c)) for r, c in window)
                if total_aura < best_aura:
                    best_aura = total_aura
                    best_window = window
    for r, c in best_window:
        print(r, c)


def distance(x1, y1, x2, y2):
    xdif = abs(x2 - x1)
    ydif = abs(y2 - y1)
    manhattan = xdif + ydif
    return manhattan


def auralosscalc(row, pos):
    counter = 0
    for i in range(0, pos):
        if row[i] == "#":
            counter += 1
    lloss = counter
    counter = 0
    for i in range(pos, len(row)):
        if row[i] == "#":
            counter += 1
    rloss = counter
    return lloss, rloss


def can_fit(mid, holder, K):
    left = 0
    count = 1
    for right in range(1, len(holder)):
        while (abs(holder[right][0] - holder[left][0]) +
                abs(holder[right][1] - holder[left][1])) > mid:
            left += 1
        if right - left + 1 >= K:
            return left
    return -1


cases = int(input())
for i in range(cases):
    auratables()