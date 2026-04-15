def solve():
    import sys
    input = sys.stdin.read().splitlines()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        
        # 读取S1阴影（y-z平面投影）
        S1 = []
        for _ in range(N):
            S1.append(input[ptr])
            ptr += 1
        
        # 读取S2阴影（x-z平面投影）
        S2 = []
        for _ in range(N):
            S2.append(input[ptr])
            ptr += 1
        
        # 计算最大体积
        max_volume = 0
        for x in range(N):
            for y in range(N):
                for z in range(N):
                    if S1[y][z] == '#' and S2[x][z] == '#':
                        max_volume += 1
        
        # 计算最小体积
        min_volume = 0
        for z in range(N):
            # 统计S1在z列的#数量（y方向）
            s1_count = 0
            for y in range(N):
                if S1[y][z] == '#':
                    s1_count += 1
            
            # 统计S2在z列的#数量（x方向）
            s2_count = 0
            for x in range(N):
                if S2[x][z] == '#':
                    s2_count += 1
            
            # 每一层z的最小填充数是两个方向中较大的那个
            min_volume += max(s1_count, s2_count)
        
        print(max_volume, min_volume)

if __name__ == "__main__":
    solve()
