from collections import deque

def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = map(int, input().split())

        visited_grass = set()
        visited_mycelium = set()
        q_grass = deque()
        q_mycelium = deque()
        
        visited_grass.add((XG, YG))
        q_grass.append((XG, YG, 0))
        
        visited_mycelium.add((XM, YM))
        q_mycelium.append((XM, YM, 0))
        
        mycelium_cells = set([(XM, YM)])
        
        dirs = [(0,1),(0,-1),(1,0),(-1,0)]
        
        time = 0
        max_time = 10000
        
        while time <= max_time:
            time += 1
            if time % 2 == 0:
                new_grass = []
                while q_grass and q_grass[0][2] < time:
                    x, y, t = q_grass.popleft()
                    for dx, dy in dirs:
                        nx, ny = x+dx, y+dy
                        if (nx, ny) not in visited_grass:
                            visited_grass.add((nx, ny))
                            new_grass.append((nx, ny, time))
                q_grass.extend(new_grass)
            if time % 7 == 0:
                new_mycelium = []
                while q_mycelium and q_mycelium[0][2] < time:
                    x, y, t = q_mycelium.popleft()
                    for dx, dy in dirs:
                        nx, ny = x+dx, y+dy
                        if (nx, ny) not in visited_mycelium and (nx, ny) not in visited_grass:
                            visited_mycelium.add((nx, ny))
                            mycelium_cells.add((nx, ny))
                            new_mycelium.append((nx, ny, time))
                q_mycelium.extend(new_mycelium)
        
        print(len(mycelium_cells))

def input():
    solve()

if __name__ == "__main__":
    solve()