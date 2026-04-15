def solve():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(input[ptr])
        M = int(input[ptr+1])
        ptr += 2
        
        # 构建网格
        grid = []
        
        # 中间行（第二行）
        middle_row = []
        for j in range(M):
            middle_row.append((j % 5) + 1 if j % 5 != 4 else 0)
        grid.append(middle_row)
        
        # 第一行
        first_row = []
        for j in range(M):
            if middle_row[j] == 2:
                first_row.append(0)
            else:
                first_row.append(1)
        grid.insert(0, first_row)
        
        # 第三行及以下
        for i in range(2, N):
            row = []
            for j in range(M):
                if middle_row[j] == 4:
                    row.append(4)
                else:
                    row.append(0)
            grid.append(row)
        
        # 输出网格
        for row in grid:
            print(' '.join(map(str, row)))

if __name__ == "__main__":
    solve()
