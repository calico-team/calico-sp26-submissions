
T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    # 存储每个坐标对应的索引
    asteroid_map = {}
    coords = []
    for i in range(K):
        x, y = map(int, input().split())
        asteroid_map[(x, y)] = i
        coords.append((x, y))
    
    # 当前位置（起点）
    cur_x, cur_y = coords[0]
    
    # 记录访问过的位置，防止无限循环
    visited = {}
    
    step = 0
    while True:
        # 移动一步
        cur_x = (cur_x + Q) % N
        cur_y = (cur_y + P) % M
        step = step + 1
        
        # 如果这个位置有小行星
        if (cur_x, cur_y) in asteroid_map:
            print(asteroid_map[(cur_x, cur_y)])
            break
        
        # 如果回到起点且没找到，说明不会命中（但题目保证会命中）
        if step > N * M:
            # 保险起见，防止死循环
            break
