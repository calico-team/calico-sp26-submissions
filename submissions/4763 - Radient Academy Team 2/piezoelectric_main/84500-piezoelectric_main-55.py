# Source: https://usaco.guide/general/io

T = int(input())

for _ in range(T):
    L, W, E, R= map(int, input().split())

    perimetro= 2*(L+W)

    energia= perimetro*R

    vueltas= (E//energia)

    print(vueltas)