t = int(input())
for _ in range(t):
    k, n, m, p, q = map(int, input().split())
    
    # 读取小行星，使用元组列表（列表查重效率低，建议用字典）
    asteroids = []
    for i in range(k):
        x, y = map(int, input().split())
        asteroids.append((x, y))
    
    start = asteroids[0]
    start_x, start_y = start
    
    # 建立位置到索引的映射（排除第0个），方便 O(1) 查询
    target_map = {}
    for i in range(1, k):
        target_map[asteroids[i]] = i
    
    x, y = start_x, start_y
    
    while True:
        # 正确移动：Q 沿 x 轴，P 沿 y 轴，并正确取模环绕
        x = (x + q) % n
        y = (y + p) % m
        
        # 如果回到起点，说明击中了第0个小行星（绕行一圈后）
        if x == start_x and y == start_y:
            print(0)
            break
        
        # 检查是否击中其他小行星
        if (x, y) in target_map:
            print(target_map[(x, y)])
            break
