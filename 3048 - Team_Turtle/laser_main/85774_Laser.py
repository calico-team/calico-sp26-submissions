Python 3.12.0 (tags/v3.12.0:0fb18b0, Oct  2 2023, 13:03:39) [MSC v.1935 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> T = int(input())
... for _ in range(T):
...     K, N, M, P, Q = map(int, input().split())
...     asteroids = []
...     pos_map = {}
...     for i in range(K):
...         x, y = map(int, input().split())
...         asteroids.append((x, y))
...         pos_map[(x, y)] = i
...     x, y = asteroids[0]   # start position
...     lazarbeam = 0
...     while True:
...         x = (x + Q) % N
...         y = (y + P) % M
...         lazarbeam += 1
...         if (x, y) in pos_map:
...             print(pos_map[(x, y)])
...             break
... def read_your_input():
