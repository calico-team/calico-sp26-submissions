n = int(input())
for i in range (n) :
    coodi = []
    hash = {}
    num, length, w, top, right = map(int, input().split())
    #   地图长宽     步长

    for j in range (num) :
        x, y = map(int, input().split())

        hash[(x, y)] = j
        coodi.append((x, y))

    sx = coodi[0][0]
    sy = coodi[0][1]
    new_x = sx
    new_y = sy
    while True :
        new_x = (new_x + right) % length
        new_y = (new_y + top) % w
        if new_x == sx and new_y == sy:
            print(0)
            break

        if (new_x, new_y) in hash :
            print(hash[(new_x, new_y)])
            break

