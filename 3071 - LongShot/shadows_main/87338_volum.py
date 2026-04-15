t = int(input())
for _ in range(t):
    n = int(input())
    s1 = [input().strip() for _ in range(n)]
    s2 = [input().strip() for _ in range(n)]
    
    max_v = 0
    min_v = 0
    
    for z in range(n):
        row_cnt = 0
        col_cnt = 0
        for x in range(n):
            if s2[x][z] == '#':
                row_cnt += 1
        for y in range(n):
            if s1[y][z] == '#':
                col_cnt += 1
        max_v += row_cnt * col_cnt
        min_v += max(row_cnt, col_cnt)
    
    print(f"{max_v} {min_v}")