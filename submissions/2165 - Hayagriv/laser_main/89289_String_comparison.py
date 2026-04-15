import sys
from asyncio import current_task
from collections import deque
from collections import Counter
#input = sys.stdin.readline

def solve():
    laser_point_x = 0
    laser_point_y = 0
    asteroid_x = []
    og_x = 0
    asteroid_y = []
    og_y = 0
    basic_info_input = input()
    basic_info_list = basic_info_input.split(" ")
    for i in range(0, int(basic_info_list[0])):
        asteroid_positions = input()
        asteroid_positions = asteroid_positions.split(" ")
        asteroid_x.append(int(asteroid_positions[0]))
        asteroid_y.append(int(asteroid_positions[1]))
    combined_asteroid_coordinates = tuple(zip(asteroid_x, asteroid_y))
    og_x = asteroid_x[0]
    og_y = asteroid_y[0]
    rise = int(basic_info_list[3])/int(basic_info_list[4])
    for laser_move in range(0, int(basic_info_list[1])*int(basic_info_list[2])):
        og_x += 1
        og_y += rise
        if og_x >= int(basic_info_list[1]):
            og_x -= int(basic_info_list[1])
            #og_y-=rise
        if og_y >= int(basic_info_list[2]):
            og_y -= int(basic_info_list[2])
            #og_x-=1
        current_coordinate = (og_x, og_y)
        #print(current_coordinate)
        if current_coordinate in combined_asteroid_coordinates:
            asteroid_index = combined_asteroid_coordinates.index(current_coordinate)
            print(asteroid_index)
            return













test_cases = input().strip()
test_cases = int(test_cases)
for i in range(0,test_cases):
    solve()