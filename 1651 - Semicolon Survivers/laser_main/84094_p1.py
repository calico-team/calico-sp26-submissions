import sys
input = sys.stdin.readline

def solve(K, N, M, P, Q, asteroids):
    asteroid_map = {}
    for i in range(K):
        pos = (asteroids[i][0], asteroids[i][1])
        if pos not in asteroid_map:
            asteroid_map[pos] = i

    laser_x = asteroids[0][0]
    laser_y = asteroids[0][1]

    for _ in range(N * M):
        laser_x = (laser_x + Q) % N
        laser_y = (laser_y + P) % M

        if (laser_x, laser_y) in asteroid_map:
            return asteroid_map[(laser_x, laser_y)]

def main():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = []
        for _ in range(K):
            x, y = map(int, input().split())
            asteroids.append((x, y))
        print(solve(K, N, M, P, Q, asteroids))

main()