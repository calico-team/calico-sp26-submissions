def solve():
    import sys
    input = sys.stdin.read().splitlines()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        
        # 读取S1阴影（z-x平面投影）
        S1 = []
        for _ in range(N):
            S1.append(input[ptr])
            ptr += 1
        
        # 读取S2阴影（z-y平面投影）
        S2 = []
        for _ in range(N):
            S2.append(input[ptr])
            ptr += 1
        
        # 计算最大体积
        max_volume = 0
        for x in range(N):
            for y in range(N):
                for z in range(N):
                    if S1[z][x] == '#' and S2[z][y] == '#':
                        max_volume += 1
        
        # 计算最小体积
        min_volume = 0
        
        for z in range(N):
            # 构建二分图
            # 左边节点：S1[z][x] = '#' 的 x
            X = []
            for x in range(N):
                if S1[z][x] == '#':
                    X.append(x)
            
            # 右边节点：S2[z][y] = '#' 的 y
            Y = []
            for y in range(N):
                if S2[z][y] == '#':
                    Y.append(y)
            
            if not X and not Y:
                continue
            
            # 构建邻接表 - 每个x可以连接所有y
            adj = [[] for _ in range(len(X))]
            for i in range(len(X)):
                adj[i] = list(range(len(Y)))
            
            # 二分图最大匹配
            match_to = [-1] * len(Y)  # y -> x的索引
            result = 0
            
            def dfs(x_idx, visited):
                for y_idx in adj[x_idx]:
                    if not visited[y_idx]:
                        visited[y_idx] = True
                        if match_to[y_idx] == -1 or dfs(match_to[y_idx], visited):
                            match_to[y_idx] = x_idx
                            return True
                return False
            
            for x_idx in range(len(X)):
                visited = [False] * len(Y)
                if dfs(x_idx, visited):
                    result += 1
            
            # 最小覆盖数 = |X| + |Y| - 最大匹配数
            min_cover = len(X) + len(Y) - result
            min_volume += min_cover
        
        print(max_volume, min_volume)

if __name__ == "__main__":
    solve()
