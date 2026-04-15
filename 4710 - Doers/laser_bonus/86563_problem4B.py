from math import gcd

def move_match(start_x, start_y, target_x, target_y, width, height, step_right, step_up):
    
    x = start_x
    y = start_y
    
    limit = width * height
    
    for _ in range(limit):
        x = (x + step_right) % width
        y = (y + step_up) % height
        
        if x == target_x and y == target_y:
            return _
    
    return 10**9


test_cases = int(input())

for _ in range(test_cases):
    
    total_rocks, width, height, step_y, step_x = map(int, input().split())
    
    rocks = []
    
    for i in range(total_rocks):
        a, b = map(int, input().split())
        rocks.append((a, b))
    
    start_x = rocks[0][0]
    start_y = rocks[0][1]
    
    best_time = 10**9
    answer_index = -1
    
    i = 0
    while i < len(rocks):
        
        target_x = rocks[i][0]
        target_y = rocks[i][1]
        
        if i == 0:
            current_time = width * height
        else:
            current_time = move_match(
                start_x, start_y,
                target_x, target_y,
                width, height,
                step_x, step_y
            )
        
        if current_time < best_time:
            best_time = current_time
            answer_index = i
        
        i += 1
    
    print(answer_index)