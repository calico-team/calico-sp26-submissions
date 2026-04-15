def solve(n, s1, s2):
    jugs_cave_image_max = 0
    jugs_cave_image_min = 0
    for z in range(n):
        r = sum(1 for x in range(n) if s1[z][x] == '#')
        c = sum(1 for y in range(n) if s2[z][y] == '#')
        jugs_cave_image_max += r * c
        jugs_cave_image_min += max(r, c)
    return jugs_cave_image_max, jugs_cave_image_min

def read_your_input():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s1 = [input().strip() for _ in range(n)]
        s2 = [input().strip() for _ in range(n)]
        mx, mn = solve(n, s1, s2)
        print(mx, mn)

read_your_input()
