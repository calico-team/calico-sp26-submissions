import math

def solve(width, height, dy, dx, asteroids):
    gcd = math.gcd(dy, dx)
    if (gcd > 1):
        dy = dy / gcd
        dx = dx / gcd

    x = asteroids[0][0]
    y = asteroids[0][1]

    while (True):
        x = (x + dx) % width
        y = (y + dy) % height

        for i in range(len(asteroids)):
            if x == asteroids[i][0] and y == asteroids[i][1]:
                return i

def main():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = input().split(" ")
        asteroids = []
        for _ in range(int(K)):
            x, y = input().split(" ")
            asteroids.append([int(x), int(y)])

        print(solve(int(N), int(M), int(P), int(Q), asteroids))

main()
