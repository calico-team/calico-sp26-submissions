line = input().split()
if line:
    t = int(line[0])
    for _ in range(t):
        line1 = input().split()
        n, p, r, k = map(int, line1)
        e = list(map(int, input().split()))
        b = 0
        possible = True
        for i in range(n):
            p -= e[i]
            if p < 0:
                possible = False
                break
            b += 1
            if b > 0 and b % k == 0:
                p += r
        if possible:
            print("nah i'd win")
        else:
            print("nah i'd lose")
