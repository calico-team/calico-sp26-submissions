T = int(input())

for _ in range(T):
    building_count = int(input())
    the_two_tower_heights = list(map(int, input().split()))

    reconstructed_base = the_two_tower_heights[:]

    print(*reconstructed_base)

def read_your_input():
    return map(int, input().split())