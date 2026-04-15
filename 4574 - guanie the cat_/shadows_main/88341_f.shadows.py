for T in range(int(input())):
    n = int(input())
    s1 = []
    s2 = []
    for i in range(n):
        s1.append(input())
    for i in range(n):
        s2.append(input())
    mincase = 0
    for i in range(n):
        for j in range(n):
            if s1[i][j] == "#" or s2[i][j] == "#":
                mincase += 1
    maxcase = 0
    s1counts = []
    s2counts = []
    for i in s1:
        s1counts.append(i.count("#"))
    for i in s2:
        s2counts.append(i.count("#"))
    for i in range(n):
        maxcase += s1counts[i] * s2counts[i]
    print(maxcase, mincase)