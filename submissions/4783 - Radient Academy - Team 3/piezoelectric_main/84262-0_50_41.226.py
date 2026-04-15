t = int(input())
for i in range(t):
    L, W, E, R = map(int, input().split())
    perimetro = 2 * (L + W)
    energia_vuelta = perimetro * R
    vueltas = E // energia_vuelta
    print(vueltas)