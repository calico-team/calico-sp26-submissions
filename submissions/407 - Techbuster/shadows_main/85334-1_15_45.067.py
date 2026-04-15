import sys
input = sys.stdin.readline

def solve():
    n= int(input())
    S_1= [input().strip() for _ in range(n)]
    S_2 = [input().strip() for _ in range(n)]
    
    jugs_cave_image = None 
    
    max_volume= 0
    min_volume =0
    
    for y in range(n):
        c1 = S_1[y].count('#')
        c2 = S_2[y].count('#')
        max_vol += c1 * c2
        min_vol += max(c1, c2)
    
    print(max_volume, min_volume)

def read_your_input():
    T =int(input())
    for _ in range(T):
        solve()

read_your_input()