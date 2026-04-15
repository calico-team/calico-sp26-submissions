def solve():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        
        S1 = []
        for _ in range(N):
            S1.append(input[ptr])
            ptr += 1
        
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
            # 计算S1中z列的#数量（y方向）
            s1_count = 0
            for y in range(N):
                if S1[y][z] == '#':
                    s1_count += 1
            
            # 计算S2中z列的#数量（x方向）
            s2_count = 0
            for x in range(N):
                if S2[x][z] == '#':
                    s2_count += 1
            
            min_volume += max(s1_count, s2_count)
        
        print(max_volume, min_volume)

if __name__ == "__main__":
    solve()
