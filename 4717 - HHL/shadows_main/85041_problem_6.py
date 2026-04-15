t = int(input())
for _ in range(t):
    n = int(input())
    s1 = []
    for i in range(n):
        s1.append(input().strip())
    s2 = []
    for i in range(n):
        s2.append(input().strip())

    max_vol = 0
    min_vol = 0

    for z in range(n):
        count1 = s1[z].count('#')
        count2 = s2[z].count('#')
        min_vol += max(count1, count2)
        for x in range(n):
            for y in range(n):
                if s1[z][x] == '#' and s2[z][y] == '#':
                    max_vol += 1

    print(max_vol, min_vol)