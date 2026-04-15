'''
T = int(input())
for i in range(T):
    A = input().strip()
    B = input().strip()
    result = ""
    current_b_position = 0
    length_of_b = len(B)
    for char in A:
        if current_b_position < length_of_b and char == B[current_b_position]:
            result += char
            current_b_position += 1
        else:
            result += "#"
    print(result)
'''
T = int(input())
directions = [(0,1),(0,-1),(1,0),(-1,0)]
for i in range(T):
    XG,YG,XM,YM=map(int,input().split())
    if (XG, YG)==(XM, YM):
        print(0)
        continue
    occupied=set()
    occupied.add((XG, YG))
    grass_front = set()
    grass_front.add((XG, YG))
    occupied.add((XM, YM))
    mycelium_front=set()
    mycelium_front.add((XM, YM))
    mycelium_count = 1
    nochange = 0
    tick = 1
    while True:
        new_grass = set()
        new_mycelium = set()
        if tick % 2 == 0:
            for (x, y) in grass_front:
                for dx, dy in directions:
                    nx = x + dx
                    ny = y + dy
                    if (nx, ny) not in occupied:
                        occupied.add((nx, ny))
                        new_grass.add((nx, ny))
        if tick % 7 == 0:
            for (x, y) in mycelium_front:
                for dx, dy in directions:
                    nx = x + dx
                    ny = y + dy
                    if (nx, ny) not in occupied:
                        occupied.add((nx, ny))
                        new_mycelium.add((nx, ny))
                        mycelium_count += 1
        if new_grass:
            grass_front = new_grass
        if new_mycelium:
            mycelium_front = new_mycelium
        if len(new_grass) == 0 and len(new_mycelium) == 0:
            nochange += 1
            if nochange >= 14:
                break
        else:
            nochange = 0
        tick += 1
    print(mycelium_count)