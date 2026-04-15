Python 3.12.0 (tags/v3.12.0:0fb18b0, Oct  2 2023, 13:03:39) [MSC v.1935 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> M = int(input())
... for _ in range(M):
...     L, W, E, R = map(int, input().split())
...     triangle_area = 2 * (L + W)
...     energy_per_lap = triangle_area * R
...     laps = E // energy_per_lap
