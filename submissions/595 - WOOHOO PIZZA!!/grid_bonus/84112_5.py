import sys
inp = [line.strip() for line in sys.stdin]
t = int(inp[0])

for i in range(1, len(inp), 2):
    n = int(inp[i])
    a = list(map(int, inp[i+1].split()))

    diffs = []
    for i in range(n-1):
        diffs.append(a[i+1] - a[i])

    ans = a[:]
    for i in range(len(diffs)-1):
        if diffs[i] < 0 and diffs[i+1] > 0: # valley
            ans[i+1] = min(a[i], a[i+2])
        elif diffs[i] > 0 and diffs[i+1] < 0: # mtn
            ans[i+1] = max(a[i], a[i+2])
        diffs[i] = ans[i+1] - ans[i]
        diffs[i+1] = ans[i+2] - ans[i+1]

    print(*ans)


    # 2 1 4 2 = 1+3+2
    # 2 2 2 2 = 0
    # between = 3


    # top = 0
    # for i in range(n-1):
    #     top += abs(a[i] - a[i+1])
    # diffs = []
    # for i in range(n-1):
    #     diffs.append(a[i+1] - a[i])

    # print(diffs)
    # print(top)
    # ans = a[:]
    # for i in range(len(diffs)-1):
    #     if diffs[i] < 0 and diffs[i+1] > 0: # valley
    #         ans[i+1] = min(a[i], a[i+2])
    #     elif diffs[i] > 0 and diffs[i+1] < 0: # mtn
    #         ans[i+1] = max(a[i], a[i+2])
    # print(*ans)


    # 1 2 5 2 5 = 10 
    # 1 2 2 2 5 = 4
    # between = 3

    # +4 +4, vs one +4
    # so when there is a big inc and dec (or vice versa), it's better to flatten it
