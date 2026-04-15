import sys
from collections import deque

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    results = []
    
    for _ in range(t):
        XG, YG, XM, YM = map(int, data[idx:idx+4])
        idx += 4
        
        # 独立扩散草地
        grass_set = {(XG, YG)}
        grass_queue = deque([(XG, YG)])
        
        # 独立扩散菌丝
        mycelium_set = {(XM, YM)}
        mycelium_queue = deque([(XM, YM)])
        
        # 记录每次扩散的新增格子，用于判断包裹
        # 持续扩散直到菌丝被草地完全包裹
        while True:
            # 草地扩散一步（2 ticks）
            new_grass = set()
            for _ in range(len(grass_queue)):
                x, y = grass_queue.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass_set:
                        new_grass.add((nx, ny))
            grass_set.update(new_grass)
            grass_queue.extend(new_grass)
            
            # 菌丝扩散一步（7 ticks）
            new_mycelium = set()
            for _ in range(len(mycelium_queue)):
                x, y = mycelium_queue.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in mycelium_set:
                        new_mycelium.add((nx, ny))
            mycelium_set.update(new_mycelium)
            mycelium_queue.extend(new_mycelium)
            
            # 检查菌丝是否被草地完全包裹
            # 即菌丝集合中所有格子都在草地集合中
            if mycelium_set.issubset(grass_set):
                break
        
        # 现在处理重叠格子：用曼哈顿距离判断谁先到达
        # 对于菌丝集合中的每个格子，检查是否真的能赢
        final_mycelium = set()
        
        for (x, y) in mycelium_set:
            # 计算曼哈顿距离
            distG = abs(x - XG) + abs(y - YG)
            distM = abs(x - XM) + abs(y - YM)
            
            # 到达时间
            timeG = 2 * distG
            timeM = 7 * distM
            
            # 菌丝严格先到达才能保留
            if timeM < timeG:
                final_mycelium.add((x, y))
        
        results.append(str(len(final_mycelium)))
    
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve()