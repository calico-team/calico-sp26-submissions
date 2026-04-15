import sys
from collections import defaultdict
import heapq

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    t = int(data[0])
    idx = 1
    out_lines = []
    
    for _ in range(t):
        N = int(data[idx]); idx += 1
        M = int(data[idx]); idx += 1
        K = int(data[idx]); idx += 1
        grid = []
        for __ in range(N):
            grid.append(data[idx]); idx += 1
        
        available = []
        aura = [[0] * M for _ in range(N)]
        
        for r in range(N):
            left_count = 0
            left_aura = [0] * M
            for c in range(M):
                left_aura[c] = left_count
                if grid[r][c] == '#':
                    left_count += 1
            
            right_count = 0
            right_aura = [0] * M
            for c in range(M - 1, -1, -1):
                right_aura[c] = right_count
                if grid[r][c] == '#':
                    right_count += 1
            
            for c in range(M):
                if grid[r][c] == '-':
                    aura_val = min(left_aura[c], right_aura[c])
                    aura[r][c] = aura_val
                    available.append((r, c))
        
        points = []
        for r, c in available:
            u = r + c
            v = r - c
            points.append((u, v, r, c, aura[r][c]))
        
        points.sort()
        
        def can(D):
            j = 0
            for i in range(len(points)):
                while j < len(points) and points[j][0] - points[i][0] < D:
                    j += 1
                vs = [p[1] for p in points[i:j]]
                vs.sort()
                left = 0
                for right in range(len(vs)):
                    while vs[right] - vs[left] >= D:
                        left += 1
                    if right - left + 1 >= K:
                        return True
            return False
        
        low, high = 0, N + M
        while low < high:
            mid = (low + high) // 2
            if can(mid):
                high = mid
            else:
                low = mid + 1
        D = low
        
        best_sum = float('inf')
        best_seats = []
        
        j = 0
        for i in range(len(points)):
            while j < len(points) and points[j][0] - points[i][0] < D:
                j += 1
            if j - i < K:
                continue
            
            cand = [(points[p][1], points[p][4], points[p][2], points[p][3]) for p in range(i, j)]
            cand.sort()
            
            left = 0
            for right in range(len(cand)):
                while cand[right][0] - cand[left][0] >= D:
                    left += 1
                if right - left + 1 >= K:
                    temp = [cand[x][1] for x in range(left, right + 1)]
                    temp.sort()
                    total = sum(temp[:K])
                    if total < best_sum:
                        best_sum = total
                        best_seats = [(cand[x][2], cand[x][3]) for x in range(left, left + K)]
        
        for r, c in best_seats:
            out_lines.append(f"{r} {c}")
    
    sys.stdout.write("\n".join(out_lines))

def input():
    solve()

if __name__ == "__main__":
    solve()