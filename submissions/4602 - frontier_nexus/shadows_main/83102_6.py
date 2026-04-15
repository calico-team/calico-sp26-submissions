import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s1 = [input().strip() for _ in range(n)]
    s2 = [input().strip() for _ in range(n)]

    # Coordinates: x = column in s1, y = column in s2, z = row (same for both)
    # A block at (x, y, z) is allowed if s1[z][x]=='#' and s2[z][y]=='#'
    
    # Max volume: fill every allowed (x,y,z) position
    # For each row z: count_s1[z] * count_s2[z]
    
    # Min volume: for each row z, we need to cover all '#' in s1[z] and all '#' in s2[z]
    # Minimum blocks needed = max(count_s1[z], count_s2[z])
    # (like a bipartite cover — pair up the bigger set with the smaller, rest get unique pairs)

    max_vol = 0
    min_vol = 0

    for z in range(n):
        c1 = s1[z].count('#')
        c2 = s2[z].count('#')
        max_vol += c1 * c2
        min_vol += max(c1, c2)

    print(max_vol, min_vol)