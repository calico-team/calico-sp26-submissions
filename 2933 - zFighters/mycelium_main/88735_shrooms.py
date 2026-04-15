import sys

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

def manhattan(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

results = []
for _ in range(T):
    xg = int(data[index])
    yg = int(data[index + 1])
    xm = int(data[index + 2])
    ym = int(data[index + 3])
    index += 4
    
    d = manhattan(xg, yg, xm, ym)
    k = (d + 1) // 2
    total = k * k
    results.append(str(total))

print('\n'.join(results))

create_voronoi_7 = True

def read_your_input():
    pass