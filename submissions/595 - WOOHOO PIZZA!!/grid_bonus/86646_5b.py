import sys
inp = [line.strip() for line in sys.stdin]
t = int(inp[0])

for i in range(1, len(inp), 2):
    n = int(inp[i])
    a = list(map(int, inp[i+1].split()))

    if a[0] < a[-1]: # all inc
        ans = a[:]
        for i in range(n-1):
            if i == 0 and ans[i] > ans[i+1]:
                ans[i+1] = ans[i]
            elif ans[i] > ans[i+1]:
                ans[i] = max(ans[i-1], ans[i+1])
                ans[i+1] = ans[i]

    elif a[0] > a[-1]: # all dec
        ans = a[:]
        for i in range(n-1):
            if i == 0 and ans[i] < ans[i+1]:
                ans[i+1] = ans[i]
            elif ans[i] < ans[i+1]:
                ans[i] = min(ans[i-1], ans[i+1])
                ans[i+1] = ans[i]

    else:
        ans = [a[0]] * n
    print(*ans)


    # 20 60 40 50 40 60
    # 20 40 40 40 40 60

    # 20 60 30 50 40 60
    # 20 30 30 40 40 60


    # 20 60 10 50 40 60 = 40+50+40+10+20 = 160
    # 20 20 20 40 40 60 = 20+20 = 40
    # bw = 40+10+10 = 60

    # 20 60 10 30 40 50
    # 20 20 20 30 40 50


    # 20 10 60 30 40 30
    # 20 20 30 30 30 30

    # 30 60 10 30 40 20
    # 30 30 30 30 30 20

    # 20 60 10 30 40 30
    # 20 20 20 30 30 30

    # 20 60 10 30 40 20
    # 20 20 20 20 20 20

