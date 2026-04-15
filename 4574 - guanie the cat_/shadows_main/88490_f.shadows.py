for T in range(int(input())):
    n = int(input())
    s1 = []
    s2 = []
    s1counts = []
    s2counts = []
    for i in range(n):
        s1.append(input())
    for i in range(n):
        s2.append(input())

    s1counts = []
    s2counts = []
    for i in s1:
        s1counts.append(i.count("#"))
    for i in s2:
        s2counts.append(i.count("#"))

    maxcase = 0
    for i in range(n):
        maxcase += s1counts[i] * s2counts[i]
    mincase = 0
    for i in range(n):
        mincase += max(s1counts[i], s2counts[i])
    print(maxcase, mincase)