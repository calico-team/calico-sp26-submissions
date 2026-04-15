T = int(input())
for _ in range(T):
    length, width, electricity, rate = map(int, input().split())
    triangle_area = 2 * (length + width)
    laps = electricity // (triangle_area * rate)
    print(laps)

def read_your_input():
    return map(int, input().split())