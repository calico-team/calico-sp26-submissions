import sys
inp = [line.strip() for line in sys.stdin]
t = int(inp[0])

for i in range(1, len(inp), 2):
    n = int(inp[i])
    a = list(map(int, inp[i+1].split()))

    ans = a[:]
    i = 1
    while i < (n-1):
        if ans[i-1] < ans[i] and ans[i] > ans[i+1]: # mtn
            ans[i] = max(ans[i-1], ans[i+1])
        elif ans[i-1] > ans[i] and ans[i] < ans[i+1]: # valley
            ans[i] = min(ans[i-1], ans[i+1])
        i += 1
    print(*ans)




    # 20 60 10 30 40 20 = 140
    # 20 20 30 30 30 20 = 20, bw = 70 -> 90
    # bruh im still getting this like in 5.py
    # 20 20 20 30 30 20 = 20, bw=40+10+10=60 WORKS
    # 20 20 20 20 20 20 = 0, bw = 80 -> 80 (correct ans)

    # 2 6 6 6 6 2 = 8
    # 2 2 2 2 2 2 = 0 + 12


    # -------------------------

    # 20 60 10 30 40 30 
    # 20 20 30 30 30 30 bad answer?
    # 20 20 20 30 30 30 is correct on other version

    # 20 60 60 60 60 20 good on this code version

    # --

    # 20 60 10 30 40 20 = 40+50+20+10+20 = 140
    # 20 20 30 30 30 20 = 20 BAD ANSWER
    # bw = 40+20+10 = 70

    # 20 20 20 20 20 20 = 0
    # bw = 40+10+10+20 = 80



    #---------------------------

