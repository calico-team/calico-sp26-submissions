import sys
import math
inp = [line.strip() for line in sys.stdin]
t = int(inp[0])

for i in range(1, len(inp), 2):
    n = int(inp[i])
    a = list(map(int, inp[i+1].split()))

    top = 0
    for i in range(n-1):
        top += abs(a[i] - a[i+1])
    diffs = []
    for i in range(n-1):
        diffs.append(a[i+1] - a[i])

    # print(diffs)
    # print(top)
    ans = a[:]
    for i in range(len(diffs)-1):
        if diffs[i] < 0 and diffs[i+1] > 0: # valley
            ans[i+1] = min(a[i], a[i+2])
        elif diffs[i] > 0 and diffs[i+1] < 0: # mtn
            ans[i+1] = max(a[i], a[i+2])
    print(*ans)

    # 1 5 3 = 6
    # 1 1 3 = 2
    # between = 4

    # 1 5 3 = 6
    # 1 3 3 = 2
    # between = 2

    # 1 5 1
    # 1 1 1

    # +4 +4, vs one +4
    # so when there is a big inc and dec (or vice versa), it's better to flatten it
