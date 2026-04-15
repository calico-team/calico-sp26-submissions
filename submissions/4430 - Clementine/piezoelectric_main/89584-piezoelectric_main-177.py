# Q1
import math
for _ in range(int(input())):
     L, W, E, R = map(int, input().split())
     energy = R*2*(L+W)
     print(math.ceil(E/energy))