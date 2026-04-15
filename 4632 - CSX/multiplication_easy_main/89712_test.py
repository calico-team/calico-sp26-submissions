'''directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
total_cases = int(input())

for case in range(total_cases):
    grass_x, grass_y, mycelium_x, mycelium_y = map(int, input().split())
    if grass_x == mycelium_x and grass_y == mycelium_y:
        print(0)
        continue
    grass_area = set()
    mycelium_area = set()
    grass_area.add((grass_x, grass_y))
    mycelium_area.add((mycelium_x, mycelium_y))
    time = 1
    last_expand_time = 1
    while True:
        temp_grass = set()
        temp_mycelium = set()
        if time % 2 == 0:
            for x, y in grass_area:
                for dx, dy in directions:
                    new_x = x + dx
                    new_y = y + dy
                    pos = (new_x, new_y)
                    if pos not in grass_area and pos not in mycelium_area:
                        temp_grass.add(pos)
        if time % 7 == 0:
            for x, y in mycelium_area:
                for dx, dy in directions:
                    new_x = x + dx
                    new_y = y + dy
                    pos = (new_x, new_y)
                    if pos not in grass_area and pos not in mycelium_area and pos not in temp_grass:
                        temp_mycelium.add(pos)
        grass_area.update(temp_grass)
        mycelium_area.update(temp_mycelium)
        if temp_grass or temp_mycelium:
            last_expand_time = time
        if time - last_expand_time >= 14:
            break
        time += 1
    print(len(mycelium_area))
'''
'''
import sys
import math

def exgcd(a, b):
    if b == 0:
        return (a, 1, 0)
    g, x1, y1 = exgcd(b, a % b)
    return (g, y1, x1 - (a // b) * y1)
def mod_inv(a, m):
    g, x, _ = exgcd(a, m)
    return (x % m + m) % m
def crt(a1, m1, a2, m2):
    g = math.gcd(m1, m2)
    if (a2 - a1) % g != 0:
        return (None, None)
    lcm = m1 // g * m2
    diff = (a2 - a1) % m2
    m1d, m2d = m1 // g, m2 // g
    t = (diff // g * mod_inv(m1d % m2d, m2d)) % m2d
    return ((a1 + m1 * t) % lcm, lcm)

def solve():
    data = sys.stdin.buffer.read().split()
    p = 0
    T = int(data[p]); p += 1
    
    for _ in range(T):
        K, N, M, P, Q = map(int, data[p:p+5]); p += 5
        
        ast = []
        for i in range(K):
            x, y = int(data[p]), int(data[p+1])
            p += 2
            ast.append((x, y))
        
        sx, sy = ast[0]
        ans, best = -1, float('inf')
        
        g1, g2 = math.gcd(Q, N), math.gcd(P, M)
        
        for i in range(K):
            x, y = ast[i]
            dx = (x - sx) % N
            if dx % g1 != 0:
                continue
            N1, Q1, dx1 = N // g1, (Q // g1) % (N // g1), (dx // g1) % (N // g1)
            t1 = (dx1 * mod_inv(Q1, N1)) % N1
            dy = (y - sy) % M
            if dy % g2 != 0:
                continue
            M1, P1, dy1 = M // g2, (P // g2) % (M // g2), (dy // g2) % (M // g2)
            t2 = (dy1 * mod_inv(P1, M1)) % M1
            t, _ = crt(t1, N1, t2, M1)
            if t and 0 < t < best:
                best, ans = t, i        
        print(ans)
solve()
'''
'''
T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    sortedA = sorted(A)
    middle = N // 2
    median = sortedA[middle]
    cost1 = 0
    for num in A:
        cost1 += abs(num - median)
    cost2 = 0
    for j in range(N - 1):
        cost2 += abs(A[j] - A[j + 1])
    if cost1 <= cost2:
        result = [str(median)] * N
        print(' '.join(result))
    else:
        print(' '.join(map(str, A)))
'''
import sys
import math
from collections import deque

def solve():
    # 读数据，注意用buffer快一些
    data = sys.stdin.buffer.read().split()
    ptr = 0
    n = int(data[ptr]); ptr += 1
    m = int(data[ptr]); ptr += 1
    D = int(data[ptr]); ptr += 1
    
    # 存约束，同时建图
    # 图里存 (对方节点, log(v), weight)
    graph = [[] for _ in range(n)]
    constraints = []  # (r, c, logv, w, idx)
    
    for i in range(m):
        r = int(data[ptr]) - 1; ptr += 1  # 转0-index
        c = int(data[ptr]) - 1; ptr += 1
        v = int(data[ptr]); ptr += 1
        w = int(data[ptr]); ptr += 1
        
        if v <= 0:
            logv = 0.0
        else:
            logv = math.log(float(v))
        
        constraints.append((r, c, logv, w, i))
        graph[r].append((c, logv, w))
        graph[c].append((r, logv, w))
    
    # 对每个连通块分别处理
    # 设变量x[i]表示ln(a[i])
    x = [0.0] * n
    visited = [False] * n
    
    for start in range(n):
        if visited[start]:
            continue
            
        # BFS找连通块
        comp = []
        q = deque([start])
        visited[start] = True
        
        while q:
            u = q.popleft()
            comp.append(u)
            for v, _, _ in graph[u]:
                if not visited[v]:
                    visited[v] = True
                    q.append(v)
        
        if len(comp) <= 1:
            x[start] = 0.0  # 孤立点随便设，exp(0)=1
            continue
        
        # 迭代法解这个连通块
        # 目标：让 x[u] + x[v] 尽量接近 logv
        for _ in range(50):  # 迭代50次应该够了
            for u in comp:
                if u == start:
                    continue  # 固定一个参考点，避免整体偏移
                    
                # 根据所有邻居算加权平均
                sum_val = 0.0
                sum_w = 0.0
                for v, logv, w in graph[u]:
                    # 如果 x[u] + x[v] = logv，那么 x[u] = logv - x[v]
                    sum_val += (logv - x[v]) * w
                    sum_w += w
                
                if sum_w > 0:
                    x[u] = sum_val / sum_w
    
    # 算一下每条约束的误差，看看要扔哪些
    to_discard = []
    if D > 0:
        errs = []
        for r, c, logv, w, idx in constraints:
            pred = x[r] + x[c]
            # 用绝对差乘权重作为评判标准
            err = abs(pred - logv) * w
            errs.append((err, idx))
        
        # 排序，选最大的D个扔掉
        errs.sort(reverse=True)
        for i in range(D):
            to_discard.append(errs[i][1])
    
    # 转回整数，注意边界
    ans = []
    for val in x:
        ai = int(round(math.exp(val)))
        if ai < 1:
            ai = 1
        if ai > 10**9:
            ai = 10**9
        ans.append(ai)
    
    # 输出
    print(' '.join(map(str, ans)))
    
    if D == 0:
        print(0)
    else:
        # 输出格式: d idx1 idx2 ... (转回1-indexed)
        res = [str(D)]
        res.extend(str(idx + 1) for idx in to_discard)
        print(' '.join(res))

if __name__ == '__main__':
    solve()
