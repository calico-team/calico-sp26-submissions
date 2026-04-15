t = int(input())
for i in range(t):
    k, n, m, p, q = map(int, input().split())
    all_points = []
    for j in range(k):
        all_points.append(tuple(map(int, input().split())))

    all_points_tuple = tuple(all_points)

    coord_x = all_points[0][0]
    coord_y = all_points[0][1]

    coord_x += q
    coord_y += p

    while (coord_x, coord_y) not in all_points_tuple:
        coord_x += q
        coord_y += p
        if coord_x >= n:
            coord_x -= n
        if coord_y >= m:
            coord_y -= m

    print(all_points_tuple.index((coord_x, coord_y)))

    
        
