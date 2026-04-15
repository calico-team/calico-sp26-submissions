def solve():
    import sys
    from collections import deque
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        Xg = int(input[ptr])
        Yg = int(input[ptr+1])
        Xm = int(input[ptr+2])
        Ym = int(input[ptr+3])
        ptr += 4
        
        # 初始化
        grass = set()
        mycelium = set()
        grass.add((Xg, Yg))
        mycelium.add((Xm, Ym))
        
        # 四个方向
        directions = [(0,1), (1,0), (0,-1), (-1,0)]
        
        # 模拟扩散过程
        # 草的扩散时间点：2,4,6,8,10,12,14,...
        # 菌丝体的扩散时间点：7,14,21,...
        
        # 计算最大可能的扩散时间
        max_time = 1000  # 足够大的时间
        
        for time in range(1, max_time + 1):
            # 草的扩散
            if time % 2 == 0:
                new_grass = set()
                for (x, y) in grass:
                    for (dx, dy) in directions:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grass and (nx, ny) not in mycelium:
                            new_grass.add((nx, ny))
                grass.update(new_grass)
            
            # 菌丝体的扩散
            if time % 7 == 0:
                new_mycelium = set()
                for (x, y) in mycelium:
                    for (dx, dy) in directions:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grass and (nx, ny) not in mycelium:
                            new_mycelium.add((nx, ny))
                mycelium.update(new_mycelium)
            
            # 检查是否停止扩散
            if not new_grass and not new_mycelium:
                break
        
        print(len(mycelium))

if __name__ == "__main__":
    solve()
