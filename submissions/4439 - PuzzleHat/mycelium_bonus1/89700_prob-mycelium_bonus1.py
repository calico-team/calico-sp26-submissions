import sys
from collections import deque
input = sys.stdin.readline

def simulate(xg, yg, xm, ym):
    mycelium = {(xm, ym)}

    def bfs_grass(mycelium_set, tick):
        max_steps = tick // 2
        visited = {(xg, yg)}
        q = deque([(xg, yg, 0)])
        while q:
            x, y, d = q.popleft()
            if d >= max_steps:
                continue
            for nx, ny in [(x-1,y),(x+1,y),(x,y-1),(x,y+1)]:
                if (nx,ny) not in visited and (nx,ny) not in mycelium_set:
                    visited.add((nx,ny))
                    q.append((nx,ny,d+1))
        return visited

    def neighbors(x, y):
        return [(x-1,y),(x+1,y),(x,y-1),(x,y+1)]

    prev_size = 0
    stable = 0

    for k in range(1, 100000):
        tick = 7 * k
        grass = bfs_grass(mycelium, tick)
        new_myc = set()
        for (x, y) in mycelium:
            for (nx, ny) in neighbors(x, y):
                if (nx, ny) not in grass and (nx, ny) not in mycelium:
                    new_myc.add((nx, ny))
        mycelium |= new_myc

        if len(mycelium) == prev_size:
            stable += 1
            if stable > 5:
                break
        else:
            stable = 0
            prev_size = len(mycelium)

    return len(mycelium)

def read_your_input():
    t = int(input())
    for _ in range(t):
        xg, yg, xm, ym = map(int, input().split())
        print(simulate(xg, yg, xm, ym))

read_your_input()
