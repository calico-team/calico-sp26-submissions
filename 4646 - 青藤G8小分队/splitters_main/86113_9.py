def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def solve():
    import sys
    from collections import deque
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    directions = {
        '<': (0, -1),
        '>': (0, 1),
        '^': (-1, 0),
        'v': (1, 0)
    }
    
    for _ in range(T):
        N = int(input[ptr])
        M = int(input[ptr+1])
        ptr += 2
        
        grid = []
        for _ in range(N):
            grid.append(input[ptr])
            ptr += 1
        
        # 检查是否有收集点
        has_collect = False
        collect_pos = None
        for i in range(N):
            for j in range(M):
                if grid[i][j] in directions:
                    di, dj = directions[grid[i][j]]
                    ni, nj = i + di, j + dj
                    if ni < 0 or ni >= N or nj < 0 or nj >= M:
                        has_collect = True
                        collect_pos = (i, j)
                        break
            if has_collect:
                break
        
        if not has_collect:
            print(0, 1)
            continue
        
        # DFS 计算概率
        def dfs(i, j, numerator, denominator):
            if i < 0 or i >= N or j < 0 or j >= M:
                # 收集点
                return (numerator, denominator)
            
            tile = grid[i][j]
            
            if tile == 'x':
                # 销毁
                return (0, 1)
            elif tile in directions:
                # 传送带
                di, dj = directions[tile]
                ni, nj = i + di, j + dj
                return dfs(ni, nj, numerator, denominator)
            elif tile == 's':
                # 分裂器
                valid_neighbors = []
                for di, dj in [(-1,0), (1,0), (0,-1), (0,1)]:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < N and 0 <= nj < M:
                        neighbor_tile = grid[ni][nj]
                        if neighbor_tile == 'x':
                            valid_neighbors.append((ni, nj))
                        elif neighbor_tile in directions:
                            # 检查是否指向分裂器
                            ndi, ndj = directions[neighbor_tile]
                            nni, nnj = ni + ndi, nj + ndj
                            if (nni, nnj) != (i, j):
                                valid_neighbors.append((ni, nj))
                
                if not valid_neighbors:
                    return (0, 1)
                
                k = len(valid_neighbors)
                total_num = 0
                total_den = 1
                
                for neighbor in valid_neighbors:
                    ni, nj = neighbor
                    num, den = dfs(ni, nj, numerator, denominator * k)
                    # 通分
                    lcm = total_den * den // gcd(total_den, den)
                    total_num = total_num * (lcm // total_den) + num * (lcm // den)
                    total_den = lcm
                
                return (total_num, total_den)
            else:
                # 空 tile
                return (0, 1)
        
        # 从左上角开始
        start_i, start_j = 0, 0
        if grid[start_i][start_j] == 'x':
            print(0, 1)
            continue
        
        p, q = dfs(start_i, start_j, 1, 1)
        
        # 化简分数
        if p == 0:
            print(0, 1)
        else:
            divisor = gcd(p, q)
            p //= divisor
            q //= divisor
            print(p, q)

if __name__ == "__main__":
    solve()
