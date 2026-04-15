import sys
input = sys.stdin.readline

def solve(n, s1, s2):
    jugs_cave_image_max = 0
    jugs_cave_image_min = 0
    for z in range(n):
        r = s1[z].count('#')
        c = s2[z].count('#')
        jugs_cave_image_max += r * c
        jugs_cave_image_min += r if r > c else c
    return jugs_cave_image_max, jugs_cave_image_min

def read_your_input():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s1 = [input() for _ in range(n)]
        s2 = [input() for _ in range(n)]
        mx, mn = solve(n, s1, s2)
        print(mx, mn)

read_your_input()
