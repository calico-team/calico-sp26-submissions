
import sys
from itertools import product

data = sys.stdin.read().strip().split()
t = int(data[0])
idx = 1
out_lines = []

for _ in range(t):
    n = int(data[idx]); idx += 1
    A = list(map(int, data[idx:idx+n])); idx += n
    
    if n == 1:
        out_lines.append(str(A[0]))
        continue
    
    if n == 2:
        # 枚举 b1, b2 在 [min(A), max(A)] 附近足够范围
        best_cost = float('inf')
        best_b = (0, 0)
        low = min(A) - 10
        high = max(A) + 10
        for b1 in range(low, high+1):
            for b2 in range(low, high+1):
                cost = abs(b1-b2) + abs(A[0]-b1) + abs(A[1]-b2) + abs(A[0]-b2) + abs(A[1]-b1)
                if cost < best_cost:
                    best_cost = cost
                    best_b = (b1, b2)
        out_lines.append(f"{best_b[0]} {best_b[1]}")
    
    if n == 3:
        best_cost = float('inf')
        best_b = (0, 0, 0)
        low = min(A) - 10
        high = max(A) + 10
        for b1 in range(low, high+1):
            for b2 in range(low, high+1):
                for b3 in range(low, high+1):
                    cost = (abs(b1-b2) + abs(b2-b3) +
                            abs(A[0]-b1) + abs(A[1]-b2) + abs(A[2]-b3) +
                            abs(A[0]-b2) + abs(A[1]-b3) + abs(A[1]-b1) + abs(A[2]-b2))
                    if cost < best_cost:
                        best_cost = cost
                        best_b = (b1, b2, b3)
        out_lines.append(f"{best_b[0]} {best_b[1]} {best_b[2]}")

sys.stdout.write("\n".join(out_lines))
